// Core.cpp //

#include "Core.h"

#include "KeybMngr.h"
#include "StateMngr.h"

#include "GameState.h"

Core::Core(){

}

Core::~Core(){

}

bool Core::Init(){
	m_xpScreen = new sf::Window(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
	if (m_xpScreen == NULL){
		return false;
	}
	
	m_xpKeybMngr = new KeybMngr();
	if (m_xpKeybMngr == NULL){
		return false;
	}

	m_xpStateMngr = new StateMngr();
	if (m_xpStateMngr == NULL){
		return false;
	}

	m_xpStateMngr->Add(new GameState());

	m_xpStateMngr->Setstate("GameState")
}

void Core::Run(){

}

void Core::UpdEvents(){

}

void Core::UpdDtime(){

}

void Core::UpdFixedDtime(){

}

float Core::GetDtime(){

}

float Core::GetFixedDtime(){

}

void Core::Cleanup(){

}