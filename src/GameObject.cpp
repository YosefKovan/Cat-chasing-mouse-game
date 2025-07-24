#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& location, ImgType img, sf::Vector2f objSize)
	:m_isDisposed(false), m_objSize(objSize), m_startPos(location)
{
	m_rectangle.setPosition(m_startPos);
	m_rectangle.setSize(m_objSize);
	m_sprite = Resources::instance().getImg(img);
}
//-------------------------------------
bool GameObject::collision(const GameObject& obj) const{

	return m_rectangle.getGlobalBounds().intersects(obj.m_rectangle.getGlobalBounds());
}
//-------------------------------------
bool GameObject::isDisposed() {

	return m_isDisposed;
}