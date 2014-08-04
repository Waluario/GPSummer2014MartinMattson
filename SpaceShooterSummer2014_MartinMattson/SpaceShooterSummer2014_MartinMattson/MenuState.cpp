// MenuState.cpp //

#include "MenuState.h"

#include "MusicMngr.h"

#include "MenuObject.h"
#include "SceneObject.h"

MenuState::MenuState(){
	m_xpScene = new SceneObject(0);

	m_xpScene->AddChild(new MenuObject());
}

MenuState::~MenuState(){

}

bool MenuState::Enter(){
	MusicMngr::Play("Bgm_Menu", 50);

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