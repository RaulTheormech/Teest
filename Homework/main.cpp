#include <stdio.h>    
#include <string.h>
#include <math.h>
#include <fstream>
#include <time.h>

#include <iostream>
#include <stdlib.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace std;
void drawCircle(float); // ������ ����
void drawPlanets(); // ������ ������� (��. ������� ����)
void drawStars();

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //������ �������� ������� ������
} 
// RGB Red Green Blue

void handleKeypress(unsigned char key, int x, int y) { // ����� �� ��������� ��� ������� ����� ������
	switch (key) { // switch ��� ������� if ��� ��������� ��������� (�����������)
	case 1:
		exit(0); // ����� �� ���������
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f); // ������� 
	}

}



// �� ��������� ���� ������� ��������. ������� ���.
void initRendering() { // ������
	glEnable(GL_DEPTH_TEST); // ������ ������� �� gl. � ������: ���� �������
}
// ������, � ���������� ������ ������� OpenGL ����� ������������� ��������� �������� �������
// ��� ���� ��������� ���� ���������� � ����������� �� ���������.


void handleResize(int w, int h) {
	glViewport(0, 0, w, h); // ������� ������ ���� ���������.
	glMatrixMode(GL_PROJECTION); //������� ���������, ����� ������� �������� ������� ��������.
	// ��������� ����������� �������� � �������� � ����� ������� ��������.

	glLoadIdentity(); //������� �������� ������� ������� �������� ���������������.
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0); // ������� ����������� ������� ������������� ��������.
}

// ���� ���������
// .f ����� ����� ������ ��� ������ � ��������� �������.
float mercury_angle = 30.0f;
float satrun_ring_angle = 30.0f;
float venus_angle = 30.0f;
float earth_angle = 30.0f;
float mars_angle = 30.0f;
float jupiter_angle = 30.0f;
float satrun_angle = 30.0f;
float uranus_angle = 30.0f;
float neptune_angle = 30.0f;
float _cameraAngle = 0.0f;

//������ 3� �����
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ������� ��������� ������, � ������
	// ������� ������ ����� � 	������� ������ �������.
	glMatrixMode(GL_MODELVIEW); // ��������� ����������� ��������� �������� � ����� ������ ������������� ������.
	glLoadIdentity(); // �������� ������� ������� �������� ���������������.
	glTranslatef(0.0f, 0.0, -50.0f); // ������������ ������� ������� ( ������� � ������ ������ ���������).
	glScalef(0.4f, 0.4f, 0.4f); // ������ �������


	// ������ ������ ������ (������ ����� �� ���������)
	drawCircle(4.62);
	drawCircle(9);
	drawCircle(12.5);
	drawCircle(18.8);
	drawCircle(30);
	drawCircle(39.5);
	drawCircle(52);
	drawCircle(63);

	// ������ �����
	drawStars();

	drawPlanets(); // ������ �������
	glutSwapBuffers(); //����� ��������� �� ������������ (��������) ������

	/*
	Swap Buffers - ����� �������. ��� ����� ������� ��� ��������. 
	�� ���������� ���� � ������� ������������, ���� ����� ������������ � ������ - ����������. 
	� ����� ������ ���������� OpenGL �� ��������� ����������� ������ ����������� � ����������� ������. 
	����� ������� glutSwapBuffers ���������� ������, ��������� ���� ������� ����� ����, ��� ��� ��� ������������. 
	��� ���������� ������ � ������������ ��������, ��� ��� �� ��������� ������������� ����� ������, ��� ����� �� ������ ����������� ����. 
	*/

}

void drawStars() {
	// ������ ���������
	glPushMatrix(); // ����� ������� �� ������� ���� (������)
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//������������� ����� ��� ��������� ��������������.
	/*
	������ �������� ���������, ��� ����� ���������� �������������.
	�� ��������� ��������: GL_POINT(�������� ������ �����), GL_LINE(������ �����) � GL_FILL(������ ����������� �������������).
	������ �������� ���������: � �������, ������� ��� �� � ����� �������� ����������� �����, �������� ������ ����������.
	*/
	glColor3f(1, 1, 1); 	// ���� RGB �� 0 �� 1
	glTranslatef(55, 0, 0.0f); // �������� (X,Y,Z) (0.0.0) ��� ����� (������)
	glutSolidSphere(0.2, 50, 50); // ����� � �������� 0.2. 50 - ������, 50 - �������
	glEnd(); // ��������� ��������
	glPopMatrix(); // ��������� � ���� ��������, ��� ������

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(48, 28, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 1, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(60, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(58, 30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd(); 
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(55, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, 35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(72, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, 20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(50, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(40, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(30, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(80, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	// ������ �����

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(60, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(58, -30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(55, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, -35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(72, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, -20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(50, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(40, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(30, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(80, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, -25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();


	// ����� ���������
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 43, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 0, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-48, 28, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 1, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-60, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-58, 30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, 35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-72, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, 20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-50, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-40, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-30, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-80, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	// ������ �����

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-60, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-58, -30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, -35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-72, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, -20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-50, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-40, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-30, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-80, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, -25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();
}

void drawPlanets() {

	//Sun
	glPushMatrix(); //��� ���������� � �������������� ������� ���������
	/*
	�������� ������� ���� ������ �� ������� ����, �������� ������� �������.
	�� ���� ����� ������ glPushMatrix ������� ������� ����� ��������� ������� ��� ���.
	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //��� ������������� ����� ��� ��������� ��������������.
	/*
	������ �������� ���������, ��� ����� ���������� �������������. 
	�� ��������� ��������: GL_POINT(�������� ������ �����), GL_LINE(������ �����) � GL_FILL(������ ����������� �������������). 
	������ �������� ���������: � �������, ������� ��� �� � ����� �������� ����������� �����, �������� ������ ����������.
	*/
	glColor3f(0.9, 0.9, 0.0);
	/*
	��������� ������ ���� ���������� ������� glColor3f(r, g, b). 
	��� �� ��������� ��������� ������������ ����� �������, ����� � ������� ������������. 
	������ �� ��� ����� ��������� �������� �� 0.0f �� 1.0f.
	*/
	glutSolidSphere(2.5, 50, 50);
	// glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
	// ������ ����� � �������� 2.5, 
	/*
	slices ���������� ������� ������ ��� Z. (������)
	stacks ���������� ������� ����� ��� z. (������� (��. ������))
	*/
	glEnd(); // �� ��������� �������� ��������
	glPopMatrix(); // ��������� ������� ���� ������, ������� ������� ������� ���, ��� ��������� ��� ��� � �����.

	// ������ ����������

	//��������
	glPushMatrix();
	glRotatef(mercury_angle, 0.0f, 0.0f, 1.0f); // ������� ������� ���������
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(3.84f, 0.0, 0.0f); // �������� ������� ��������� ��� ��������
	glutSolidSphere(0.492, 50, 50);
	glPopMatrix();

	//������
	glPushMatrix();
	glRotatef(venus_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(7.23f, 0.0, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(255.0, 215.0, 0.75);
	glutSolidSphere(0.4755, 50, 50);
	glPopMatrix();


	//�����
	glPushMatrix();
	glRotatef(earth_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.137255, 0.137255, 0.556863);
	glTranslatef(10.0f, 0.0, 0.0f);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	//����
	glPushMatrix();
	glRotatef(mars_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8, 0.0, 0.0);
	glTranslatef(15.2f, 0.0, 0.0f);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	//������
	glPushMatrix();
	glRotatef(jupiter_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.36, 0.25, 0.20);
	glTranslatef(24.0f, 0.0f, 0.0f);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//������
	glPushMatrix();
	glRotatef(satrun_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef(32.0f, 0.0, 0.0f);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(1.7, 50, 50);
	glPopMatrix();

	//������ �������
	glPushMatrix();
	glRotatef(satrun_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(39.73f, 0.0, 0.0f);
	drawCircle(3);
	glPopMatrix();


	//����
	glPushMatrix();
	glRotatef(uranus_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 1);
	glTranslatef(42.0f, 0.0, 0.0f);
	glutSolidSphere(1.6, 50, 50);
	glPopMatrix();

	//������
	glPushMatrix();
	glRotatef(neptune_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.35, 0.35, 0.67);
	glTranslatef(51.0f, 0.0, 0.0f);
	glutSolidSphere(1.5, 50, 50);
	glPopMatrix();
}


void drawCircle(float radius) { // ������� ���������� ���������� � ��������

	int cir_x = 0;
	int cir_y = 0;
	int min_angle = 0;
	int max_angle = 360;
	float theta;
	int i;
	float cir_x_itr;
	float cir_y_itr;
	float x;
	float y;

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (i = min_angle; i <= max_angle; i++) {

		theta = 0.0174532925 * float(i); // 1 ������ ��� 0.0174532925 ������. �� ����� i-�� ������������ ����
		cir_x_itr = radius * cosf(theta); // ���������� ��� ��������� i-�� ������������ ����� �� � � �
		cir_y_itr = radius * sinf(theta);

		x = cir_x + cir_x_itr;
		y = cir_y + cir_y_itr;

		glVertex3f(x, y, -30.0f); // ��������� ������� �� �����������
	}
	glEnd();
	glPopMatrix();
}


void update_mercury(int value) {
	mercury_angle += 2.0f;
	if (mercury_angle > 360) {
		mercury_angle -= 360;
	}

	glutPostRedisplay(); // �������� �������� ����, ������� ������ ���� ������������, ��� ������ ��������� �����
	glutTimerFunc(4.82, update_mercury, 0); 
	/*
	��� ������� ������������� ������. 
	������ �������� millis ������ ����� � �������������, �� ��������� ������� ���������� �������, 
	(������ ����������� ��������)
	������� ������� ��� ������ ��������. 
	������ �������� value ��������� �������������� �������, 
	�.�. �������� ����� ���� ������������ �������� ���������.
	*/
}

void update_venus(int value) {
	venus_angle += 2.0f;
	if (venus_angle > 360) {
		venus_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(10.3, update_venus, 0);
}


void update_earth(int value) {
	earth_angle += 2.0f;
	if (earth_angle > 360) {
		earth_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(15, update_earth, 0);
}

void update_mars(int value) {
	mars_angle += 2.0f;
	if (mars_angle > 360) {
		mars_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25.2, update_mars, 0);
}
void update_jupiter(int value) {
	jupiter_angle += 2.0f;
	if (jupiter_angle > 360) {
		jupiter_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(36.5, update_jupiter, 0);
}
void update_satrun(int value) {
	satrun_angle += 2.0f;
	if (satrun_angle > 360) {
		satrun_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40.2, update_satrun, 0);
}
void update_satrun_ring(int value) {
	satrun_ring_angle += 2.0f;
	if (satrun_ring_angle > 360) {
		satrun_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40.2, update_satrun_ring, 0);
}





void update_uranus(int value) {
	uranus_angle += 2.0f;
	if (uranus_angle > 360) {
		uranus_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(50.5, update_uranus, 0);
}
void update_neptune(int value) {
	neptune_angle += 2.0f;
	if (neptune_angle > 360) {
		neptune_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(61.8, update_neptune, 0);
}



int main(int argc, char** argv) {

	/*
	  glutInit(int **argcp, char **argv); 
	argc - ��� ��������� �� ��� �� ���������� ���������� argc ������� ������� ��������� (main). 
	����� �������� �� �������, ��������, �� ������� ��������� argcp, ����� ����������, 
	��� ��� glutInit ��������� ��� ����� ��������� ������, ����������� � ���������� GLUT, 
	��������, � ������� X-Window ��� �����, ����������� � ���������� ������, ������������� � GLUT. 
	argv - ��� ��� �� ���������� ���������� argv ������� �������.  

	glutInit ����������� �� ������������� ���������� ��������� GLUT 
	� ������� ������ � �������� ���������� ������.
	*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/* ����� ������ ����:
   ��������� ����� � RGBA ������� */
	glutInitWindowSize(1080, 720);
	/* ��������� �������� ���� */

	initGL(); // ������� �����

	glutCreateWindow("2D Solar System"); // �������� ����
	initRendering(); // ������ � ������ �������


	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);


	glutTimerFunc(4.82, update_mercury, 0);
	glutTimerFunc(12.3, update_venus, 0);
	glutTimerFunc(15, update_earth, 0);
	glutTimerFunc(25.2, update_mars, 0);
	glutTimerFunc(36.5, update_jupiter, 0);
	glutTimerFunc(40.2, update_satrun, 0);
	glutTimerFunc(40.2, update_satrun_ring, 0);
	glutTimerFunc(50.5, update_uranus, 0);
	glutTimerFunc(61.8, update_neptune, 0);

	glutMainLoop();
	return 0;
}



