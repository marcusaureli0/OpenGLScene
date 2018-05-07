#include "Table.h"



Table::Table(float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
}

void Table::load(){
	texture = SOIL_load_OGL_texture("files/textures/wood.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void Table::update(){}
void Table::draw() {
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

	glBindTexture(GL_TEXTURE_2D, texture);

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad;
		quad = gluNewQuadric();
		gluQuadricNormals(quad, GLU_SMOOTH);
		gluQuadricTexture(quad, GL_TRUE);
		gluCylinder(quad, 0.1, 0.1, 3.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad2;
		quad2 = gluNewQuadric();
		gluQuadricNormals(quad2, GLU_SMOOTH);
		gluQuadricTexture(quad2, GL_TRUE);
		gluCylinder(quad2, 0.1, 0.1, 3.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad3;
		quad3 = gluNewQuadric();
		gluQuadricNormals(quad3, GLU_SMOOTH);
		gluQuadricTexture(quad3, GL_TRUE);
		gluCylinder(quad3, 0.1, 0.1, 3.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad4;
		quad4 = gluNewQuadric();
		gluQuadricNormals(quad4, GLU_SMOOTH);
		gluQuadricTexture(quad4, GL_TRUE);
		gluCylinder(quad4, 0.1, 0.1, 3.0, 10.0, 10.0);
		glPopMatrix();

		//superficie da Table
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 2.0f, posY + 3.0f, posZ - 2.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad5;
		quad5 = gluNewQuadric();
		gluQuadricNormals(quad5, GLU_SMOOTH);
		gluQuadricTexture(quad5, GL_TRUE);
		gluCylinder(quad5, 4.0, 0.0, 0.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 2.0f, posY + 3.3f, posZ - 2.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad6;
		quad6 = gluNewQuadric();
		gluQuadricNormals(quad6, GLU_SMOOTH);
		gluQuadricTexture(quad6, GL_TRUE);
		gluCylinder(quad6, 4.0, 0.0, 0.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 2.0f, posY + 3.0f, posZ - 2.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad7;
		quad7 = gluNewQuadric();
		gluQuadricNormals(quad7, GLU_SMOOTH);
		gluQuadricTexture(quad7, GL_TRUE);
		gluCylinder(quad7, 4.0, 4.0, 0.3, 10.0, 10.0);
		glPopMatrix();

}
Table::~Table()
{
}
