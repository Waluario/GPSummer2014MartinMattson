// PlayerBulletObject.h //

#pragma once

#include "GameObject.h"

class Sprite;

class PlayerBulletObject : public GameObject {
public:
	PlayerBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration);
	~PlayerBulletObject();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	sf::Vector2f m_vDir;

	float m_fAcceleration;

	Sprite *m_xpSprite;
};