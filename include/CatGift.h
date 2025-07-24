#pragma once

#include "Static.h"

class CatGift : public Static{

public:
	CatGift(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;

};