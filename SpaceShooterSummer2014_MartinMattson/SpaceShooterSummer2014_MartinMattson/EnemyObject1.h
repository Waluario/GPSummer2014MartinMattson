// EnemyObject1.h //

#include "EnemyObject.h"

#pragma once

class Sprite;

class EnemyObject1 : public EnemyObject {
public:
	EnemyObject1(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd, sf::Vector2f p_vFire);
	~EnemyObject1();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	bool m_bBulletDirSet;

	Sprite *m_xpSprite;

	sf::Vector2f m_vBulletDir;
};