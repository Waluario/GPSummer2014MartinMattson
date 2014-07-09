// ScoreMngr.cpp //

#include "ScoreMngr.h"

int ScoreMngr::m_iScore;
int ScoreMngr::m_iHiScore;
int ScoreMngr::m_iNextScore;
int ScoreMngr::m_iNextScoreUp;
int ScoreMngr::m_iLifes;
int ScoreMngr::m_iStartLifes;

ScoreMngr::ScoreMngr(int p_iScore, int p_iHiScore, int p_iNextScore, int p_iNextScoreUp, int p_iLifes){
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
	return m_iScore;
}

void ScoreMngr::SetScore(int p_iScore){
	m_iScore = p_iScore;
}

void ScoreMngr::PlusScore(int p_iScore){
	m_iScore += p_iScore;
}

int ScoreMngr::GetHiScore(){
	return m_iHiScore;
}

void ScoreMngr::SetHiScore(int p_iHiScore){
	m_iHiScore = p_iHiScore;
}

int ScoreMngr::GetNextScore(){
	return m_iNextScore;
}

void ScoreMngr::SetNextScore(int p_iNextScore){
	m_iNextScore = p_iNextScore;
}

void ScoreMngr::PlusNextScore(){
	m_iNextScore += (m_iNextScore + m_iNextScoreUp);
}

int ScoreMngr::GetNextScoreUp(){
	return m_iNextScoreUp;
}

void ScoreMngr::SetNextScoreUp(int p_iNextScore){
	m_iNextScoreUp = p_iNextScore;
}

int ScoreMngr::GetLifes(){
	return m_iLifes;
}

void ScoreMngr::SetLifes(int p_iLifes){
	m_iLifes = p_iLifes;
}

void ScoreMngr::MinusLife(){
	m_iLifes--;
}

void ScoreMngr::PlusLife(){
	m_iLifes++;
}

int ScoreMngr::GetStartLifes(){
	return m_iStartLifes;
}

void ScoreMngr::SetStartLifes(int p_iStartLifes){
	m_iStartLifes = p_iStartLifes;
}

float ScoreMngr::GetScoreModifier(){
	return (1.5f - (.25f * GetStartLifes()));
}