#include "TopBar.h"
#include "Resources.h"
#include "Mouse.h"
#include <iostream>

int TopBar::m_totalTime;


TopBar::TopBar(const int& totalTime)
    :  m_seconds(59), m_minutes(0), m_countDown(0), m_regularClock(false)
{
    if (totalTime <= 0)
    {   
        m_regularClock = true;
        m_totalTime = 0;
        m_seconds = 0;
    }
    else
        m_totalTime = totalTime - 1;
     
    setSpritesAndPositions();
}
//------------------------------------------
void TopBar::setSpritesAndPositions()
{
    //this will set the sprites for all the locations and set the positions
    m_clockSprite = Resources::instance().getImg(ImgType::CLOCK_GIFT);
    Resources::instance().scaleImg(m_clockSprite, sf::Vector2f(70, 70));

    m_timerSprite = Resources::instance().getImg(ImgType::HOURGLASS);
    Resources::instance().scaleImg(m_timerSprite, sf::Vector2f(70, 70));

    m_scoreSprite = Resources::instance().getImg(ImgType::SCORE);
    Resources::instance().scaleImg(m_scoreSprite, sf::Vector2f(70, 60));
    m_scoreSprite.setPosition(410, 0);

    m_levelSprite = Resources::instance().getImg(ImgType::LEVEL);
    Resources::instance().scaleImg(m_levelSprite, sf::Vector2f(130, 60));
    m_levelSprite.setPosition(640, 4);

    m_keysSprite = Resources::instance().getImg(ImgType::KEY);
    Resources::instance().scaleImg(m_keysSprite, sf::Vector2f(70, 50));
    m_keysSprite.setPosition(250, 10);

    m_backSprite = Resources::instance().getImg(ImgType::SKY);
    Resources::instance().scaleImg(m_backSprite, sf::Vector2f(1200, 70));
}
//------------------------------------------
void TopBar::timerLogic() {

    if (m_clock.getElapsedTime().asSeconds() >= 60) {
        m_clock.restart();
        
        if (m_regularClock) 
        {
            m_totalTime++;
            m_seconds = 0;
            return;
        }
        else
        {
            m_totalTime--;
            m_seconds = 59;
        } 
    }
    else if(m_regularClock) 
        m_seconds = static_cast<int> (m_clock.getElapsedTime().asSeconds());
    else   
        m_seconds = 59 - static_cast<int> (m_clock.getElapsedTime().asSeconds());
}
//------------------------------------------
void TopBar::displayTimer()
{
    timerLogic();
    std::string m = ((m_totalTime < 10) ? "0" : "");
    std::string s = ((m_seconds < 10) ? "0" : "");
    sf::Text timerText = Resources::instance().getText();
    
    timerText.setPosition(70, 10);
    timerText.setString(m + std::to_string(m_totalTime) + " : "+ s + std::to_string(m_seconds));

    Resources::instance().getWindow().draw(timerText);
    if (m_regularClock)
       Resources::instance().getWindow().draw(m_clockSprite);
    else
       Resources::instance().getWindow().draw(m_timerSprite);
}
//------------------------------------------
void TopBar::displayTotalScore(int score) const
{  
    sf::Text& scoreText = Resources::instance().getText();
    scoreText.setPosition(500, 10);
    scoreText.setString(std::to_string(score));

    Resources::instance().getWindow().draw(scoreText);
    Resources::instance().getWindow().draw(m_scoreSprite);
}
//------------------------------------------
void TopBar::displayLivesLeft(int lives) const
{   
    sf::Sprite livesSprite = Resources::instance().getImg(LIFE_GIFT);
    Resources::instance().scaleImg(livesSprite, sf::Vector2f(60, 60));
    
    for (int i = 0; i < lives; ++i)
    {
        livesSprite.setPosition(860 + i * 60, 4);
        Resources::instance().getWindow().draw(livesSprite);
    }  
}
//------------------------------------------
void TopBar::displayTotalKeys(int totalKeys) const
{
    sf::Text& keysText = Resources::instance().getText();
    keysText.setPosition(330, 10);
    keysText.setString(std::to_string(totalKeys));

    Resources::instance().getWindow().draw(keysText);
    Resources::instance().getWindow().draw(m_keysSprite);
}
//------------------------------------------
void TopBar::displayLevel(int level) const
{
    sf::Text& scoreText = Resources::instance().getText();
    scoreText.setPosition(780, 10);
    scoreText.setString(std::to_string(level));

    Resources::instance().getWindow().draw(scoreText);
    Resources::instance().getWindow().draw(m_levelSprite);
}
//------------------------------------------
void TopBar::updateMinutes(int time)
{
    m_totalTime += time;
}
//------------------------------------------
void TopBar::display(int totalScore, int level) 
{
    //this will display the background
    Resources::instance().getWindow().draw(m_backSprite);

    //these will display the rest of the top bar
    displayTimer();
    displayLivesLeft(Mouse::getInfo(mouseCollectedInfo::lives));
    displayTotalKeys(Mouse::getInfo(mouseCollectedInfo::keys));
    displayTotalScore(Mouse::getInfo(mouseCollectedInfo::score) + totalScore);
    displayLevel(level);

}
//------------------------------------------
int TopBar::getTotalTime() {

    return m_totalTime;
}