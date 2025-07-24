#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>

class TopBar {

public:
	TopBar(const int&);
	void displayTimer();
	void displayTotalScore(int) const;
	void displayLivesLeft(int) const;
	void displayTotalKeys(int) const;
	void displayLevel(int) const;
	void display(int, int);
	static void updateMinutes(int);
	static int getTotalTime();

private:
	sf::Clock m_clock;
	sf::Time m_deltaTime;
	sf::Sprite m_timerSprite, m_scoreSprite, m_clockSprite;
	sf::Sprite m_levelSprite, m_keysSprite, m_backSprite;
	int m_minutes;
	static int m_totalTime;
	int m_countDown;
	int m_seconds;
	bool m_regularClock;
	void timerLogic();	
	void setSpritesAndPositions();
};

