#include "Cloud.h"



Cloud::Cloud(float sizeX, float sizeY, float sizeZ)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
}
Cloud::~Cloud()
{
	
}

void Cloud::draw() {
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	GLfloat luzEmissiva[4] = { 0.2, 0.2, 0.2, 0.1 };
	GLfloat ambientLight[4] = { 1.0, 1.0, 1.0, 0.2 };                         /*vetores que armazenam dados a serem utilizados na configuracao de luzes*/
																			  //desenha as nuvens em uma esfera
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glNormal3f(0, 1, 0);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);                         /*configura as diversas luzes do prograss*/
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	GLUquadricObj *quad;
	quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluSphere(quad, sizeX, 10.0, 10.0);
	glPopMatrix();
}

void Cloud::load() {
	texture = SOIL_load_OGL_texture("files/textures/cloud1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}

void Cloud::update() {

}
