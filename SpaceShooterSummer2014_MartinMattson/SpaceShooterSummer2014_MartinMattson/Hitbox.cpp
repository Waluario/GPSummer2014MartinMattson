// Hitbox.cpp //

#include "CollisionMngr.h"
#include "Hitbox.h"

#include <iostream>

Hitbox::Hitbox(GameObject *p_xpGameObject){
	m_fSize = 0.0f;
}

Hitbox::Hitbox(GameObject *p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize){
	m_fSize = p_fSize;
	m_vPosition = p_vPosition;
	m_xpGameObject = p_xpGameObject;

	m_xpShape = new sf::CircleShape(m_fSize);
	m_xpShape->setFillColor(sf::Color(0xff, 0xff, 0x00));
	m_xpShape->setOrigin(sf::Vector2f(m_fSize / 1, m_fSize / 1));
	m_xpShape->setPosition(GetPosition());
}

Hitbox::~Hitbox(){
	m_xpGameObject = NULL;

	delete m_xpShape;
	m_xpShape = NULL;
}

float Hitbox::GetSize(){
	return m_fSize;
}

void Hitbox::SetSize(float p_f){
	m_fSize = p_f;
}

sf::Vector2f Hitbox::GetPosition(){
	return m_vPosition;
}

void Hitbox::SetPosition(sf::Vector2f p_vPosition){
	m_vPosition = p_vPosition;
}

GameObject* Hitbox::GetGameObject(){
	return m_xpGameObject;
}

void Hitbox::SetGameObject(GameObject *p_xpGameObject){
	m_xpGameObject = p_xpGameObject;
}

sf::CircleShape* Hitbox::GetShape(){
	m_xpShape->setPosition(GetPosition());
	
	return m_xpShape;
}

bool Hitbox::Overlap(Hitbox *p_xpHitbox){
	float _a = m_vPosition.x - p_xpHitbox->GetPosition().x,
		_b = m_vPosition.y - p_xpHitbox->GetPosition().y,
		_c = sqrtf((_a * _a) + (_b * _b));

	if (_c < (m_fSize + p_xpHitbox->GetSize())){
		return true;
	}

	return false;
}