#pragma once
#ifndef Fog_H
#define Fog_H

class Fog
{
private:
	float density;
	float colorFog[4] = { 0.5f,0.5f,0.5f,1.0f };
public:
	
	Fog();
	~Fog();
};

#endif // !Fog_H