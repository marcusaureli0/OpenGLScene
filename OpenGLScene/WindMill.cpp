#include "WindMill.h"



WindMill::WindMill(float posX, float posY, float posZ, float rotationRate, float width, float height)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->angle = 0;
	this->rotationRate = rotationRate;
	this->width = width;
	this->height = height;

}

void WindMill::load() {
	texture = SOIL_load_OGL_texture("files/textures/wind.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	propellerTexture = SOIL_load_OGL_texture("files/textures/propeller.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void WindMill::draw() {
GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glTranslatef(posX,posY,posZ);
	//desenha o suporte do wind
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

	GLUquadricObj *quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad,width,width / 4,height, 10.0f, 10.0f);
	glPopMatrix();

	//desenha suporte da hélice
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glTranslatef(posX,height - 3.5f,posZ - 8.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	quad = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, propellerTexture);
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad, 2.0f, 2.0f, 7.0f, 10.0f, 10.0f);
	glPopMatrix();

	//desenha propeller 1
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX, height - 3.0f,posZ - 8.0f);
	//glRotatef(45, 0.0f, 0.0f, 1.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.5, 50.5, -1.5);       // top-left
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.5, 50.5, 1.5);       // top-right
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(1.5, -50.5, 1.5);       // bottom-right
	glTexCoord2f(1.0f, 0.0f);  glVertex3f(1.5, -50.5, -1.5);       //bottom-left
	glEnd();
	glPopMatrix();

	//desenha propeller 2
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX,height - 3.0f,posZ - 8.0f);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.5, 50.5, -1.5);       // top-left
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.5, 50.5, 1.5);       // top-right
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(1.5, -50.5, 1.5);       // bottom-right
	glTexCoord2f(1.0f, 0.0f);  glVertex3f(1.5, -50.5, -1.5);       //bottom-left
	glEnd();
	glPopMatrix();
}
void WindMill::update() {
	angle += rotationRate;
	if (angle > 360) {
		angle = 0;
	}

}

WindMill::~WindMill()
{
}
