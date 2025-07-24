#pragma once

#include "Static.h"
#include"Mouse.h"
#include <iostream>


class Wall : public Static {

public:
	Wall(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;	
};