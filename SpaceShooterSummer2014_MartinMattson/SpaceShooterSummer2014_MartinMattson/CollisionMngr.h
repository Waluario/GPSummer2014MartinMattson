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

	static Hitbox* NewHitbox(float p_fSize, GameObject* p_xpGameObject);
	static void DeleteHitbox(Hitbox* p_xpHitbox);

private:
	static std::vector<Hitbox*> m_xpaHitboxes;
};