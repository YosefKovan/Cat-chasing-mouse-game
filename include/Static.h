#pragma once

#include "GameObject.h"

class Static : public GameObject{

public:
	Static(sf::Vector2f, ImgType, sf::Vector2f);
	void handleCollision(Cat&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Door&) override;
	void handleCollision(Key& obj) override;
	void handleCollision(Cheese& obj) override;
	void handleCollision(CatGift& obj) override;
	void handleCollision(LifeGift& obj) override;
	void handleCollision(TimeGift& obj) override;
	void handleCollision(FreezeGift& obj) override;
	void draw(sf::RenderWindow& window) override;
};
