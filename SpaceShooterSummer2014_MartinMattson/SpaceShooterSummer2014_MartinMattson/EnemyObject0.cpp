// EnemyObject0.h //

#include "EnemyObject0.h"

#include "Sprite.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

EnemyObject0::EnemyObject0(){
	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
}

EnemyObject0::~EnemyObject0(){

}

void EnemyObject0::OnUpdateThis(){
	setPosition(0, 0);
	m_xpSprite->setPosition(getPosition());
	//std::cout << getPosition().x << " " << getPosition().y << " : " << m_xpSprite->getPosition().x << " " << m_xpSprite->getPosition().y << std::endl;
}

void EnemyObject0::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void EnemyObject0::OnCollision(GameObject *p_xpCollider){

}