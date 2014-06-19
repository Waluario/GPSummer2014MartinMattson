// Core.cpp //

#include "Core.h"

#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "StateMngr.h"

#include "GameState.h"

Core::Core(){

}

Core::~Core(){

}

bool Core::Init(){
	m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
	if (m_xpScreen == NULL){
		return false;
	}
	
	m_xpDrawMngr = new DrawMngr(m_xpScreen);
	if (m_xpDrawMngr == NULL){
		return false;
	}

	m_xpKeybMngr = new KeybMngr();
	if (m_xpKeybMngr == NULL){
		return false;
	}

	m_xpSpriteMngr = new SpriteMngr("../rec/Graphics/");
	if (m_xpSpriteMngr == NULL){
		return false;
	}

	m_xpTimeMngr = new TimeMngr(new sf::Clock, sf::seconds(1.f / 60.f));
	if (m_xpTimeMngr == NULL){
		return false;
	}

	m_xpStateMngr = new StateMngr();
	if (m_xpStateMngr == NULL){
		return false;
	}

	m_xpStateMngr->Add(new GameState());

	m_xpStateMngr->SetState("GameState");

	return true;
}

void Core::Run(){

	while (m_xpStateMngr->IsRunning()){
		UpdEvents();

		while (m_xpTimeMngr->UpdDtime()){
			while (m_xpTimeMngr->UpdDtime()){
				m_xpStateMngr->Update(m_xpTimeMngr->GetDtime());
				m_xpStateMngr->Draw();

				m_xpDrawMngr->Present();
				m_xpDrawMngr->Clear();
			}
		}
	}
}

void Core::UpdEvents(){

}

void Core::Cleanup(){

}