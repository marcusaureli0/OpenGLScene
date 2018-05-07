#pragma once

#ifndef Table_H
#define Table_H
#include "SceneObject.h"

class Table: public SceneObject
{
private:
	float posX, posY, posZ;
public:
	Table(float posX, float posY, float posZ);
	~Table();
	void draw() override;
	void load() override;
	void update() override;
};

#endif // !Table_H


