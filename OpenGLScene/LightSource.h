#pragma once
#ifndef LightSource_H
#define LightSource_H

#include "SceneObject.h"
class LightSource : public SceneObject
{
private:
	float posX, posY, posZ;
	bool isInitialLight;
	float intensity;
	int isOnTexture, isOffTexture;
public:
	bool isOn;
	LightSource(float posX, float posY, float posZ, bool isOn, bool isInitialLight);
	~LightSource();
	void configure();
	void draw() override;
	void update() override;
	void load() override;
};



#endif // !LightSource_H

