// PlayerBulletObject.cpp //

#include "PlayerBulletObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include <iostream>

PlayerBulletObject::PlayerBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration){
	setPosition(p_vPos);
	m_vDir = p_vDir;

	m_fAcceleration = p_fAcceleration;

	m_xpSprite = SpriteMngr::LoadSprite("BulletSprite.png");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 8.0f, 0));
}

PlayerBulletObject::~PlayerBulletObject(){	
	delete m_xpSprite;
	m_xpSprite = NULL;
}

void PlayerBulletObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	m_xpSprite->setPosition(getPosition().x - m_xpSprite->getTextureRect().width / 2, getPosition().y - m_xpSprite->getTextureRect().height / 2);
	GetHitbox()->SetPosition(getPosition());
}

void PlayerBulletObject::OnCreate(){

}

void PlayerBulletObject::OnUpdateThis(){
	SetAllPositions(getPosition() + (TimeMngr::GetDtime() * (m_vDir * m_fAcceleration)));
	
	if (getPosition().x > DrawMngr::GetScreen()->getDefaultView().getSize().x || getPosition().x < 0.f){
		DeleteMe();
	}

	if (getPosition().y > DrawMngr::GetScreen()->getDefaultView().getSize().y || getPosition().y < 0.f){
		DeleteMe();
	}
}

void PlayerBulletObject::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void PlayerBulletObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy")){
		std::cout << "Hit!";

		DeleteMe();
	}
}