#pragma once

#include "GameObject.h"


class MovingObject : public GameObject{

public:
	MovingObject(const sf::Vector2f&, ImgType, sf::Vector2f);
	virtual ~MovingObject() = default;
	virtual void move(sf::Vector2f dir, sf::Time time, int rows, int cols) = 0;
	void resetLocation();
	bool mouseCatCollision();
	static bool isFrozen();

protected:
	bool m_collision;
	static sf::Clock m_clock;
	sf::Vector2f imgPos[4];
	sf::Vector2f m_prevPos;
	static bool m_freeze;
	void checkOutOfBounds();

private:	
	static int m_freezeSec;
};
