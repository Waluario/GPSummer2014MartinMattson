// ScoreMngr.cpp //

#include "ScoreMngr.h"

int ScoreMngr::m_iScore;
int ScoreMngr::m_iHiScore;
int ScoreMngr::m_iNextScore;
int ScoreMngr::m_iNextScoreUp;
int ScoreMngr::m_iLifes;
int ScoreMngr::m_iStartLifes;

ScoreMngr::ScoreMngr(int p_iScore, int p_iHiScore, int p_iNextScore, int p_iNextScoreUp, int p_iLifes){
	// Sets all of the preset valies
	m_iScore = p_iScore;
	m_iHiScore = p_iHiScore;
	m_iNextScore = p_iNextScore;
	m_iNextScoreUp = p_iNextScoreUp;
	m_iLifes = p_iLifes;
	m_iStartLifes = p_iLifes;;
}

ScoreMngr::~ScoreMngr(){

}

int ScoreMngr::GetScore(){
	// Returns Score
	return m_iScore;
}

void ScoreMngr::SetScore(int p_iScore){
	// Sets Score
	m_iScore = p_iScore;
}

void ScoreMngr::PlusScore(int p_iScore, bool p_bModifier){
	// Increases score by a set amount, the Score Modifier can be used if one so wishes
	m_iScore += (p_iScore + p_bModifier * GetScoreModifier());
}

int ScoreMngr::GetHiScore(){
	// Returns HiScore
	return m_iHiScore;
}

void ScoreMngr::SetHiScore(int p_iHiScore){
	// Sets HiScore
	m_iHiScore = p_iHiScore;
}

int ScoreMngr::GetNextScore(){
	// Returns NextScore
	return m_iNextScore;
}

void ScoreMngr::SetNextScore(int p_iNextScore){
	// Sets NextScore
	m_iNextScore = p_iNextScore;
}

void ScoreMngr::PlusNextScore(){
	// Increases NextScore with a certain amount based on the current NextScore and NextScoreUp
	m_iNextScore += (m_iNextScore + m_iNextScoreUp);
}

int ScoreMngr::GetNextScoreUp(){
	// Returns NextScoreUp
	return m_iNextScoreUp;
}

void ScoreMngr::SetNextScoreUp(int p_iNextScore){
	// Sets NextScoreUp
	m_iNextScoreUp = p_iNextScore;
}

int ScoreMngr::GetLifes(){
	// Returns Lifes
	return m_iLifes;
}

void ScoreMngr::SetLifes(int p_iLifes){
	// Sets Lifes
	m_iLifes = p_iLifes;
}

void ScoreMngr::MinusLife(){
	// Player Life is descreased by 1
	m_iLifes--;
}

void ScoreMngr::PlusLife(){
	// Player Life is increased by 1
	m_iLifes++;
}

int ScoreMngr::GetStartLifes(){
	// Returns StartLifes
	return m_iStartLifes;
}

void ScoreMngr::SetStartLifes(int p_iStartLifes){
	// Sets StartLifes
	m_iStartLifes = p_iStartLifes;
}

float ScoreMngr::GetScoreModifier(){
	// The Score modifier value is based on the StartLifes. with this formula below the player will gain 1x the normal score with 2 lifes, 1.5x with 0 abd .25x with 5
	// 0 StartLifes = 1.5x
	// 1 StartLife = 1.25x
	// 2 StartLifes = 1x
	// 3 StartLifes = .75x
	// 4 StartLifes = .5x
	// 5 StartLifes = .25x
	return (1.5f - (.25f * GetStartLifes()));
}