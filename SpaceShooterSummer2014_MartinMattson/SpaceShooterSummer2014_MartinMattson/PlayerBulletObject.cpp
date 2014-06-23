// PlayerBulletObject.cpp //

#include "PlayerBulletObject.h"

PlayerBulletObject::PlayerBulletObject(sf::Vector2f p_vDir, float p_fAcceleration){
	m_vDir = p_vDir;

	m_fAcceleration = p_fAcceleration;
}

PlayerBulletObject::~PlayerBulletObject(){

}

void PlayerBulletObject::OnUpdateThis(){
	sf::Vector2f l_vVelocity(m_vDir * m_fAcceleration);
}

void PlayerBulletObject::OnDrawThis(){

}

void PlayerBulletObject::OnCollision(GameObject *p_xpCollider){

}