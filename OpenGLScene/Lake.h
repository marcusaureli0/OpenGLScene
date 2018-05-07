#pragma once
#ifndef Lake_H
#define Lake_H
#include "SceneObject.h"

class Lake : public SceneObject
{
private:
	int woodTexture;
	float posX;
	float posY;
	float posZ;
	float widthX;
	float widthY;
	float widthZ;
	float alfa;
	float a;
	float b;
	float c;
	float material;
	float shininess;
	float translation, rotation;
	bool increase;
public:
	void update();
	Lake(float posX, float posY, float posZ, float widthX, float widthY, float widthZ);
	~Lake();
	void draw() override;
	void load() override;
};

#endif // !Lake_H


