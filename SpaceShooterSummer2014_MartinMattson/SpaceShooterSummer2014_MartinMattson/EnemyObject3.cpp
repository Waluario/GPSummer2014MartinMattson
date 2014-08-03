// EnemyObject3.cpp //

#include "EnemyObject3.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "GameObjectMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include "EnemyBulletObject.h"

EnemyObject3::EnemyObject3(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd){
	m_vSpd = p_vSpd;

	setPosition(p_vPosition);

	m_iBulletAmmo = INT_MAX;
	m_iLife = 120;
	m_iScore = 32;

	m_fFireRateMax = 2.f;
	m_fFireRate = m_fFireRateMax;
}

EnemyObject3::~EnemyObject3(){

}

void EnemyObject3::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);

	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyObject3::OnCreate(){
	m_xpSprite = SpriteMngr::GetSprite("Enemy3");
	m_xpSprite->SetPosition(getPosition());

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 35.f, 0));

	m_xpPlayer = GameObjectMngr::GetGameObject("Player");
}

void EnemyObject3::OnUpdateThis(){
	SetAllPositions(sf::Vector2f(getPosition() + m_vSpd * TimeMngr::GetDtime()));

	if (CanFire()){
		float _iA = m_xpPlayer->getPosition().x - getPosition().x;
		float _iB = m_xpPlayer->getPosition().y - getPosition().y;
		float _iC = sqrt((_iA * _iA) + (_iB * _iB));

		sf::Vector2f _vBulletDir = sf::Vector2f((_iA / _iC), (_iB / _iC));

		GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 60.f));
		GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 95.f));
		GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 140.f));
		GetParent()->AddChild(new EnemyBulletObject(getPosition(), _vBulletDir, 175.f));
	}

	if (!OnScreen()){
		DeleteMe();
	}
}

void EnemyObject3::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void EnemyObject3::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("PBullet")){
		m_iLife--;

		if (m_iLife <= 0){
			SoundMngr::Play("Sfx_EnemyDeath");
			DropScore();
			DeleteMe();
		}
	}
}