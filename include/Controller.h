#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include "Board.h"
#include "Menu.h"
#include "TopBar.h"


class Controller {

public:
	Controller();
	void startMenu();
	void playGame();
	
private:	
	void playLevel(std::string);
	sf::RenderWindow& m_window;
	int m_totalScore;
	int m_countDown;
	std::string m_fileName;
	bool m_gameOver;
	int m_level;
};