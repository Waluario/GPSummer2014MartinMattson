// EnemyObject.cpp //

#include "EnemyObject.h"

#include "ScoreObject.h"

#include "DrawMngr.h"
#include "ScoreMngr.h"
#include "TimeMngr.h"

EnemyObject::EnemyObject(){
	AddTag("Enemy");
}

EnemyObject::~EnemyObject(){
	
}

bool EnemyObject::OnScreen(){
	if (getPosition().x > DrawMngr::GetScreen()->getDefaultView().getSize().x * 2 || getPosition().x < -DrawMngr::GetScreen()->getDefaultView().getSize().x){
		return false;
	}

	if (getPosition().y > DrawMngr::GetScreen()->getDefaultView().getSize().y * 2 || getPosition().y < -DrawMngr::GetScreen()->getDefaultView().getSize().y){
		return false;
	}

	return true;
}

bool EnemyObject::CanFire(){
	if (m_iBulletAmmo > 0){

		if (m_fFireRate <= 0.f){
			m_iBulletAmmo--;
			m_fFireRate = m_fFireRateMax;

			return true;
		}

		m_fFireRate -= TimeMngr::GetDtime();
	}

	return false;
}

void EnemyObject::DropScore(){
	if (ScoreMngr::GetSpawn()){
		for (int i = 0; i < m_iScore; i++){
			GetParent()->AddChild(new ScoreObject(getPosition()));
		}
	}
}