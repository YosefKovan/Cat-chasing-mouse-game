#pragma once

#include "FileReader.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "Mouse.h"
#include "Cat.h"
#include "Wall.h"
#include "Door.h"
#include "Key.h"
#include "Cheese.h"
#include "CatGift.h"
#include "TimeGift.h"
#include "FreezeGift.h"
#include "LifeGift.h"


class FileReader {

public:
	FileReader(const std::string&);
	FileReader() = default;
	void getLevelFromFile();
	void addObject(char, sf::Vector2f&);
	int getTotalTime();
	int getTotalCheese(); 
	std::vector<std::unique_ptr<MovingObject>>& getMoving();
	std::vector<std::unique_ptr<GameObject>>& getStatic();
	static sf::Vector2f getTileSize();
	static sf::Vector2f getMovingSize();
	static sf::Vector2f getSmallStaticSize();

private:
	int m_rows, m_cols;
	int m_totalCheese; 
	int m_countDown;
	sf::RenderWindow& m_window; 
	std::string m_fileName;
	std::vector<std::unique_ptr<MovingObject>> m_moving;
	std::vector<std::unique_ptr<GameObject>> m_static;
	static sf::Vector2f m_tileSize;

};