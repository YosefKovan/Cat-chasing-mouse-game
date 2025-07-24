#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "MovingObject.h"

class Cat : public MovingObject {

public:	
	
	Cat(const sf::Vector2f&, ImgType);
	void mouseLocation(const sf::Vector2f& mouseLocation);
	void handleCollision(FreezeGift& obj) override;
	void move(sf::Vector2f, sf::Time, int rows, int cols) override;
	void draw(sf::RenderWindow& window) override;
	sf::Vector2f getDirection();
	void handleCollision(GameObject&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Door&) override;
	void handleCollision(CatGift&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override;
	void handleCollision(Key&) override;
	void handleCollision(Cheese&) override;
	void handleCollision(TimeGift& obj) override;
	void handleCollision(LifeGift& obj) override;
	static int getTotalCats();
	static void updateTotalCats(int count);

private:
	sf::Vector2f m_mouseLocation;
	int m_enumDir;
	bool m_hitWall;
	static int m_totalCats;
};