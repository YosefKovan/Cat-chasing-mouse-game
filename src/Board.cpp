#include "Board.h"
#include "Controller.h"
#include <fstream>
#include <iostream>
#include "Consts.h"


Board::Board(FileReader& file)
    :  m_moving(file.getMoving()), m_static(file.getStatic()),
       m_window(Resources::instance().getWindow()), m_totalCheese(file.getTotalCheese())
{
    m_backrndSprite = Resources::instance().getImg(ImgType::Background);
    Resources::instance().scaleImg(m_backrndSprite, SCREEN_SIZE);
}
//-----------------------------------------------
void Board::mainGmaeLogic() {

    updateAndGetEvent();
    const auto deltaTime = m_gameClock.restart();
    
    for (auto& obj : m_moving) {
        obj->move(m_dir, deltaTime, m_len, m_height);
        handleCollisions(*obj);
    }

    checkAndResetMoving();
    shareMouseLocationWithCats();
    dealWithCatRemoval();
    handleDrawAndRemoval();
}
//-----------------------------------------------
void Board::handleCollisions(GameObject& gameObject) {

    for (auto& obj : m_moving) 
    { 
        if (obj->collision(gameObject))
            obj->handleCollision(gameObject);
    }

    for (auto& obj : m_static) 
    {
        if (obj->collision(gameObject)) 
            obj->handleCollision(gameObject);
    }
   
}
//-----------------------------------------------
void Board::handleDrawAndRemoval() {

    //erasing items that need to be disposed
    std::erase_if(m_static, [](auto& unmovable)
    {
        return unmovable->isDisposed();
    });

    //drawing the background
    m_window.draw(m_backrndSprite); 

    //drawing the rest of the objects
    for (auto& obj : m_static)
        obj->draw(m_window);

    for (auto& obj : m_moving)
        obj->draw(m_window);

}
//-----------------------------------------
void Board::checkAndResetMoving() 
{
   if (auto mouse = dynamic_cast<Mouse*>(m_moving[0].get()))
   {
       if (mouse->mouseCatCollision()) 
       {
           for (const auto& obj : m_moving)
           {
               obj->resetLocation();
           }
       }     
   }
}
//-----------------------------------------
void Board::shareMouseLocationWithCats() 
{
    if (auto mouse = dynamic_cast<Mouse*>(m_moving[0].get()))
    {
        for (auto& obj : m_moving) {
            if (auto cat = dynamic_cast<Cat*>(obj.get()))
                cat->mouseLocation(mouse->getPos());
        }
    }
}
//-----------------------------------------
bool Board::gameOver() const
{
    if (TopBar::getTotalTime() < 0) 
        return true;
        
    for (auto& obj : m_moving)
        if (obj->isDisposed())
            return true;
    
    return false;
}
//-----------------------------------------
void Board::dealWithCatRemoval() 
{
    //the life reward is added by the mouse itself

    if (auto mouse = dynamic_cast<Mouse*>(m_moving[0].get())) 
    {
        if (mouse->checkCatRemovalReward())
        {
            if (m_moving.size() > 1)
                m_moving.erase(m_moving.begin() + 1);
        }       
    }
}

//------------------------------------------------------
bool Board::levelFinishedSuccessfully() {

    if (auto mouse = dynamic_cast<Mouse*>(m_moving[0].get()))
    {
        return mouse->getInfo(mouseCollectedInfo::totalCheese) == m_totalCheese;
    }
}

//-----------------------------------------------
void Board::updateAndGetEvent() {


    if (auto event = sf::Event{}; m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyPressed:
            m_dir = getDirection(event);
            break;
        case sf::Event::KeyReleased:
            m_dir = sf::Vector2f(0, 0); 
            break;

        }
    }
}
//-----------------------------------------------
sf::Vector2f Board::getDirection(const sf::Event& event) const {

    switch (event.key.code) {

    case sf::Keyboard::Left:
        return sf::Vector2f(-1, 0);
    case sf::Keyboard::Right:
        return sf::Vector2f(1, 0);
    case sf::Keyboard::Up:
        return sf::Vector2f(0, -1);
    case sf::Keyboard::Down:
        return sf::Vector2f(0, 1);
    }

    return sf::Vector2f(0, 0);
}
