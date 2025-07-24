#pragma once

#include "Controller.h"
#include <fstream>
#include <iostream>
#include "Consts.h"


Controller::Controller()
    : m_fileName("Levels.txt"),
      m_gameOver(false), m_countDown(0), m_totalScore(0),
      m_window(Resources::instance().getWindow()), m_level(0)
{}
//-----------------------------------------------
void Controller::startMenu() {

    Menu gameMenu(m_window);
    while (gameMenu.wantToPlay()) 
    { 
        m_gameOver = false;
        m_totalScore = 0;
        playGame();
    }
}
//-----------------------------------------------
void Controller::playGame()
{ 
    std::ifstream file;
    file.open(m_fileName); //this contains the level names
    std::string levelFileName;
    m_level = 0;
   
    while (m_window.isOpen())
    {
        if (m_gameOver)
        {
            m_gameOver = false;
            playLevel(levelFileName);
        }
        else if (std::getline(file, levelFileName))
        {
            m_level++;
            playLevel(levelFileName);
        }
        else {
            Resources::instance().playSound(SoundsIndexes::LevelUp);
            m_window.close();
            
        }
    } 
}
//-----------------------------------------------
void Controller::playLevel(std::string levelFileName) 
{
    auto fileReader = FileReader(levelFileName);
    auto board = Board(fileReader);
    auto topBar = TopBar(fileReader.getTotalTime());
    
    
    while (m_window.isOpen() && !m_gameOver)
    {

        Resources::instance().playMusic(MusicIndexes::GameMuisc);
        m_window.clear();
        board.mainGmaeLogic();
        topBar.display(m_totalScore, m_level);
        m_window.display();

        m_gameOver = board.gameOver();
        
        if (board.levelFinishedSuccessfully())
        { 
            m_totalScore += Mouse::getInfo(mouseCollectedInfo::score) + 25 + 5 * Cat::getTotalCats();
            break;
        }
   
    }
   
    Resources::instance().stopMusic();
}
//-----------------------------------------------

