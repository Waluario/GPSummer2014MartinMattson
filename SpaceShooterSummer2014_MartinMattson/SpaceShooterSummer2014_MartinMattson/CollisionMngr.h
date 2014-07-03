// CollisionMngr.h //

#pragma once

#include <vector>

class GameObject;
class Hitbox;

class CollisionMngr {
public:
	CollisionMngr();
	~CollisionMngr();

	static void NewList();

	static void CheckForCollisions();

	static Hitbox* NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize, int p_iList);
	static void DeleteHitbox(Hitbox* p_xpHitbox);

private:
	static std::vector<std::vector<Hitbox*>> m_xpaHitboxes;
};