#include "MovingObject.h"
#include <iostream>

sf::Clock MovingObject::m_clock;
bool MovingObject::m_freeze = false;
int MovingObject::m_freezeSec = 10;


MovingObject::MovingObject(const sf::Vector2f& location, ImgType img, sf::Vector2f objSize)
	: GameObject(location, img, objSize), m_collision(false), m_prevPos(location)
{
	m_freeze = false;
}
//------------------------------------------
void MovingObject::resetLocation() 
{
	m_rectangle.setPosition(m_startPos);
}
//------------------------------------------
bool MovingObject::mouseCatCollision() 
{
	if (m_collision) {
		m_collision = false;
		return true;
	}
	
	return false;
}
//------------------------------------------
bool MovingObject::isFrozen()
{   

	if (m_freeze && m_clock.getElapsedTime().asSeconds() < m_freezeSec)
	{
		return true;
	}
	
	m_freeze = false;
	return false;
}
//------------------------------------------
void MovingObject::checkOutOfBounds()
{
	if ((m_rectangle.getPosition().x < 0 || m_rectangle.getPosition().x + m_rectangle.getSize().x > SCREEN_SIZE.x) ||
		m_rectangle.getPosition().y < 70 || m_rectangle.getPosition().y + m_rectangle.getSize().y > SCREEN_SIZE.y)
		m_rectangle.setPosition(m_prevPos);
}
