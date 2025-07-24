#pragma once

#include "Static.h"
#include "Mouse.h"
#include "FileReader.h"

class Key : public Static {

public:
	Key(sf::Vector2f location, ImgType img);
	using Static::handleCollision;
	void handleCollision(GameObject& obj) override;
	void handleCollision(Mouse& obj) override;
};