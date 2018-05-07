#pragma once
#ifndef Chair_H
#define Chair_H

#include "SceneObject.h"

class Chair : public SceneObject
{
private:
	float posX, posY, posZ;
public:
	Chair(float posX, float posY, float posZ);
	~Chair();
	void draw() override;
	void update() override;
	void load() override;
};
#endif // !Chair_H


