// PlayerObject.h //

#pragma once

#include "GameObject.h"

class Sprite;

class PlayerObject : public GameObject {
public:
	PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration);
	~PlayerObject();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

public:
	bool CanFire();
	sf::Vector2f GetSpeed();

private:
	float m_fAcceleration,
		m_fCdwn,
		m_fMaxCdwn,
		m_fFirerate,
		m_fFirerateMax,
		m_fFireRange,
		m_fFireRangeMax,
		m_fBlinkTime,
		m_fBlinkTimeMax;

	bool m_bFireRangeUp,
		m_bDrawSprite;

	Sprite *m_xpSprite;
};