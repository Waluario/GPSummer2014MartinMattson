// KeybMngr.cpp //

#include "KeybMngr.h"

#include "Button.h"

KeybMngr::KeybMngr(){
	m_xaKeybPress[0] = new Button(sf::Keyboard::Up);
	m_xaKeybPress[1] = new Button(sf::Keyboard::Down);
	m_xaKeybPress[2] = new Button(sf::Keyboard::Left);
	m_xaKeybPress[3] = new Button(sf::Keyboard::Right);
	m_xaKeybPress[4] = new Button(sf::Keyboard::Z);
	m_xaKeybPress[5] = new Button(sf::Keyboard::LShift);
	m_xaKeybPress[6] = new Button(sf::Keyboard::RShift);
}

KeybMngr::~KeybMngr(){
	for (int i = m_xaKeybPress.size() - 1; i >= 0; i--){
		delete m_xaKeybPress[i];
		m_xaKeybPress[i] = NULL;
	}
}

void KeybMngr::Update(float p_fDtime){
	for (int i = 0; i < m_xaKeybPress.size(); i++){
		m_xaKeybPress[i]->Update(p_fDtime);
	}
}

std::vector<Button*> KeybMngr::GetVector(){
	return m_xaKeybPress;
}