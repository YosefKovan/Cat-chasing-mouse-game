#pragma once

#include <SFML/Graphics.hpp>
#include "Consts.h"
#include "Resources.h"

class Mouse;
class Cat;
class Wall;
class Door;
class Key;
class Cheese;
class CatGift;
class LifeGift;
class TimeGift;
class FreezeGift;

class GameObject {

public:
	GameObject(const sf::Vector2f&, ImgType, sf::Vector2f = sf::Vector2f(60,60));
	virtual ~GameObject() = default;
	bool collision(const GameObject&) const;
	virtual void handleCollision(GameObject&) = 0;
	virtual void handleCollision(Mouse&) = 0;
	virtual void handleCollision(Cat&) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Door&) = 0;
	virtual void handleCollision(Key&) = 0;
	virtual void handleCollision(Cheese&) = 0;
	virtual void handleCollision(CatGift&) = 0;
	virtual void handleCollision(LifeGift&) = 0;
	virtual void handleCollision(TimeGift&) = 0;
	virtual void handleCollision(FreezeGift&) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	void scaleImage();
	bool isDisposed();

protected:
	sf::RectangleShape m_rectangle;
	sf::Vector2f m_startPos;
	sf::Sprite m_sprite;
	bool m_isDisposed;
	sf::Vector2f m_objSize;
};


