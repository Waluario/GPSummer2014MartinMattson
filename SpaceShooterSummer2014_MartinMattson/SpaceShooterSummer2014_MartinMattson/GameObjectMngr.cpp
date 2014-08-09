// GameObjectMngr.cpp //

#include "GameObjectMngr.h"

#include "GameObject.h"

std::vector<GameObject*> GameObjectMngr::m_xpaGameObjects;

GameObjectMngr::GameObjectMngr(){

}

GameObjectMngr::~GameObjectMngr(){
	// Deletes all game objects. The game objects are not cleared since the game objects take care of that by themsevles
	for (int i = m_xpaGameObjects.size() - 1; i >= 0; i--){
		if (i < m_xpaGameObjects.size()){
			delete m_xpaGameObjects[i];
		}
	}
}

void GameObjectMngr::AddGameObject(GameObject *p_xpGameObject){
	// Adds a game object to the vector. Nothing more to it
	m_xpaGameObjects.push_back(p_xpGameObject);
}

void GameObjectMngr::RemoveGameObject(GameObject *p_xpGameObject){
	// Removes a game object and clears up the spot in the vector
	for (int i = 0; i < m_xpaGameObjects.size(); i++){
		if (m_xpaGameObjects[i] == p_xpGameObject){
			delete m_xpaGameObjects[i];
			m_xpaGameObjects[i] = NULL;
			m_xpaGameObjects.erase(m_xpaGameObjects.begin() + i);
		}
	}
}

void GameObjectMngr::ClearGameObject(GameObject *p_xpGameObject){
	// clears up a spot in the vector
	for (int i = m_xpaGameObjects.size() - 1; i >= 0; i--){
		if (m_xpaGameObjects[i] == p_xpGameObject){
			m_xpaGameObjects[i] = NULL;
			m_xpaGameObjects.erase(m_xpaGameObjects.begin() + i);
		}
	}
}

GameObject* GameObjectMngr::GetGameObject(std::string p_sTag){
	// Returns a game object with a specific tag
	for (int i = 0; i < m_xpaGameObjects.size(); i++){
		if (m_xpaGameObjects[i] != NULL){
			if (m_xpaGameObjects[i]->HasTag(p_sTag)){
				return m_xpaGameObjects[i];
			}
		}
	}

	return NULL;
}

std::vector<GameObject*> GameObjectMngr::GetVector(){
	// Returns the vector of a game object
	return m_xpaGameObjects;
}