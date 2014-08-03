// GameState.cpp //

#include "GameState.h"

#include "CollisionMngr.h"
#include "LevelMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "StateMngr.h"

#include "EnemyObject0.h"
#include "EnemyObject1.h"
#include "EnemyObject2.h"
#include "HUDObject.h"
#include "PlayerObject.h"
#include "SceneObject.h"

#include <iostream>

GameState::GameState(float p_fStageTimeStart){
	m_fStageTimeStart = p_fStageTimeStart;
}

GameState::~GameState(){

}

bool GameState::Enter(){
	m_xpScene = LevelMngr::LoadFromFile("Level_0.txt", 1);
	m_xpScene->AddChild(new HUDObject());
	m_xpScene->AddChild(new PlayerObject(sf::Vector2f(400, 500), 5, 256.0f));

	m_fStageTimeStart = LevelMngr::GetTime();

	ScoreMngr::SetScore(0);
	ScoreMngr::SetLifes(ScoreMngr::GetStartLifes());
	ScoreMngr::SetSpawn(true);

	MusicMngr::Play("Bgm00", 0);

	m_fStageTime = m_fStageTimeStart;

	return true;
}

void GameState::Exit(){
	delete m_xpScene;
	m_xpScene = NULL;
	
	LevelMngr::Clear();
	CollisionMngr::ClearList(0);

	MusicMngr::Stop();
}

bool GameState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	CollisionMngr::CheckForCollisions(0);

	m_fStageTime -= p_fDtime * ScoreMngr::GetSpawn();

	if (m_fStageTime <= 0.f){
		StateMngr::SetNextState("GameOverState");
		StateMngr::ChangeState();
	}

	LevelMngr::Update(m_xpScene, p_fDtime);

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