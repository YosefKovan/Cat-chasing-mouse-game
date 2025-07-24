#include "Cheese.h"
#include "Mouse.h"
#include "FileReader.h"

Cheese::Cheese(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getSmallStaticSize())
{}
//-------------------------------------------------------
void Cheese::handleCollision(GameObject& obj) {

	obj.handleCollision(*this);
}
//-------------------------------------------------------
void Cheese::handleCollision(Mouse& obj) {

	Resources::instance().playSound(SoundsIndexes::ChewingSound);
	m_isDisposed = true;
}