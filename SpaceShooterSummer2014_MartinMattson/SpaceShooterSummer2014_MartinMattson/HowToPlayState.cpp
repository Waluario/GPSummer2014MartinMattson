// HowToPlayState.cpp //

#include "HowToPlayState.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "StateMngr.h"

#include "InfoObject.h"

HowToPlayState::HowToPlayState(float p_fWaitTimeStart, std::string p_sFile){
	m_fWaitTimeStart = p_fWaitTimeStart;

	m_xpHowToPlay = new InfoObject(sf::Vector2f(0, 0), p_sFile);
}

HowToPlayState::~HowToPlayState(){
	delete m_xpHowToPlay;
	m_xpHowToPlay = NULL;
}

bool HowToPlayState::Enter(){
	return true;
}

void HowToPlayState::Exit(){

}

bool HowToPlayState::Update(float p_fDtime){
	if (KeybMngr::GetButtonPressedOnce(4) && m_fWaitTime <= 0.f){
		StateMngr::SetNextState("MenuState");
		StateMngr::ChangeState();
	}

	m_fWaitTime -= p_fDtime;

	return true;
}

void HowToPlayState::Draw(){
	m_xpHowToPlay->OnDraw();
}

std::string HowToPlayState::Next(){
	return m_sNext;
}

bool HowToPlayState::IsType(const std::string &p_sType){
	return p_sType.compare("HowToPlayState") == 0;
}