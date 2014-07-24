// GameObjectMngr.h //

#pragma once

#include <vector>

class GameObject;

class GameObjectMngr {
public:
	GameObjectMngr();
	~GameObjectMngr();

	static void AddGameObject(GameObject *p_xpGameObject); // Adds a game object to the vector
	static void RemoveGameObject(GameObject *p_xpGameObject); // Deletes and clears a game object from the vector
	static void ClearGameObject(GameObject *p_xpGameObject); // Clears the game object without deleting it

	static GameObject* GetGameObject(std::string p_sTag); // returns the first game object with a specific tag

	static std::vector<GameObject*> GetVector(); // returns the netire vector of game objects

private:
	static std::vector<GameObject*> m_xpaGameObjects;
};