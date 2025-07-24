#pragma once

#include "Static.h"

class FreezeGift : public Static {

public:
	FreezeGift(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;

};