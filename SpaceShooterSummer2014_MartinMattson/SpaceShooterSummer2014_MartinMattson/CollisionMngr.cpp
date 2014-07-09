// CollisionMngr.cpp //

#include "CollisionMngr.h"

#include "GameObject.h"
#include "Hitbox.h"

std::vector<std::vector<Hitbox*>> CollisionMngr::m_xpaHitboxes;

CollisionMngr::CollisionMngr(){

}

CollisionMngr::~CollisionMngr(){

}

void CollisionMngr::NewList(){
	std::vector<Hitbox*> _xpaHitboxes;

	m_xpaHitboxes.push_back(_xpaHitboxes);
}

void CollisionMngr::CheckForCollisions(){
	for (int i = 0; i < m_xpaHitboxes[0].size(); i++){
		for (int ii = 0; ii < m_xpaHitboxes[0].size(); ii++){
			if (m_xpaHitboxes[0][i] != m_xpaHitboxes[0][ii]){
				if (m_xpaHitboxes[0][i]->Overlap(m_xpaHitboxes[0][ii])){
					m_xpaHitboxes[0][i]->GetGameObject()->OnCollision(m_xpaHitboxes[0][ii]->GetGameObject());
				}
			}
		}
	}
}

Hitbox* CollisionMngr::NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize, int p_iList){
	m_xpaHitboxes[p_iList].push_back(new Hitbox(p_xpGameObject, p_vPosition, p_fSize));

	return m_xpaHitboxes[p_iList][m_xpaHitboxes[p_iList].size() - 1];
}

void CollisionMngr::DeleteHitbox(Hitbox* p_xpHitbox){
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