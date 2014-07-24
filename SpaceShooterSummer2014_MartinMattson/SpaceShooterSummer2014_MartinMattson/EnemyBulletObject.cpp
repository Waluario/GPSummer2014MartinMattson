// EnemyBulletObject.cpp //

#include "EnemyBulletObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

#include <iostream>

EnemyBulletObject::EnemyBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration){
	setPosition(p_vPos);
	m_vDir = p_vDir;

	m_fAcceleration = p_fAcceleration;

	m_xpSprite = SpriteMngr::GetSprite("EBullet");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 4.f, 0));

	AddTag("EBullet");
}

EnemyBulletObject::~EnemyBulletObject(){
	delete m_xpSprite;
	m_xpSprite = NULL;
}

void EnemyBulletObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void EnemyBulletObject::OnCreate(){

}

void EnemyBulletObject::OnUpdateThis(){
	SetAllPositions(getPosition() + (TimeMngr::GetDtime() * (m_vDir * m_fAcceleration)));

	if (!OnScreen()){
		DeleteMe();
	}
}

void EnemyBulletObject::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
	//DrawMngr::Draw(GetHitbox()->GetShape());
}

void EnemyBulletObject::OnCollision(GameObject *p_xpCollider){

}