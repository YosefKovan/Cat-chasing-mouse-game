#pragma once

#include "Static.h"
#include"Mouse.h"
#include <iostream>

class Door : public Static{

public:
	Door(sf::Vector2f, ImgType);
	
	using Static::handleCollision;

	void handleCollision(GameObject&) override;
	void handleCollision(Mouse&) override;

};



