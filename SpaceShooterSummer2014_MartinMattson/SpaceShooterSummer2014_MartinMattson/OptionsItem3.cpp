// OptionsItem3.cpp //

#include "OptionsItem3.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"
#include "TimeMngr.h"

#include <sstream>

OptionsItem3::OptionsItem3(sf::Vector2f p_vPos, std::string p_sText, int p_iKeyb)
: MenuItem(" ", p_sText, p_vPos){
	m_iKeyb = p_iKeyb;
	m_sChoice = p_sText;

	m_xpText = new sf::Text(sf::String(m_sChoice + " " + KeybMngr::GetButtonSymbol(m_iKeyb)), *FontMngr::GetFont("Arial"));

	m_bCanMovePointer = true;

	m_fStopTimeStart = .25f;
	m_fStopTime = m_fStopTimeStart;

	SetPosition(p_vPos);
}

OptionsItem3::~OptionsItem3(){
	delete m_xpText;
	m_xpText = NULL;
}

sf::Vector2f OptionsItem3::GetPosition(){
	return m_xpText->getPosition();
}

void OptionsItem3::SetPosition(sf::Vector2f p_vPosition){
	m_xpText->setPosition(p_vPosition);
}

sf::Text* OptionsItem3::GetText(){
	return m_xpText;
}

void OptionsItem3::SetText(sf::Text *p_xpChoice){
	m_xpText = p_xpChoice;
}

void OptionsItem3::OnDraw(){
	m_bCanMovePointer = true;

	m_xpText->setString(m_sChoice + " " + KeybMngr::GetButtonSymbol(m_iKeyb));
	DrawMngr::Draw(m_xpText);
}

void OptionsItem3::OnDrawWhenChosen(){
	if (m_bCanMovePointer){
		m_xpText->setString("<" + m_sChoice + " " + KeybMngr::GetButtonSymbol(m_iKeyb) + ">");
	}
	else {
		m_xpText->setString(sf::String("<" + m_sChoice + " (Press any key, Esc to quit)>"));
	}

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem3::OnChosen(){
	if (m_bCanMovePointer){
		if (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12)){
			m_fStopTime = m_fStopTimeStart;
			m_bCanMovePointer = false;
		}
	}
	else {
		if (GetKeyPressed() != sf::Keyboard::Key::Unknown && m_fStopTime < 0.f){
			KeybMngr::GetVector()[m_iKeyb]->SetKey(GetKeyPressed());
			m_bCanMovePointer = true;
		}
		else {
			m_fStopTime -= TimeMngr::GetDtime();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
			m_bCanMovePointer = true;
		}
	}
}

bool OptionsItem3::CanMovePointer(){
	return m_bCanMovePointer;
}

sf::Keyboard::Key OptionsItem3::GetKeyPressed(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
		return sf::Keyboard::Key::A;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)){
		return sf::Keyboard::Key::B;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)){
		return sf::Keyboard::Key::C;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
		return sf::Keyboard::Key::D;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){
		return sf::Keyboard::Key::E;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)){
		return sf::Keyboard::Key::F;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)){
		return sf::Keyboard::Key::G;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H)){
		return sf::Keyboard::Key::H;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)){
		return sf::Keyboard::Key::I;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)){
		return sf::Keyboard::Key::J;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)){
		return sf::Keyboard::Key::K;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)){
		return sf::Keyboard::Key::L;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)){
		return sf::Keyboard::Key::M;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)){
		return sf::Keyboard::Key::N;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O)){
		return sf::Keyboard::Key::O;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){
		return sf::Keyboard::Key::P;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
		return sf::Keyboard::Key::Q;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
		return sf::Keyboard::Key::R;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
		return sf::Keyboard::Key::S;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)){
		return sf::Keyboard::Key::T;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U)){
		return sf::Keyboard::Key::U;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V)){
		return sf::Keyboard::Key::V;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
		return sf::Keyboard::Key::W;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)){
		return sf::Keyboard::Key::X;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)){
		return sf::Keyboard::Key::Y;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
		return sf::Keyboard::Key::Z;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0)){
		return sf::Keyboard::Key::Num0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){
		return sf::Keyboard::Key::Num1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)){
		return sf::Keyboard::Key::Num2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)){
		return sf::Keyboard::Key::Num3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)){
		return sf::Keyboard::Key::Num4;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)){
		return sf::Keyboard::Key::Num5;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)){
		return sf::Keyboard::Key::Num6;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)){
		return sf::Keyboard::Key::Num7;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8)){
		return sf::Keyboard::Key::Num8;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9)){
		return sf::Keyboard::Key::Num9;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Comma)){
		return sf::Keyboard::Key::Comma;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Period)){
		return sf::Keyboard::Key::Period;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract)){
		return sf::Keyboard::Key::Subtract;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
		return sf::Keyboard::Key::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
		return sf::Keyboard::Key::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
		return sf::Keyboard::Key::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
		return sf::Keyboard::Key::Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)){
		return sf::Keyboard::Key::LShift;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)){
		return sf::Keyboard::Key::RShift;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)){
		return sf::Keyboard::Key::LControl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)){
		return sf::Keyboard::Key::RControl;
	}
	else {
		return sf::Keyboard::Key::Unknown;
	}
}