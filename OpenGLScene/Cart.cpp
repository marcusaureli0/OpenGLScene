#include "Cart.h"



Cart::Cart(float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
}

void Cart::update(){

}
void Cart::load() {
	texture = SOIL_load_OGL_texture("files/textures/wood2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}

void Cart::draw() {
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };
		//base carroça
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX, posY, posZ);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 2.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 2.0f, 0.0f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 2.3f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 2.3f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 2.3f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 2.3f, 0.0f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 2.3f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 2.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 2.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 2.3f, 0.0f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 2.3f, -4.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 2.3f, -4.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 2.3f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 2.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.0f, 2.3f, -4.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, 2.3f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f, 2.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 2.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 2.3f, -4.5f);
		glEnd();

		glPopMatrix();

		//woods da base
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 0.2f, posY + 2.3f, posZ);
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
		glTranslatef(posX + 3.8f, posY + 2.3f, posZ);
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
		glTranslatef(posX + 0.2f, posY + 2.3f, posZ - 4.0f);
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
		glTranslatef(posX + 3.8f, posY + 2.3f, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *quad4;
		quad4 = gluNewQuadric();
		gluQuadricNormals(quad4, GLU_SMOOTH);
		gluQuadricTexture(quad4, GL_TRUE);
		gluCylinder(quad4, 0.1, 0.1, 3.0, 10.0, 10.0);
		glPopMatrix();

		//ligação roda
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 2.0f, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad04;
		quad04 = gluNewQuadric();
		gluQuadricNormals(quad04, GLU_SMOOTH);
		gluQuadricTexture(quad04, GL_TRUE);
		gluCylinder(quad04, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 2.0f, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad05;
		quad05 = gluNewQuadric();
		gluQuadricNormals(quad05, GLU_SMOOTH);
		gluQuadricTexture(quad05, GL_TRUE);
		gluCylinder(quad05, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		//ligação cerca
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 3.0f, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad06;
		quad06 = gluNewQuadric();
		gluQuadricNormals(quad06, GLU_SMOOTH);
		gluQuadricTexture(quad06, GL_TRUE);
		gluCylinder(quad06, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 3.0f, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad07;
		quad07 = gluNewQuadric();
		gluQuadricNormals(quad07, GLU_SMOOTH);
		gluQuadricTexture(quad07, GL_TRUE);
		gluCylinder(quad07, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 3.0f, posZ - 4.0f);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad08;
		quad08 = gluNewQuadric();
		gluQuadricNormals(quad08, GLU_SMOOTH);
		gluQuadricTexture(quad08, GL_TRUE);
		gluCylinder(quad08, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY + 3.0f, posZ - 4.0f);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad09;
		quad09 = gluNewQuadric();
		gluQuadricNormals(quad09, GLU_SMOOTH);
		gluQuadricTexture(quad09, GL_TRUE);
		gluCylinder(quad09, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		//ligação cerca2
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 4.0f, posZ - 4.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad01;
		quad01 = gluNewQuadric();
		gluQuadricNormals(quad01, GLU_SMOOTH);
		gluQuadricTexture(quad01, GL_TRUE);
		gluCylinder(quad01, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 4.0f, posZ);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad02;
		quad02 = gluNewQuadric();
		gluQuadricNormals(quad02, GLU_SMOOTH);
		gluQuadricTexture(quad02, GL_TRUE);
		gluCylinder(quad02, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 4.0f, posZ - 4.0f);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad03;
		quad03 = gluNewQuadric();
		gluQuadricNormals(quad03, GLU_SMOOTH);
		gluQuadricTexture(quad03, GL_TRUE);
		gluCylinder(quad03, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY + 4.0f, posZ - 4.0f);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad041;
		quad041 = gluNewQuadric();
		gluQuadricNormals(quad041, GLU_SMOOTH);
		gluQuadricTexture(quad041, GL_TRUE);
		gluCylinder(quad041, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		//puxador
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.0f, posY + 2.0f, posZ);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad011;
		quad011 = gluNewQuadric();
		gluQuadricNormals(quad011, GLU_SMOOTH);
		gluQuadricTexture(quad011, GL_TRUE);
		gluCylinder(quad011, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY + 2.0f, posZ);
		glRotatef(180, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad012;
		quad012 = gluNewQuadric();
		gluQuadricNormals(quad012, GLU_SMOOTH);
		gluQuadricTexture(quad012, GL_TRUE);
		gluCylinder(quad012, 0.1, 0.1, 4.0, 10.0, 10.0);
		glPopMatrix();


		//lateral
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX - 0.1f, posY + 2.0f, posZ - 1.7f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad6;
		quad6 = gluNewQuadric();
		gluQuadricNormals(quad6, GLU_SMOOTH);
		gluQuadricTexture(quad6, GL_TRUE);
		gluCylinder(quad6, 2.0, 0.0, 0.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();//lateral
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 4.10f, posY + 2.0f, posZ - 1.7f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		GLUquadricObj *quad9;
		quad9 = gluNewQuadric();
		gluQuadricNormals(quad9, GLU_SMOOTH);
		gluQuadricTexture(quad9, GL_TRUE);
		gluCylinder(quad9, 2.0, 0.0, 0.0, 10.0, 10.0);
		glPopMatrix();
}
Cart::~Cart()
{
}
