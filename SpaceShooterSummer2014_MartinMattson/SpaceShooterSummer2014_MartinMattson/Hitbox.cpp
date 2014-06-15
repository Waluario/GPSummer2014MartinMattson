// Hitbox.cpp //

#include "Hitbox.h"

Hitbox::Hitbox(){
	m_fSize = 0.0f;
}

Hitbox::Hitbox(float p_f){
	m_fSize = p_f;
}

Hitbox::~Hitbox(){

}

float Hitbox::GetSize(){
	return m_fSize;
}

void Hitbox::SetSize(float p_f){
	m_fSize = p_f;
}

bool Hitbox::Overlap(sf::Vector2f p_vPos0, sf::Vector2f p_vPos, float p_fSize){
	return true;
}