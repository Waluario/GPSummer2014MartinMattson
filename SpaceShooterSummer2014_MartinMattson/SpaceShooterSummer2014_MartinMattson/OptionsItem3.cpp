// OptionsItem3.cpp //

#include "OptionsItem3.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"

#include <sstream>

OptionsItem3::OptionsItem3(sf::Vector2f p_vPos, std::string p_sText, int p_iKeyb){
	m_iKeyb = p_iKeyb;
	m_sChoice = p_sText;

	// m_xpText = new sf::Text(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str()), *FontMngr::GetFont("Arial"));

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
	//m_xpText->setString(sf::String(m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str()));

	DrawMngr::Draw(m_xpText);
}

void OptionsItem3::OnDrawWhenChosen(){
	//m_xpText->setString(sf::String("<" + m_sChoice + " " + static_cast<std::ostringstream*>(&(std::ostringstream() << *m_fpOption))->str() + ">"));

	DrawMngr::DrawText(m_xpText);
}

void OptionsItem3::OnChosen(){
	if (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12)){
		while (1){
			DrawMngr::Clear();
			
			m_xpText->setString(sf::String("<" + m_sChoice + " (Enter any key, press Esc to quit)>"));
			DrawMngr::Draw(m_xpText);
		}
	}
}