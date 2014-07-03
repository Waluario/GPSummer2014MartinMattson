// GameState.cpp //

#include "GameState.h"

#include "CollisionMngr.h"
#include "EnemyObject0.h"
#include "PlayerObject.h"
#include "SceneObject.h"

GameState::GameState(){

}

GameState::~GameState(){

}

bool GameState::Enter(){
	m_xpScene = new SceneObject();

	m_xpScene->AddChild(new PlayerObject(sf::Vector2f(0, 0), 5, 256.0f));
	m_xpScene->AddChild(new EnemyObject0(sf::Vector2f(0, 0), 64.f, 256.f, 0.0001, 20));

	return true;
}

void GameState::Exit(){
	delete m_xpScene;
	m_xpScene = NULL;
}

bool GameState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	CollisionMngr::CheckForCollisions();

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