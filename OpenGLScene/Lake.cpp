#include "Lake.h"



void Lake::update()
{
	if (alfa > 1.0f) alfa = 0;
	if (a > 1.0f) a = 0;
	if (b > 1.0f) b = 0;
	if (c > 1.0f) c = 0;
	if (material > 100.0f) material = 0;
	if(!increase)
	translation -= 0.6f;
	else translation += 0.6f;
	rotation += 2.0f;
	alfa += 0.01f;
	a += 0.001f;
	b += 0.001f;
	c += 0.01f;
	material += 5.0f;
	shininess += 0.01f;
	if (shininess > 1.0f) shininess = 0.8;
	if (translation <= -30.0f && !increase) {
		increase = true;
	}
	else if (translation >= 30.0f && increase) {
		increase = false;
	}
	if (rotation >= 120) rotation = 0;
}

void Lake::load() {
	texture = SOIL_load_OGL_texture("files/textures/water.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	woodTexture = SOIL_load_OGL_texture("files/textures/wood2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
}
void Lake::draw() {
	GLfloat mat_specular[] = { 0.7f, 0.5f, 0.6f, 0.8f };
	GLfloat mat_shininess[] = { shininess };
	GLfloat ambientLight[] = { 0.8f, 0.7f, 0.3f, alfa };
	GLfloat difuseLight[] = { 0.8, 0.8, 0.8, alfa };
	GLfloat luzEmissiva[] = { 0.2, 0.2, 0.2, alfa };
	glBindTexture(GL_TEXTURE_2D, texture);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, 1.0f);

	glPushMatrix();

	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);

	glTranslatef(posX, posY, posZ);

	glBlendFunc(GL_SRC_ALPHA, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY, -widthZ);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY, -widthZ);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY, widthZ);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY, widthZ);

	glEnd();

	glPopMatrix();
	glPushMatrix();

	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ);

	glBlendFunc(GL_SRC_ALPHA, 1.0f);

	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, -widthZ);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, -widthZ);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, widthZ);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, widthZ);
	glEnd();
	glPopMatrix();


	//onda
	//p1
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//onda-cima
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY + 2.3f, posZ + 4.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 1.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 1.0f);
	glEnd();
	glPopMatrix();

	//p2
	//onda
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ + 5.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//onda-cima
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY + 2.3f, posZ + 9.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(-rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 1.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 1.0f);
	glEnd();
	glPopMatrix();


	//onda
	//p3
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ - 12.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//onda-cima
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY + 2.3f, posZ - 11.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 1.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 1.0f);
	glEnd();
	glPopMatrix();


	//onda
	//p1
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ + 15);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//onda-cima
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY + 2.3f, posZ + 19.0f);
	glTranslatef(0.0f, 0.0f, translation);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, -1.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 3.0f, 1.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 3.0f, 1.0f);
	glEnd();
	glPopMatrix();


	glDisable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, woodTexture);

	//barreira 1
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, -5.1f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, 8.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//barreira 2
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX, posY, posZ * 2 - 5.1f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, 8.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//barreira 3
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX + widthX + 5.1f, posY, posZ);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, 8.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//barreira 4
	glPushMatrix();
	glNormal3f(0, 1, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuseLight);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
	glMaterialfv(GL_FRONT, GL_EMISSION, luzEmissiva);
	glTranslatef(posX - widthX + 5.1f, posY, posZ);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, -8.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(widthX, widthY + 5.0f, 8.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(-widthX, widthY + 5.0f, 8.0f);
	glEnd();
	glPopMatrix();
}

Lake::Lake(float posX, float posY, float posZ, float widthX, float widthY, float widthZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->widthX = widthX;
	this->widthY = widthY;
	this->widthZ = widthZ;
	this->alfa = 0;
	 this->a = 0;
	 this->b =0;
	 this->c = 0;
	 this->material = 0;
	 this->shininess = 0.8;
	 this->increase = false;
}

Lake::~Lake()
{
}
