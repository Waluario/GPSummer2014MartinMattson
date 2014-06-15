// Button.cpp //

#include "Button.h"

Button::Button(){
	m_xKey = sf::Keyboard::Unknown;
}

Button::Button(sf::Keyboard::Key p_xKey){
	m_xKey = p_xKey;
}

Button::~Button(){

}

void Button::Update(float p_fDtime){
	if (sf::Keyboard::isKeyPressed(m_xKey)){
		if (IsPressed()){
			m_bPressedOnce = true;
		}
		else {
			m_bPressedOnce = false;
		}

		m_fTimer += p_fDtime;
	}
	else {
		m_fTimer = 0.0f;
		m_bPressedOnce = false;
	}
}

bool Button::IsPressed(){
	return (m_fTimer > 0.0f);
}

bool Button::IsPressedOnce(){
	return m_bPressedOnce;
}

float Button::GetTimer(){
	return m_fTimer;
}

void Button::SetKey(sf::Keyboard::Key p_xKey){
	m_xKey = p_xKey;
}