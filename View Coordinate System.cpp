/***********************************************************************/
/*                HW#5-1. gluLookAt()�� �ǽð� ����                    */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 29��   */
/*                                                                     */
/*  ���� ���� :   ���� ��ǥ�踦 Keyboard Callback �Լ���               */
/*                �ǽð� ��� �����ϵ��� ����				           */
/*                                                                     */
/*  ��� :        ī�޶�� ������ ��ǥ�� ����/����                     */
/*                S,s - ��ǥ �̵� ����                                 */
/***********************************************************************/
/*
#include <GL/glut.h>

GLboolean StopTrig = false;	// �������� �����ϱ� ���� �ο��� ����
static double cx = 0, cy = 0, fx = 0, fy = 0, fz = 0;	// ī�޶��� ��ġ�� ī�޶��� ������ �����ų ����

void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);	// ��ü�� ������ (0.5, 0.5, 0.5)�� ����
	glBegin(GL_POLYGON);	// 4���� ���������� ����� Polygon�� ǥ��
		glVertex3f(-2.0, -0.71, 2.0);
		glVertex3f(2.0, -0.71, 2.0);
		glVertex3f(2.0, -0.71, -2.0);
		glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);	// 2���� ���������� ������ �ݺ������� ǥ��
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �÷� ���ۿ� ���� ���۸� �ʱ�ȭ
	glMatrixMode(GL_MODELVIEW);	// �𵨺���� ���� ���� ����
	glLoadIdentity();	// ���� ����� �׵������ ����� �ʱ�ȭ
	
	gluLookAt(0.0 + cx, 3.5 + cy, 3.5, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); 
	// ī�޶� (0.0 + cx, 3.5 + cy, 3.5)�� ��ġ, (0.0 + fx, 0.0 + fy, 0.0 + fz)�� �ٶ󺸰�, y������ 1��ŭ ����̰� ����

	DrawGround();

	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0);	// ũ�Ⱑ 1�� ������ ����

	glFlush(); // ť�� �����Ͽ� ���� ������� ���� ����� ����
}

void fxp(int Value) {
	fx += 0.1;
	glutPostRedisplay();	// ������ ���÷��� �̺�Ʈ�� �߻�

	if (!StopTrig)
		glutTimerFunc(50, fxp, 1);	// Ÿ�̸� �̺�Ʈ�� Ư���� ���������� Ÿ�̸� �̺�Ʈ�� �߻���Ŵ. fxp �Լ��� 50ms �Ŀ� ����
}

void fxm(int Value) {
	fx -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fxm, 1);
}

void fyp(int Value) {
	fy += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fyp, 1);
}

void fym(int Value) {
	fy -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fym, 1);
}

void fzp(int Value) {
	fz += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fzp, 1);
}

void fzm(int Value) {
	fz -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fzm, 1);
}

void cxp(int Value) {
	cx += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cxp, 1);
}

void cxm(int Value) {
	cx -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cxm, 1);
}

void cyp(int Value) {
	cy += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cyp, 1);
}

void cym(int Value) {
	cy -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cym, 1);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A':	// A,a �Է½� ī�޶��� ���� x��ǥ 0.1��ŭ ����
	case 'a':
		StopTrig = FALSE;
		glutTimerFunc(50, fxp, 1);
		break;
	case 'F':	// F,f �Է½� ī�޶��� ���� x��ǥ 0.1��ŭ ����
	case 'f':
		StopTrig = FALSE;
		glutTimerFunc(50, fxm, 1);
		break;
	case 'R':	// R,r �Է½� ī�޶��� ���� y��ǥ 0.1��ŭ ����
	case 'r':
		StopTrig = FALSE;
		glutTimerFunc(50, fyp, 1);
		break;
	case 'V':	// V,v �Է½� ī�޶��� ���� y��ǥ 0.1��ŭ ����
	case 'v':
		StopTrig = FALSE;
		glutTimerFunc(50, fym, 1);
		break;
	case 'Z':	// Z,z �Է½� ī�޶��� ���� z��ǥ 0.1��ŭ ����
	case 'z':
		StopTrig = FALSE;
		glutTimerFunc(50, fzp, 1);
		break;
	case 'T':	// T,t �Է½� ī�޶��� ���� z��ǥ 0.1��ŭ ����
	case 't':
		StopTrig = FALSE;
		glutTimerFunc(50, fzm, 1);
		break;
	case 'S':	// S,s �Է½� ������ ����
	case 's':
		StopTrig = TRUE;
		break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:	// �� �Է½� ī�޶��� ��ġ y��ǥ 0.1��ŭ ����
		StopTrig = FALSE;
		glutTimerFunc(50, cyp, 1);
		break;
	case GLUT_KEY_DOWN:	// �� �Է½� ī�޶��� ��ġ y��ǥ 0.1��ŭ ����
		StopTrig = FALSE;
		glutTimerFunc(50, cym, 1);
		break;
	case GLUT_KEY_LEFT:	// �� �Է½� ī�޶��� ��ġ x��ǥ 0.1��ŭ ����
		StopTrig = FALSE;
		glutTimerFunc(50, cxm, 1);
		break;
	case GLUT_KEY_RIGHT:	// �� �Է½� ī�޶��� ��ġ x��ǥ 0.1��ŭ ����
		StopTrig = FALSE;
		glutTimerFunc(50, cxp, 1);
		break;
	}
	glutPostRedisplay();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);	// ������ȯ �Լ��� ȣ��
	glMatrixMode(GL_PROJECTION);	// ������� ���� ���� ����
	glLoadIdentity();

	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);	// ���� �����Լ��� ȣ���Ͽ� ��ü ����
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	// ���÷��� ��带 ����. SINGLE�� ���Ϲ���, RGBA�� GLUT_RGBA���� ���
	glutInitWindowSize(500, 500);	// �������� �⺻ ũ�� ����
	glutInitWindowPosition(0, 0);	// �������� �⺻ ��ġ ��ǥ ����
	glutCreateWindow("VCS (View Coordinate System)");	// �������� Ÿ��Ʋ ����
	glClearColor(0.0, 0.0, 0.0, 0.0);	// �������� ������ �ʱ�ȭ

	glutDisplayFunc(MyDisplay);	// ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(MyReshape);	// �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutKeyboardFunc(MyKeyboard);	// Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutSpecialFunc(MySpecial);	// ����� Ű���� �ݹ��Լ� ���. Ư�� Ű �̺�Ʈ �߻��� ȣ��

	glutMainLoop();	// GLUT �̺�Ʈ ó�� ���� �Է�
	return 0;
}
*/