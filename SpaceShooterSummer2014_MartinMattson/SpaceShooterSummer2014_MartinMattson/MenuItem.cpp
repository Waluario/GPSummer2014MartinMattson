// MenuItem.cpp //

#include "MenuItem.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"
#include "StateMngr.h"

MenuItem::MenuItem(std::string p_sState, std::string p_sChoice, sf::Vector2f p_vPosition){
	m_sState = p_sState;

	m_xpChoice = new sf::Text(sf::String(p_sChoice), *FontMngr::GetFont("Arial"));
	m_xpChoice->setPosition(p_vPosition);
}

MenuItem::~MenuItem(){

}

sf::Vector2f MenuItem::GetPosition(){
	return m_xpChoice->getPosition();
}

void MenuItem::SetPosition(sf::Vector2f p_vPosition){
	m_xpChoice->setPosition(p_vPosition);
}

std::string MenuItem::GetState(){
	return m_sState;
}

void MenuItem::SetState(std::string p_sState){
	m_sState = p_sState;
}

sf::Text* MenuItem::GetText(){
	return m_xpChoice;
}

void MenuItem::SetText(sf::Text *p_xpChoice){
	m_xpChoice = p_xpChoice;
}

void MenuItem::OnDraw(){
	DrawMngr::DrawText(m_xpChoice);
}

void MenuItem::OnDrawWhenChosen(){
	sf::Text *_xpText = new sf::Text(sf::String("<" + m_xpChoice->getString() + ">"), *FontMngr::GetFont("Arial"));
	_xpText->setPosition(GetPosition());

	DrawMngr::DrawText(_xpText);

	delete _xpText;
	_xpText = NULL;
}

void MenuItem::OnChosen(){
	if (KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12)){
		StateMngr::SetNextState(m_sState);
		StateMngr::ChangeState();
	}
}

bool MenuItem::CanMovePointer(){
	return true;
}

bool MenuItem::IgnoreOption(){
	return false;
}