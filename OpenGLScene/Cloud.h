#pragma once
#ifndef Cloud_H
#define Cloud_H
#include "SceneObject.h"

class Cloud : public SceneObject
{
private:
	float sizeX, sizeY, sizeZ;
public:
	Cloud(float sizeX, float sizeY, float sizeZ);
	~Cloud();
	void draw() override;
	void load() override;
	void update() override;
};

#endif //Cloud_H
