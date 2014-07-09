// EnemyObject0.h //

#include "EnemyObject.h"

#pragma once

class Sprite;

class EnemyObject0 : public EnemyObject {
public:
	EnemyObject0(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd, sf::Vector2f p_vDeaccel, sf::Vector2f p_vMaxSpd);
	~EnemyObject0();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

	bool CanFire();

private:
	sf::Vector2f m_vSpd,
		m_vDeaccel,
		m_vMaxSpd;

	float m_fFireRate,
		m_fFireRateMax;

	int m_iBulletAmmo,
		m_iLife,
		m_iScore;

	Sprite *m_xpSprite;

	GameObject *m_xpPlayer;
};