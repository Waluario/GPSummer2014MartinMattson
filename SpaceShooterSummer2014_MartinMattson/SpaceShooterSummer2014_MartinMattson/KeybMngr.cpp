// KeybMngr.cpp //

#include "KeybMngr.h"

KeybMngr::KeybMngr(){
	KeybMngr::m_xaKeybPress[0] = new Button(sf::Keyboard::Up);
	KeybMngr::m_xaKeybPress[1] = new Button(sf::Keyboard::Down);
	KeybMngr::m_xaKeybPress[2] = new Button(sf::Keyboard::Left);
	KeybMngr::m_xaKeybPress[3] = new Button(sf::Keyboard::Right);
	KeybMngr::m_xaKeybPress[4] = new Button(sf::Keyboard::Z);
	KeybMngr::m_xaKeybPress[5] = new Button(sf::Keyboard::LShift);
	KeybMngr::m_xaKeybPress[6] = new Button(sf::Keyboard::RShift);
}

KeybMngr::~KeybMngr(){
	for (int i = KeybMngr::m_xaKeybPress.size() - 1; i >= 0; i--){
		delete KeybMngr::m_xaKeybPress[i];
		KeybMngr::m_xaKeybPress[i] = NULL;
	}
}

void KeybMngr::Update(float p_fDtime){
	for (int i = 0; i < m_xaKeybPress.size(); i++){
		KeybMngr::m_xaKeybPress[i]->Update(p_fDtime);
	}
}

std::vector<Button*> KeybMngr::GetVector(){
	return KeybMngr::m_xaKeybPress;
}