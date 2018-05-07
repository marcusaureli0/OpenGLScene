#include "Terrain.h"

Terrain::Terrain(float sizeX, float sizeY, float sizeZ)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
}

void Terrain::draw() {
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glBegin(GL_QUADS);
	glNormal3f(1, 1, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-sizeX, sizeY, -sizeZ);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(sizeX, sizeY, -sizeZ);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(sizeX, sizeY, sizeZ);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-sizeX, sizeY, sizeZ);
	glEnd();
	glPopMatrix();
}

void Terrain::load() {
	texture =SOIL_load_OGL_texture("files/textures/grass.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

void Terrain::update() {

}
Terrain::~Terrain()
{
}
