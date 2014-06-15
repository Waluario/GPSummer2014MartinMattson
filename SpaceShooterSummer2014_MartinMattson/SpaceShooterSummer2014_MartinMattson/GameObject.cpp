// GameObject.cpp //

#include "GameObject.h"

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::AddChild(GameObject *p_xpChild){

}

void GameObject::RemoveChild(GameObject *p_xpChild){

}

void GameObject::AddParent(GameObject *p_xpChild){

}

void GameObject::RemoveParent(GameObject *p_xpChild){

}

GameObject* GameObject::GetChild(){

}

GameObject* GameObject::GetParent(){

}

Hitbox* GameObject::GetHitbox(){
	return m_xpHitbox
}

bool GameObject::IsColliding(){

}

void GameObject::Update(){

}