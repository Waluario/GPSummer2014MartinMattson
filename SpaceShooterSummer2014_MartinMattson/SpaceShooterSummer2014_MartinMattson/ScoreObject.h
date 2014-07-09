// ScoreObject.h //

#pragma once

#include "GameObject.h"

class Sprite;

class ScoreObject : public GameObject {
public:
	ScoreObject(sf::Vector2f p_vPosition);
	~ScoreObject();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	Sprite *m_xpSprite;

	sf::Vector2f m_vSpd,
		m_vMaxSpd,
		m_vAcceleration;

	float m_fRotationSpeed;
};