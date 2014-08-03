// EnemyObject0.h //

#include "EnemyObject0.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "GameObjectMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "EnemyBulletObject.h"

#include <iostream>

EnemyObject0::EnemyObject0(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd, sf::Vector2f p_vDeaccel){
	setPosition(p_vPosition);
	m_vSpd = p_vSpd;
	m_vDeaccel = p_vDeaccel;
	m_vMaxSpd = sf::Vector2f(100, 100);

	m_iBulletAmmo = 4;
	m_iLife = 16;
	m_iScore = 8;

	m_fFireRateMax = .8f;
	m_fFireRate = m_fFireRateMax;
}

EnemyObject0::~EnemyObject0(){
	
}

void EnemyObject0::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyObject0::OnCreate(){
	m_xpSprite = SpriteMngr::GetSprite("Enemy0");
	AddTag("Enemy");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 35.0f, 0));

	m_xpPlayer = GameObjectMngr::GetGameObject("Player");
}

void EnemyObject0::OnUpdateThis(){
	m_vSpd -= m_vDeaccel * TimeMngr::GetDtime();

	SetAllPositions(sf::Vector2f(getPosition().x + TimeMngr::GetDtime() * m_vSpd.x, getPosition().y + TimeMngr::GetDtime() * m_vSpd.y));

	if (CanFire()){
		float _iA = m_xpPlayer->getPosition().x - getPosition().x;
		float _iB = m_xpPlayer->getPosition().y - getPosition().y;
		float _iC = sqrt((_iA * _iA) + (_iB * _iB));

		GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f((_iA / _iC), (_iB / _iC)), 95.f));
		GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f((_iA / _iC), (_iB / _iC)), 60.f));
	}

	if (!OnScreen()){
		DeleteMe();
	}
}

void EnemyObject0::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void EnemyObject0::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("PBullet")){
		m_iLife--;

		if (m_iLife <= 0){
			SoundMngr::Play("Sfx_EnemyDeath");
			DropScore();
			DeleteMe();
		}
	}
}