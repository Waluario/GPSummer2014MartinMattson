// OptionsItem0.cpp //

#include "OptionsItem0.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"

OptionsItem0::OptionsItem0(sf::Vector2f p_vPos, std::string p_sText, bool *p_bpOption, bool p_bShowOption)
: MenuItem(" ", p_sText, p_vPos){
	m_bpOption = p_bpOption;
	m_bShowOption = p_bShowOption;
	m_sChoice = p_sText;

	if (p_bpOption){
		m_xpText = new sf::Text(sf::String(sf::String(p_sText + " Yes")), *FontMngr::GetFont("Arial"));
	}
	else {
		m_xpText = new sf::Text(sf::String(sf::String(p_sText + " No")), *FontMngr::GetFont("Arial"));
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
	if (*m_bpOption && m_bShowOption){
		m_xpText->setString(sf::String(m_sChoice + " Yes"));
	}
	else if (!*m_bpOption && m_bShowOption) {
		m_xpText->setString(sf::String(m_sChoice + " No"));
	}
	else if (!m_bShowOption){
		m_xpText->setString(sf::String(m_sChoice));
	}

	DrawMngr::Draw(m_xpText);
}

void OptionsItem0::OnDrawWhenChosen(){
	if (*m_bpOption && m_bShowOption){
		m_xpText->setString(sf::String("<" + m_sChoice + " Yes" + ">"));
	}
	else if (!*m_bpOption && m_bShowOption) {
		m_xpText->setString(sf::String("<" + m_sChoice + " No" + ">"));
	}
	else if (!m_bShowOption){
		m_xpText->setString(sf::String("<" + m_sChoice + ">"));
	}

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem0::OnChosen(){
	if (*m_bpOption && (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12) || (KeybMngr::GetButtonPressedOnce(9) && m_bShowOption))){
		*m_bpOption = false;
	}
	else if (!*m_bpOption && (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12) || (KeybMngr::GetButtonPressedOnce(10) && m_bShowOption))){
		*m_bpOption = true;
	}
}