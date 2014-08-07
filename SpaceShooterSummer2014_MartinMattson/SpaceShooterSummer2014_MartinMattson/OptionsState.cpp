// OptionsState.cpp //

#include "OptionsState.h"

#include "OptionsItem.h"

#include "OptionsObject.h"
#include "SceneObject.h"

OptionsState::OptionsState(float p_fWaitTimeStart, std::vector<OptionsItem*> p_xpaOptions){
	m_fWaitTimeStart = p_fWaitTimeStart;

	m_xpScene = new SceneObject(0);

	m_xpScene->AddChild(new OptionsObject(sf::Vector2f(0, 0), p_xpaOptions));
}

OptionsState::~OptionsState(){

}

bool OptionsState::Enter(){
	return true;
}

void OptionsState::Exit(){

}

bool OptionsState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	return true;
}

void OptionsState::Draw(){
	m_xpScene->OnDraw();
}

std::string OptionsState::Next(){
	return m_sNext;
}

bool OptionsState::IsType(const std::string &p_sType){
	return p_sType.compare("OptionsState") == 0;
}