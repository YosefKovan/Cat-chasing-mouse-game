#pragma once

#include "Static.h"

class LifeGift : public Static {

public:
	LifeGift(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;
};