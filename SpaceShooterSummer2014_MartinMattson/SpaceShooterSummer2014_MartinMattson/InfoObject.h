// CreditsObject.h //

#pragma once

#include "GameObject.h"

#include <vector>

class InfoObject : public GameObject {
public:
	InfoObject(sf::Vector2f p_vPosition, std::string p_sFile);
	~InfoObject();

	void SetAllPositions(sf::Vector2f p_vPosition);

	virtual void OnCreate();
	virtual void OnUpdateThis();
	virtual void OnDrawThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	std::vector<sf::Text*> m_xpaText;
};