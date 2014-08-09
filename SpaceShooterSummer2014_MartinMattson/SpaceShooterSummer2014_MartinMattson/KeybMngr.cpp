// KeybMngr.cpp //

#include "KeybMngr.h"

#include "Button.h"

std::vector<Button*> KeybMngr::m_xpaKeybPress;

KeybMngr::KeybMngr(){
	// Sets the predetermined keys
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Up)); // 0
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Down)); // 1
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Left)); // 2
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Right)); // 3
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Z)); // 4
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::LShift)); // 5
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::X)); // 6

	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Up)); // 7
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Down)); // 8
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Left)); // 9
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Right)); // 10
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Z)); // 11
	KeybMngr::m_xpaKeybPress.push_back(new Button(sf::Keyboard::Return)); // 12
}

KeybMngr::~KeybMngr(){
	// Delets all of the Keyboard Managers spots and clears the spot
	for (int i = KeybMngr::m_xpaKeybPress.size() - 1; i >= 0; i--){
		delete KeybMngr::m_xpaKeybPress[i];
		KeybMngr::m_xpaKeybPress[i] = NULL;
	}
}

void KeybMngr::Update(float p_fDtime){
	// Updates the timers of all keys pressed
	for (int i = 0; i < m_xpaKeybPress.size(); i++){
		KeybMngr::m_xpaKeybPress[i]->Update(p_fDtime);
	}
}

std::vector<Button*> KeybMngr::GetVector(){
	// Returns vector
	return KeybMngr::m_xpaKeybPress;
}

float KeybMngr::GetButtonPressedTime(int p_iKey){
	// Returns the time the desired button has been pressed
	return m_xpaKeybPress[p_iKey]->GetTimer();
}

bool KeybMngr::GetButtonPressed(int p_iKey){
	// returns wether or not the button in question is pressed or not
	return (m_xpaKeybPress[p_iKey]->IsPressed());
}

bool KeybMngr::GetButtonPressedOnce(int p_iKey){
	// Returns wehter or not the button in question is pressed once
	return m_xpaKeybPress[p_iKey]->IsPressedOnce();
}

std::string KeybMngr::GetButtonSymbol(int p_iKey){
	return m_xpaKeybPress[p_iKey]->GetKeySymbol();
}