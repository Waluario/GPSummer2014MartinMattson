// GameState.cpp //

#include "GameState.h"

GameState::GameState(){

}

GameState::~GameState(){

}

bool GameState::Enter(){
	return true;
}

void GameState::Exit(){

}

bool GameState::Update(float p_fDtime){
	return true;
}

void GameState::Draw(){

}

std::string GameState::Next(){
	return m_sNext;
}

bool GameState::IsType(const std::string &p_sType){
	return p_sType.compare("GameState") == 0;
}