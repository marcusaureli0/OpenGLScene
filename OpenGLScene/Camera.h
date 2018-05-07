#pragma once
#include <cmath>
#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	float posX; // posi��o atual X da c�mera
	float posY; // posi��o atual Y da c�mera
	float posZ; // posi��o atual Z da c�mera
	float angle; // �ngulo atual da c�mera
	float dxcamera;
	float dycamera;
	float velocity;
	float r, g, b, a;
	float dzcamera;  /*dire��o ao deslocar a camera*/
	void updateAngle();
	void updateMagnitude(bool more);
	Camera();
	~Camera();
};

#endif // !CAMERA_H


