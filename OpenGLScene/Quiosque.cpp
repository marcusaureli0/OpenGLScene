#include "Kiosk.h"



Kiosk::Kiosk(float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
}


Kiosk::~Kiosk()
{
}

void Kiosk::draw()
{
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

		//Pilares do Kiosk
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ); //localização origem
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *pilar;
		pilar = gluNewQuadric();
		gluQuadricNormals(pilar, GLU_SMOOTH);
		gluQuadricTexture(pilar, GL_TRUE);
		gluCylinder(pilar, 0.8, 0.8, 10.2, 10.0, 10.0); // base, topo, width
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 20.0f, posY, posZ); //localização origem

		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *pilar2;
		pilar2 = gluNewQuadric();
		gluQuadricNormals(pilar2, GLU_SMOOTH);
		gluQuadricTexture(pilar2, GL_TRUE);
		gluCylinder(pilar2, 0.8, 0.8, 10.2, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ - 20.0f); //localização origem

		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *pilar3;
		pilar3 = gluNewQuadric();
		gluQuadricNormals(pilar3, GLU_SMOOTH);
		gluQuadricTexture(pilar3, GL_TRUE);
		gluCylinder(pilar3, 0.8, 0.8, 10.2, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 20.0f, posY, posZ - 20.0f); //localização origem
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *pilar4;
		pilar4 = gluNewQuadric();
		gluQuadricNormals(pilar4, GLU_SMOOTH);
		gluQuadricTexture(pilar4, GL_TRUE);
		gluCylinder(pilar4, 0.8, 0.8, 10.2, 10.0, 10.0);
		glPopMatrix();

		//ceiling do Kiosk
		glBindTexture(GL_TEXTURE_2D, roofTexture);

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX + 10.0f, posY + 8.0f, posZ - 10.0f); //localização origem
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		GLUquadricObj *ceiling;
		ceiling = gluNewQuadric();
		gluQuadricNormals(ceiling, GLU_SMOOTH);
		gluQuadricTexture(ceiling, GL_TRUE);
		gluCylinder(ceiling, 20.0, 0.1, 10.0, 10.0, 10.0);
		glPopMatrix();

		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		glTranslatef(posX, posY, posZ); //localização origem

																   //Balcao do Kiosk
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 3.0f, 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(3.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(3.5f, 3.0f, 0.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 3.3f, 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 3.3f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(3.5f, 3.3f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(3.5f, 3.3f, 0.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 3.3f, 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 3.0f, 0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(3.5f, 3.0f, 0.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(3.5f, 3.3f, 0.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 3.3f, -4.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(3.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(3.5f, 3.3f, -4.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 3.3f, 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 3.0f, 0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, 3.3f, -4.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(3.5f, 3.3f, 0.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(3.5f, 3.0f, 0.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(3.5f, 3.0f, -4.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(3.5f, 3.3f, -4.5f);
		glEnd();

		//floor do Kiosk
		glBindTexture(GL_TEXTURE_2D, floorTexture);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.5f, 0.0f, 5.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(25.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(25.5f, 0.0f, 5.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.5f, 1.0f, 5.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.5f, 1.0f, -25.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(25.5f, 1.0f, -25.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(25.5f, 1.0f, 5.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.5f, 1.0f, 5.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.5f, 0.0f, 5.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(25.5f, 0.0f, 5.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(25.5f, 1.0f, 5.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.5f, 1.0f, -25.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(25.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(25.5f, 1.0f, -25.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.5f, 1.0f, 5.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.5f, 0.0f, 5.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.5f, 1.0f, -25.5f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(25.5f, 1.0f, 5.5f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(25.5f, 0.0f, 5.5f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(25.5f, 0.0f, -25.5f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(25.5f, 1.0f, -25.5f);
		glEnd();

		//walls
		glBindTexture(GL_TEXTURE_2D, brickTexture);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 8.0f, 0.7f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 8.0f, -0.8f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 8.0f, -0.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 8.0f, 0.7f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 1.0f, 0.7f); //superior
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 1.0f, -0.8f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 1.0f, -0.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 1.0f, 0.7f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 8.0f, 0.7f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 1.0f, 0.7f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 1.0f, 0.7f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 8.0f, 0.7f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.0f, 8.f, -0.8f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.0f, 1.0f, -0.8f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 1.0f, -0.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 8.0f, -0.8f);
		glEnd();
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, 8.0f, 0.7f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 1.0f, 0.7f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 1.0f, -0.8f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 8.0f, -0.8f);
		glEnd();
		glPopMatrix();


}

void Kiosk::load()
{
	texture = SOIL_load_OGL_texture("files/textures/wood.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	floorTexture = SOIL_load_OGL_texture("files/textures/floor.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	roofTexture = SOIL_load_OGL_texture("files/textures/ceiling.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	brickTexture = SOIL_load_OGL_texture("files/textures/bricks.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}

void Kiosk::update()
{
}
