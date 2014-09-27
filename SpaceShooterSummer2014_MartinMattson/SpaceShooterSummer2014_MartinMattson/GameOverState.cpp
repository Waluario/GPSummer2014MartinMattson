// GameOverState.cpp //

#include "GameOverState.h"

#include "DrawMngr.h"
#include "FontMngr.h"
#include "KeybMngr.h"
#include "ScoreMngr.h"
#include "StateMngr.h"

#include <sstream>

GameOverState::GameOverState(float p_fWaitTimeStart){
	m_fWaitTimeStart = p_fWaitTimeStart;
}

GameOverState::~GameOverState(){
	if (m_xpText != NULL){
		delete m_xpText;
		m_xpText = NULL;
	}

	if (m_xpScoreText != NULL){
		delete m_xpScoreText;
		m_xpScoreText = NULL;
	}

	if (m_xpHiScoreText != NULL){
		delete m_xpHiScoreText;
		m_xpHiScoreText = NULL;
	}

	if (m_xpContinueText != NULL){
		delete m_xpContinueText;
		m_xpContinueText = NULL;
	}
}

bool GameOverState::Enter(){
	if (ScoreMngr::GetLifes() >= 0){
		m_xpText = new sf::Text(sf::String(std::string("Congratulations!")), *FontMngr::GetFont("Arial"));
	}
	else {
		m_xpText = new sf::Text(sf::String(std::string("Game Over")), *FontMngr::GetFont("Arial"));
	}

	m_xpText->setPosition(25, 0);

	m_xpScoreText = new sf::Text(sf::String(std::string("Your Score: " + static_cast<std::ostringstream*>(&(std::ostringstream() << ScoreMngr::GetScore()))->str())), *FontMngr::GetFont("Arial"));
	m_xpScoreText->setPosition(25, 50);

	if (CheckHighScore(ScoreMngr::GetScore(), ScoreMngr::GetHiScore())){
		m_xpHiScoreText = new sf::Text(sf::String(std::string("Best Score: " + static_cast<std::ostringstream*>(&(std::ostringstream() << ScoreMngr::GetHiScore()))->str() + " (NEW)")), *FontMngr::GetFont("Arial"));
		ScoreMngr::WriteHiScore("../rec/High_Score.txt", ScoreMngr::GetHiScore());
	}
	else {
		m_xpHiScoreText = new sf::Text(sf::String(std::string("Best Score: " + static_cast<std::ostringstream*>(&(std::ostringstream() << ScoreMngr::GetHiScore()))->str())), *FontMngr::GetFont("Arial"));
	}

	m_xpHiScoreText->setPosition(25, 75);

	m_xpContinueText = new sf::Text(sf::String(std::string("Press the <Fire> button to continue...")), *FontMngr::GetFont("Arial"));
	m_xpContinueText->setPosition(25, 150);

	m_fWaitTime = m_fWaitTimeStart;

	return true;
}

void GameOverState::Exit(){
	delete m_xpText;
	m_xpText = NULL;

	delete m_xpScoreText;
	m_xpScoreText = NULL;

	delete m_xpHiScoreText;
	m_xpHiScoreText = NULL;

	delete m_xpContinueText;
	m_xpContinueText = NULL;
}

bool GameOverState::Update(float p_fDtime){
	if (KeybMngr::GetButtonPressedOnce(4) && m_fWaitTime <= 0.f){
		StateMngr::SetNextState("MenuState");
		StateMngr::ChangeState();
	}
	
	m_fWaitTime -= p_fDtime;
	
	return true;
}

void GameOverState::Draw(){
	DrawMngr::Draw(m_xpText);
	DrawMngr::Draw(m_xpScoreText);
	DrawMngr::Draw(m_xpHiScoreText);
	DrawMngr::Draw(m_xpContinueText);
}

std::string GameOverState::Next(){
	return m_sNext;
}

bool GameOverState::IsType(const std::string &p_sType){
	return p_sType.compare("GameOverState") == 0;
}

bool GameOverState::CheckHighScore(int p_fNewScore, int p_fOldScore){
	if (p_fNewScore > p_fOldScore){
		ScoreMngr::SetHiScore(p_fNewScore);
		
		return true;
	}

	return false;
}