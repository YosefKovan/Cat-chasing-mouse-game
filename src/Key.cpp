#include "Key.h"
#include "Mouse.h"

Key::Key(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getSmallStaticSize())
{}
//-------------------------------------------------------
void Key::handleCollision(GameObject& obj) {

	obj.handleCollision(*this);
}
//-------------------------------------------------------
void Key::handleCollision(Mouse& obj)
{
	Resources::instance().playSound(SoundsIndexes::RewardSound);
	m_isDisposed = true;
}

