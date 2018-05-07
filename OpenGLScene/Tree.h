#pragma once
#ifndef Tree_H
#define Tree_H
#include "SceneObject.h"

class Tree : public SceneObject
{
private :
	void drawTrunk();
	void drawLeaf();
	int leafTexture;
	float posX;
	float posY;
	float posZ;
	float rotX;
	float rotY;
	float rotZ;
	float trunkHeight;
	float angle;
	bool isIncrease;
public:
	Tree(float posX, float posY, float posZ);
	~Tree();
	virtual void draw() override;
	virtual void load() override;
	virtual void update() override;
};

#endif // !Tree_H
