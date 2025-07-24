#pragma once

#include "Mouse.h"
#include "Cat.h"
#include "Wall.h"
#include "Door.h"
#include "Key.h"
#include "Cheese.h"
#include "Cheese.h"
#include "MovingObject.h"
#include "CatGift.h"
#include "FreezeGift.h"
#include "TimeGift.h"
#include "LifeGift.h"
#include "TopBar.h"
#include "FileReader.h"
#include <iostream>

int Mouse::m_cheese = 0; int Mouse::m_lives = 3;
int Mouse::m_score = 0; int Mouse::m_keys = 0;

Mouse::Mouse(const sf::Vector2f& location, ImgType img)
	:  MovingObject(location, img, FileReader::getMovingSize()), 
	   m_direction(sf::Vector2f(0, 0)),
	   m_catRemovalReward(false)
{
	imgPos[0] = sf::Vector2f(37,15);
	imgPos[1] = sf::Vector2f(76, 49);
	imgPos[2] = sf::Vector2f(425, 1501);
	imgPos[3] = sf::Vector2f(386, 266);

	m_cheese = m_score = m_keys = 0; 
	m_lives = 3;	
}
//-------------------------------------------
void Mouse::move(sf::Vector2f dir, sf::Time deltaTime, int len, int height) {

	float speed = 60.f;
	m_prevPos = m_rectangle.getPosition();
	m_rectangle.move(dir * speed * deltaTime.asSeconds());
	m_direction = dir;
	
	//check if move is out of bounds
	checkOutOfBounds();

	isFrozen(); //this will check if it is frozen and if not it will return it back to false
	
}
//-------------------------------------------
void Mouse::draw(sf::RenderWindow& window) {

	int posX = (int)m_rectangle.getPosition().x;
	int posY = (int)m_rectangle.getPosition().y;
	
	switch (getDirectionInt())
	{
	case Left:
		m_sprite.setTextureRect(sf::IntRect(imgPos[3].x, (posX % 14)/2 * 54+266, 42, 54));
		break;
	case Right:
		m_sprite.setTextureRect(sf::IntRect(imgPos[2].x, (posX % 7)/2 * 54+1510, 42, 54));
		break;
	case Up:
		m_sprite.setTextureRect(sf::IntRect(imgPos[1].x, posY % 5 * 52.7 + 48, 37, 52.7));
		break;
	case Down:
		m_sprite.setTextureRect(sf::IntRect(imgPos[0].x, posY % 14 * 50 + 16, 37, 50));
		break;
	case None:
		m_sprite.setTextureRect(sf::IntRect(imgPos[0].x, posY % 14 * 50 +16, 37, 50));
	}

	Resources::instance().scaleImg(m_sprite, m_objSize); //this will adjust the size
	m_sprite.setPosition(m_rectangle.getPosition());
	window.draw(m_sprite);
	
}
//---------------------------------------------
int Mouse::getDirectionInt() 
{
	if (m_direction.x == -1 && m_direction.y == 0)
		return Left;
	else if (m_direction.x == 1 && m_direction.y == 0)
		return Right;
	else if (m_direction.x == 0 && m_direction.y == -1)
		return Up;
	else if (m_direction.x == 0 && m_direction.y == 1)
		return Down;

	return None;
}
//-----------------------------------------------------
sf::Vector2f Mouse::getPos() 
{
    return m_rectangle.getPosition();
}
//-----------------------------------------------------
bool Mouse::checkCatRemovalReward() 
{
	if (m_catRemovalReward)
	{ 
		m_catRemovalReward = false;
		return true;
	}
	return false;
}
//-----------------------------------------------------
int Mouse::getInfo(mouseCollectedInfo info)
{
	switch (info) 
	{
	case mouseCollectedInfo::keys:
		return m_keys;
	case mouseCollectedInfo::score:
		return m_score;
	case mouseCollectedInfo::lives:
		return m_lives;
	case mouseCollectedInfo::totalCheese:
		return m_cheese;
	}
	
}
//===================== handle collision functions =====================
//-------------------------------------------
void Mouse::handleCollision(GameObject& gameObj) {

	gameObj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(Mouse&) {

	//do nothing
}
//-------------------------------------------
void Mouse::handleCollision(Cat& obj) {

	if (isFrozen()) //if the cat is frozen nothing will happen to the mouse
		return;

	m_collision = true;
	m_lives--;
	
	if (m_lives == 0)
	{
		//play loosing sound!
		m_isDisposed = true;
	}
}
//-------------------------------------------
void Mouse::handleCollision(Wall& obj) {

	m_rectangle.setPosition(m_prevPos);
}
//-------------------------------------------
void Mouse::handleCollision(Door& obj) {

	if (m_keys > 0) {
		m_score += 2;
		m_keys--;
		obj.handleCollision(*this);
		return;
	}

	m_rectangle.setPosition(m_prevPos);
}
//-------------------------------------------
void Mouse::handleCollision(Key& obj) {

	m_keys++;
	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(Cheese& obj) {

	m_score += 10; //the right score
	m_cheese++;
	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(CatGift& obj) {

	m_score += 5;
	m_catRemovalReward = true;
	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(FreezeGift& obj) {

	m_score += 5;
	m_clock.restart();
	m_freeze = true;
	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(TimeGift& obj) {
	
	m_score += 5;
	TopBar::updateMinutes(1); //this will update the clock by a minute
	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(LifeGift& obj) {

	m_score += 5;
	m_lives++;
	obj.handleCollision(*this);
}