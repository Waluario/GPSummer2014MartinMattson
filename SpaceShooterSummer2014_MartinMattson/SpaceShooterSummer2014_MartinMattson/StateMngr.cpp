// StateMngr.cpp //

#include "StateMngr.h"

#include "State.h"

std::vector<State*> StateMngr::m_cpaStates;
State *StateMngr::m_cpCurrent;

StateMngr::StateMngr(){
	m_cpCurrent = NULL;
}

StateMngr::~StateMngr(){
	// Deletes all states and nulls the pointers
	for (int i = 0; i < m_cpaStates.size(); i++){
		delete m_cpaStates[i];
		m_cpaStates[i] = NULL;
	}
	
}

void StateMngr::Add(State *p_cpState){
	// Adds a new State to the vecor
	m_cpaStates.push_back(p_cpState);
}

void StateMngr::Update(float p_fDtime){
	// CHecka if the Vector is empty or not
	if (m_cpaStates.empty()){
		return;
	}

	// If the current State is null the method is aborted
	if (m_cpCurrent != NULL){
		// Updates the curretn State and changes state if necessary
		if (!m_cpCurrent->Update(p_fDtime)){
			ChangeState();
		}
	}
}

void StateMngr::SetState(const std::string &p_skrState){
	// Goes through the vector one item at a time and then enters a new State
	for (unsigned int i = 0; i < m_cpaStates.size(); i++){
		if (m_cpaStates[i]->IsType(p_skrState)){
			m_cpCurrent = m_cpaStates[i];
			m_cpCurrent->Enter();
			return;
		}
	}
}

void StateMngr::SetNextState(const std::string p_sState){
	// Sets the next state
	m_cpCurrent->m_sNext = p_sState;
}

void StateMngr::ChangeState(){
	std::string l_vNext = m_cpCurrent->Next();

	// Plays the current state's Exit method
	if (m_cpCurrent != NULL){
		m_cpCurrent->Exit();
		m_cpCurrent = NULL;
	}

	// Searches for the next State and Enters it
	for (unsigned int i = 0; i < m_cpaStates.size(); i++){
		if (m_cpaStates[i]->IsType(l_vNext)){
			m_cpCurrent = m_cpaStates[i];
			m_cpCurrent->Enter();
			return;
		}
	}
}

void StateMngr::Draw(){
	// Draws the current state
	if (m_cpCurrent == NULL){
		return;
	}

	m_cpCurrent->Draw();
}

void StateMngr::Quit(){
	// Quits the State Manager and the game
	m_cpCurrent = NULL;
}

bool StateMngr::IsRunning(){
	// Checks if the game is actually running
	return m_cpCurrent != NULL;
}
