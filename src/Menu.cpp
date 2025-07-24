
#include "Menu.h"
#include "Resources.h"


Menu::Menu(sf::RenderWindow& window)
    : m_window(window),m_play(false), m_exit(false), 
	  m_help(false), m_back(false),
	  m_helpSprite(Resources::instance().getImg(ImgType::HELP)),
	  m_menuSprite(Resources::instance().getImg(ImgType::MENU))
{
	Resources::instance().scaleImg(m_helpSprite, sf::Vector2f(1200, 1000));
}
//------------------------------------
bool Menu::wantToPlay() {

	//every time menu is called it will reset everything to false
	m_play = m_exit = m_help = false; 
	m_window.create(sf::VideoMode(800, 800), "Game window");
	
    while (true) {

		Resources::instance().playMusic(MusicIndexes::MenuMusic);
		m_window.clear();
		getMouseEvent(true);

		if (m_play) {
			Resources::instance().stopMusic();
			Resources::instance().playSound(SoundsIndexes::StartSound);
			return true;
		}
		if (m_exit || !m_window.isOpen()) {
			return false;
		}
		if (m_help) {
			Resources::instance().playSound(SoundsIndexes::StartSound);
			helpWindow();
			continue;
		}

		m_window.draw(m_menuSprite);
		m_window.display();

    }
}
//------------------------------------
void Menu::getMouseEvent(bool menu) {

	if (auto event = sf::Event{}; m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Resources::instance().stopMusic();
			m_window.close();
			break;
		case sf::Event::MouseButtonReleased:
			if (menu)
				handleClickMenu(event.mouseButton);
			else
				m_back = true; //this means it is not the menu but the help screen
			break;
		}
	}
}
//---------------------------------
void Menu::handleClickMenu(const sf::Event::MouseButtonEvent& event) 
{
	sf::Vector2f eventPos = m_window.mapPixelToCoords({ event.x, event.y });
	
	m_play = clickedButton(eventPos, sf::Vector2f(281, 170));
    m_exit = clickedButton(eventPos, sf::Vector2f(15, 170));
	m_help = clickedButton(eventPos, sf::Vector2f(546, 170));	
}
//---------------------------------
 bool Menu::clickedButton(sf::Vector2f eventPos, sf::Vector2f point) 
{
	int len = 240, height = 155;
	if (eventPos.x >= point.x && eventPos.x <= point.x + len) {
		if (eventPos.y >= point.y && eventPos.y <= point.y + height) {
			return true;
		}
	}
	return false;
}
//---------------------------------
void Menu::helpWindow()
{
	
	m_window.create(sf::VideoMode(1200, 1000), "Game window");

	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_helpSprite);
		getMouseEvent();
		m_window.display();

		if (m_back) {
			break;
		}		
	}
	//this will recreate the main menu window
	m_window.create(sf::VideoMode(800, 800), "Game window");	

	m_back = false;
	m_help = false;
}