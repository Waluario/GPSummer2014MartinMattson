// PlayerObject.cpp //

#include "PlayerObject.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "Sprite.h"

#include "PlayerBulletObject.h"

#include <iostream>

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_iLife = p_iLife;
	m_fAcceleration = p_fAcceleration;

	setPosition(p_vPos);

	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::OnCreate(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	sf::Vector2f l_vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	l_vSpeed *= (m_fAcceleration * TimeMngr::GetDtime(false));

	if (_Keys[4]->IsPressed()){
		AddChild(new PlayerBulletObject(getPosition(), sf::Vector2f(0, -1), 1.0f));
	}

	m_fCdwn -= (TimeMngr::GetDtime());

	setPosition(getPosition().x + l_vSpeed.x, getPosition().y + l_vSpeed.y);
	m_xpSprite->setPosition(getPosition());
}

void PlayerObject::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy")){
		if (m_fCdwn > 0.0f){
			m_iLife -= 1;
			m_fCdwn = m_fMaxCdwn;
			std::cout << "Hit!";
		}
	}
}