/***********************************************************************/
/*                             HW#8. ����                              */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 12��  8��   */
/*                                                                     */
/*  ���� ���� :   ���ݱ��� ������ �ǽ������� ������ �����Ͽ�           */
/*                ��ü�� �𵨸��ϰ�, �ݹ����α׷���, �𵨺�ȯ,         */
/*                ������ȯ, ������ȯ, ������ȯ, ���ü��˻�, ����,      */
/*				  �ؽ��� �� �����ð��� ����� ����� ��� ���� ��      */
/*				  �ֵ��� ���α׷��� �����ÿ�.                      */
/*                                                                     */
/*  ��� :        �� ����                                              */
/*                R - �ʱ�ȭ          G - ���ӽ���                     */
/*                A - �������� ����   Z - �������� �Ʒ���              */
/*               �� - �������� ����  �� - �������� �Ʒ���              */
/***********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <GL/glaux.h>
#include <GL/glut.h>
#include <ctime>
using namespace std;

GLUquadricObj *qobj = gluNewQuadric();	// ���ο� Quadric�� ����
static double cx = 0.0, cy = 0.0, cz = 0.0, rx = 0.0, ry = 0.0, rz = 0.0;	// ī�޶��� ��ġ�� ������ ����
static double ballx = 0.0, bally = 0.0, ballz = 0.0;	// ���� ��ġ�� ������ ����
static double stickLz = 0.0, stickRz = 0.0;	// ��, ���� ������ ��ġ�� ������ ����
static bool stickLUpStop = true, stickLDnStop = true, stickRUpStop = true, stickRDnStop = true, ballStop = true;	// ������ �� �ִ� ��ü���� ������ �ο� ����
static int temp, ranNumA;	// ������ ���� ���� ����
static double deltaX;

void moveStickLUp(int); void moveStickLDn(int); void moveStickRUp(int); void moveStickRDn(int);
void moveBallUpL(int); void moveBallDnL(int); void moveBallUpR(int); void moveBallDnR(int);

char Filename[] = "brick.bmp";	// �ؽ��� ���ο� ���� ������ �̸�
AUX_RGBImageRec *LoadBMP(char *Filename) {
	FILE * File = NULL;
	if (!Filename) return NULL;
	fopen_s(&File, Filename, "r");

	// seFilename�� �����ڵ� ��Ʈ������ �ٲٱ�
	int size = strlen(Filename);
	wchar_t* w_Filename = new wchar_t[size];

	for (int i = 0; i <size; ++i)  w_Filename[i] = Filename[i];
	w_Filename[size] = NULL;

	if (File) {
		fclose(File);
		return auxDIBImageLoad(w_Filename);     //���Ϸκ��� �޸𸮷�
	}
	return NULL;
}

int LoadGLTextures() {
	int Status = FALSE;
	AUX_RGBImageRec *TextureImage[1];
	memset(TextureImage, 0, sizeof(void *) * 1);

	if (TextureImage[0] = LoadBMP(Filename)) {
		Status = TRUE;

		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);	// GLU �Ӹ� ����

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// �ؽ��� �Ķ����
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);	// �ڵ� �ؽ��� ����
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);	// ��ü�� MCS�� ������� �ؽ��� ��ǥ ����
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
	}

	if (TextureImage[0]) {
		if (TextureImage[0]->data) {
			free(TextureImage[0]->data);
		}

		free(TextureImage[0]);
	}

	return Status;
}

void MyInit(void) {
	LoadGLTextures();	// �ؽ��� �ε�

	glClearColor(0.0, 0.0, 0.0, 1.0);	// �������� ������ �ʱ�ȭ
	glShadeModel(GL_SMOOTH);

	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // �ֺ����� ����
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // �ݻ籤�� ����
	GLfloat mat_shininess[] = { 50.0 }; // ����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // ������ ��ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);	// ���� �𵨿� ���� ���� �Ű� ������ ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// ���� �Ű� ���� ���� ��ȯ
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);	// ���� �� �Ű� ������ ����

	glEnable(GL_LIGHTING);	// �����带 Ȱ��ȭ
	glEnable(GL_LIGHT0);	// 0�� ������ Ȱ��ȭ
	glEnable(GL_DEPTH_TEST);	// ���� ���۸� Ȱ��ȭ
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// ���ٿ� ���� �ؽ��� ������ ���� �Լ�
	glEnable(GL_TEXTURE_2D);	// �ؽ��� ��� Ȱ��ȭ
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �÷� ���ۿ� ���� ���۸� �ʱ�ȭ

	glMatrixMode(GL_MODELVIEW);	// �𵨺���� ���� ���� ����
	glLoadIdentity();	// ���� ����� �׵������ ����� �ʱ�ȭ

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	gluQuadricDrawStyle(qobj, GLU_FILL);	// Quadric�� Draw Style�� FILL�� ����
	gluQuadricNormals(qobj, GLU_SMOOTH);	// ��ü�� �𼭸��� �ε巴�� ���̵��� �������� ����
	gluQuadricOrientation(qobj, GLU_OUTSIDE);	// �ٱ����� ����Ű�� ���͸� ���� Quadric �׸���
	gluQuadricTexture(qobj, GL_FALSE);	// Texture ��ǥ �̻���

	glViewport(0, 0, 500, 500);	// ������ȯ �Լ��� ȣ��
	gluLookAt(0.0 + cx, 1.0 + cy, 0.0 + cz, 0.0, 0.1, -0.1, 0.0 + rx, 1.0 + ry, 0.0 + rz);	// ī�޶� (0, 1, 0)�� ��ġ, (0, 0.1, -0.1)�� �ٶ󺸰�, y������ 1��ŭ ����̰� ����

	glPushMatrix();	// ��
		glTranslatef(ballx, bally, ballz);
		gluSphere(qobj, 0.5, 10, 10);
	glPopMatrix();

	glPushMatrix();	// ��ܹ�
		glTranslatef(0.0, 0.0, -9.0);
		glRotatef(45, 1.0, 0.0, 0.0);
		glScalef(18.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// �ϴܹ�
		glTranslatef(0.0, 0.0, 9.0);
		glRotatef(45, 1.0, 0.0, 0.0);
		glScalef(18.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// ���� ����
		glTranslatef(-9.0, 0.0, stickLz);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(30, 1.0, 0.0, 0.0);
		glScalef(6.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// ���� ����
		glTranslatef(9.0, 0.0, stickRz);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(30, 1.0, 0.0, 0.0);
		glScalef(6.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glutSwapBuffers();	// �����ӹ��۸� ��ȯ
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	GLfloat wf = (GLfloat)w / (GLfloat)500;
	GLfloat hf = (GLfloat)h / (GLfloat)500;

	glMatrixMode(GL_PROJECTION);	// ������� ���� ���� ����
	glLoadIdentity();

	glOrtho(-10.0 * wf, 10.0 * hf, -10.0 * hf, 10.0 * wf, -10.0, 10.0);	// ����� ��� ������ ���������� ���Ͽ� ���� ����

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A':	// 'A', 'a' �Է� �� ���� ���븦 ���� ������
	case 'a':
		stickLUpStop = false; stickLDnStop = true;
		glutTimerFunc(20, moveStickLUp, 1);	// Ÿ�̸� �̺�Ʈ�� Ư���� ���������� Ÿ�̸� �̺�Ʈ�� �߻���Ŵ. moveStickLUp �Լ��� 20ms �Ŀ� ����
		break;
	case 'Z':	// 'Z', 'z' �Է� �� ���� ���븦 �Ʒ��� ������
	case 'z':
		stickLUpStop = true; stickLDnStop = false;
		glutTimerFunc(20, moveStickLDn, 1);
		break;
	case 'G':	// 'G', 'g' �Է� �� ���� ����
	case 'g':
		ballStop = false;

		srand((unsigned int)time(NULL));
		ranNumA = rand(); temp = rand(); deltaX = ((temp % 7) + 10);	// ranNumA, temp�� ���� ���� �Է�, deltaX�� ���� ���� ��ȯ�Ͽ� �Է�
		switch (ranNumA % 4) {	// �������� ���� ������ ����
			case 0:
				glutTimerFunc(20, moveBallUpL, 1);
				break;
			case 1:
				glutTimerFunc(20, moveBallDnL, 1);
				break;
			case 2:
				glutTimerFunc(20, moveBallUpR, 1);
				break;
			case 3:
				glutTimerFunc(20, moveBallDnR, 1);
				break;
		}
		break;
	case 'R':	// 'R', 'r' �Է� �� ��� ��� �ʱ�ȭ
	case 'r':
		cx = 0.0; cz = 0.0;
		ballx = 0, bally = 0, ballz = 0;
		stickLz = 0, stickRz = 0;
		stickLUpStop = true, stickLDnStop = true, stickRUpStop = true, stickRDnStop = true, ballStop = true;
		glutPostRedisplay(); 	// ������ ���÷��� �̺�Ʈ�� �߻�
		break;
	}
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:	// �� �Է½� ���� ���븦 ���� ������
		stickRUpStop = false; stickRDnStop = true;
		glutTimerFunc(20, moveStickRUp, 1);
		break;
	case GLUT_KEY_DOWN:	// �� �Է½� ���� ���븦 �Ʒ��� ������
		stickRUpStop = true; stickRDnStop = false;
		glutTimerFunc(20, moveStickRDn, 1);
		break;
	}
}

void moveStickLUp(int value) {
	if (!stickLUpStop && stickLz > -5.5) {	// ���� ���밡 ��ܱ��� �������� ���� ���
		stickLz -= 0.1;	// ���븦 �̵���Ŵ
		glutPostRedisplay();
		glutTimerFunc(20, moveStickLUp, 1);
	}	
}
void moveStickLDn(int value) {
	if (!stickLDnStop && stickLz < 5.5) {	// ���� ���밡 �ϴܱ��� �������� ���� ���
		stickLz += 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickLDn, 1);
	}
}
void moveStickRUp(int value) {	// ���� ���밡 ��ܱ��� �������� ���� ���
	if (!stickRUpStop && stickRz > -5.5) {
		stickRz -= 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickRUp, 1);
	}
}
void moveStickRDn(int value) {	// ���� ���밡 �ϴܱ��� �������� ���� ���
	if (!stickRDnStop && stickRz < 5.5) {
		stickRz += 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickRDn, 1);
	}
}

void moveBallUpL(int value) {	// ���� ���� ������� �̵�
	if (!ballStop) {
		ballx = ballx - (0.016 * deltaX);	// �տ��� ������ deltaX x 0.016�� �� ��ŭ ���� x ��ǥ �̵�
		ballz = ballz - (0.016 * (17 - deltaX));	// (17 - deltaX) x 0.016�� �� ��ŭ ���� y ��ǥ �̵�
		cx -= 0.00005; cz -= 0.00005;	// ���� �̵��� ���� ī�޶��� ���� �̵�
		glutPostRedisplay();

		if (ballx < -8.7 || ballz < -8.7)	// ���� �ʵ带 ����� ��� ����
			ballStop = true;
		else if (ballz < -8.2)	// ��ܹٿ� �´� ��� ������ ����
			glutTimerFunc(20, moveBallDnL, 1);
		else if (ballx < -8.2) {	// ����� �������� ��
			if (ballz <= stickLz && ballz >= stickLz - 3.0)	// ������ ��ܿ� �´� ��� ���� ������� ƨ�ܳ�
				glutTimerFunc(20, moveBallUpR, 1);
			else if (ballz <= stickLz + 3.0 && ballz > stickLz)	// ������ ��ܿ� �´� ��� ���� �ϴ����� ƨ�ܳ�
				glutTimerFunc(20, moveBallDnR, 1);
			else	// ���븦 �ȸ´� ��� ���
				glutTimerFunc(20, moveBallUpL, 1);	
		} 
		else
			glutTimerFunc(20, moveBallUpL, 1);
	}
}

void moveBallDnL(int value) {	// ���� ���� �ϴ����� �̵�
	if (!ballStop) {
		ballx = ballx - (0.016 * deltaX);
		ballz = ballz + (0.016 * (17 - deltaX));
		cx -= 0.00005; cz += 0.00005;
		glutPostRedisplay();

		if (ballx < -8.7 || ballz > 8.7)	
			ballStop = true;
		else if (ballz > 8.2)	// �ϴܹٿ� �´� ��� ������ ����
			glutTimerFunc(20, moveBallUpL, 1);
		else if (ballx < -8.2) {	// ����� �������� ��
			if (ballz <= stickLz && ballz >= stickLz - 3.0)	// ������ ��ܿ� �´� ��� ���� ������� ƨ�ܳ�
				glutTimerFunc(20, moveBallUpR, 1);
			else if (ballz <= stickLz + 3.0 && ballz > stickLz)	// ������ ��ܿ� �´� ��� ���� �ϴ����� ƨ�ܳ�
				glutTimerFunc(20, moveBallDnR, 1);
			else	// ���븦 �ȸ´� ��� ���
				glutTimerFunc(20, moveBallDnL, 1);
		}
		else
			glutTimerFunc(20, moveBallDnL, 1);
	}
}

void moveBallUpR(int value) {	// ���� ���� ������� �̵�
	if (!ballStop) {
		ballx = ballx + (0.016 * deltaX);
		ballz = ballz - (0.016 * (17 - deltaX));
		cx += 0.00005; cz -= 0.00005;
		glutPostRedisplay();

		if (ballx > 8.7 || ballz < -8.7)
			ballStop = true;
		else if (ballz < -8.2) 	// ��ܹٿ� �´� ��� ������ ����
			glutTimerFunc(20, moveBallDnR, 1);
		else if (ballx > 8.2) {	// ����� �������� ��
			if (ballz <= stickRz && ballz >= stickRz - 3.0)	// ������ ��ܿ� �´� ��� ���� ������� ƨ�ܳ�
				glutTimerFunc(20, moveBallUpL, 1);
			else if (ballz <= stickRz + 3.0 && ballz > stickRz)	// ������ ��ܿ� �´� ��� ���� �ϴ����� ƨ�ܳ�
				glutTimerFunc(20, moveBallDnL, 1);
			else	// ���븦 �ȸ´� ��� ���
				glutTimerFunc(20, moveBallUpR, 1);
		}
		else
			glutTimerFunc(20, moveBallUpR, 1);
	}
}

void moveBallDnR(int value) {	// ���� ���� �ϴ����� �̵�
	if (!ballStop) {
		ballx = ballx + (0.016 * deltaX);
		ballz = ballz + (0.016 * (17 - deltaX));
		cx += 0.00005; cz += 0.00005;
		glutPostRedisplay();

		if (ballx > 8.7 || ballz > 8.7)
			ballStop = true;
		else if (ballz > 8.2)	// �ϴܹٿ� �´� ��� ������ ����
			glutTimerFunc(20, moveBallUpR, 1); 
		else if (ballx > 8.2) {		// ����� �������� ��
			if (ballz <= stickRz && ballz >= stickRz - 3.0)	// ������ ��ܿ� �´� ��� ���� ������� ƨ�ܳ�
				glutTimerFunc(20, moveBallUpL, 1);
			else if (ballz <= stickRz + 3.0 && ballz > stickRz)	// ������ ��ܿ� �´� ��� ���� �ϴ����� ƨ�ܳ�
				glutTimerFunc(20, moveBallDnL, 1);
			else	// ���븦 �ȸ´� ��� ���
				glutTimerFunc(20, moveBallDnR, 1);
		}
		else
			glutTimerFunc(20, moveBallDnR, 1);
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// ���÷��� ��带 ����. DOUBLE�� �������, RGB�� GLUT_RGBA����, DEPTH�� ���̹��� ���
	glutInitWindowSize(500, 500);	// �������� �⺻ ũ�� ����
	glutInitWindowPosition(100, 100);	// �������� �⺻ ��ġ ��ǥ ����
	glutCreateWindow("Pong");	// �������� Ÿ��Ʋ ����
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	MyInit();
	glutDisplayFunc(MyDisplay);	// ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(MyReshape);	// �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutKeyboardFunc(MyKeyboard);	// Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutSpecialFunc(MySpecial);	// ����� Ű���� �ݹ��Լ� ���. Ư�� Ű �̺�Ʈ �߻��� ȣ��
	glutMainLoop();	// GLUT �̺�Ʈ ó�� ���� �Է�
	return 0;
}