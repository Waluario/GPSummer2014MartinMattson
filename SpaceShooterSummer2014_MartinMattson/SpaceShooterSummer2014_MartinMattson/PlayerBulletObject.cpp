// PlayerBulletObject.cpp //

#include "PlayerBulletObject.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Sprite.h"

#include <iostream>

PlayerBulletObject::PlayerBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration){
	setPosition(p_vPos);
	m_vDir = p_vDir;

	m_fAcceleration = p_fAcceleration;

	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
}

PlayerBulletObject::~PlayerBulletObject(){
	RemoveParent();
	
	delete m_xpSprite;
	m_xpSprite = NULL;
}

void PlayerBulletObject::OnUpdateThis(){
	sf::Vector2f l_vVelocity(m_vDir * m_fAcceleration);

	setPosition(getPosition() + l_vVelocity);
	m_xpSprite->setPosition(getPosition());

	if (getPosition().x > DrawMngr::GetScreen()->getDefaultView().getSize().x || getPosition().x/* + m_xpSprite->getTexture()->getSize().x*/ < 0.f){
		std::cout << "Delete!";
		GetParent()->RemoveChild(this); //this->~PlayerBulletObject();
	}

	if (getPosition().y > DrawMngr::GetScreen()->getDefaultView().getSize().y || getPosition().y/* + m_xpSprite->getTexture()->getSize().y*/ < 0.f){
		std::cout << "Delete!";
		GetParent()->RemoveChild(this); //this->~PlayerBulletObject();
	}
}

void PlayerBulletObject::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void PlayerBulletObject::OnCollision(GameObject *p_xpCollider){

}