// PlayerBulletObject.cpp //

#include "PlayerBulletObject.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "SoundMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

PlayerBulletObject::PlayerBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration){
	m_vDir = p_vDir;

	m_fAcceleration = p_fAcceleration;

	m_xpSprite = SpriteMngr::GetSprite("PBullet");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 8.0f, 0));

	AddTag("PBullet");

	SoundMngr::Play("Sfx00");

	SetAllPositions(p_vPos);
}

PlayerBulletObject::~PlayerBulletObject(){	
//	delete m_xpSprite;
	m_xpSprite = NULL;
}

void PlayerBulletObject::SetAllPositions(sf::Vector2f p_vPosition){
	setPosition(p_vPosition);
	//m_xpSprite->setPosition(getPosition().x - m_xpSprite->getTextureRect().width / 2, getPosition().y - m_xpSprite->getTextureRect().height / 2);
	m_xpSprite->SetPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());
}

void PlayerBulletObject::OnCreate(){

}

void PlayerBulletObject::OnUpdateThis(){
	SetAllPositions(getPosition() + (TimeMngr::GetDtime() * (m_vDir * m_fAcceleration)));
	
	if (!OnScreen()){
		DeleteMe();
	}
}

void PlayerBulletObject::OnDrawThis(){
	DrawMngr::Draw(m_xpSprite->GetSprite());
}

void PlayerBulletObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy")){
		DeleteMe();
	}
}