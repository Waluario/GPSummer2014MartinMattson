// LevelManager.h //

#pragma once

#include <map>

class GameObject;
class SceneObject;

class LevelMngr {
public:
	LevelMngr(std::string p_sPath);
	~LevelMngr();

	SceneObject* LoadFromFile(std::string p_sFile); // Loads the level data from a file

	void Update(SceneObject *p_xpScene, float p_fDTime); // Updates the Level Manager

	std::vector<float> Check(float p_fDTime); // Checks if there are any game objects that should be added to the active scene

	void Build(SceneObject *p_xpScene, std::vector<float> p_faLevel); // Builds new Game Objects

	void Clear(); // Clears the Current Level Cevtor

private:
	static float m_fTimePassed;

	static std::string m_sPath; // The File Path tath the Level be loaded from

	static std::vector<SceneObject*> *m_xpaScenes; // THe basic scenes that all game objects will be added to

	static std::map<float, GameObject*> m_xpaLevel; // Holds the Level data right before it's time to use it
};