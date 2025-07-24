#include "LifeGift.h"
#include "FileReader.h"

LifeGift::LifeGift(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getSmallStaticSize())
{}
//--------------------------------------
void LifeGift::handleCollision(GameObject& obj)
{
	obj.handleCollision(*this);
}
//--------------------------------------

void LifeGift::handleCollision(Mouse& obj)
{
	Resources::instance().playSound(SoundsIndexes::RewardSound);
	m_isDisposed = true;
}