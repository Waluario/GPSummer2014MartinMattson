// CollisionMngr.h //

#pragma once

#include <vector>

class GameObject;
class Hitbox;

class CollisionMngr {
public:
	CollisionMngr();
	~CollisionMngr();

	static void CheckForCollisions();

	static Hitbox* NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize);
	static void DeleteHitbox(Hitbox* p_xpHitbox);

private:
	static std::vector<Hitbox*> m_xpaHitboxes;
};