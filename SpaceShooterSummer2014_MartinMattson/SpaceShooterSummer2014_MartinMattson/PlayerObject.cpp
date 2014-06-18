// PlayerObject.cpp //

#include "PlayerObject.h"

#include "KeybMngr.h"

PlayerObject::PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration){
	m_iLife = p_iLife;

	setPosition(p_vPos);
}

PlayerObject::~PlayerObject(){

}

void PlayerObject::OnUpdateThis(){
	std::vector<Button*> _Keys = KeybMngr::GetVector();

	m_vSpeed = sf::Vector2f((KeybMngr::GetVector()[3]->IsPressed() - KeybMngr::GetVector()[2]->IsPressed()), (KeybMngr::GetVector()[1]->IsPressed() - KeybMngr::GetVector()[0]->IsPressed()));

	m_vSpeed *= m_fAcceleration;

	setPosition(getPosition().x + m_vSpeed.x, getPosition().y + m_vSpeed.y);
}

void PlayerObject::OnCollision(GameObject *p_xpCollider){

}