#pragma once
#ifndef Mist_H
#define Mist_H

class Mist
{
public:
	float minDensity;
	float maxDensity;
	float *color;
	float density;
	Mist(float density, float color[]);
	~Mist();
};

#endif // !Mist_H