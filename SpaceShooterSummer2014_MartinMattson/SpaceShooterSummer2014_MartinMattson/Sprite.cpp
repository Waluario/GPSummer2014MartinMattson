// Sprite.cpp //

#include "Sprite.h"

#include "SpriteMngr.h"

Sprite::Sprite(){
	m_xpSprite = new sf::Sprite;
}

Sprite::~Sprite(){
	delete m_xpSprite;
	m_xpSprite = NULL;

	SpriteMngr::DeleteSprite(this);
}

void Sprite::SetName(std::string p_sName){
	m_sName = p_sName;
}

std::string Sprite::GetName(){
	return m_sName;
}

sf::Sprite* Sprite::GetSprite(){
	return m_xpSprite;
}

void Sprite::SetSprite(sf::Sprite *p_xpSprite){
	m_xpSprite = p_xpSprite;
}

sf::Vector2f Sprite::GetPosition(){
	return GetSprite()->getPosition();
}

void Sprite::SetPosition(sf::Vector2f p_vPosition){
	GetSprite()->setPosition(p_vPosition);
}