#pragma once
#ifndef Cart_H
#define Cart_H

#include "SceneObject.h"
class Cart : public SceneObject
{
private:
	float posX, posY, posZ;
public:
	Cart(float posX, float posY, float posZ);
	~Cart();
	void load() override;
	void draw() override;
	void update() override;
};

#endif // !Cart_H


