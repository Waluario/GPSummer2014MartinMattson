// StateMngr.cpp //

#include "StateMngr.h"

#include "State.h"

std::vector<State*> StateMngr::m_cpaStates;
State *StateMngr::m_cpCurrent;

StateMngr::StateMngr(){
	m_cpCurrent = NULL;
}

StateMngr::~StateMngr(){
	for (int i = 0; i < m_cpaStates.size(); i++){
		delete m_cpaStates[i];
		m_cpaStates[i] = NULL;
	}
	
}

void StateMngr::Add(State *p_cpState){
	m_cpaStates.push_back(p_cpState);
}

void StateMngr::Update(float p_fDtime){
	if (m_cpaStates.empty()){
		return;
	}

	if (m_cpCurrent != NULL){
		if (!m_cpCurrent->Update(p_fDtime)){
			ChangeState();
		}
	}
}

void StateMngr::SetState(const std::string &p_skrState){
	for (unsigned int i = 0; i < m_cpaStates.size(); i++){
		if (m_cpaStates[i]->IsType(p_skrState)){
			m_cpCurrent = m_cpaStates[i];
			m_cpCurrent->Enter();
			return;
		}
	}
}

void StateMngr::ChangeState(){
	std::string l_vNext = m_cpCurrent->Next();
	if (m_cpCurrent != NULL){
		m_cpCurrent->Exit();
		m_cpCurrent = NULL;
	}

	for (unsigned int i = 0; i < m_cpaStates.size(); i++){
		if (m_cpaStates[i]->IsType(l_vNext)){
			m_cpCurrent = m_cpaStates[i];
			m_cpCurrent->Enter();
			return;
		}
	}
}

void StateMngr::Draw(){
	if (m_cpCurrent == NULL){
		return;
	}

	m_cpCurrent->Draw();
}

void StateMngr::Quit(){
	m_cpCurrent = NULL;
}

bool StateMngr::IsRunning(){
	return m_cpCurrent != NULL;
}
