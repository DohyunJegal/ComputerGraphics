/***********************************************************************/
/*                HW#7. ���� Can Robot�� ���� ȿ�� ����                */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 11�� 20��   */
/*                                                                     */
/*  ���� ���� :   ������ �𵨸� ����� ���� ������ �κ��� ������       */
/*                ������ �ȴٸ��� ������ �޸��� ����� �ǰ� ����       */
/*                                                                     */
/*  ��� :                    ���� ��ȯ                                */
/*                �� - �κ��� ����, �� - �κ��� �Ʒ���                 */
/*                �� - �κ��� ����, �� - �κ��� ������                 */
/*   		       F - �κ��� ����,  B - �κ��� ����                   */
/*                           ������ ����                               */
/*			    R - �޸���, S - ����, Z - �κ��� ��ġ �ʱ�ȭ           */
/***********************************************************************/
/*
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj *qobj = gluNewQuadric();	// ���ο� Quadric�� ����
GLboolean StopTrig = false;	// �������� �����ϱ� ���� �ο��� ����
static double cx = 0, cy = 0, cz = 0, rx = 0, ry = 0, rz = 0;	// ī�޶��� ��ġ ����
static int head = 0;	// �Ӹ��� ������ ����
static int shoulderL = 20, shoulderR = 20, armL = 20, armR = 20;	// �� ���� ������ ������ ����
static int legL = 0, legR = 0, kneeL = 0, kneeR = 0;	// �ٸ��� ���� ����

static double shoulderLy = 0, shoulderRy = 0, armLy = 0, armRy = 0;	// �޸��� ��� ǥ���� ���� ���� ���� ���� ����
static double legLy = 0, legRy = 0, kneeLy = 0, kneeRy = 0;
static double armLp = 0, armRp = 0, kneeLp = 0, kneeRp = 0;

void moveheadL(int); void moveheadR(int);
void armLup(int); void armLdown(int);
void armRup(int); void armRdown(int);
void legLup(int); void legLdown(int);
void legRup(int); void legRdown(int);
void runningA(int); void runningB(int);

void MyMainMenu(int entryID) {
	if (entryID == 1) {
		StopTrig = false;
		glutTimerFunc(25, moveheadL, 1);	// Ÿ�̸� �̺�Ʈ�� Ư���� ���������� Ÿ�̸� �̺�Ʈ�� �߻���Ŵ. moveheadL �Լ��� 25ms �Ŀ� ����
	}
	if (entryID == 2) {
		StopTrig = false;
		glutTimerFunc(25, armLup, 1);
	}
	if (entryID == 3) {
		StopTrig = false;
		glutTimerFunc(25, armRup, 1);
	}
	if (entryID == 4) {
		StopTrig = false;
		glutTimerFunc(25, legLup, 1);
	}
	if (entryID == 5) {
		StopTrig = false;
		glutTimerFunc(25, legRup, 1);
	}
	if (entryID == 6) exit(0);
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// �������� ������ �ʱ�ȭ
	glShadeModel(GL_FLAT);

	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // �ֺ����� ����
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // �ݻ籤�� ����
	GLfloat mat_shininess[] = { 50.0 }; // ������
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // ������ ��ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);	// ���� �𵨿� ���� ���� �Ű� ������ ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// ���� �Ű� ���� ���� ��ȯ
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);	// ���� �� �Ű� ������ ����

	glEnable(GL_LIGHTING);	// ������带 Ȱ��ȭ
	glEnable(GL_LIGHT0);	// 0�� ������ Ȱ��ȭ
	glEnable(GL_DEPTH_TEST);	// ���� ���۸� Ȱ��ȭ

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);	// �޴� �ݹ��Լ� ���
	glutAddMenuEntry("Move head", 1);	// pop-up �޴��� �׸� 'Move head' �߰�
	glutAddMenuEntry("Move left arm", 2);
	glutAddMenuEntry("Move right arm", 3);
	glutAddMenuEntry("Move left leg", 4);
	glutAddMenuEntry("Move right leg", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	// ������ ���콺 ��ư�� ���� ���� �޴� �Ҵ�, ��ư�� ������ �޴� �˾�
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

	glPushMatrix();	// ����
	glTranslatef(0.0, 0.0, -1.0);	// ��ü�� (0, 0, -1) ��ŭ �̵�
	gluCylinder(qobj, 1.5, 1.5, 4.0, 30, 1); // �������� 1.5, ���̰� 4, Z�� �߽����� ȸ���ϴ� Subdivision�� 30, Z���� ������ Subdivision�� 1�� �Ǹ���
	glPopMatrix();

	glPushMatrix();	// ��
	glTranslatef(0.0, 0.0, -1.9);
	gluCylinder(qobj, 0.5, 0.5, 1.0, 30, 1);
	glPopMatrix();

	glPushMatrix();	// �Ӹ�
	glTranslatef(0.0, 0.0, -2.0);
	glRotatef(head, 0.0, 0.0, -1.0);	// (0, 0, -1)�� �������� head��ŭ ȸ��
	glTranslatef(0.0, 0.0, -2.0);
	gluCylinder(qobj, 1.0, 1.5, 2.0, 30, 1);

	glPushMatrix();	// ������ ��
	glTranslatef(-0.5, 1.15, 0.8);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluDisk(qobj, 0.0, 0.15, 20, 3); // ��ũ�� �ٱ��� �������� 0.15, Z�� �߽� Subdivision�� 20, ����ȭ �Ǵ� ���ɿ��� 3�� ��ũ
	glPopMatrix();

	glPushMatrix();	// ���� ��
	glTranslatef(0.5, 1.15, 0.8);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluDisk(qobj, 0.0, 0.15, 20, 3);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();	// ���� �ȶ�
	glTranslatef(1.0, 0.0, -0.15);
	glRotatef(shoulderL, 0.0, 5.0, 0.0);
		glRotatef(shoulderLy, 5.0, 0.0, 0.0);
	glTranslatef(1.0, 0.0, -0.15);
	gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);
	glPopMatrix();

	glPushMatrix();	// ���� ��
	glTranslatef(1.325, armLp, 0.1);
	glRotatef(armL, 0.0, -5.0, 0.0);
		glRotatef(armLy, -5.0, 0.0, 0.0);
	glTranslatef(1.325, 0.0, 0.1);
	gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);

	// ���� ��
	glTranslatef(0.0, 0.0, 1.8);
	gluSphere(qobj, 0.5, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();	// ������ �ȶ�
	glTranslatef(-1.0, 0.0, -0.15);
	glRotatef(shoulderR, 0.0, -5.0, 0.0);
		glRotatef(shoulderRy, 5.0, 0.0, 0.0);
	glTranslatef(-1.0, 0.0, -0.15);
	gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);
	glPopMatrix();

	glPushMatrix();	// ������ ��
	glTranslatef(-1.325, armRp, 0.1);
	glRotatef(armR, 0.0, 5.0, 0.0);
		glRotatef(armRy, -5.0, 0.0, 0.0);
	glTranslatef(-1.325, 0.0, 0.1);
	gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);

	// ������ ��
	glTranslatef(0.0, 0.0, 1.8);
	gluSphere(qobj, 0.5, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	// ���� �����
	glTranslatef(0.35, 0.0, 1.5);
	glRotatef(legL, 0.0, 5.0, 0.0);
		glRotatef(legLy, 5.0, 0.0, 0.0);
	glTranslatef(0.35, 0.0, 1.5);
	gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

	// ���� ���Ƹ�
	glTranslatef(0.0, kneeLp, 2.0);
		glRotatef(kneeLy, 5.0, 0.0, 0.0);
	gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

	// ���� ��
	glTranslatef(0.2, 0.0, 2.0);
	gluCylinder(qobj, 0.8, 0.8, 0.5, 30, 1);
	glPopMatrix();

	glPushMatrix();
	// ������ �����
	glTranslatef(-0.35, 0.0, 1.5);
	glRotatef(legR, 0.0, -5.0, 0.0);
		glRotatef(legRy, 5.0, 0.0, 0.0);
	glTranslatef(-0.35, 0.0, 1.5);
	gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

	// ������ ���Ƹ�
	glTranslatef(0.0, kneeRp, 1.0);
	glRotatef(kneeR, 0.0, -5.0, 0.0);
		glRotatef(kneeRy, 5.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 1.0);
	gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

	// ������ ��
	glTranslatef(-0.2, 0.0, 2.0);
	gluCylinder(qobj, 0.8, 0.8, 0.5, 30, 1);
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

void moveheadL(int Value) {
	head += 1;	// �Ӹ� ���� ����
	glutPostRedisplay();	// ������ ���÷��� �̺�Ʈ�� �߻�

	if (!StopTrig) {
		if (head < 45)
			glutTimerFunc(25, moveheadL, 1);
		else
			glutTimerFunc(25, moveheadR, 1);
	}
}

void moveheadR(int Value) {
	head -= 1;	// �Ӹ� ���� ����
	glutPostRedisplay();

	if (!StopTrig)
		if (head != 0)
			glutTimerFunc(25, moveheadR, 1);

	if (head == 0)
		StopTrig = true;
}

void armLup(int Value) {
	shoulderL += 1; armL -= 1.0;	// ���� ��� ���� ����, �Ȳ�ġ ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderL < 90)
			glutTimerFunc(25, armLup, 1);
		else
			glutTimerFunc(25, armLdown, 1);
	}
}

void armLdown(int Value) {
	shoulderL -= 1; armL += 1.0;	// ���� ��� ���� ����, �Ȳ�ġ ���� ����
	glutPostRedisplay();

	if (!StopTrig)
		if (shoulderL != 20)
			glutTimerFunc(25, armLdown, 1);

	if (shoulderL == 20)
		StopTrig = true;
}

void armRup(int Value) {
	shoulderR += 1; armR -= 1.0;	// ������ ��� ���� ����, �Ȳ�ġ ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderR < 90)
			glutTimerFunc(25, armRup, 1);
		else
			glutTimerFunc(25, armRdown, 1);
	}
}

void armRdown(int Value) {
	shoulderR -= 1; armR += 1.0;	// ������ ��� ���� ����, �Ȳ�ġ ���� ����
	glutPostRedisplay();

	if (!StopTrig)
		if (shoulderR != 20)
			glutTimerFunc(25, armRdown, 1);

	if (shoulderR == 20)
		StopTrig = true;
}

void legLup(int Value) {
	legL += 1;	// �޴ٸ� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (legL < 30)
			glutTimerFunc(25, legLup, 1);
		else
			glutTimerFunc(25, legLdown, 1);
	}
}

void legLdown(int Value) {
	legL -= 1;	// �����ٸ� ���� ����
	glutPostRedisplay();

	if (!StopTrig)
		if (legL != 0)
			glutTimerFunc(25, legLdown, 1);

	if (legL == 0)
		StopTrig = true;
}

void legRup(int Value) {
	legR += 1; kneeR -= 1;	// �����ٸ� ���� ����, ���� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (legR < 30)
			glutTimerFunc(25, legRup, 1);
		else
			glutTimerFunc(25, legRdown, 1);
	}
}

void legRdown(int Value) {
	legR -= 1; kneeR += 1;	// �����ٸ� ���� ����, ���� ���� ����
	glutPostRedisplay();

	if (!StopTrig)
		if (legR != 0)
			glutTimerFunc(25, legRdown, 1);

	if (legR == 0)
		StopTrig = true;
}

void runningA(int value) {	// �޸��� ��� A 
	shoulderLy += 1; armLy -= 1; armLp -= 0.025;
	shoulderRy -= 1; armRy += 1; armRp += 0.025;
	legLy -= 1; kneeLy += 0.8; kneeLp += 0.005;
	legRy += 1; kneeRy -= 0.8; kneeRp -= 0.005;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderLy < 45)
			glutTimerFunc(20, runningA, 1);
		else
			glutTimerFunc(20, runningB, 1);
	}
}

void runningB(int value) {	// �޸��� ��� B, A�� B�� �ݴ���� ������
	shoulderLy -= 1; armLy += 1; armLp += 0.025;
	shoulderRy += 1; armRy -= 1; armRp -= 0.025;
	legLy += 1; kneeLy -= 0.8; kneeLp -= 0.005;
	legRy -= 1; kneeRy += 0.8; kneeRp += 0.005;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderLy > -45)
			glutTimerFunc(20, runningB, 1);
		else
			glutTimerFunc(20, runningA, 1);
	}
}

void reset() {	// �κ��� ��ǥ�� �ʱ�ȭ�Ͽ� ���� ���·� ����
	head = 0;
	shoulderL = 20; shoulderR = 20; armL = 20; armR = 20;
	shoulderLy = 0; shoulderRy = 0; armLy = 0; armRy = 0;
	legL = 0; legR = 0; kneeL = 0; kneeR = 0; kneeLp = 0;
	legLy = 0; legRy = 0; kneeLy = 0; kneeRy = 0; kneeRp = 0;

	armLp = 0; armRp = 0;
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'S':	// S,s �Է½� ������ ����
	case 's':
		StopTrig = true;
		break;
	case 'F':	// F,f �Է½� �κ��� �������� ���� ����
	case 'f':
		cx = 0; cy = 0; cz = 0; rx = 0; ry = 0; rz = 0;
		glutPostRedisplay();
		break;
	case 'B':	// B,b �Է½� �κ��� �������� ���� ����
	case 'b':
		cx = 0; cy = -2.0; cz = 0; rx = 0; ry = 0; rz = -180;
		glutPostRedisplay();
		break;
	case 'R':	// R,r �Է½� �κ��� ��, �ٸ��� ������ �޸��� ����� ����
	case 'r':
		StopTrig = false;
		shoulderLy = 0; armLy = 30; armLp = 0;
		shoulderRy = 0; armRy = 30; armRp = 0;
		legLy = 0; kneeLy = 30; kneeLp = 0;
		legRy = 0; kneeRy = 30; kneeRp = 0.5;
		glutTimerFunc(20, runningA, 1);
		glutPostRedisplay();
		break;
	case 'Z':	// Z,z �Է½� �κ��� ��ǥ �ʱ�ȭ
	case 'z':
		reset();
		glutPostRedisplay();
		break;
	}
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:	// �� �Է½� �κ��� �������� ���� ����
		cx = 0; cy = -0.8; cz = -1.0; rx = 0; ry = 0; rz = 0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:	// �� �Է½� �κ��� �Ʒ������� ���� ����
		cx = 0; cy = -1.0; cz = 1.0; rx = 0; ry = 0; rz = 0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:	// �� �Է½� �κ��� �������� ���� ����
		cx = -1.0; cy = -1.0; cz = 0; rx = 0; ry = 0; rz = -180;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:	// �� �Է½� �κ��� ���������� ���� ����
		cx = 1.0; cy = -1.0; cz = 0; rx = 0; ry = 0; rz = -180;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// ���÷��� ��带 ����. DOUBLE�� ��������, RGB�� GLUT_RGBA���� ���
	glutInitWindowSize(500, 500);	// �������� �⺻ ũ�� ����
	glutInitWindowPosition(100, 100);	// �������� �⺻ ��ġ ��ǥ ����
	glutCreateWindow("Can Robot");	// �������� Ÿ��Ʋ ����
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	MyInit();
	glutDisplayFunc(MyDisplay);	// ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(MyReshape);	// �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutKeyboardFunc(MyKeyboard);	// Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutSpecialFunc(MySpecial);	// ����� Ű���� �ݹ��Լ� ���. Ư�� Ű �̺�Ʈ �߻��� ȣ��
	glutMainLoop();	// GLUT �̺�Ʈ ó�� ���� �Է�
	return 0;
}
*/