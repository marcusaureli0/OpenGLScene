#include "Puppet.h"



Puppet::Puppet(float posX, float posY, float posZ)
{
	this->armSum = true;
	this->headSum = true;
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->headRotX = 0.5f;
	this->headRotY = 0.0f;
	this->headRotZ = 0.0f;
	this->headAngle = 0;
	this->armAngle = 0;	
	this->armRotX = 0.8f;
	this->armRotY = 0.0f;
	this->armRotZ = 0.0f;
}

void Puppet::load() {
	bodyTexture = SOIL_load_OGL_texture("files/textures/body.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture = SOIL_load_OGL_texture("files/textures/head.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void Puppet::update() {
	if (headSum) {
		headAngle += headRotX;
		if (headAngle > 2)
			headSum = false;
	}
	else {
		headAngle -= headRotX;
		if (headAngle < -2) headSum = true;
	}

	if (armSum) {
		armAngle += armRotX;
		if (armAngle > 10) armSum = false;
	}
	else {
		armAngle -= armRotX;
		if (armAngle < -10) armSum = true;
	}
}

void Puppet::draw() {
	GLfloat shininess[] = { 90.0 };
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	//Cabeça do boneco do posto
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glRotatef(headAngle, 1.0f, 0.0f, 0.0f);

	GLUquadricObj *quad;
	quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	glTranslatef(0.0f, 10.0f, 0.0f);
	gluSphere(quad, 1.5f, 30.0, 30.0);
	glPopMatrix();

	//colorpo do boneco do posto
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(headAngle*0.6, 1.0f, 0.0f, 0.0f);
	quad = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad, 2.5f, 0.5f, 9.3f, 10.0f, 10.0f);
	glPopMatrix();

	//braço esquerdo do boneco do posto
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glTranslatef(0.0f, 6.5f, 0.0f);

	glRotatef(armAngle, 1.0f, 0.0f, 0.0f);

	//GLUquadricObj *quad;
	quad = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad, 0.5f, 1.5f, 4.0f, 10.0f, 10.0f);
	glPopMatrix();

	//braço direito do boneco do posto
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glTranslatef(0.0f, 6.5f, 0.0f);
	glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-armAngle * 4, 1.0f, 0.0f, 0.0f);
	glRotatef(-armAngle, 0.0f, 0.0f, 1.0f);

	//GLUquadricObj *quad;
	quad = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, bodyTexture);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad, 0.5f, 1.5f, 6.0f, 10.0f, 10.0f);
	glPopMatrix();

}

Puppet::~Puppet()
{
}
