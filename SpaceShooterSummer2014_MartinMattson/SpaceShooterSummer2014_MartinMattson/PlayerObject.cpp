// PlayerObject.cpp //

#include "PlayerObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "ScoreMngr.h"
#include "StateMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "PlayerBulletObject.h"

#include <iostream>

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_fAcceleration = p_fAcceleration;

	setPosition(p_vPos);

	m_fMaxCdwn = 2.f;
	m_fCdwn = 0.f;

	m_fFirerateMax = .0625f;
	m_fFirerate = m_fFirerateMax;

	m_fFireRange = 0.0f;
	m_fFireRangeMax = .5f;
	m_bFireRangeUp = true;

	AddTag("Player");

	m_xpSprite = SpriteMngr::GetSprite("Ship");
	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 8.0f, 0));
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	//m_xpSprite->setPosition(getPosition().x - m_xpSprite->getTextureRect().width / 2, getPosition().y - m_xpSprite->getTextureRect().height / 2);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void PlayerObject::OnCreate(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	sf::Vector2f _vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	if (_Keys[4]->IsPressed() && CanFire()){
		//AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x, getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x - ((m_fFireRangeMax / m_fFireRangeMax) * (m_xpSprite->GetSprite()->getTextureRect().width / 3)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x + ((m_fFireRangeMax / m_fFireRangeMax) * (m_xpSprite->GetSprite()->getTextureRect().width / 3)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		/*
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x - ((m_fFireRange / m_fFireRangeMax) * (m_xpSprite->getTextureRect().width / 5)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x + ((m_fFireRange / m_fFireRangeMax) * (m_xpSprite->getTextureRect().width / 5)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x - ((m_fFireRange / m_fFireRangeMax) * (m_xpSprite->getTextureRect().width / 9)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));
		AddChild(new PlayerBulletObject(sf::Vector2f(getPosition().x + ((m_fFireRange / m_fFireRangeMax) * (m_xpSprite->getTextureRect().width / 9)), getPosition().y), sf::Vector2f(0, -1), 1024.0f));*/
	}

	if (m_fCdwn > 0.f){
		m_fCdwn -= (TimeMngr::GetDtime());
	}

	SetAllPositions(getPosition() + (_vSpeed * m_fAcceleration * TimeMngr::GetDtime(false)));
}

void PlayerObject::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy") || p_xpCollider->HasTag("EBullet")){
		if (m_fCdwn <= 0.0f){
			m_fCdwn = m_fMaxCdwn;

			std::cout << "Hit!";
			ScoreMngr::MinusLife();

			if (ScoreMngr::GetLifes() < 0){
				StateMngr::Quit();
			}
		}
	}
}

bool PlayerObject::CanFire(){
	if (m_fFirerate <= 0){
		m_fFirerate = m_fFirerateMax;

		return true;
	}

	m_fFirerate -= TimeMngr::GetDtime(false);

	// Fire Range

	if (m_fFireRange <= -m_fFireRangeMax && !m_bFireRangeUp){
		m_bFireRangeUp = true;
	}
	else if (m_fFireRange >= m_fFireRangeMax && m_bFireRangeUp){
		m_bFireRangeUp = false;
	}

	m_fFireRange += (-1 + (2 * m_bFireRangeUp)) * TimeMngr::GetDtime();

	return false;
}