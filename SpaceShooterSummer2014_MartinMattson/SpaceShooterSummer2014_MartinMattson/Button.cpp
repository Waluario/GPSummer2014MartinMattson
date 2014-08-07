// Button.cpp //

#include "Button.h"

#include <iostream>

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
			m_bPressedOnce = false;
		}
		else {
			m_bPressedOnce = true;
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

std::string Button::GetKeySymbol(){
	switch (m_xKey){
	case sf::Keyboard::Key::A:
		return "A";
		break;
	case sf::Keyboard::Key::B:
		return "B";
		break;
	case sf::Keyboard::Key::C:
		return "C";
		break;
	case sf::Keyboard::Key::D:
		return "D";
		break;
	case sf::Keyboard::Key::E:
		return "E";
		break;
	case sf::Keyboard::Key::F:
		return "F";
		break;
	case sf::Keyboard::Key::G:
		return "G";
		break;
	case sf::Keyboard::Key::H:
		return "H";
		break;
	case sf::Keyboard::Key::I:
		return "I";
		break;
	case sf::Keyboard::Key::J:
		return "J";
		break;
	case sf::Keyboard::Key::K:
		return "K";
		break;
	case sf::Keyboard::Key::L:
		return "L";
		break;
	case sf::Keyboard::Key::M:
		return "M";
		break;
	case sf::Keyboard::Key::N:
		return "N";
		break;
	case sf::Keyboard::Key::O:
		return "O";
		break;
	case sf::Keyboard::Key::P:
		return "P";
		break;
	case sf::Keyboard::Key::Q:
		return "Q";
		break;
	case sf::Keyboard::Key::R:
		return "R";
		break;
	case sf::Keyboard::Key::S:
		return "S";
		break;
	case sf::Keyboard::Key::T:
		return "T";
		break;
	case sf::Keyboard::Key::U:
		return "U";
		break;
	case sf::Keyboard::Key::V:
		return "V";
		break;
	case sf::Keyboard::Key::W:
		return "W";
		break;
	case sf::Keyboard::Key::X:
		return "X";
		break;
	case sf::Keyboard::Key::Y:
		return "Y";
		break;
	case sf::Keyboard::Key::Z:
		return "Z";
		break;
	case sf::Keyboard::Key::Num0:
		return "0";
		break;
	case sf::Keyboard::Key::Num1:
		return "1";
		break;
	case sf::Keyboard::Key::Num2:
		return "2";
		break;
	case sf::Keyboard::Key::Num3:
		return "3";
		break;
	case sf::Keyboard::Key::Num4:
		return "4";
		break;
	case sf::Keyboard::Key::Num5:
		return "5";
		break;
	case sf::Keyboard::Key::Num6:
		return "6";
		break;
	case sf::Keyboard::Key::Num7:
		return "7";
		break;
	case sf::Keyboard::Key::Num8:
		return "8";
		break;
	case sf::Keyboard::Key::Num9:
		return "9";
		break;
	case sf::Keyboard::Key::Comma:
		return "Comma";
		break;
	case sf::Keyboard::Key::Period:
		return "Period";
		break;
	case sf::Keyboard::Key::Subtract:
		return "Subtract";
		break;
	case sf::Keyboard::Key::Up:
		return "Up";
		break;
	case sf::Keyboard::Key::Down:
		return "Down";
		break;
	case sf::Keyboard::Key::Left:
		return "Left";
		break;
	case sf::Keyboard::Key::Right:
		return "Right"; 
		break;
	case sf::Keyboard::Key::LShift:
		return "LShift";
		break;
	case sf::Keyboard::Key::RShift:
		return "RShift";
		break;
	case sf::Keyboard::Key::LControl:
		return "LCtrl";
		break;
	case sf::Keyboard::Key::RControl:
		return "RCtrl";
		break;
	}
}