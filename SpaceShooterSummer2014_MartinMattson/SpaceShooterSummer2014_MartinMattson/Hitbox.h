// Hitbox.h //

#pragma once

class GameObject;

class Hitbox {
public:
	Hitbox(GameObject *p_xpGameObject);
	Hitbox(GameObject *p_xpGameObject, sf::Vector2f p_vPosition, float p_fSize);
	~Hitbox();
	
	float GetSize();
	void SetSize(float p_f);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f p_vPosition);

	GameObject* GetGameObject();
	void SetGameObject(GameObject *p_xpGameObject);

	sf::CircleShape* GetShape();

	bool Overlap(Hitbox *p_xpHitbox);

private:
	float m_fSize;

	sf::Vector2f m_vPosition;

	GameObject *m_xpGameObject;
};