// EnemyObject0.h //

#include "EnemyObject.h"

#pragma once

class Sprite;

class EnemyObject0 : public EnemyObject {
public:
	EnemyObject0();
	~EnemyObject0();

	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	Sprite *m_xpSprite;
};