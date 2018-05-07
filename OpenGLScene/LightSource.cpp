#include "LightSource.h"



LightSource::LightSource(float posX, float posY, float posZ, bool isOn, bool isInitialLight)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->isOn = isOn;
	this->intensity = 90.0f;
	this->isInitialLight = isInitialLight;
}

void LightSource::configure() {
		float lightPosition[] = { posX, posY,posZ, 1.0f };
		float spot[] = { posX,posY, posZ };

		if (isInitialLight == 0) {
			GLfloat difuseLight[] = { 0.1, 0.1, 0.1, 0.3 };
			GLfloat specular[] = { 0.5, 0.3, 0.1, 0.5 };
			GLfloat ambientLight[4] = { 0.8, 0.03, 0.03, 0.05 };

			glLightfv(GL_LIGHT0, GL_DIFFUSE, difuseLight);
			glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);

			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot);
			glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 45.0f);

		}
		else {
			GLfloat difuseLight[] = { 0.7, 0.7, 0.7, 0.7 };
			GLfloat specular[] = { 0.4, 0.6, 0.5, 0.8 };
			GLfloat ambientLight[4] = { 0.01, 0.01, 0.2, 0.05 };

			glLightfv(GL_LIGHT1, GL_DIFFUSE, difuseLight);
			glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
			glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);

			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot);
			glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
			glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f);
			glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 12.0f);

		}
	
}
void LightSource::update(){}

void LightSource::load() {
	texture = SOIL_load_OGL_texture("files/textures/stake.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	isOnTexture = SOIL_load_OGL_texture("files/textures/lighton.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	isOffTexture = SOIL_load_OGL_texture("files/textures/lightoff.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void LightSource::draw() {
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	if (isOn) {
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHT1);
			glBindTexture(GL_TEXTURE_2D, isOnTexture);

		}
		else {
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHT1);
			glBindTexture(GL_TEXTURE_2D, isOffTexture);
		}

		//lâmpada
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glNormal3f(0, 1, 0);
		GLUquadricObj *quad;
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		glTranslatef(posX, posY, posZ);
		gluSphere(quad, 1.0f, 30.0, 20.0);
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, texture);

		//stake
		glPushMatrix();
		glNormal3f(0, 1, 0);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);

		glTranslatef(posX, 0.0f, posZ);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, 2.5f, 0.5f, posY, 10.0f, 10.0f);
		glPopMatrix();
	
}

LightSource::~LightSource()
{
}
