// Core.cpp //

#include "Core.h"

#include "CollisionMngr.h"
#include "DrawMngr.h"
#include "KeybMngr.h"
#include "SpriteMngr.h"
#include "TimeMngr.h"

#include "StateMngr.h"

#include "GameState.h"
#include "MenuState.h"

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

	CollisionMngr::NewList();

	m_xpStateMngr->Add(new GameState());
	m_xpStateMngr->Add(new MenuState());

	m_xpStateMngr->SetState("MenuState");

	return true;
}

void Core::Run(){

	while (m_xpStateMngr->IsRunning()){
		UpdEvents();

		if (m_xpTimeMngr->UpdDtime()){
			m_xpKeybMngr->Update(m_xpTimeMngr->GetDtime());

			m_xpStateMngr->Update(m_xpTimeMngr->GetDtime());
			m_xpStateMngr->Draw();

			m_xpDrawMngr->Present();
			m_xpDrawMngr->Clear();
		}
	}
}

void Core::UpdEvents(){
	sf::Event event;
	while (m_xpScreen->pollEvent(event)){
		switch (event.type){
			case sf::Event::Closed:
				m_xpScreen->close();
				m_xpStateMngr->Quit();
				break;
		}
	}
}

void Core::Cleanup(){
	if (m_xpDrawMngr != NULL){
		delete m_xpDrawMngr;
		m_xpDrawMngr = NULL;
	}

	if (m_xpKeybMngr != NULL){
		delete m_xpKeybMngr;
		m_xpKeybMngr = NULL;
	}

	if (m_xpSpriteMngr != NULL){
		delete m_xpSpriteMngr;
		m_xpSpriteMngr = NULL;
	}

	if (m_xpTimeMngr != NULL){
		delete m_xpTimeMngr;
		m_xpTimeMngr = NULL;
	}

	if (m_xpStateMngr != NULL){
		delete m_xpStateMngr;
		m_xpStateMngr = NULL;
	}
}