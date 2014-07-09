// GameObjectMngr.h //

#pragma once

#include <vector>

class GameObject;

class GameObjectMngr {
public:
	GameObjectMngr();
	~GameObjectMngr();

	static void AddGameObject(GameObject *p_xpGameObject);
	static void RemoveGameObject(GameObject *p_xpGameObject);

	static GameObject* GetGameObject(std::string p_sTag);

private:
	static std::vector<GameObject*> m_xpaGameObjects;
};