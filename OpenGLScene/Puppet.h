#pragma once
#ifndef Puppet_H
#define Puppet_H

#include "SceneObject.h"
class Puppet : public SceneObject
{
private:
	int bodyTexture;
	float posX;
	float posY;
	float posZ;
	float armRotX;
	float armRotY;
	float armRotZ;
	float headRotX;
	float headRotY;
	float headRotZ;
	float headAngle;
	float armAngle;
	bool headSum;
	bool armSum;
public:
	Puppet(float posX, float posY, float posZ);
	~Puppet();
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !Puppet_H


