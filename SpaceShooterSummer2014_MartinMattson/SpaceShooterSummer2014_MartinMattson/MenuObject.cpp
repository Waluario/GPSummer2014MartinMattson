// MenuObject.cpp //

#include "MenuObject.h"

#include "KeybMngr.h"
#include "StateMngr.h"

#include "MenuItem.h"

#include <iostream>

MenuObject::MenuObject(){
	m_iCurrentChoice = 0;

	m_xpaItems.push_back(new MenuItem("GameState", "Start Game", sf::Vector2f(0, 0)));
	m_xpaItems.push_back(new MenuItem("EndState", "Exit", sf::Vector2f(0, 0)));
}

MenuObject::~MenuObject(){

}

void MenuObject::OnCreate(){

}

void MenuObject::OnUpdateThis(){
	if (KeybMngr::GetVector()[0]->IsPressedOnce()){
		m_iCurrentChoice--;

		if (m_iCurrentChoice < 0.f){
			m_iCurrentChoice = m_xpaItems.size() - 1;
		}
	}

	if (KeybMngr::GetVector()[1]->IsPressedOnce()){
		m_iCurrentChoice++;

		if (m_iCurrentChoice >= m_xpaItems.size()){
			m_iCurrentChoice =  0;
		}
	}

	if (KeybMngr::GetVector()[4]->IsPressedOnce()){
		StateMngr::SetState(m_xpaItems[m_iCurrentChoice]->GetState());
	}
}

void MenuObject::OnDrawThis(){
	for (int i = 0; i < m_xpaItems.size(); i++){
		if (i == m_iCurrentChoice){
			std::cout << "<";
		}

		std::cout << m_xpaItems[i]->GetChoice();

		if (i == m_iCurrentChoice){
			std::cout << ">";
		}

		std::cout << std::endl;
	}
}

void MenuObject::OnCollision(GameObject *p_xpCollider){

}