// HUDObject.h //

#pragma once

#include "GameObject.h"

class HUDObject : public GameObject {
public:
	HUDObject();
	~HUDObject();

	virtual void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	sf::RectangleShape m_xRect;

	sf::Text *m_xpScore,
		*m_xpHiScore,
		*m_xpLife;
};