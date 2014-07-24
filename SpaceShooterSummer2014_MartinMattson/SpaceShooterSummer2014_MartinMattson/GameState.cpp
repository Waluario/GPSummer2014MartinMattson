// GameState.cpp //

#include "GameState.h"

#include "CollisionMngr.h"
#include "MusicMngr.h"
#include "ScoreMngr.h"
#include "StateMngr.h"

#include "EnemyObject0.h"
#include "EnemyObject1.h"
#include "HUDObject.h"
#include "PlayerObject.h"
#include "SceneObject.h"

#include <iostream>

GameState::GameState(float p_fStageTimeStart){
	m_fStageTimeStart = p_fStageTimeStart;

	m_xpScene = new SceneObject(1);
}

GameState::~GameState(){

}

bool GameState::Enter(){
	m_xpScene->AddChild(new HUDObject());
	m_xpScene->AddChild(new PlayerObject(sf::Vector2f(400, 500), 5, 256.0f));
	/*m_xpScene->AddChild(new EnemyObject0(sf::Vector2f(200, 0), sf::Vector2f(80.f, 256.f), sf::Vector2f(0, 128.f)));
	m_xpScene->AddChild(new EnemyObject0(sf::Vector2f(600, 0), sf::Vector2f(-80.f, 256.f), sf::Vector2f(0, 128.f)));

	for (int i = 0; i < 4; i++){
		m_xpScene->AddChild(new EnemyObject1(sf::Vector2f(800 + 100 * i, 150), sf::Vector2f(-180.f, 0)));
	}

	for (int i = 0; i < 4; i++){
		m_xpScene->AddChild(new EnemyObject1(sf::Vector2f(0 - 100 * i, 300), sf::Vector2f(180.f, 0)));
	}*/

	ScoreMngr::SetScore(0);
	ScoreMngr::SetLifes(ScoreMngr::GetStartLifes());

	MusicMngr::Play("Bgm00");

	m_fStageTime = m_fStageTimeStart;

	return true;
}

void GameState::Exit(){
	std::cout << "\n:: " << m_xpScene->GetChildren().size() << " ::\n";
	for (int i = m_xpScene->GetChildren().size() - 1; i >= 0; i--){
		std::cout << i << " : " << m_xpScene->GetChildren()[i]->CanDelete() << " : ";
		m_xpScene->GetChildren()[i]->WriteTags();
		std::cout << std::endl;

		if (m_xpScene->GetChildren()[i]->HasTag("Player")){
			std::cout << std::endl;
		}

		delete m_xpScene->GetChildren()[i];
	}

	/*delete m_xpScene;
	m_xpScene = NULL;*/

	//MusicMngr::Pause();
	MusicMngr::Stop();
}

bool GameState::Update(float p_fDtime){
	m_xpScene->OnUpdate();

	CollisionMngr::CheckForCollisions();

	m_fStageTime -= p_fDtime;

	if (m_fStageTime <= 0.f){
		StateMngr::SetNextState("MenuState");
		StateMngr::ChangeState();
	}

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