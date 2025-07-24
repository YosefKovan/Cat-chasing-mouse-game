#pragma once 

#include "Static.h"

class Cheese : public Static{

public:

	Cheese(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;
	
};