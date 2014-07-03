// MenuItem.cpp //

#include "MenuItem.h"

MenuItem::MenuItem(std::string p_sState, std::string p_sChoice, sf::Vector2f p_vPosition){
	m_sState = p_sState;
	m_sChoice = p_sChoice;

	m_vPosition = p_vPosition;
}

MenuItem::~MenuItem(){

}

sf::Vector2f MenuItem::GetPosition(){
	return m_vPosition;
}

void MenuItem::SetPosition(sf::Vector2f p_vPosition){
	m_vPosition = p_vPosition;
}

std::string MenuItem::GetState(){
	return m_sState;
}

void MenuItem::SetState(std::string p_sState){
	m_sState = p_sState;
}

std::string MenuItem::GetChoice(){
	return m_sChoice;
}

void MenuItem::SetChoice(std::string p_sChoice){
	m_sChoice = p_sChoice;
}