// MenuState.cpp //

#include "MenuState.h"

#include "MusicMngr.h"

#include "OptionsObject.h"
#include "SceneObject.h"

#include "MenuItem.h"

MenuState::MenuState(){
	m_xpScene = new SceneObject(0);

	std::vector<MenuItem*> _xpaItems;
	_xpaItems.push_back(new MenuItem("GameState", "Start Game", sf::Vector2f(0, 0)));
	_xpaItems.push_back(new MenuItem("HowToPlayState", "How To Play", sf::Vector2f(0, 35)));
	_xpaItems.push_back(new MenuItem("OptionsState", "Options", sf::Vector2f(0, 70)));
	_xpaItems.push_back(new MenuItem("CreditsState", "Credits", sf::Vector2f(0, 105)));
	_xpaItems.push_back(new MenuItem("EndState", "Exit", sf::Vector2f(0, 140)));

	m_xpScene->AddChild(new OptionsObject(sf::Vector2f(0, 0), _xpaItems));
}

MenuState::~MenuState(){

}

bool MenuState::Enter(){
	MusicMngr::Stop();
	MusicMngr::Play("Bgm_Menu", 100);

	return true;
}

void MenuState::Exit(){

}

bool MenuState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	return true;
}

void MenuState::Draw(){
	m_xpScene->OnDraw();
}

std::string MenuState::Next(){
	return m_sNext;
}

bool MenuState::IsType(const std::string &p_sType){
	return p_sType.compare("MenuState") == 0;
}