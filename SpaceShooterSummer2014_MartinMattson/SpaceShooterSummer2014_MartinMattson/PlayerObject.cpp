// PlayerObject.cpp //

#include "PlayerObject.h"

#include "Sprite.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_iLife = p_iLife;

	setPosition(p_vPos);

	m_xpSprite = SpriteMngr::LoadSprite("ShipSprite.png");
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	m_vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	m_vSpeed *= m_fAcceleration;

	//m_fCdwn -= 

	setPosition(getPosition().x + m_vSpeed.x, getPosition().y + m_vSpeed.y);
}

void PlayerObject::OnDrawThis(){
	DrawMngr::DrawSprite(m_xpSprite);
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){
	if (p_xpCollider->HasTag("Enemy")){
		if (m_fCdwn > 0.0f){
			m_iLife -= 1;
			m_fCdwn = m_fMaxCdwn;
		}
	}
}