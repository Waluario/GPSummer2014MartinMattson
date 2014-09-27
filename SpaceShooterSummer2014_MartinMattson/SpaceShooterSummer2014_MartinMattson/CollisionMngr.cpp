// CollisionMngr.cpp //

#include "CollisionMngr.h"

#include "GameObject.h"
#include "Hitbox.h"

#include <iostream>

std::vector<std::vector<Hitbox*>> CollisionMngr::m_xpaHitboxes;

CollisionMngr::CollisionMngr(){

}

CollisionMngr::~CollisionMngr(){
	for (int i = 0; i < m_xpaHitboxes.size(); i++){
		ClearList(i);
	}
}

void CollisionMngr::NewList(){
	// Clrreates a new empty list of Hitboces
	std::vector<Hitbox*> _xpaHitboxes;

	m_xpaHitboxes.push_back(_xpaHitboxes);
}

void CollisionMngr::CheckForCollisions(){
	// checks all of the lists for collisions
	for (int i = 0; i < m_xpaHitboxes.size(); i++){
		// Goes through each and every single hitbox against each other to see if they collide
		for (int ii = 0; ii < m_xpaHitboxes[i].size(); ii++){
			for (int iii = 0; iii < m_xpaHitboxes[i].size(); iii++){
				// Checks so that the hitbox does not collide with itself
				if (m_xpaHitboxes[i][ii] != m_xpaHitboxes[i][iii]){
					if (m_xpaHitboxes[i][ii]->Overlap(m_xpaHitboxes[i][iii])){
						// If the two hitboxes overlap one of the hitboxes will call it's gameObjects OnCollision method
						m_xpaHitboxes[i][ii]->GetGameObject()->OnCollision(m_xpaHitboxes[i][iii]->GetGameObject()); 
					}
				}
			}
		}
	}
}

void CollisionMngr::CheckForCollisions(int p_iList){
	// checks the requested loist of hitboxes

	// Checls if the number is valid
	if (p_iList < m_xpaHitboxes.size()){
		// Goes through each and every single hitbox against each other to see if they collide
		for (int i = 0; i < m_xpaHitboxes[p_iList].size(); i++){
			for (int ii = 0; ii < m_xpaHitboxes[p_iList].size(); ii++){
				// Checks so that the hitbox does not collide with itself
				if (m_xpaHitboxes[p_iList][i] != m_xpaHitboxes[p_iList][ii]){
					if (m_xpaHitboxes[p_iList][i]->Overlap(m_xpaHitboxes[p_iList][ii])){
						// If the two hitboxes overlap one of the hitboxes will call it's gameObjects OnCollision method
						if (m_xpaHitboxes[p_iList][i]->GetGameObject()->GetHitbox() == m_xpaHitboxes[p_iList][i] && m_xpaHitboxes[p_iList][ii]->GetGameObject()->GetHitbox() == m_xpaHitboxes[p_iList][ii]){
							m_xpaHitboxes[p_iList][i]->GetGameObject()->OnCollision(m_xpaHitboxes[p_iList][ii]->GetGameObject());
						}
					}
				}
			}
		}
	}
}

Hitbox* CollisionMngr::NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize, int p_iList){
	// Creates a new hitbox and adds it to the list of choice
	m_xpaHitboxes[p_iList].push_back(new Hitbox(p_xpGameObject, p_vPosition, p_fSize));

	return m_xpaHitboxes[p_iList][m_xpaHitboxes[p_iList].size() - 1];
}

void CollisionMngr::DeleteHitbox(Hitbox* p_xpHitbox){
	// Deletes the hitbox of choice
	for (int i = 0; i < m_xpaHitboxes.size(); i++){
		for (int ii = 0; ii < m_xpaHitboxes[i].size(); ii++){
			if (m_xpaHitboxes[i][ii] == p_xpHitbox){
				delete m_xpaHitboxes[i][ii];
				m_xpaHitboxes[i][ii] = NULL;
				m_xpaHitboxes[i].erase(m_xpaHitboxes[i].begin() + ii);
			}
		}
	}
}

void CollisionMngr::ClearList(int p_iList){
	if (!m_xpaHitboxes.empty()){
		if (!m_xpaHitboxes[p_iList].empty()){
			for (int i = m_xpaHitboxes[p_iList].size() - 1; i >= 0; i--){
				delete m_xpaHitboxes[p_iList][i];
				m_xpaHitboxes[p_iList][i] = NULL;
				m_xpaHitboxes[p_iList].erase(m_xpaHitboxes[p_iList].begin() + i);
			}
		}
	}
}