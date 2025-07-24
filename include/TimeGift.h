#pragma once

#include "Static.h"

class TimeGift : public Static {

public:
	TimeGift(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;
};