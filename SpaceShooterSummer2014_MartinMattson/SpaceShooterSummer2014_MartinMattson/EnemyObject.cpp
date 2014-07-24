// EnemyObject.cpp //

#include "EnemyObject.h"

#include "ScoreObject.h"

#include "TimeMngr.h"

EnemyObject::EnemyObject(){
	AddTag("Enemy");
}

EnemyObject::~EnemyObject(){

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
	for (int i = 0; i < m_iScore; i++){
		GetParent()->AddChild(new ScoreObject(getPosition()));
	}
}