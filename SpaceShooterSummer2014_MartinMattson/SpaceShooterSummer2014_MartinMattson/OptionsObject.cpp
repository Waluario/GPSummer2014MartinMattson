// OptionsObject.cpp //

#include "OptionsObject.h"

#include "MenuItem.h"

#include "OptionsItem0.h"
#include "OptionsItem1.h"

#include "KeybMngr.h"

OptionsObject::OptionsObject(sf::Vector2f p_vPos, std::vector<MenuItem*> p_xpaOptions){
	m_iCurrentChoice = 0;

	m_xpaOptions = p_xpaOptions;

	SetAllPositions(sf::Vector2f(0, 0));
}

OptionsObject::~OptionsObject(){

}

void OptionsObject::SetAllPositions(sf::Vector2f p_vPosition){
	for (int i = 0; i < m_xpaOptions.size(); i++){
		m_xpaOptions[i]->SetPosition(sf::Vector2f(p_vPosition.x, p_vPosition.y + (35.f * i)));
	}
}

void OptionsObject::OnCreate(){

}

void OptionsObject::OnUpdateThis(){
	if (KeybMngr::GetVector()[7]->IsPressedOnce() && m_xpaOptions[m_iCurrentChoice]->CanMovePointer()){
		m_iCurrentChoice--;

		if (m_iCurrentChoice < 0.f){
			m_iCurrentChoice = m_xpaOptions.size() - 1;
		}

		if (m_xpaOptions[m_iCurrentChoice]->IgnoreOption()){
			m_iCurrentChoice--;
		}
	}

	if (KeybMngr::GetVector()[8]->IsPressedOnce() && m_xpaOptions[m_iCurrentChoice]->CanMovePointer()){
		m_iCurrentChoice++;

		if (m_iCurrentChoice >= m_xpaOptions.size()){
			m_iCurrentChoice = 0;
		}

		if (m_xpaOptions[m_iCurrentChoice]->IgnoreOption()){
			m_iCurrentChoice++;
		}
	}

	m_xpaOptions[m_iCurrentChoice]->OnChosen();
}

void OptionsObject::OnDrawThis(){
	for (int i = m_xpaOptions.size() - 1; i >= 0; i--){
		if (m_iCurrentChoice == i){
			m_xpaOptions[i]->OnDrawWhenChosen();
		}
		else {
			m_xpaOptions[i]->OnDraw();
		}
	}
}

void OptionsObject::OnCollision(GameObject *p_xpCollider){

}