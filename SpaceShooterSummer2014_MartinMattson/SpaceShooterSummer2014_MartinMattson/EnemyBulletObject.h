// EnemyBulletObject.h //

#pragma once

#include "GameObject.h"

class Sprite;

class EnemyBulletObject : public GameObject {
public:
	EnemyBulletObject(sf::Vector2f p_vPos, sf::Vector2f p_vDir, float p_fAcceleration);
	~EnemyBulletObject();

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