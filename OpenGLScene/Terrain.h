#pragma once
#ifndef Terrain_H
#define Terrain_H
#include "SceneObject.h"
class Terrain : public SceneObject
{
private:
	float sizeX;
	float sizeY;
	float sizeZ;
public:
	Terrain(float sizeX, float sizeY, float sizeZ);
	~Terrain();
	void draw() override;
	void load() override;
	void update() override;
};

#endif // Terrain_H


