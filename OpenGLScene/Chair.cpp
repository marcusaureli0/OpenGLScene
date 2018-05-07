#include "Chair.h"

Chair::Chair(float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
}
void Chair::draw() {
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad;
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, 0.1, 0.1, 2.6, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 0.8f, posY, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad2;
		quad2 = gluNewQuadric();
		gluQuadricNormals(quad2, GLU_SMOOTH);
		gluQuadricTexture(quad2, GL_TRUE);
		gluCylinder(quad2, 0.1, 0.1, 2.6, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ - 0.8f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad3;
		quad3 = gluNewQuadric();
		gluQuadricNormals(quad3, GLU_SMOOTH);
		gluQuadricTexture(quad3, GL_TRUE);
		gluCylinder(quad3, 0.1, 0.1, 1.6, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 0.8f, posY, posZ - 0.8f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad4;
		quad4 = gluNewQuadric();
		gluQuadricNormals(quad4, GLU_SMOOTH);
		gluQuadricTexture(quad4, GL_TRUE);
		gluCylinder(quad4, 0.1, 0.1, 1.6, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
		//acento
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.0f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 2.0f, -1.f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 2.0f, -1.f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 2.0f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 1.6f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 1.6f, -1.f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 1.6f, -1.f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 1.6f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.0f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 1.6f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.6f, 0.2f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 1.6f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.6f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, -1.0f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.0f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 1.6f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.2f, 1.6f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.2f, 2.0f, -1.0f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.6f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.6f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, -1.0f);
		glEnd();

		//encosto
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.6f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 2.6f, -0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 2.6f, -0.2f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 2.6f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 3.0f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 3.0f, -0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.f, 3.0f, -0.2f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.f, 3.0f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.6f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 3.0f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 3.0f, 0.2f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.6f, 0.2f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.6f, -0.20f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 3.0f, -0.20f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 3.0f, -0.20f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.6f, -0.20f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.2f, 2.6f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.2f, 3.0f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.2f, 3.0f, -0.20f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.2f, 2.6f, -0.20f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.6f, 0.2f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 3.0f, 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 3.0f, -0.20f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.6f, -0.20f);
		glEnd();
		glPopMatrix();
}

void Chair::update(){
}

void Chair::load() {
	texture = SOIL_load_OGL_texture("files/textures/wood.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
Chair::~Chair()
{
}
