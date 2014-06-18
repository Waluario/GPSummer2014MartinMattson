// PlayerObject.h //

#include "GameObject.h"

class PlayerObject : public GameObject {
public:
	PlayerObject(sf::Vector2f p_vPos, int p_iLife, float p_fAcceleration);
	~PlayerObject();

	virtual void OnUpdateThis();
	virtual void OnCollision(GameObject *p_xpCollider);

private:
	int m_iLife;

	float m_fAcceleration;

	sf::Vector2f m_vSpeed;
};