#pragma once

#include <SFML/System/Clock.hpp> 
#include <SFML/Audio.hpp>
#include <vector>
#include "Consts.h"

class Resources {

public:

	static Resources& instance();
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;
	sf::Sprite& getImg(ImgType);
	void scaleImg(sf::Sprite&, sf::Vector2f);
	void playMusic(MusicIndexes);
	void stopMusic();
	void playSound(SoundsIndexes);
	sf::Text& getText();
	sf::RenderWindow& getWindow();
	sf::RenderWindow m_window;
	
private:
	Resources();
	void readImages();
	void addSounds();
	std::vector<sf::Texture> m_textures;
	std::vector<sf::SoundBuffer> m_buffers;
	std::vector<sf::Sound> m_sounds;
	sf::Music m_music;
	sf::Font m_font;
	sf::Text m_text;
};