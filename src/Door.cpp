#include "Door.h"
#include "FileReader.h"

Door::Door(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getTileSize())
{}
//----------------------------------------
void Door::handleCollision(GameObject& obj) {
	
	obj.handleCollision(*this);
}
//----------------------------------------
void Door::handleCollision(Mouse& obj) {

	Resources::instance().playSound(SoundsIndexes::DoorOpeningSound);
	m_isDisposed = true;
}
