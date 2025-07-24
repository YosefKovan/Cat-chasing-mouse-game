#include "Resources.h"


Resources::Resources() 
{
    readImages();
    addSounds();
    m_font.loadFromFile("top.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(40);
    m_text.setFillColor(sf::Color::Blue);
}
//----------------------------------------
Resources& Resources::instance() 
{
    static auto resources = Resources();
    return resources;
}
//----------------------------------------
void Resources::readImages() 
{
    for (int i = 0; i < TOTAL_IMAGES; i++) 
    {
        sf::Texture texture;
        texture.loadFromFile(imgStrArr[i]);
        m_textures.push_back(texture);
    }
}
//----------------------------------------
void Resources::addSounds() 
{
    for (int i = 0; i < TOTAL_SOUNDS; i++) 
    {
        sf::SoundBuffer buffer;
        buffer.loadFromFile(Sounds[i]);
        m_buffers.push_back(buffer);
    }
  
    for (int i = 0; i < m_buffers.size(); i++) 
    {
        sf::Sound sound;
        sound.setBuffer(m_buffers[i]);
        m_sounds.push_back(sound);
    }
    
}
//----------------------------------------
void Resources::playSound(SoundsIndexes index) 
{ 
    m_sounds[index].play();
}
//----------------------------------------
void Resources::playMusic(MusicIndexes index) 
{
    if (m_music.getStatus() != sf::Music::Playing) 
    {
        m_music.openFromFile(Songs[index]);
        m_music.play();
    }
}
//----------------------------------------
void Resources::stopMusic() 
{  
    if (m_music.getStatus() == sf::Music::Playing) 
        m_music.stop();
}
//----------------------------------------
sf::Text& Resources::getText() 
{  
    return m_text;
}
//----------------------------------------
sf::RenderWindow& Resources::getWindow() {

    return m_window;
}
//----------------------------------------
sf::Sprite& Resources::getImg(ImgType img) 
{
    sf::Sprite sprite;
    sprite.setTexture(m_textures[img]);
    return sprite;
}
//----------------------------------------
void Resources::scaleImg(sf::Sprite& sprite, sf::Vector2f size)
{
    float scaleX = size.x / sprite.getGlobalBounds().width;
    float scaleY = size.y / sprite.getGlobalBounds().height;
    sprite.scale(scaleX, scaleY);
}