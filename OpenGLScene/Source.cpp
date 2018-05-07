#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <map>
#include <cstring>
#include "Terrain.h"
#include "Control.h"
#include "Camera.h"
#include "Cloud.h"
#include "Mist.h"
#include "Puppet.h"
#include "Tree.h"
#include "Bird.h"
#include "WindMill.h"
#include "Lake.h"
#include "House.h"
#include "LightSource.h"
#include "Kiosk.h"
#include "Table.h"
#include "Chair.h"
#include "Cart.h"
#include "SceneObject.h"

using namespace std;

//Intervalo de atualização
float FPS = 1000 / 45;

//Tamanho e posição inicial da janela
int width = 720, height = 480, px = 100, py = 100;

//Cria um objeto da classe Terrain
Terrain terrain = Terrain(320.0f, 0.0f, 320.0f);

//Cria um objeto da classe Control
Control control = Control();

//Cria um objeto da classe Câmera
Camera camera = Camera();

//Cria um vetor de objetos da classe Cloud
Cloud cloud = Cloud(320.0f, 320.0f, 320.0f);

//Cria um boneco
Puppet puppet = Puppet(300.0f, 0.0f, 100.0f);

//Cria um objeto da classe Tree
Tree tree = Tree(50.0f, 0.0f, 50.0f);

//Cria os objetos da classe Bird
Bird bird1 = Bird(100.0f, 100.0f, 40.0f, 0.03f, true);
Bird bird2 = Bird(80.0f, 90.0f, 50.0f, 0.03f, true);
Bird bird3 = Bird(100.0f, 90.0f, 50.0f, 0.03f, false);
Bird bird4 = Bird(80.0f, 100.0f, 40.0f, 0.03f, false);
Bird bird5 = Bird(-10.0f, 100.0f, -40.0f, 0.04f, true);
Bird bird6 = Bird(-20.0f, 90.0f, -130.0f, 0.05f, true);
Bird bird7 = Bird(-100.0f, 90.0f, -150.0f, 0.06f, false);
Bird bird8 = Bird(-80.0f, 120.0f, -60.0f, 0.07f, false);
Bird bird9 = Bird(0.0f, 120.0f, -240.0f, 0.08f, false);
Bird birds[] = { bird1, bird2,bird3,bird4,bird5,bird6,bird7,bird8,bird9 };

//Cria objetos da classe wind de Vento
WindMill wind1 = WindMill(10.0f, 0.0f, 180.0f, 20.0f, 8.0f, 100.0f);
WindMill wind2 = WindMill(-80.0f, 0.0f, -100.0f, 12.0f, 6.0f, 70.0f);
WindMill winds[] = { wind1, wind2 };

//Cria um objeto da classe Lake
Lake lake = Lake(120.0f, 0.2f, 50.0f, 50.0f, 0.1f, 50.0f);

//Cria um objeto da classe Mist
float mistColor[] = { 0.8, 0.8, 0.8, 1.0 };

// Nevoeiro 
Mist mist = Mist(0.0005, mistColor);

//Cria os objetos da classe House
House house1 = House(20.0f, 10.0f, 20.0f, 10.0f, 8.0f, 8.5f, 100.0f, 0.0f, 190.0f);
House house2 = House(20.0f, 10.0f, 20.0f, 10.0f, 8.0f, 8.5f, 50.0f, 0.0f, 280.0f);
House house3 = House(20.0f, 10.0f, 20.0f, 10.0f, 8.0f, 8.5f, -50.0f, 0.0f, -120.0f);
House house4 = House(20.0f, 10.0f, 20.0f, 10.0f, 8.0f, 8.5f, 0.0f, 0.0f, -190.0f);
House house5 = House(20.0f, 10.0f, 20.0f, 10.0f, 8.0f, 8.5f, -10.0f, 0.0f, -20.0f);
House houses[] = { house1, house2, house3,house4, house5 };

//Cria os objetos da classe LightSource
LightSource light1 = LightSource(-123.0f, 40.0f, -148.0f, false, false);
LightSource light2 = LightSource(85.0f, 90.0f, 105.0f, false, true);
LightSource lightCam = LightSource(camera.posX, camera.posY, camera.posZ, true, false);
LightSource lights[] = { light2, light1 };

//Cria os objetos da classe Kiosk
Kiosk kiosk1 = Kiosk(-180.0f, 0.05f, -80.0f);
Kiosk kiosk2 = Kiosk(-120.0f, 0.05f, 70.0f);
Kiosk kiosk3 = Kiosk(-10.0f, 0.05f, 60.0f);
Kiosk kiosks[] = { kiosk1, kiosk2,kiosk3 };

//Cria os objetos da classe Table
Table table1 = Table(-20.0f, 0.05f, 80.0f);
Table table2 = Table(-30.0f, 0.05f, 75.0f);
Table table3 = Table(-35.0f, 0.05f, 90.0f);
Table tables[] = { table1, table2, table3 };

//Cria os objetos da classe Chair
Chair chair1 = Chair(-20.0f, 0.05f, 85.0f);
Chair chair2 = Chair(-25.0f, 0.05f, 80.0f);
Chair chair3 = Chair(-35.0f, 0.05f, 75.0f);
Chair chair4 = Chair(-45.0f, 0.05f, 90.0f);
Chair chair5 = Chair(-40.0f, 0.05f, 60.0f);
Chair chairs[] = { chair1, chair2, chair3, chair4, chair5 };

//Cria os objetos da classe Cart
Cart cart1 = Cart(-81.0f, 0.05f, -11.0f);
Cart cart2 = Cart(-69.0f, 0.05f, 61.0f);
Cart cart3 = Cart(-98.0f, 0.05f, 118.0f);
Cart cart4 = Cart(-13.0f, 0.05f, -30.0f);
Cart carts[] = { cart1, cart2, cart3, cart4 };

//Início das funções que identificam as teclas pressionadas
void keyboardUp(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		control.w = false;
		break;

	case 'a':
	case 'A':
		control.a = false;
		break;

	case 's':
	case 'S':
		control.s = false;
		break;

	case 'd':
	case 'D':
		control.d = false;
		break;
	case 'f':
	case 'F':
		control.F = false;
		break;
	case 'g':
	case 'G':
		control.G = false;
		break;
	case '+':
		control.more = false;
		break;
	case '-':
		control.less = false;
		break;
		break;
	}
}
void keyboardDown(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		control.esc = true;
		break;
	case 'w':
	case 'W':
		control.w = true;
		break;

	case 'a':
	case 'A':
		control.a = true;
		break;

	case 's':
	case 'S':
		control.s = true;
		break;

	case 'd':
	case 'D':
		control.d = true;
		break;

	case 'f':
	case 'F':
		control.F = true;
		break;
	case 'g':
	case 'G':
		control.G = true;
		break;
	case 'o':
	case 'O':
		control.O = control.O ? false : true;
		break;
	case 'l':
	case 'L':
		control.L = control.L ? false : true;
		break;
	case '+':
		control.more = true;
		break;
	case '-':
		control.less = true;
		break;
	}
}
void keyboardSpecialUp(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:
		control.down = false;
		break;
	case GLUT_KEY_UP:
		control.up = false;
		break;
	}
}
void keyboardSpecialDown(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:
		control.down = true;
		break;

	case GLUT_KEY_UP:
		control.up = true;
		break;
	}
}

//Fim das funções que identificam as teclas pressionadas
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1);
	terrain.draw();
	cloud.draw();
	puppet.draw();
	for (Chair &object : chairs) {
		object.draw();
	}
	for (Kiosk &object : kiosks) {
		object.draw();
	}
	tree.draw();
	for (Bird &object : birds) {
		object.draw();
	}
	for (Cart &object : carts) {
		object.draw();
	}
	for (Table &object : tables) {
		object.draw();
	}
	lake.draw();
	for (WindMill &object : winds) {
		object.draw();
	}
	for (House &object : houses) {
		object.draw();
	}

	for (LightSource &object : lights) {
		object.draw();
	}
}

void reshape(int width, int height) {
	if (height == 0) height = 1;
	int taxa = 1.0f * width / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0, taxa, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.posX, camera.posY, camera.posZ, camera.posX + camera.dxcamera, camera.posY + camera.dycamera, camera.posZ + camera.dzcamera, 0.0f, 1.0f, 0.0f);
}

void loadObjects() {

	terrain.load();
	cloud.load();
	for (Chair &object : chairs) {
		object.load();
	}

	for (Kiosk &object : kiosks) {
		object.load();
	}
	
	for (Bird &object : birds) {
		object.load();
	}

	for (Cart &object : carts) {
		object.load();
	}

	for (Table &object : tables) {
		object.load();
	}
	for (WindMill &object : winds) {
		object.load();
	}

	lake.load();

	tree.load();

	puppet.load();

	for (House &object : houses) {
		object.load();
	}

	for (LightSource &object : lights) {
		object.load();
	}
}

void updateCamera() {
	glLoadIdentity();
	GLfloat cameraPosition[4] = { camera.posX,camera.posY,camera.posZ, 1.0f };

	GLfloat ambientLight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat difuseLight[] = { camera.r, camera.g, camera.b, camera.a };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat spot[3] = { camera.posX, camera.posY,camera.posZ };

	gluLookAt(camera.posX, camera.posY, camera.posZ, camera.posX + camera.dxcamera, camera.posY + camera.dycamera, camera.posZ + camera.dzcamera, 0.0f, 1.0f, 0.0f);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT2, GL_POSITION, cameraPosition);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, difuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180.0f); // ângulo
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0f);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 45.0f); // intensity
}

void configureLight() {
	for (LightSource &object : lights) {
		object.configure();
	}
}
void init() {
	glShadeModel(GL_SMOOTH);                                               /*sombreamento suavizado*/

	glEnable(GL_COLOR_MATERIAL);                                           /*habilita o uso de configuração de materiais*/
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);                      						   /*habilita iluminação*/
	glEnable(GL_LIGHT0);												   /*habilita as diversas luzes*/
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	loadObjects();	
	configureLight();
	glEnable(GL_DEPTH_TEST);                                               /*habilita teste de profundidade*/
	glEnable(GL_FOG); //Habilida o uso da FOG
	glFrontFace(GL_CW);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, mist.density); // densidade da Mist
	glFogfv(GL_FOG_COLOR, mist.color); //color da Mist
	glEnable(GL_TEXTURE_2D);                                            /* habilita o uso de texturas 2d*/
	updateCamera();
	camera.updateAngle();
}

void update(int val) {
	//Verifica as teclas pressionadas
	if (control.a) { camera.angle -= 0.02; camera.updateAngle(); }
	if (control.d) { camera.angle += 0.02; camera.updateAngle(); }
	if (control.s) { camera.posZ += -1 * (camera.dzcamera)*camera.velocity; camera.posX += -1 * (camera.dxcamera)*camera.velocity; }
	if (control.w) { camera.posZ += (camera.dzcamera)*camera.velocity; camera.posX += (camera.dxcamera)*camera.velocity; }
	if (control.F) {
		if (mist.density*1.10 > mist.maxDensity) {
			mist.density = mist.maxDensity;
		}
		else {
			mist.density *= 1.10;
		}
		glFogf(GL_FOG_DENSITY, mist.density);
	}
	if (control.G) {
		if (mist.density / 1.10 < mist.minDensity) {
			mist.density = mist.minDensity;
		}
		else {
			mist.density /= 1.10;
		}
		glFogf(GL_FOG_DENSITY, mist.density);
	}
	if (control.down) { if (camera.posY >= 2) camera.posY -= 1; }
	if (control.up) { camera.posY += 1; }
	if (control.esc) { exit(0); }

	//Atualização dos objetos do cenário
	
	for (Bird &object : birds) {
		object.update();
	}

	for (Chair &object : chairs) {
		object.update();
	}
	tree.update();

	for (WindMill &object : winds) {
		object.update();
	}
	lake.update();

	puppet.update();
	tree.update();
	
	// Atualização dos pontos de luz
	for (LightSource &light: lights) {
		if (control.L) 
			light.isOn = true;
		else 
			light.isOn = false;
	}

	//Atualiza câmera
	if (!control.O) {
		if (control.more)
			camera.updateMagnitude(true);
		if (control.less)
			camera.updateMagnitude(false);
	}
	if (control.O) {
		glDisable(GL_LIGHT2);
	}
	else { glEnable(GL_LIGHT2); }

	updateCamera();
	glutSwapBuffers();

	glutPostRedisplay();
	glutTimerFunc(FPS, update, 0);
}

//Configurações iniciais para o cenário 3d
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(px, py);
	glutInitWindowSize(width, height);
	glutCreateWindow("Village");

	init();

	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(keyboardSpecialDown);
	glutSpecialUpFunc(keyboardSpecialUp);

	glutDisplayFunc(draw);
	glutTimerFunc(FPS, update, 0);
	//glutFullScreen();
	glutReshapeFunc(reshape);
	
	glutMainLoop();

	return 0;
}