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
	m_xDtime = sf::Time::Zero;
	m_xFps = sf::seconds(1.f / 60.f);

	m_xpScreen = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter Summer 2014", sf::Style::Default);
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

	m_xpStateMngr->SetState("GameState");
}

void Core::Run(){
	m_xpClock = new sf::Clock;

	while (m_xpStateMngr->IsRunning()){
		UpdEvents();

		while (UpdDtime()){
			m_xpScreen->clear(sf::Color::Blue);

			m_xpStateMngr->Update(m_xDtime.asSeconds());
			m_xpStateMngr->Draw();

			m_xpScreen->display();
		}
	}
}

void Core::UpdEvents(){

}

bool Core::UpdDtime(){
	m_xDtime += m_xpClock->restart();

	if (m_xDtime >= m_xFps){
		m_xDtime = m_xFps;

		return true;
	}
	return false;
}

float Core::GetDtime(){
	return m_xDtime.asSeconds();
}

void Core::Cleanup(){

}