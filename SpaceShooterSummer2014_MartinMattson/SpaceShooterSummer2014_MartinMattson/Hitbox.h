// Hitbox.h //

#pragma once

class GameObject;

class Hitbox {
public:
	Hitbox(GameObject *p_xpGameObject);
	Hitbox(GameObject *p_xpGameObject, float p_fSize);
	~Hitbox();

	float GetSize();
	void SetSize(float p_f);

	GameObject* GetGameObject();
	void SetGameObject(GameObject *p_xpGameObject);

	bool Overlap(Hitbox *p_xpHitbox);

private:
	float m_fSize;

	sf::Vector2f m_vPos;

	GameObject *m_xpGameObject;
};