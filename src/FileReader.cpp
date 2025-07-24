#include "FileReader.h"
#include <fstream>
#include <iostream>
#include "Consts.h"

sf::Vector2f FileReader::m_tileSize;

FileReader::FileReader(const std::string& fileName)
    : m_rows(0), m_cols(0), m_countDown(0), m_fileName(fileName),
      m_window(Resources::instance().getWindow()), m_totalCheese(0)
{
    getLevelFromFile();
}
//-----------------------------------------------
void FileReader::getLevelFromFile() {

    sf::Vector2f location(0, 70);

    m_moving.clear();
    m_static.clear(); //these are done for the next level


    std::ifstream file;
    file.open(m_fileName);
    std::string line;


    if (file >> m_rows >> m_cols >> m_countDown)
    {
        m_window.create(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Game window");
        m_tileSize = sf::Vector2f(SCREEN_SIZE.x/m_cols, (SCREEN_SIZE.y - location.y) /m_rows);
    }

    std::getline(file, line); //this will remove the '\n' at the end of the line.
    while (std::getline(file, line)) {

        for (auto character : line) {
            addObject(character, location);
            location.x += m_tileSize.x;
        }

        location.x = 0;
        location.y += m_tileSize.y;
    }
}

//-----------------------------------------------
void FileReader::addObject(char object, sf::Vector2f& location) {

    switch (object) {
    case mouse:
        m_moving.insert(m_moving.begin(), std::make_unique<Mouse>(location, ImgType::MOUSE));
        break;
    case cat:
        m_moving.push_back(std::make_unique<Cat>(location, ImgType::CAT));
        Cat::updateTotalCats(Cat::getTotalCats() + 1);
        break;
    case wall:
        m_static.push_back(std::make_unique<Wall>(location, ImgType::WALL));
        break;
    case door:
        m_static.push_back(std::make_unique<Door>(location, ImgType::DOOR));
        break;
    case key:
        m_static.push_back(std::make_unique<Key>(location, ImgType::KEY));
        break;
    case cheese:
        m_static.push_back(std::make_unique<Cheese>(location, ImgType::CHEESE));
        m_totalCheese++;
        break;
    case cat_gift:
        m_static.push_back(std::make_unique<CatGift>(location, ImgType::CAT_GIFT));
        break;
    case time_gift:
        m_static.push_back(std::make_unique<TimeGift>(location, ImgType::CLOCK_GIFT));
        break;
    case freeze_gift:
        m_static.push_back(std::make_unique<FreezeGift>(location, ImgType::FREEZE_GIFT));
        break;
    case life_gift:
        m_static.push_back(std::make_unique<LifeGift>(location, ImgType::LIFE_GIFT));
        break;
    
    }
}
//-----------------------------------------------
int FileReader::getTotalTime() {

    return m_countDown;
}
//-----------------------------------------------
std::vector<std::unique_ptr<MovingObject>>& FileReader::getMoving()
{
    return m_moving;
}
//-----------------------------------------------
std::vector<std::unique_ptr<GameObject>>& FileReader::getStatic()
{
    return m_static;
}
//-----------------------------------------------
int FileReader::getTotalCheese()
{
    return m_totalCheese;
}
//-----------------------------------------------
sf::Vector2f FileReader::getTileSize()
{
    return m_tileSize;
}
//-----------------------------------------------
sf::Vector2f FileReader::getMovingSize()
{
    return sf::Vector2f(m_tileSize.x * 3/4, m_tileSize.y * 3/4);
}
//-----------------------------------------------
sf::Vector2f FileReader::getSmallStaticSize()
{
    return sf::Vector2f(m_tileSize.x * 1 / 2, m_tileSize.y * 1 / 2);
}