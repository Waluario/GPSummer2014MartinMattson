// GameState.cpp //

#include "GameState.h"

#include "CollisionMngr.h"
#include "KeybMngr.h"
#include "LevelMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "StateMngr.h"

#include "EnemyObject0.h"
#include "EnemyObject1.h"
#include "EnemyObject2.h"
#include "HUDObject.h"
#include "OptionsObject.h"
#include "PlayerObject.h"
#include "SceneObject.h"

#include "MenuItem.h"
#include "OptionsItem0.h"
#include "TextItem.h"

#include <iostream>

GameState::GameState(float p_fStageTimeStart){
	m_fStageTimeStart = p_fStageTimeStart;

	m_bpPlaying = new bool(true);
}

GameState::~GameState(){
	delete m_bpPlaying;
	m_bpPlaying = NULL;
}

bool GameState::Enter(){
	m_xpScene = LevelMngr::LoadFromFile("Level_0.txt", 1);
	m_xpScene->AddChild(new HUDObject());
	m_xpScene->AddChild(new PlayerObject(sf::Vector2f(400, 500), 5, 256.0f));

	m_fStageTimeStart = LevelMngr::GetTime();

	m_xpPause = new SceneObject(2);
	std::vector<MenuItem*> _xpaMenu;
	_xpaMenu.push_back(new TextItem("-Game Paused-", sf::Vector2f(0, 0)));
	_xpaMenu.push_back(new OptionsItem0(sf::Vector2f(0, 0), "Resume", *m_bpPlaying, 0));
	_xpaMenu.push_back(new MenuItem("GameOverState", "Main Menu", sf::Vector2f(0, 0)));
	m_xpPause->AddChild(new OptionsObject(sf::Vector2f(0, 0), _xpaMenu));

	for (int i = _xpaMenu.size() - 1; i >= 0; i--){
		_xpaMenu[i] = NULL;
	}

	*m_bpPlaying = true;

	ScoreMngr::SetScore(0);
	ScoreMngr::SetLifes(ScoreMngr::GetStartLifes());
	ScoreMngr::SetNextScore(2000);
	ScoreMngr::SetNextScoreUp(500);
	ScoreMngr::SetSpawn(true);

	MusicMngr::Stop();
	MusicMngr::Play("Bgm_Stage", 10);

	m_fStageTime = m_fStageTimeStart;

	return true;
}

void GameState::Exit(){
	delete m_xpScene;
	m_xpScene = NULL;
	
	LevelMngr::Clear();
	CollisionMngr::ClearList(0);

	delete m_xpPause;
	m_xpPause = NULL;

	MusicMngr::Stop();
}

bool GameState::Update(float p_fDtime){
	if (*m_bpPlaying){
		m_xpScene->OnUpdate();

		CollisionMngr::CheckForCollisions(0);

		m_fStageTime -= p_fDtime * ScoreMngr::GetSpawn();

		if (m_fStageTime <= 0.f){
			StateMngr::SetNextState("GameOverState");
			StateMngr::ChangeState();
		}

		LevelMngr::Update(m_xpScene, p_fDtime);

		if (KeybMngr::GetButtonPressedOnce(13)){
			*m_bpPlaying = false;
		}
	}
	else {
		m_xpPause->OnUpdate();

		if (KeybMngr::GetButtonPressedOnce(13)){
			*m_bpPlaying = true;
		}
	}

	return true;
}

void GameState::Draw(){
	if (*m_bpPlaying){
		m_xpScene->OnDraw();
	}
	else {
		m_xpPause->OnDraw();
	}
}

std::string GameState::Next(){
	return m_sNext;
}

bool GameState::IsType(const std::string &p_sType){
	return p_sType.compare("GameState") == 0;
}