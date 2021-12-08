/***********************************************************************/
/*                     HW#4 : ������ �𵨸�                            */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 27��   */
/*                                                                     */
/*  ���� ���� :   �հ��� 3 ���� ���� Robot Arm ����				       */
/*                                                                     */
/*  ��� :        �հ����� ����, Ư�� ��ü�� ��� �� ó�� ������       */
/***********************************************************************/
/*
#include <stdlib.h>
#include <GL/glut.h>

void finger1_in(int); void finger1_out(int);
void finger2_in(int); void finger2_out(int);
void finger3_in(int); void finger3_out(int);
void finger_in(int); void finger_out(int);

static int shoulder = -45, elbow = 45;	// ����� �Ȳ�ġ ������ ���� ����
static int finger1A = 0, finger1B = 0, finger1C = 0;	// �հ������� ���� ����
static int finger2A = 0, finger2B = 0, finger2C = 0;
static int finger3A = 0, finger3B = 0, finger3C = 0;

GLboolean StopTrig = false;	// �������� �����ϱ� ���� �ο��� ����

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// �������� ������ �ʱ�ȭ
	glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);	// �÷� ���� ���
	glPushMatrix();	// ���
		glTranslatef(-3.0, 0.5, 0.0);	// ��ü�� (-3, 0.5, 0) ��ŭ �̵�
		glRotatef((GLfloat)shoulder, -0.5, 0.0, 1.0);	// (-0.5, 0, 1)�� �������� shoulder��ŭ ȸ��
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);	// ��ü�� ������ (1, 1, 1)�� ����
			glScalef(2.0, 0.4, 1.0);	// ��ü�� ũ�⸦ x�� 2�� Ȯ��, y�� 0.4�� ���
			glutWireCube(1.0);	// �������� ����
		glPopMatrix();

		// �Ȳ�ġ
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();

		// ù��° �հ���
		glPushMatrix();	
			glTranslatef(0.75, 0.0, -0.15);	// ù��° ����
			glRotatef((GLfloat)finger1A, 0.2, 0.0, 1.0);
			glTranslatef(0.75, 0.0, -0.15);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// �ι�° ����
			glRotatef((GLfloat)finger1B, 0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// ����° ����
			glRotatef((GLfloat)finger1C, 0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);	
			glPopMatrix();
		glPopMatrix();

		// �ι�° �հ���
		glPushMatrix();	
			glTranslatef(0.75, 0.0, 0.0);	// ù��° ����
			glRotatef((GLfloat)finger2A, 0.0, 0.0, 1.0);
			glTranslatef(0.75, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// �ι�° ����
			glRotatef((GLfloat)finger2B, 0.0, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// ����° ����
			glRotatef((GLfloat)finger2C, 0.0, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);	
			glPopMatrix();
		glPopMatrix();

		// ����° �հ���
		glPushMatrix();
			glTranslatef(0.75, 0.0, 0.15);	// ù��° ����
			glRotatef((GLfloat)finger3A, -0.2, 0.0, 1.0);
			glTranslatef(0.75, 0.0, 0.15);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// �ι�° ����
			glRotatef((GLfloat)finger3B, -0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// ����° ����
			glRotatef((GLfloat)finger3C, -0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();	// �����ӹ��۸� ��ȯ
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);	// ������ȯ �Լ��� ȣ��
	glMatrixMode(GL_PROJECTION);	// ������� ���� ���� ����
	glLoadIdentity();	// ���� ����� �׵������ ����� �ʱ�ȭ
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);	// �þ߰��� 65, ��Ⱦ�� w/h, ���� ���ܸ� 1, �Ĺ� ���ܸ� 20�� ���ú���
	glMatrixMode(GL_MODELVIEW);	// �𵨺���� ���� ���� ����
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void finger1_in(int Value) {
	finger1A += 1; finger1B += 1; finger1C += 1;	// ù��° �հ��� ���� ����
	glutPostRedisplay();	// ������ ���÷��� �̺�Ʈ�� �߻�

	if (!StopTrig) {
		if (finger1A < 90)
			glutTimerFunc(25, finger1_in, 1);	// Ÿ�̸� �̺�Ʈ�� Ư���� ���������� Ÿ�̸� �̺�Ʈ�� �߻���Ŵ. finger1_in �Լ��� 25ms �Ŀ� ����
		else 
			glutTimerFunc(25, finger1_out, 1);
	}
}

void finger1_out(int Value) {
	finger1A -= 1; finger1B -= 1; finger1C -= 1;	// ù��° �հ��� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A > 0)
			glutTimerFunc(25, finger1_out, 1);
		else
			glutTimerFunc(25, finger1_in, 1);
	}
}

void finger2_in(int Value) {
	finger2A += 1; finger2B += 1; finger2C += 1;	// �ι�° �հ��� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger2A < 90)
			glutTimerFunc(25, finger2_in, 1);
		else
			glutTimerFunc(25, finger2_out, 1);
	}
}

void finger2_out(int Value) {
	finger2A -= 1; finger2B -= 1; finger2C -= 1;	// �ι�° �հ��� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger2A > 0)
			glutTimerFunc(25, finger2_out, 1);
		else
			glutTimerFunc(25, finger2_in, 1);
	}
}

void finger3_in(int Value) {
	finger3A += 1; finger3B += 1; finger3C += 1;	// ����° �հ��� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger3A < 90)
			glutTimerFunc(25, finger3_in, 1);
		else
			glutTimerFunc(25, finger3_out, 1);
	}
}

void finger3_out(int Value) {
	finger3A -= 1; finger3B -= 1; finger3C -= 1;	// ����° �հ��� ���� ����
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger3A > 0)
			glutTimerFunc(25, finger3_out, 1);
		else
			glutTimerFunc(25, finger3_in, 1);
	}
}

void finger_in(int Value) {
	finger1A += 1; finger1B += 1; finger1C += 1;	// ��� �հ����� ���� ����
	finger2A += 1; finger2B += 1; finger2C += 1;
	finger3A += 1; finger3B += 1; finger3C += 1;
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A < 90 || finger2A < 90 || finger3A < 90)
			glutTimerFunc(25, finger_in, 1);
		else
			glutTimerFunc(25, finger_out, 1);
	}
}

void finger_out(int Value) {
	finger1A -= 1; finger1B -= 1; finger1C -= 1;	// ��� �հ����� ���� ����
	finger2A -= 1; finger2B -= 1; finger2C -= 1;
	finger3A -= 1; finger3B -= 1; finger3C -= 1;
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A > 0 || finger2A > 0 || finger3A > 0)
			glutTimerFunc(25, finger_out, 1);
		else
			glutTimerFunc(25, finger_in, 1);
	}
}

void grab_in(int Value) {
	shoulder -= 1; elbow += 1;	// ��� ���� ����, �Ȳ�ġ ���� ����
	finger1A += 2; finger1B += 2; finger1C += 2;
	finger2A += 2; finger2B += 2; finger2C += 2;
	finger3A += 2; finger3B += 2; finger3C += 2;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulder > -90)
			glutTimerFunc(25, grab_in, 1);
	}
}

void grab_out(int Value) {
	shoulder += 1; elbow -= 1;	// ��� ���� ����, �Ȳ�ġ ���� ����
	finger1A -= 2; finger1B -= 2; finger1C -= 2;
	finger2A -= 2; finger2B -= 2; finger2C -= 2;
	finger3A -= 2; finger3B -= 2; finger3C -= 2;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulder < -45)
			glutTimerFunc(25, grab_out, 1);
	}
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) {	// ���콺 ���� ��ư�� ������ �� grab_in �Լ� �۵�
		StopTrig = false;
		glutTimerFunc(25, grab_in, 1);
	}	
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) {	// ���콺 ������ ��ư�� ������ �� grab_out �Լ� �۵�
		StopTrig = false;
		glutTimerFunc(25, grab_out, 1);
	}
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		StopTrig = false;
		glutTimerFunc(25, finger1_in, 1);
		break;
	case '2':
		StopTrig = false;
		glutTimerFunc(25, finger2_in, 1);
		break;
	case '3':
		StopTrig = false;
		glutTimerFunc(25, finger3_in, 1);
		break;
	case '4':
		StopTrig = false;
		glutTimerFunc(25, finger_in, 1);
		break;
	case 'S':	// Ű������ S Ű�� ������ ����
	case 's':
		StopTrig = true;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// ���÷��� ��带 ����. DOUBLE�� �������, RGB�� GLUT_RGBA���� ���
	glutInitWindowSize(800, 600);	// �������� �⺻ ũ�� ����
	glutInitWindowPosition(100, 100);	// �������� �⺻ ��ġ ��ǥ ����
	glutCreateWindow("Robot Arm");	// �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay);	// ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(MyReshape);	// �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutKeyboardFunc(MyKeyboard);	// Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutMouseFunc(MyMouse); // ���콺 �ݹ��Լ� ���. ���콺 �̺�Ʈ �߻��� ȣ��
	glutMainLoop();	// GLUT �̺�Ʈ ó�� ���� �Է�
	return 0;
}
*/