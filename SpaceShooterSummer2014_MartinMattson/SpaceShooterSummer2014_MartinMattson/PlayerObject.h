// PlayerObject.h //

#pragma once

#include "GameObject.h"

class Sprite;

class PlayerObject : public GameObject {
public:
	PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration);
	~PlayerObject();

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	int m_iLife;

	float m_fAcceleration,
		m_fCdwn,
		m_fMaxCdwn;

	Sprite *m_xpSprite;
};