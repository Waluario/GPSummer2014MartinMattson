// OptionsItem2.cpp //

#include "OptionsItem2.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"

#include <sstream>

OptionsItem2::OptionsItem2(sf::Vector2f p_vPos, std::string p_sText, float *p_fpOption, float p_fMin, float p_fMax, float p_fChange)
: MenuItem(" ", p_sText, p_vPos){
	m_fpOption = p_fpOption;
	m_sChoice = p_sText;

	m_fMin = p_fMin;
	m_fMax = p_fMax;
	m_fChange = p_fChange;

	m_xpText = new sf::Text(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str()), *FontMngr::GetFont("Arial"));

	SetPosition(p_vPos);
}

OptionsItem2::~OptionsItem2(){
	delete m_xpText;
	m_xpText = NULL;

	m_fpOption = NULL;
}

sf::Vector2f OptionsItem2::GetPosition(){
	return m_xpText->getPosition();
}

void OptionsItem2::SetPosition(sf::Vector2f p_vPosition){
	m_xpText->setPosition(p_vPosition);
}

sf::Text* OptionsItem2::GetText(){
	return m_xpText;
}

void OptionsItem2::SetText(sf::Text *p_xpChoice){
	m_xpText = p_xpChoice;
}

void OptionsItem2::OnDraw(){
	m_xpText->setString(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str()));

	DrawMngr::Draw(m_xpText);
}

void OptionsItem2::OnDrawWhenChosen(){
	m_xpText->setString(sf::String("<" + m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str() + ">"));

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem2::OnChosen(){
	if (KeybMngr::GetButtonPressedOnce(9) && *m_fpOption > m_fMin){
		*m_fpOption -= m_fChange;
	}

	if (KeybMngr::GetButtonPressedOnce(10) && *m_fpOption < m_fMax){
		*m_fpOption += m_fChange;
	}

	if (m_fChange > m_fMax){
		m_fChange = m_fMax;
	}

	if (m_fChange < m_fMin){
		m_fChange = m_fMin;
	}
}