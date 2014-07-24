// EnemyObject1.cpp //

#include "EnemyObject1.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "GameObjectMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "EnemyBulletObject.h"
#include "ScoreObject.h"

#include <iostream>

EnemyObject1::EnemyObject1(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd, sf::Vector2f p_vFire){
	m_vSpd = p_vSpd;
	m_vMaxSpd = sf::Vector2f(100, 100);
	m_vBulletDir = p_vFire;

	m_iBulletAmmo = 6;
	m_iLife = 8;
	m_iScore = 4;

	m_fFireRateMax = .4f;
	m_fFireRate = .8f;

	m_bBulletDirSet = false;

	setPosition(p_vPosition);
}

EnemyObject1::~EnemyObject1(){
	
}

void EnemyObject1::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyObject1::OnCreate(){
	m_xpSprite = SpriteMngr::GetSprite("Enemy1");
	AddTag("Enemy");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 35.0f, 0));

	m_xpPlayer = GameObjectMngr::GetGameObject("Player");

	SetAllPositions(getPosition());
}

void EnemyObject1::OnUpdateThis(){
	SetAllPositions(sf::Vector2f(getPosition() + (m_vSpd * TimeMngr::GetDtime())));

	if (OnScreen()){
		if (CanFire()){
			/*if (!m_bBulletDirSet){
				/*float _iA = m_xpPlayer->getPosition().x - getPosition().x;
				float _iB = m_xpPlayer->getPosition().y - getPosition().y;
				float _iC = sqrt((_iA * _iA) + (_iB * _iB));

				//m_vBulletDir = sf::Vector2f((_iA / _iC), (_iB / _iC));
				m_vBulletDir = sf::Vector2f(0, 1);

				m_bBulletDirSet = true;
			}*/

			GetParent()->AddChild(new EnemyBulletObject(getPosition(), m_vBulletDir, 145.f));
		}
	}
}

void EnemyObject1::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
	DrawMngr::Draw(GetHitbox()->GetShape());
}

void EnemyObject1::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("PBullet")){
		m_iLife--;

		if (m_iLife <= 0){
			DropScore();
			DeleteMe();
		}
	}
}