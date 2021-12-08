/***********************************************************************/
/*                   HW#3 : Timer Callback ����                        */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ���α׷��� ����Ǹ� ������ ���������� 0.1��          */
/*                ���������� �����̰� �ϰ�, ������ ��迡 �ε�����     */
/*                ������ ������ ���ϰ� �� ��, �ٽ� ������ ��������     */
/*                0.1�� ���������� �����̴� ������ �ݺ���              */
/*                                                                     */
/*  ��� :        ���콺 ���� Ű�� ������ �����̴� ������ ����         */
/***********************************************************************/
/*
#include <GL/glut.h>

void MyTimerP(int);
void MyTimerM(int);

GLfloat Delta = 0.0; // ��ü�� ��ġ�� ���� ����
GLfloat r = 0.0, g = 0.5, b = 0.8;  // ��ü�� ������ ���� ����
GLboolean StopTrig = false; // ��ü�� �̵��� ���߱� ���� ���� ����

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����
	glBegin(GL_POLYGON); // 4���� ���������� Polygon�� ǥ��
	glColor3f(r,g,b); // ��ü�� ������ (r, g, b)�� ����
		glVertex3f(-1.0 + Delta, -0.5, 0.0);  // ��ǥ�� �̵���Ű�� ���� ���� ��ǥ�� Delta�� ����
		glVertex3f(0.0 + Delta, -0.5, 0.0);
		glVertex3f(0.0 + Delta, 0.5, 0.0);
		glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers(); // �����ӹ��۸� ��ȯ
}

void MyTimerP(int Value) {
	r = 0.0; g = 0.5; b = 0.8; // ��ü�� ������ (0.0, 0.5, 0.8)���� ����
	Delta += 0.1; // ��ü�� ��ǥ�� �������� �̵�
	glutPostRedisplay(); // ������ ���÷��� �̺�Ʈ�� �߻�

	if (!StopTrig) {
		if(0.0 + Delta < 1.0) // ��ü�� �����츦 ����� ���� �� ���������� �̵�
			glutTimerFunc(100, MyTimerP, 1); // Ÿ�̸� �̺�Ʈ�� Ư���� ���������� Ÿ�̸� �̺�Ʈ�� �߻���Ŵ. MyTimerP �Լ��� 100�� �Ŀ� ����
		else // ��ü�� �������� �̵�
			glutTimerFunc(100, MyTimerM, 1); // MyTimerM �Լ��� 100�� �Ŀ� ����
	}
}

void MyTimerM(int Value) {
	r = 0.5; g = 0.5; b = 0.8; // ��ü�� ������ (0.5, 0.5, 0.8)���� ����
	Delta -= 0.1; // ��ü�� ��ǥ�� �������� �̵�
	glutPostRedisplay();

	if (!StopTrig) {
		if (-1.0 + Delta > -0.9) // ��ü�� �����츦 ����� ���� �� �������� �̵�
			glutTimerFunc(100, MyTimerM, 1);
		else // ��ü�� ���������� �̵�
			glutTimerFunc(100, MyTimerP, 1);
	}
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) // ���콺 �޹�ư�� ���� ��� ��ü�� �̵��� ����
		StopTrig = true; 
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // ���������� ��ȯ
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // ���÷��� ��带 ����. RGB�� GLUT_RGBA, DOUBLE�� ������� ���
	glutInitWindowSize(300, 300); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("Timer Callback"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutTimerFunc(100, MyTimerP, 1); // Ÿ�̸� �ݹ��Լ� ���. Ÿ�̸� �̺�Ʈ �߻��� ȣ��.
	glutMouseFunc(MyMouse); // ���콺 �ݹ��Լ� ���. ���콺 �̺�Ʈ �߻��� ȣ��

	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/