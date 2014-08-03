// LevelMngr.cpp //

#include "LevelMngr.h"

#include "EnemyObject0.h"
#include "EnemyObject1.h"
#include "EnemyObject2.h"
#include "EnemyObject3.h"
#include "EnemyObject4.h"
#include "GameObject.h"
#include "SceneObject.h"

#include "LevelItem.h"

#include "ScoreMngr.h"

#include <fstream>
#include <sstream>
#include <iostream>

float LevelMngr::m_fTimePassed,
LevelMngr::m_fLevelTime;

std::string LevelMngr::m_sPath;

std::vector<LevelItem*> LevelMngr::m_xpaLevel;

LevelMngr::LevelMngr(std::string p_sPath){
	m_sPath = p_sPath;
}

LevelMngr::~LevelMngr(){

}

SceneObject* LevelMngr::LoadFromFile(std::string p_sFile, int p_iSceneNum){
	std::string _sData = m_sPath + p_sFile;

	std::ifstream stream;
	stream.open(_sData.c_str());

	if (!stream.is_open()){
		return false;
	}

	std::string row;
	stream >> row;

	while (!stream.eof()) {
		std::getline(stream, row);

		if (row.length() == 0){
			continue;
		}

		std::stringstream ss(row);

		std::string _sType;

		ss >> _sType;

		if (_sType.compare("#") == 0){
			row = "";
			continue;
		}

		if (_sType.compare("Enemy0") == 0){
			float _fTime,
				_fPosx,
				_fPosy,
				_fSpdx,
				_fSpdy,
				_fDeacx,
				_fDeacy;

			ss >> _fTime;
			ss >> _fPosx;
			ss >> _fPosy;
			ss >> _fSpdx;
			ss >> _fSpdy;
			ss >> _fDeacx;
			ss >> _fDeacy;

			m_xpaLevel.push_back(new LevelItem(_fTime, new EnemyObject0(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy), sf::Vector2f(_fDeacx, _fDeacy))));
		}

		if (_sType.compare("Enemy1") == 0){
			float _fTime,
				_fPosx,
				_fPosy,
				_fSpdx,
				_fSpdy,
				_fFirex,
				_fFirey;

			ss >> _fTime;
			ss >> _fPosx;
			ss >> _fPosy;
			ss >> _fSpdx;
			ss >> _fSpdy;
			ss >> _fFirex;
			ss >> _fFirey;

			m_xpaLevel.push_back(new LevelItem(_fTime, new EnemyObject1(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy), sf::Vector2f(_fFirex, _fFirey))));
		}

		if (_sType.compare("Enemy2") == 0){
			float _fTime,
				_fPosx,
				_fPosy,
				_fSpd;

			ss >> _fTime;
			ss >> _fPosx;
			ss >> _fPosy;
			ss >> _fSpd;

			m_xpaLevel.push_back(new LevelItem(_fTime, new EnemyObject2(sf::Vector2f(_fPosx, _fPosy), _fSpd)));
		}

		if (_sType.compare("Enemy3") == 0){
			float _fTime,
				_fPosx,
				_fPosy,
				_fSpdx,
				_fSpdy;

			ss >> _fTime;
			ss >> _fPosx;
			ss >> _fPosy;
			ss >> _fSpdx;
			ss >> _fSpdy;

			m_xpaLevel.push_back(new LevelItem(_fTime, new EnemyObject3(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy))));
		}

		if (_sType.compare("Enemy4") == 0){
			float _fTime,
				_fPosx,
				_fPosy,
				_fSpdx,
				_fSpdy;

			ss >> _fTime;
			ss >> _fPosx;
			ss >> _fPosy;
			ss >> _fSpdx;
			ss >> _fSpdy;

			m_xpaLevel.push_back(new LevelItem(_fTime, new EnemyObject4(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy))));
		}

		if (_sType.compare("SetTime") == 0){
			float _fTime;

			ss >> _fTime;

			m_fLevelTime = _fTime;
		}
	}

	m_fTimePassed = 0.f;

	return new SceneObject(p_iSceneNum);
}

void LevelMngr::Update(SceneObject *p_xpScene, float p_fDTime){
	if (!m_xpaLevel.empty()){
		for (int i = m_xpaLevel.size() - 1; i >= 0; i--){
			if (m_xpaLevel[i]->GetTime() < m_fTimePassed + p_fDTime){
				m_xpaLevel[i]->GetGameObject()->OnCreate();
				p_xpScene->AddChild(m_xpaLevel[i]->GetGameObject());

				delete m_xpaLevel[i];
				m_xpaLevel[i] = NULL;
				m_xpaLevel.erase(m_xpaLevel.begin() + i);
			}
		}
	}

	m_fTimePassed += p_fDTime * ScoreMngr::GetSpawn();
}

std::vector<float> LevelMngr::Check(float p_fDTime){
	std::vector<float> _faLevel;

	for (int i = 0; i < m_xpaLevel.size(); i++){
		if (m_xpaLevel[i]->GetTime() < m_fTimePassed + p_fDTime){

		}
	}

	m_fTimePassed += p_fDTime;

	return _faLevel;
}

void LevelMngr::Build(SceneObject *p_xpScene, std::vector<float> p_faLevel){
	/*if (!p_faLevel.empty()){
		for (int i = 0; i < p_faLevel.size(); i++){
			m_xpaLevel[p_faLevel[i]]->OnCreate();
			p_xpScene->AddChild(m_xpaLevel[p_faLevel[i]]);
		}
	}*/
}

void LevelMngr::Clear(){
	m_xpaLevel.clear();
}

float LevelMngr::GetTime(){
	return m_fLevelTime;
}

void LevelMngr::SetTime(float p_fLevelTime){
	m_fLevelTime = p_fLevelTime;
}