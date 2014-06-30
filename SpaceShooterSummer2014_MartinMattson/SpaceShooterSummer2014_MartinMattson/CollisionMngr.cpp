// CollisionMngr.cpp //

#include "CollisionMngr.h"

#include "GameObject.h"
#include "Hitbox.h"

std::vector<Hitbox*> CollisionMngr::m_xpaHitboxes;

CollisionMngr::CollisionMngr(){

}

CollisionMngr::~CollisionMngr(){

}

void CollisionMngr::CheckForCollisions(){
	for (int i = 0; i < m_xpaHitboxes.size(); i++){
		for (int ii = 0; ii < m_xpaHitboxes.size(); ii++){
			if (m_xpaHitboxes[i]->GetGameObject() != m_xpaHitboxes[ii]->GetGameObject()){
				if (m_xpaHitboxes[i]->Overlap(m_xpaHitboxes[ii])){
					m_xpaHitboxes[i]->GetGameObject()->OnCollision(m_xpaHitboxes[ii]->GetGameObject());
				}
			}
		}
	}
}

Hitbox* CollisionMngr::NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize){
	m_xpaHitboxes.push_back(new Hitbox(p_xpGameObject, p_vPosition, p_fSize));

	return m_xpaHitboxes[m_xpaHitboxes.size() - 1];
}

void CollisionMngr::DeleteHitbox(Hitbox* p_xpHitbox){
	for (int i = 0; i < m_xpaHitboxes.size(); i++){
		if (m_xpaHitboxes[i] == p_xpHitbox){
			delete m_xpaHitboxes[i];
			m_xpaHitboxes[i] = NULL;
			m_xpaHitboxes.erase(m_xpaHitboxes.begin() + i);
		}
	}
}