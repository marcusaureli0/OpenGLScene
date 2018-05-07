#include "House.h"



House::House(float wallWidthA, float wallWidthB, float wallWidthC, float wallWidthD, float  wallHeight,
	float roofHeight, float posX, float posY, float posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->wallWidthA = wallWidthA;
	this->wallWidthB = wallWidthB;
	this->wallWidthC = wallWidthC;
	this->wallWidthD = wallWidthD;
	this->wallHeight = wallHeight;
	this->roofHeight = roofHeight;
}

void House::draw() {
	GLfloat shininess[] = { 90.0 };
	GLfloat ambientLight[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat specular[] = { 0.5, 0.5, 0.5, 0.5 };

		//desenha wallA
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
		//glMaterialfv(GL_FRONT, GL_AMBIENT, qaAmbientLight);

		glTranslatef(posX, wallHeight, posZ);
		glRotatef(90.0f, 1, 0, 0);
		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthA, posY, -wallHeight);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthA, posY, -wallHeight);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthA, posY, wallHeight);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthA, posY, wallHeight);
		glEnd();
		glPopMatrix();

		//desenha wallB
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX - wallWidthA, wallHeight, posZ - wallWidthA / 2);
		glRotatef(90.0f, 1, 0, 0);
		glRotatef(90.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthB, posY, -wallHeight);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthB, posY, -wallHeight);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthB, posY, wallHeight);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthB, posY, wallHeight);
		glEnd();
		glPopMatrix();

		//desenha wallC
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX, wallHeight, posZ - wallWidthA);
		glRotatef(90.0f, 1, 0, 0);
		glRotatef(180.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthC, posY, -wallHeight);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthC, posY, -wallHeight);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthC, posY, wallHeight);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthC, posY, wallHeight);
		glEnd();
		glPopMatrix();

		//desenha wallD1
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX + wallWidthC, wallHeight / 2, posZ - (wallHeight / 3) * 1.25f);
		glRotatef(90.0f, 1, 0, 0);
		glRotatef(90.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(-1, 1, -1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, -wallHeight / 2);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, -wallHeight / 2);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, wallHeight / 2);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, wallHeight / 2);
		glEnd();
		glPopMatrix();

		//desenha wallD2
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX + wallWidthC, wallHeight / 2, posZ - wallWidthD*1.68f);
		glRotatef(90.0f, 1, 0, 0);
		glRotatef(90.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(-1, 1, -1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, -wallHeight / 2);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, -wallHeight / 2);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, wallHeight / 2);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, wallHeight / 2);
		glEnd();
		glPopMatrix();

		//desenha porta 1
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX + wallWidthC*1.17f, wallHeight / 3, posZ - wallWidthD*1.35f);
		glRotatef(90.0f, 1, 0, 0);
		//glRotatef(90.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, -wallHeight / 3);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, -wallHeight / 3);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, wallHeight / 3);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, wallHeight / 3);
		glEnd();
		glPopMatrix();

		//desenha porta 2
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX + wallWidthC*1.17f, wallHeight / 3, posZ - wallWidthD*0.663f);
		glRotatef(90.0f, 1, 0, 0);
		//glRotatef(90.0f, 0, 0, 1);

		glBegin(GL_QUADS);
		glNormal3f(1, 0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, -wallHeight / 3);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, -wallHeight / 3);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthD / 3, posY, wallHeight / 3);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthD / 3, posY, wallHeight / 3);
		glEnd();
		glPopMatrix();

		//desenha roof 1
		glBindTexture(GL_TEXTURE_2D, roofTexture);
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX, wallWidthA, posZ - 4.0f);
		glRotatef(45.0f, 1, 0, 0);

		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthA, posY, -roofHeight);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthA, posY, -roofHeight);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthA, posY, roofHeight);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthA, posY, roofHeight);
		glEnd();
		glPopMatrix();

		//desenha roof 2
		glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuseLight);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);

		glTranslatef(posX, wallWidthA, posZ - wallWidthA + 4.0f);
		glRotatef(-45.0f, 1, 0, 0);

		glBegin(GL_QUADS);
		glNormal3f(0, 1, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-wallWidthA, posY, -roofHeight);
		glTexCoord2f(0.0f, 80.0f); glVertex3f(wallWidthA, posY, -roofHeight);
		glTexCoord2f(80.0f, 80.0f); glVertex3f(wallWidthA, posY, roofHeight);
		glTexCoord2f(80.0f, 0.0f); glVertex3f(-wallWidthA, posY, roofHeight);
		glEnd();
		glPopMatrix();
}

void House::update() {}
void House::load() {
	roofTexture = SOIL_load_OGL_texture("files/textures/roof.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture = SOIL_load_OGL_texture("files/textures/wall.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
House::~House()
{
}
