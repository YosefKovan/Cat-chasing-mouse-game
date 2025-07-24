#pragma once

#include <SFML/System/Clock.hpp>
#include "Resources.h"

class Menu {

public:
	Menu(sf::RenderWindow&);
	bool wantToPlay();
	
private:
	sf::Sprite m_menuSprite;
	sf::Sprite m_helpSprite;
	sf::RenderWindow& m_window;
	void handleClickMenu(const sf::Event::MouseButtonEvent& event);
	void getMouseEvent(bool = false);
	bool clickedButton(sf::Vector2f, sf::Vector2f);
	void helpWindow();
	bool m_play;
	bool m_exit;
	bool m_help;
	bool m_back;
};