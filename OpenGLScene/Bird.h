#pragma once
#ifndef Bird_H
#define Bird_H

#include <cmath>
#include "SceneObject.h"
class Bird: public SceneObject
{
private:
	float posX; // posição X do pássaro
	float posY; // possição Y (height) do pássaro
	float posZ; // posição Z do pássaro
	float angle; // ângulo de rotação
	float rotationRate; // taxa de aumento do ângulo de rotação do vôo
	bool isClockWise; // sentido da rotação do vôo
	float dx;
	float dy;
	float dz;
	float wingAngle; // ângulo de rotação da asa
	float wingRotationRate; // taxa de aumento do ângulo de rotação
	bool windIsRotationWise; // sentido de rotação da asa
	float limit;
public:
	Bird(float posX, float posY, float posZ, float increaseRate, bool isClockWise);
	~Bird();
	
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !Bird_H

