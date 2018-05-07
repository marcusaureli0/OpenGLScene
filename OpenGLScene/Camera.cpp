#include "Camera.h"

Camera::Camera()
{
	posX = -244.0f;
	posY = 26.0f;
	posZ = -137.0f;
	dxcamera = 0.0f;
	dycamera = 0.0f;
	dzcamera = -1.0f; 
	angle = -4.1f;
	velocity = 2.0f;
	r = 0.5f;
	g = 0.5f;
	b = 0.5f;
	a = 0.5f;
}

void Camera::updateAngle() {
	dxcamera = sin(angle);
	dzcamera = -cos(angle);
}

void Camera::updateMagnitude(bool more) {
	float dif = 0.01f;
	if (more && r+dif<=1.0f) {
		r += dif;
		g += dif;
		b += dif;
		a += dif;
	}
	else if(r - dif >= 0.0f){
		r -= dif;
		g -= dif;
		b -= dif;
		a -= dif;
	}

}



Camera::~Camera()
{
}
