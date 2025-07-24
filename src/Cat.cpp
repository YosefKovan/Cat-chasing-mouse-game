
#include "Cat.h"
#include "Mouse.h"
#include "FileReader.h"
int Cat::m_totalCats = 0;
Cat::Cat(const sf::Vector2f& location, ImgType img)
	:MovingObject(location, img, FileReader::getMovingSize())
{
	imgPos[0] = sf::Vector2f(1905, 13);
	imgPos[1] = sf::Vector2f(1984, 13);
	imgPos[2] = sf::Vector2f(758, 646);
	imgPos[3] = sf::Vector2f(758, 351);
}

//-------------------------------------------
void Cat::draw(sf::RenderWindow& window) {

	int posX = (int)m_rectangle.getPosition().x;
	int posY = (int)m_rectangle.getPosition().y;

	switch (m_enumDir)
	{
	case None:
		m_sprite.setTextureRect(sf::IntRect(imgPos[0].x, imgPos[0].y, 58, 99));
		break;
	case Left:
		m_sprite.setTextureRect(sf::IntRect(imgPos[3].x, posX / 2 % 3 * 99 + 351, 84, 99));
		break;
	case Right:
		m_sprite.setTextureRect(sf::IntRect(imgPos[2].x, posX / 2 % 2 * 99 + 646, 84, 99));
		break;
	case Up:
		m_sprite.setTextureRect(sf::IntRect(imgPos[1].x, posY / 2 % 6 * 100 + 14, 55, 100));
		break;
	case Down:
		m_sprite.setTextureRect(sf::IntRect(imgPos[0].x, posY / 2 % 7 * 99 + 13, 58, 99));
		break;
	case Freeze:
		m_sprite.setTextureRect(sf::IntRect(1825, 13, 58, 99));
	}

	Resources::instance().scaleImg(m_sprite, m_objSize);
	m_sprite.setPosition(m_rectangle.getPosition());
	window.draw(m_sprite);
}
//-------------------------------------------
void Cat::move(sf::Vector2f dir, sf::Time deltaTime, int len, int height) {

	//this will check if the cat is frozen and if so will not move
	if (isFrozen())
	{
		m_rectangle.setPosition(m_prevPos);
		m_enumDir = Freeze;
		return;
	}

	float speed = 30.f;

	dir = getDirection();
	
	checkOutOfBounds();

	m_prevPos = m_rectangle.getPosition();
	m_rectangle.move(dir * speed * deltaTime.asSeconds());

	//check if move is out of bounds
	checkOutOfBounds();

}
//-------------------------------------------
void Cat::mouseLocation(const sf::Vector2f& mouseLocation) {

	m_mouseLocation = mouseLocation;
}
//-------------------------------------------
sf::Vector2f Cat::getDirection() 
{
	sf::Vector2f catLoc = m_rectangle.getPosition();
	float xDif = m_mouseLocation.x - catLoc.x;
	float yDif = m_mouseLocation.y - catLoc.y;
	float threshold = 5.0f;

	if (std::abs(xDif) > threshold) {
		m_enumDir = (xDif < 0) ? Left : Right;
		return sf::Vector2f((xDif < 0) ? -1 : 1, 0);
	}
	else if (std::abs(yDif) > threshold) {
		m_enumDir = (yDif < 0) ? Up : Down;
		return sf::Vector2f(0, (yDif < 0) ? -1 : 1);
	}
	else {
		m_enumDir = 0;
		return sf::Vector2f(0, 0);
	}
}
//------------------------------------------
void Cat::updateTotalCats(int count) 
{
	m_totalCats = count;
}
//------------------------------------------
int Cat::getTotalCats() 
{
	return m_totalCats;
}
//===================== handle collision functions =====================
//-------------------------------------------
void Cat::handleCollision(GameObject& gameObj) {

	gameObj.handleCollision(*this);
}
//-------------------------------------------
void Cat::handleCollision(Wall& obj)
{
	m_hitWall = true;
	m_rectangle.setPosition(m_prevPos);
}
//-------------------------------------------
void Cat::handleCollision(Door&) {

	m_rectangle.setPosition(m_prevPos);
}
//-------------------------------------------
void Cat::handleCollision(FreezeGift& obj) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(Mouse&) {

	//do nothing

}
//-------------------------------------------
void Cat::handleCollision(Cat&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(Key&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(Cheese&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(CatGift&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(TimeGift&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(LifeGift&) {

	//do nothing
}

