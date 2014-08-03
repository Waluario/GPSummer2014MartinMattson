// LevelManager.h //

#pragma once

#include <map>

class GameObject;
class SceneObject;

class LevelItem;

class LevelMngr {
public:
	LevelMngr(std::string p_sPath);
	~LevelMngr();

	static SceneObject* LoadFromFile(std::string p_sFile, int p_iSceneNum); // Loads the level data from a file

	static void Update(SceneObject *p_xpScene, float p_fDTime); // Updates the Level Manager

	static std::vector<float> Check(float p_fDTime); // Checks if there are any game objects that should be added to the active scene

	static void Build(SceneObject *p_xpScene, std::vector<float> p_faLevel); // Builds new Game Objects

	static void Clear(); // Clears the Current Level Cevtor

	static float GetTime(); // Returns the Level TIme
	static void SetTime(float p_fLevelTime); // Sets the Level TIme

private:
	static float m_fTimePassed, // How much time has passed in-game
		m_fLevelTime;

	static std::string m_sPath; // The File Path tath the Level be loaded from

	static std::vector<LevelItem*> m_xpaLevel; // Holds the Level data right before it's time to use it
};