#include "Mist.h"



Mist::Mist(float density, float color[])
{
	this->density = density;
	this->color = color;
	this->maxDensity = 0.0088578f;
	this->minDensity = 0.0001617f;
	
}


Mist::~Mist()
{
}
