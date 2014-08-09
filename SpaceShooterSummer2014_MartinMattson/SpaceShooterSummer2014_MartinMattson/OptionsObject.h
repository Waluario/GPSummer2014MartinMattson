// OptionsObject.h //

#pragma once

#include "GameObject.h"

class MenuItem;

class OptionsObject : public GameObject {
public:
	OptionsObject(sf::Vector2f p_vPos, std::vector<MenuItem*> p_xpaOptions);
	~OptionsObject();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	int m_iCurrentChoice;

	std::vector<MenuItem*> m_xpaOptions;
};