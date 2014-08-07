// OptionsItem1.cpp //

#include "OptionsItem1.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"

#include <sstream>

OptionsItem1::OptionsItem1(sf::Vector2f p_vPos, std::string p_sText, int *p_ipOption, int p_iMin, int p_iMax){
	m_ipOption = p_ipOption;
	m_sChoice = p_sText;

	m_iMin = p_iMin;
	m_iMax = p_iMax;

	m_xpText = new sf::Text(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_ipOption))->str()), *FontMngr::GetFont("Arial"));

	SetPosition(p_vPos);
}

OptionsItem1::~OptionsItem1(){
	delete m_xpText;
	m_xpText = NULL;

	m_ipOption = NULL;
}

sf::Vector2f OptionsItem1::GetPosition(){
	return m_xpText->getPosition();
}

void OptionsItem1::SetPosition(sf::Vector2f p_vPosition){
	m_xpText->setPosition(p_vPosition);
}

sf::Text* OptionsItem1::GetText(){
	return m_xpText;
}

void OptionsItem1::SetText(sf::Text *p_xpChoice){
	m_xpText = p_xpChoice;
}

void OptionsItem1::OnDraw(){
	m_xpText->setString(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_ipOption))->str()));

	DrawMngr::Draw(m_xpText);
}

void OptionsItem1::OnDrawWhenChosen(){
	m_xpText->setString(sf::String("<" + m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_ipOption))->str() + ">"));

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem1::OnChosen(){
	if (KeybMngr::GetButtonPressedOnce(9) && *m_ipOption > m_iMin){
		*m_ipOption-= 1;
	}
	
	if (KeybMngr::GetButtonPressedOnce(10) && *m_ipOption < m_iMax){
		*m_ipOption+= 1;
	}
}