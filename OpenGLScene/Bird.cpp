#include "Bird.h"



Bird::Bird(float posX, float posY, float posZ, float rotationRate, bool isClockWise)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->rotationRate = rotationRate;
	this->angle = 0;
	this->isClockWise = isClockWise;
	this->windIsRotationWise = isClockWise;
	this->dx = 0;
	this->dy = 0;
	this->dz = 0;
	this->limit = 360;
	this->wingAngle = 0;
	this->wingRotationRate = 15.0f;
}

void Bird::update() {
	dx = sin(angle);
	dz = -cos(angle);


	if (windIsRotationWise) {
		if (wingAngle > 60) {
			windIsRotationWise = false;
		}
		wingAngle +=wingRotationRate;
	}
	else {
		if(wingAngle< -60){
			windIsRotationWise = true;
		}
		wingAngle -= wingRotationRate;
	}

	if (isClockWise) {
		angle += rotationRate;
		if (angle > limit) {
			angle = 0;
		}
	}
	else {
		angle -= rotationRate;
		if (angle < -limit) {
			angle = 0;
		}
	}
}
Bird::~Bird()
{
}

void Bird::draw()
{
	GLfloat shininess[] = { 90.0 };
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	glBindTexture(GL_TEXTURE_2D, texture);

		glPushMatrix();
		glNormal3f(0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		GLUquadricObj *quad;
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		glTranslatef(posX + dx * 20, posY + dy * 10, posZ + dz * 30);
		glRotatef(dx, 1.0f, 0.0f, 0.0f);
		gluSphere(quad, 1.0f, 20.0, 20.0);
		glPopMatrix();

		glPushMatrix();
		glNormal3f(0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		glTranslatef(posX + dx * 20 + -0.8f, posY + dy * 10 + 1.2f, posZ + dz * 30);
		glRotatef(dx, 1.0f, 0.0f, 0.0f);
		gluSphere(quad, 0.6f, 20.0, 20.0);
		glPopMatrix();

		//asa esquerda
		glPushMatrix();
		glNormal3f(0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + dx * 20, posY + dy * 10, posZ + dz * 30);
		glRotatef(angle, 1.0f, 0.0f, 0.0f);
		glRotatef(wingAngle, 0.0f, 1.0f, 0.0f);
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, 0.3f, 0.2f, 4.0f, 10.0f, 10.0f);
		glPopMatrix();

		//asa direita
		glPushMatrix();
		glNormal3f(0, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + dx * 20, posY + dy * 10, posZ + dz * 30);
		glRotatef(angle, 1.0f, 0.0f, 0.0f);
		glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(wingAngle, 0.0f, 1.0f, 0.0f);
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, 0.3f, 0.2f, 4.0f, 10.0f, 10.0f);
		glPopMatrix();
}

void Bird::load()
{
	texture = SOIL_load_OGL_texture("files/textures/bird.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}
