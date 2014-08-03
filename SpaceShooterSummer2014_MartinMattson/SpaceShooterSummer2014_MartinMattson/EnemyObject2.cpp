// EnemyObject2.cpp //

#include "EnemyObject2.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "GameObjectMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "EnemyBulletObject.h"

EnemyObject2::EnemyObject2(sf::Vector2f p_vPosition, float p_fSpd){
	m_fSpd = p_fSpd;

	setPosition(p_vPosition);

	m_iBulletAmmo = INT_MAX;
	m_iLife = 24;
	m_iScore = 18;

	m_fFireRateMax = 2.f;
	m_fFireRate = m_fFireRateMax;

	m_fStopTimeMax = 1.f;
	m_fStopTime = m_fStopTimeMax;

	m_bStopNow = false;
}

EnemyObject2::~EnemyObject2(){

}

void EnemyObject2::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyObject2::OnCreate(){
	m_xpSprite = SpriteMngr::GetSprite("Enemy2");
	m_xpSprite->SetPosition(getPosition());

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 35.f, 0));

	m_xpPlayer = GameObjectMngr::GetGameObject("Player");

	SetAllPositions(getPosition());
}

void EnemyObject2::OnUpdateThis(){
	if (!m_bStopNow){
		if (m_fStopTime <= 0){
			m_bStopNow = true;
		}

		m_fStopTime -= TimeMngr::GetDtime();
		SetAllPositions(sf::Vector2f(getPosition() + m_vSpd * m_fSpd));
	}
	else {
		if (CanFire()){
			m_bStopNow = false;
			m_fStopTime = m_fStopTimeMax;

			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(-1, -1), 60.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(-1, 0), 95.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(-1, 1), 60.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(0, -1), 95.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(0, 1), 95.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(1, -1), 60.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(1, 0), 95.f));
			GetParent()->AddChild(new EnemyBulletObject(getPosition(), sf::Vector2f(1, 1), 60.f));
		}

		float _iA = m_xpPlayer->getPosition().x - getPosition().x;
		float _iB = m_xpPlayer->getPosition().y - getPosition().y;
		float _iC = sqrt((_iA * _iA) + (_iB * _iB));

		m_vSpd = sf::Vector2f((_iA / _iC), (_iB / _iC));
	}

	if (!OnScreen()){
		DeleteMe();
	}
}

void EnemyObject2::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void EnemyObject2::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("PBullet")){
		m_iLife--;

		if (m_iLife <= 0){
			SoundMngr::Play("Sfx_EnemyDeath");
			DropScore();
			DeleteMe();
		}
	}
}