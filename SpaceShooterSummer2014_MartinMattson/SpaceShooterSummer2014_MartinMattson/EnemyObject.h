// EnemyObject.h //

#include "GameObject.h"

#pragma once

class EnemyObject : public GameObject {
public:
	EnemyObject();
	~EnemyObject();

	bool CanFire();

	void DropScore();

protected:
	sf::Vector2f m_vSpd,
		m_vMaxSpd;

	float m_fFireRate,
		m_fFireRateMax;

	int m_iBulletAmmo,
		m_iLife,
		m_iScore;

	GameObject *m_xpPlayer;
};