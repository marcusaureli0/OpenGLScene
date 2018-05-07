#pragma once
#include <cmath>
#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	float posX; // posição atual X da câmera
	float posY; // posição atual Y da câmera
	float posZ; // posição atual Z da câmera
	float angle; // ângulo atual da câmera
	float dxcamera;
	float dycamera;
	float velocity;
	float r, g, b, a;
	float dzcamera;  /*direção ao deslocar a camera*/
	void updateAngle();
	void updateMagnitude(bool more);
	Camera();
	~Camera();
};

#endif // !CAMERA_H


