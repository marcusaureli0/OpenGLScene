#pragma once
#ifndef Kiosk_H
#define Kiosk_H
#include "SceneObject.h"

class Kiosk: public SceneObject
{
private:
	int floorTexture, roofTexture, brickTexture; 
	float posX, posY, posZ;
public:
	
	Kiosk(float posX, float posY, float posZ);
	~Kiosk();
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !Kiosk_H


