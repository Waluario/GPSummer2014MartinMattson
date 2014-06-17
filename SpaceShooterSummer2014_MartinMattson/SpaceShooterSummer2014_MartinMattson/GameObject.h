// GameObject.h //

#include <vector>

class Hitbox;

class GameObject : public sf::Transformable, sf::Drawable {
public:
	GameObject();
	~GameObject();

	void AddParent(GameObject *p_xpChild);
	void RemoveParent(GameObject *p_xpChild);

	bool HasParent();

	GameObject* GetParent();

	void AddChild(GameObject *p_xpChild);
	void RemoveChild(GameObject *p_xpChild);

	GameObject* GetChild(int p_i);
	std::vector<GameObject*> GetChildren();

	bool HasChild();
	int ChildrenNumber();

	std::vector<std::string> GetTags();

	Hitbox* GetHitbox();
	bool HasHitbox();

	bool IsColliding(sf::Vector2f p_vPos, Hitbox *p_xpHitbox);

	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnFixedUpdate();
	virtual void OnCollision(GameObject *p_xpCollider);
	virtual void OnDestroy();

private:
	std::vector<std::string> m_saTags;

	std::vector<GameObject*> m_xpaChildren;
	GameObject *m_xpParent;

	Hitbox *m_xpHitbox;
};