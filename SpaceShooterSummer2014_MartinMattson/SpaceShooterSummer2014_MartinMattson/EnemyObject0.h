// EnemyObject0.h //

#include "EnemyObject.h"

#pragma once

class Sprite;

class EnemyObject0 : public EnemyObject {
public:
	EnemyObject0(sf::Vector2f p_vPosition, sf::Vector2f p_vSpd, sf::Vector2f p_vDeaccel);
	~EnemyObject0();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	sf::Vector2f m_vDeaccel;

	Sprite *m_xpSprite;
};