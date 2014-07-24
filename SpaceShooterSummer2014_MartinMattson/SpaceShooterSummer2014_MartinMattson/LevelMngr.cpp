// LevelMngr.cpp //

#include "LevelMngr.h"

#include "EnemyObject0.h"
#include "EnemyObject1.h"
#include "GameObject.h"
#include "SceneObject.h"

#include <fstream>
#include <sstream>

float LevelMngr::m_fTimePassed;

std::string LevelMngr::m_sPath;

std::vector<SceneObject*> *LevelMngr::m_xpaScenes;

std::map<float, GameObject*> LevelMngr::m_xpaLevel;

LevelMngr::LevelMngr(std::string p_sPath){
	m_sPath = p_sPath;
}

LevelMngr::~LevelMngr(){

}

SceneObject* LevelMngr::LoadFromFile(std::string p_sFile){
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

		if (_sType.compare("0") == 0){
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

			m_xpaLevel[_fTime] = new EnemyObject0(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy), sf::Vector2f(_fDeacx, _fDeacy));
		}

		if (_sType.compare("1") == 0){
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

			m_xpaLevel[_fTime] = new EnemyObject1(sf::Vector2f(_fPosx, _fPosy), sf::Vector2f(_fSpdx, _fSpdy), sf::Vector2f(_fFirex, _fFirey));
		}
	}
}

void LevelMngr::Update(SceneObject *p_xpScene, float p_fDTime){
	Build(p_xpScene, Check(p_fDTime));
}

std::vector<float> LevelMngr::Check(float p_fDTime){
	m_fTimePassed += p_fDTime;

	std::vector<float> _faLevel;

	for (float f = 0.f; f < m_xpaLevel.size() && f < p_fDTime; f += 0.01f){
		if (m_xpaLevel.find(m_fTimePassed + f) != m_xpaLevel.end()){
			_faLevel.push_back(m_fTimePassed + f);
		}
	}

	return _faLevel;
}

void LevelMngr::Build(SceneObject *p_xpScene, std::vector<float> p_faLevel){
	if (!p_faLevel.empty()){
		for (int i = 0; i < p_faLevel.size(); i++){
			m_xpaLevel[p_faLevel[i]]->OnCreate();
			p_xpScene->AddChild(m_xpaLevel[p_faLevel[i]]);
		}
	}
}

void LevelMngr::Clear(){
	m_xpaLevel.clear();
}