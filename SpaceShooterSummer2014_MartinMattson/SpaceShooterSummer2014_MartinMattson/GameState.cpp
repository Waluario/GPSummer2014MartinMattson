// GameState.cpp //

#include "GameState.h"

#include "EnemyObject0.h"
#include "PlayerObject.h"
#include "SceneObject.h"

GameState::GameState(){

}

GameState::~GameState(){

}

bool GameState::Enter(){
	m_xpScene = new SceneObject();

	m_xpScene->AddChild(new PlayerObject(sf::Vector2f(0, 0), 5, 8.0f));
	m_xpScene->AddChild(new EnemyObject0());

	return true;
}

void GameState::Exit(){

}

bool GameState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	return true;
}

void GameState::Draw(){
	m_xpScene->OnDraw();
}

std::string GameState::Next(){
	return m_sNext;
}

bool GameState::IsType(const std::string &p_sType){
	return p_sType.compare("GameState") == 0;
}