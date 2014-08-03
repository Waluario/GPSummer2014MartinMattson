// EnemyObject2.h //

#pragma once

#include "EnemyObject.h"

class Sprite;

class EnemyObject2 : public EnemyObject {
public:
	EnemyObject2(sf::Vector2f p_vPosition, float p_fSpd);
	~EnemyObject2();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	float m_fSpd,
		m_fStopTime,
		m_fStopTimeMax;

	bool m_bStopNow;

	Sprite *m_xpSprite;
};