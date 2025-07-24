#pragma once

#include "MovingObject.h"


class Mouse : public MovingObject {

public:
	Mouse(const sf::Vector2f&, ImgType img);
	void handleCollision(GameObject&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Door&) override;
	void handleCollision(Key& obj) override;
	void handleCollision(Cheese& obj) override;
	void handleCollision(CatGift& obj) override;
	void handleCollision(FreezeGift& obj) override;
	void handleCollision(TimeGift& obj) override;
	void handleCollision(LifeGift& obj) override;
	void move(sf::Vector2f, sf::Time, int rows, int cols) override;
	void draw(sf::RenderWindow& window) override;
	int getDirectionInt();
	static int getInfo(mouseCollectedInfo);
	bool checkCatRemovalReward();
	sf::Vector2f getPos();

private:
	static int m_cheese, m_lives, m_score, m_keys;
	bool m_catRemovalReward;
	sf::Vector2f m_direction;	
};