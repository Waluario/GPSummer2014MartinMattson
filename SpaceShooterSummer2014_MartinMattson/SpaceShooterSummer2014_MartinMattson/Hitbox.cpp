// Hitbox.cpp //

#include "Hitbox.h"

Hitbox::Hitbox(GameObject *p_xpGameObject){
	m_fSize = 0.0f;
}

Hitbox::Hitbox(GameObject *p_xpGameObject, float p_fSize){
	m_fSize = p_fSize;
	m_xpGameObject = p_xpGameObject;
}

Hitbox::~Hitbox(){

}

float Hitbox::GetSize(){
	return m_fSize;
}

void Hitbox::SetSize(float p_f){
	m_fSize = p_f;
}

GameObject* Hitbox::GetGameObject(){
	return m_xpGameObject;
}

void Hitbox::SetGameObject(GameObject *p_xpGameObject){
	m_xpGameObject = p_xpGameObject;
}

bool Hitbox::Overlap(Hitbox *p_xpHitbox){
	return false;
}