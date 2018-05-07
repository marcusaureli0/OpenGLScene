#pragma once
#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <GL/glut.h>
#include <soil/SOIL.h>

class SceneObject
{
protected:
	int texture;
public:
	SceneObject();
	~SceneObject();
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void load() = 0;

};

#endif SCENE_OBJECT_H
