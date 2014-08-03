// EnemyObject3.h //

#pragma once

#include "EnemyObject.h"

class Sprite;

class EnemyObject3 : public EnemyObject {
public:
	EnemyObject3(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd);
	~EnemyObject3();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	Sprite *m_xpSprite;
};