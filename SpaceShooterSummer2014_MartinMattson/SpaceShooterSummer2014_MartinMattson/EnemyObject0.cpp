// EnemyObject0.h //

#include "EnemyObject0.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Hitbox.h"
#include "Sprite.h"

EnemyObject0::EnemyObject0(sf::Vector2f p_vPosition, float p_fHorizontalSpd, float p_fVerticalSpd, float p_fDeaccel, float p_fMaxSpd){
	setPosition(p_vPosition);
	m_fHorizontalSpd = p_fHorizontalSpd;
	m_fVerticalSpd = p_fVerticalSpd;
	m_fDeaccel = p_fDeaccel;
	m_fMaxSpd = m_fMaxSpd;

	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
	AddTag("Enemy");

	SetHitbox(CollisionMngr::NewHitbox(this, getPosition(), 64.0f));
}

EnemyObject0::~EnemyObject0(){

}

void EnemyObject0::OnCreate(){

}

void EnemyObject0::OnUpdateThis(){
	m_fVerticalSpd -= m_fDeaccel;
	sf::Vector2f _vSpeed(m_fHorizontalSpd, m_fVerticalSpd);

	setPosition(getPosition() + _vSpeed);

	m_xpSprite->setPosition(getPosition());
	GetHitbox()->SetPosition(getPosition());

	//std::cout << getPosition().x << " " << getPosition().y << " : " << m_xpSprite->getPosition().x << " " << m_xpSprite->getPosition().y << std::endl;
}

void EnemyObject0::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void EnemyObject0::OnCollision(GameObject *p_xpCollider){

}