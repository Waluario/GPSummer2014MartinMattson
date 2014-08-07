// OptionsItem0.cpp //

#include "OptionsItem0.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"

OptionsItem0::OptionsItem0(sf::Vector2f p_vPos, std::string p_sText, bool *p_bpOption){
	m_bpOption = p_bpOption;
	m_sChoice = p_sText;

	if (p_bpOption){
		m_xpText = new sf::Text(sf::String(sf::String(p_sText + " 1")), *FontMngr::GetFont("Arial"));
	}
	else {
		m_xpText = new sf::Text(sf::String(sf::String(p_sText + " 0")), *FontMngr::GetFont("Arial"));
	}

	 SetPosition(p_vPos);
}

OptionsItem0::~OptionsItem0(){
	delete m_xpText;
	m_xpText = NULL;

	m_bpOption = NULL;
}

sf::Vector2f OptionsItem0::GetPosition(){
	return m_xpText->getPosition();
}

void OptionsItem0::SetPosition(sf::Vector2f p_vPosition){
	m_xpText->setPosition(p_vPosition);
}

sf::Text* OptionsItem0::GetText(){
	return m_xpText;
}

void OptionsItem0::SetText(sf::Text *p_xpChoice){
	m_xpText = p_xpChoice;
}

void OptionsItem0::OnDraw(){
	if (*m_bpOption){
		m_xpText->setString(sf::String(m_sChoice + " 1"));
	}
	else {
		m_xpText->setString(sf::String(m_sChoice + " 0"));
	}

	DrawMngr::Draw(m_xpText);
}

void OptionsItem0::OnDrawWhenChosen(){
	if (*m_bpOption){
		m_xpText->setString(sf::String("<" + m_sChoice + " 1" + ">"));
	}
	else {
		m_xpText->setString(sf::String("<" + m_sChoice + " 0" + ">"));
	}

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem0::OnChosen(){
	if (*m_bpOption && (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12) || KeybMngr::GetButtonPressedOnce(9))){
		*m_bpOption = false;
	}
	else if (!*m_bpOption && (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12) || KeybMngr::GetButtonPressedOnce(10))){
		*m_bpOption = true;
	}
}