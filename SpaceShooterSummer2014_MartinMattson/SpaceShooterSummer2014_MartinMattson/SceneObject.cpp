// SceneObject.cpp //

#include "SceneObject.h"

#include <iostream>
#include <sstream>

SceneObject::SceneObject(int p_iScene){
	AddTag("Scene" + static_cast<std::ostringstream*>(&(std::ostringstream() << p_iScene))->str());
}

SceneObject::~SceneObject(){
	std::cout << "Scene Deleted";
}

void SceneObject::OnCreate(){

}

void SceneObject::OnUpdateThis(){

}

void SceneObject::OnDrawThis(){

}

void SceneObject::OnCollision(GameObject *p_xpCollider){

}