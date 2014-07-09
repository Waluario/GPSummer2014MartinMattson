// GameObjectMngr.cpp //

#include "GameObjectMngr.h"

#include "GameObject.h"

std::vector<GameObject*> GameObjectMngr::m_xpaGameObjects;

GameObjectMngr::GameObjectMngr(){

}

GameObjectMngr::~GameObjectMngr(){
	for (int i = m_xpaGameObjects.size() - 1; i >= 0; i--){
		delete m_xpaGameObjects[i];
		m_xpaGameObjects[i] = NULL;
		m_xpaGameObjects.erase(m_xpaGameObjects.begin() + i);
	}
}

void GameObjectMngr::AddGameObject(GameObject *p_xpGameObject){
	m_xpaGameObjects.push_back(p_xpGameObject);
}

void GameObjectMngr::RemoveGameObject(GameObject *p_xpGameObject){
	for (int i = 0; i < m_xpaGameObjects.size(); i++){
		if (m_xpaGameObjects[i] == p_xpGameObject){
			delete m_xpaGameObjects[i];
			m_xpaGameObjects[i] = NULL;
			m_xpaGameObjects.erase(m_xpaGameObjects.begin() + i);
		}
	}
}

GameObject* GameObjectMngr::GetGameObject(std::string p_sTag){
	for (int i = 0; i < m_xpaGameObjects.size(); i++){
		if (m_xpaGameObjects[i]->HasTag(p_sTag)){
			return m_xpaGameObjects[i];
		}
	}

	return NULL;
}