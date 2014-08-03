// LevelItem.h //

#pragma once

class GameObject;

class LevelItem {
public:
	LevelItem(float p_fTime, GameObject *p_xpGameObject);
	~LevelItem();

	float GetTime();
	void SetTime(float p_fTime);

	GameObject* GetGameObject();
	void SetGameObject(GameObject *p_xpGameObject);

private:
	float m_fTime;

	GameObject *m_xpGameObject;
};