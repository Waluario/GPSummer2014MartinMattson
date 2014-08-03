// CollisionMngr.h //

#pragma once

#include <vector>

class GameObject;
class Hitbox;

class CollisionMngr {
public:
	CollisionMngr();
	~CollisionMngr();

	static void NewList(); // Constructs a new list, an item may onlty collide with another item on the same list

	static void CheckForCollisions(); // Checks the collisions in all lists
	static void CheckForCollisions(int p_iList); // Checks for collisions in the expected list

	static Hitbox* NewHitbox(GameObject* p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize, int p_iList); // Creates a new hitbox in the expected list
	static void DeleteHitbox(Hitbox* p_xpHitbox); // Delets the expected Hitbox from the manager
	static void ClearList(int p_iList); // Clears the requested list of hitboxes completely

private:
	static std::vector<std::vector<Hitbox*>> m_xpaHitboxes; // a vector of a vector of hitboxes that allows for there to be severla scenes where differenct hitboxes clash
};