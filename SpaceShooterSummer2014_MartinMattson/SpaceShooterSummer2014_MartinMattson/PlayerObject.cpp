// PlayerObject.cpp //

#include "PlayerObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "PlayerBulletObject.h"

#include <iostream>

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_iLife = p_iLife;
	m_fAcceleration = p_fAcceleration;

	setPosition(p_vPos);

	m_fFirerateMax = .0625f;
	m_fFirerate = m_fFirerateMax;

	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 8.0f, 0));
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	m_xpSprite->setPosition(getPosition().x - m_xpSprite->getTextureRect().width / 2, getPosition().y - m_xpSprite->getTextureRect().height / 2);
	GetHitbox()->SetPosition(getPosition());
}

void PlayerObject::OnCreate(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	sf::Vector2f _vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	if (_Keys[4]->IsPressed() && CanFire()){
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		/*AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(.25, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(.125, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(-.25, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(-.125, -1), 1024.0f));*/
	}

	m_fCdwn -= (TimeMngr::GetDtime());

	SetAllPositions(getPosition() + (_vSpeed * m_fAcceleration * TimeMngr::GetDtime(false)));
}

void PlayerObject::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy")){
		if (m_fCdwn > 0.0f){
			m_iLife -= 1;
			m_fCdwn = m_fMaxCdwn;
			std::cout << "Hit!";
		}
	}
}

bool PlayerObject::CanFire(){
	if (m_fFirerate <= 0){
		m_fFirerate = m_fFirerateMax;

		return true;
	}

	m_fFirerate -= TimeMngr::GetDtime(false);

	return false;
}