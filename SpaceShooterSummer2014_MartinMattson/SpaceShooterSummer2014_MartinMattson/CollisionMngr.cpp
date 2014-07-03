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
	/*for (int i = 0; i < m_xpaHitboxes.size(); i++){
		for (int ii = 0; ii < m_xpaHitboxes.size(); ii++){
			if (i != ii){
				for (int iii = 0; iii < m_xpaHitboxes[i].size(); iii++){
					for (int i4 = 0; i4 < m_xpaHitboxes[ii].size(); i4++){
						if (m_xpaHitboxes[i][iii]->Overlap(m_xpaHitboxes[ii][i4])){
							m_xpaHitboxes[i][iii]->GetGameObject()->OnCollision(m_xpaHitboxes[ii][i4]->GetGameObject());
						}
					}
				}
			}
		}
	}*/

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