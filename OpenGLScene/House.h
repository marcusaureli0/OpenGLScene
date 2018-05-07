#pragma once
#ifndef House_H
#define House_H

#include "SceneObject.h"
class House : public SceneObject
{
private :
	int roofTexture;
	float wallWidthA, wallWidthB, wallWidthC, wallWidthD, wallHeight, roofHeight;
	float posX, posY, posZ;
public:
	House(float wallWidthA, float wallWidthB, float wallWidthC, float wallWidthD,
		float  wallHeight, float roofHeight, float posX, float posY, float posZ);
	~House();
	void draw() override;
	void update() override;
	void load() override;
};

#endif // !House_H


