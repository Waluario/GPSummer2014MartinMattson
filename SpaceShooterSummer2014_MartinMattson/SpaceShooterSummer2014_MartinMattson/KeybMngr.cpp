// KeybMngr.cpp //

#include "KeybMngr.h"

std::vector<Button*> KeybMngr::m_xpaKeybPress;

KeybMngr::KeybMngr(){
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Up));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Down));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Left));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Right));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Z));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::LShift));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::RShift));

	/*KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Up));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Down));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Left));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Right));
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Z));*/
}

KeybMngr::~KeybMngr(){
	for (int i = KeybMngr::m_xpaKeybPress.size() - 1; i >= 0; i--){
		delete KeybMngr::m_xpaKeybPress[i];
		KeybMngr::m_xpaKeybPress[i] = NULL;
	}
}

void KeybMngr::Update(float p_fDtime){
	for (int i = 0; i < m_xpaKeybPress.size(); i++){
		KeybMngr::m_xpaKeybPress[i]->Update(p_fDtime);
	}
}

std::vector<Button*> KeybMngr::GetVector(){
	return KeybMngr::m_xpaKeybPress;
}