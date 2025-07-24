#include "Wall.h"
#include "FileReader.h"

Wall::Wall(sf::Vector2f location, ImgType img)
	: Static(location, img, FileReader::getTileSize())
{}
//-------------------------------------------------------
void Wall::handleCollision(GameObject& obj) {
	
	obj.handleCollision(*this);
}
//-------------------------------------------------------
void Wall::handleCollision(Mouse& obj)
{
	obj.handleCollision(*this);
}

