#include "Static.h"

Static::Static(sf::Vector2f location, ImgType img, sf::Vector2f imgSize)
	: GameObject(location, img, imgSize) 
{} 
//------------------------------------------
void Static::handleCollision(Cat&)
{
	//do nothing
} 
//------------------------------------------
void Static::handleCollision(Wall&)
{
	//do nothing
} 
//------------------------------------------
void Static::handleCollision(Door&)
{
    //do nothing
}
//------------------------------------------
void Static::handleCollision(Key&)
{
    //do nothing
}
//------------------------------------------
void Static::handleCollision(Cheese&)
{
	//do nothing
}
//------------------------------------------
void Static::handleCollision(CatGift&)
{
	//do nothing
}
//------------------------------------------
void Static::handleCollision(LifeGift&)
{
	//do nothing
}
//------------------------------------------
void Static::handleCollision(TimeGift&)
{
	//do nothing
}
//------------------------------------------
void Static::handleCollision(FreezeGift&)
{
	//do nothing
}
//------------------------------------------
void Static::draw(sf::RenderWindow& window){

	Resources::instance().scaleImg(m_sprite, m_objSize);
	m_sprite.setPosition(m_rectangle.getPosition());
	window.draw(m_sprite);
}

