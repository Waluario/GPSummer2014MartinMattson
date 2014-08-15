// CreditsState.cpp //

#include "CreditsState.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "StateMngr.h"

#include "InfoObject.h"

CreditsState::CreditsState(float p_fWaitTimeStart, std::string p_sFile){
	m_fWaitTimeStart = p_fWaitTimeStart;

	m_xpCredits = new InfoObject(sf::Vector2f(0, 0), p_sFile);
}

CreditsState::~CreditsState(){
	delete m_xpCredits;
	m_xpCredits = NULL;
}

bool CreditsState::Enter(){
	return true;
}

void CreditsState::Exit(){
	
}

bool CreditsState::Update(float p_fDtime){
	if ((KeybMngr::GetButtonPressedOnce(11) || KeybMngr::GetButtonPressedOnce(12)) && m_fWaitTime <= 0.f){
		StateMngr::SetNextState("MenuState");
		StateMngr::ChangeState();
	}

	m_fWaitTime -= p_fDtime;

	return true;
}

void CreditsState::Draw(){
	m_xpCredits->OnDraw();
}

std::string CreditsState::Next(){
	return m_sNext;
}

bool CreditsState::IsType(const std::string &p_sType){
	return p_sType.compare("CreditsState") == 0;
}