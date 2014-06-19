// KeybMngr.cpp //

#include "KeybMngr.h"

std::vector<Button*> KeybMngr::m_xaKeybPress;

KeybMngr::KeybMngr(){
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::Up));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::Down));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::Left));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::Right));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::Z));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::LShift));
	KeybMngr::m_xaKeybPress.push_back(new Button(sf::Keyboard::RShift));
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