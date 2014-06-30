// EnemyObject0.h //

#include "EnemyObject.h"

#pragma once

class Sprite;

class EnemyObject0 : public EnemyObject {
public:
	EnemyObject0(sf::Vector2f p_vPositionfloat, float p_fHorizontalSpd, float p_fVerticalSpd, float p_fDeaccel, float p_fMaxSpd);
	~EnemyObject0();

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	float m_fHorizontalSpd,
		m_fVerticalSpd,
		m_fDeaccel,
		m_fMaxSpd;

	Sprite *m_xpSprite;
};