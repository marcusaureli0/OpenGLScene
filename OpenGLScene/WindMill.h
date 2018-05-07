#pragma once
#ifndef WindMill_H
#define WindMill_H

#include "SceneObject.h"

class WindMill : public SceneObject
{
private:
	int propellerTexture;
	float posX;
	float posY;
	float posZ;
	float angle;
	float rotationRate;
	float height;
	float width;
public:
	WindMill(float posX, float posY, float posZ, float rotationRate, float width, float height);
	~WindMill();
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !WindMill_H

