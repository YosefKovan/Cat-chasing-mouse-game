#include "TimeGift.h"
#include "FileReader.h"

TimeGift::TimeGift(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getTileSize())
{}
//---------------------------------
void TimeGift::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//---------------------------------
void TimeGift::handleCollision(Mouse& obj) 
{
	Resources::instance().playSound(SoundsIndexes::RewardSound);
	m_isDisposed = true;
}