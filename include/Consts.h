#pragma once

#include <SFML/Graphics.hpp>
#include <string>


enum Arrows { None, Left, Right, Up, Down, Freeze};

//-----------------------------------

enum ObjectIndexes { mouse = '%', cat = '^', wall = '#', door = 'D', key = 'F', 
	                 cheese = '*', cat_gift= '$', time_gift = 'T', freeze_gift = 'I',
                     life_gift = 'L' };
//-----------------------------------

const int TILE_SIZE = 60;

//---------------- IMAGES -----------------
enum ImgType { MENU, Background, MOUSE, CAT, WALL, DOOR, KEY, CHEESE, CAT_GIFT, LIFE_GIFT,    
               FREEZE_GIFT, CLOCK_GIFT, SCORE, LEVEL, SKY, HELP , HOURGLASS
};

const int TOTAL_IMAGES = 17;

const std::string imgStrArr[TOTAL_IMAGES] = { "Menu.png","Background.jpg", "all.png",
                                              "all.png", "wall.jpg",  "door.png", "key.png",
                                              "cheese.png", "CatGift.png", "heart.png", "ice.png", 
                                              "clock.png", "score.png", "level.png", "sky.jpg",
                                              "help.png", "hourglass.png"};
//--------------- SOUNDS ---------------

const int TOTAL_SONGS = 2;

enum MusicIndexes{MenuMusic, GameMuisc};

const std::string Songs[TOTAL_SONGS] = { "menuMusic.wav", "gameMusic.wav"};

//-------------- SONGS -----------------

const int TOTAL_SOUNDS = 6;

enum SoundsIndexes{StartSound, ChewingSound, RewardSound, GameOverSound, DoorOpeningSound, LevelUp};

const std::string Sounds[TOTAL_SOUNDS] = { "start.wav", "chewing.wav", "reward.WAV", "gameOver.WAV", "doorOpening.WAV", "levelUp.WAV"};

//-----------------------------------
const auto move = sf::Vector2f(10, 10);

//-----------------------------------

enum mouseCollectedInfo{keys, score, lives, totalCheese};

//-----------------------------------

const auto SCREEN_SIZE = sf::Vector2f(1200, 800);