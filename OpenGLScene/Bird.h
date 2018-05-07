#pragma once
#ifndef Bird_H
#define Bird_H

#include <cmath>
#include "SceneObject.h"
class Bird: public SceneObject
{
private:
	float posX; // posi��o X do p�ssaro
	float posY; // possi��o Y (height) do p�ssaro
	float posZ; // posi��o Z do p�ssaro
	float angle; // �ngulo de rota��o
	float rotationRate; // taxa de aumento do �ngulo de rota��o do v�o
	bool isClockWise; // sentido da rota��o do v�o
	float dx;
	float dy;
	float dz;
	float wingAngle; // �ngulo de rota��o da asa
	float wingRotationRate; // taxa de aumento do �ngulo de rota��o
	bool windIsRotationWise; // sentido de rota��o da asa
	float limit;
public:
	Bird(float posX, float posY, float posZ, float increaseRate, bool isClockWise);
	~Bird();
	
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !Bird_H

