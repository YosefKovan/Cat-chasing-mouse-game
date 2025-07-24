#include "CatGift.h"
#include "Mouse.h"
#include "FileReader.h"

CatGift::CatGift(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getTileSize())
{}
//-----------------------------------------
void CatGift::handleCollision(GameObject& obj) 
{
	obj.handleCollision(*this);
}
//-----------------------------------------
void CatGift::handleCollision(Mouse& obj) 
{
	Resources::instance().playSound(SoundsIndexes::RewardSound);
	m_isDisposed = true;
}