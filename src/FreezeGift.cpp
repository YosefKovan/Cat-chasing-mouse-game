#include "FreezeGift.h"
#include "FileReader.h"


FreezeGift::FreezeGift(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getTileSize())
{}
//-----------------------------------------
void FreezeGift::handleCollision(GameObject& obj) 
{
	obj.handleCollision(*this);
}
//-----------------------------------------

void FreezeGift::handleCollision(Mouse& obj)
{
	Resources::instance().playSound(SoundsIndexes::RewardSound);
	m_isDisposed = true;
}