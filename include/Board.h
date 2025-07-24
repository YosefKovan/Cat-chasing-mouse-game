#pragma once

#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>
#include "FileReader.h"
#include "GameObject.h"


class Board {

public:
	Board(FileReader &file);
	Board() = default;
	void handleCollisions(GameObject&);
	void handleDrawAndRemoval();
	void mainGmaeLogic();
	void shareMouseLocationWithCats();
	void checkAndResetMoving();
	bool gameOver() const;
	void dealWithCatRemoval();
	bool levelFinishedSuccessfully();

private:
	sf::Clock m_gameClock;
	sf::RenderWindow& m_window;
	sf::Sprite m_backrndSprite;
	int m_totalCheese;
	int m_len, m_height;
	std::string m_fileName;
	std::vector<std::unique_ptr<MovingObject>>& m_moving;
	std::vector<std::unique_ptr<GameObject>>& m_static;	
	sf::Vector2f m_dir;
	void updateAndGetEvent();
	sf::Vector2f getDirection(const sf::Event& event) const;
	
};