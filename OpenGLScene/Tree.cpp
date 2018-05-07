#include "Tree.h"
#include <functional>

Tree::Tree(float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->trunkHeight = 30.0f;
	this->angle = 0;
}
void Tree::load() {
	texture = SOIL_load_OGL_texture("files/textures/trunk.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	leafTexture = SOIL_load_OGL_texture("files/textures/leaf.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void Tree::drawLeaf() {
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	glBindTexture(GL_TEXTURE_2D, leafTexture);
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

	glTranslatef(posX, posY + trunkHeight + 2.0f, posZ);
	glRotatef(angle*4.5f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f);  glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX, posY + trunkHeight + 2.0f, posZ);
	glRotatef(45, 1.0f, 0.0f, 0.0f);
	glRotatef(-angle*3.5f, 0.0f, 0.0f, 1.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX, posY + trunkHeight + 2.0f, posZ + 10.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glRotatef(angle*3.5f, 0.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX, posY + trunkHeight + 2.0f, posZ + 15.0f);
	glRotatef(30, 0.0f, 0.0f, 1.0f);
	glRotatef(-angle*4.5f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(posX + 1.0f, posY + trunkHeight, posZ - 3.0f);
	glRotatef(30, 0.0f, 0.0f, 1.0f);
	glRotatef(angle*1.5f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX + 1.0f, posY + trunkHeight, posZ - 3.0f);
	glRotatef(60, 0.0f, 0.0f, 1.0f);
	glRotatef(-angle, 0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX - 3.0f, posY + trunkHeight - 2.0f, posZ + 4.0f);
	glRotatef(60, 0.0f, 0.0f, 1.0f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX + 6.0f, posY + trunkHeight - 2.0f, posZ + 3.0f);
	glRotatef(180, 0.0f, 0.0f, 1.0f);
	glRotatef(angle, 1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glTranslatef(posX - 8.0f, posY + trunkHeight + 2.0f, posZ);
	glRotatef(150, 0.0f, 1.0f, 1.0f);
	glRotatef(angle, 1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.5, -10.5, -10.5);       // P1
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.5, 8.5, -18.5);       // P2
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.5, 4.5, 10.5);       // P3
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.5, -10.5, -4.5);       // P4
	glEnd();
	glPopMatrix();
}
void Tree::drawTrunk() {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glTranslatef(posX, posY, posZ);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(angle*0.2, 1.0f, 0.0f, 0.0f);
	GLUquadricObj *quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricTexture(quad, GL_TRUE);
	gluCylinder(quad, 5.0f, 2.0f, trunkHeight, 10.0f, 10.0f);
	glPopMatrix();
}

void Tree::update() {
	if (isIncrease) {
		angle += 0.3f;

		if (angle > 4)
			isIncrease = false;
	}
	else {
		angle -= 0.3f;
		if (angle < -4)
			isIncrease = true;
	}
}
void Tree::draw() {
	drawTrunk();
	drawLeaf();
}
Tree::~Tree()
{
}
