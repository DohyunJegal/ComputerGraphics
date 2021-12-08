/***********************************************************************/
/*                   HW#3 : Idle Callback ����                         */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ������ ���� ����ǵ��� �ڵ� �ۼ�                     */
/*                                                                     */
/*  ��� :        �� : vertex ��ǥ�� �� ������ 0.1 �� �̵�             */
/*                �� : vertex ��ǥ�� �Ʒ� ������ 0.1 �� �̵�           */
/*                �� : vertex ��ǥ�� �� ������ 0.1 �� �̵�             */
/*                �� : vertex ��ǥ�� ���������� 0.1 �� �̵�            */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <windows.h>

GLfloat DeltaX = 0.0, DeltaY = 0.0; // ��ü�� ��ġ�� ���� ����

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����
	glBegin(GL_POLYGON); // 4���� ���������� Polygon�� ǥ��
	glColor3f(0.0, 0.5, 0.8); // ��ü�� ������ (0.0, 0.5, 0.8)�� ����
		glVertex3f(-1.0 + DeltaX, -0.5 + DeltaY, 0.0); // ��ǥ�� �̵���Ű�� ���� ���� ��ǥ�� DeltaX, DeltaY�� ����
		glVertex3f(0.0 + DeltaX, -0.5 + DeltaY, 0.0);
		glVertex3f(0.0 + DeltaX, 0.5 + DeltaY, 0.0);
		glVertex3f(-1.0 + DeltaX, 0.5 + DeltaY, 0.0);
	glEnd();
	glutSwapBuffers(); // �����ӹ��۸� ��ȯ
}

void MyIdleXP() { // vertex ��ǥ�� �����츦 ����� ���� �� ���������� 0.1�� �̵�
	if (0.0 + DeltaX < 1.0) {
		DeltaX += 0.1;
		Sleep(50); // 50ms ���� ����
	}
	glutPostRedisplay(); // ������ ���÷��� �̺�Ʈ�� �߻�
}

void MyIdleXM() { // vertex ��ǥ�� �����츦 ����� ���� �� �������� 0.1�� �̵�
	if (-1.0 + DeltaX > -0.9) {
		DeltaX -= 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MyIdleYP() { // vertex ��ǥ�� �����츦 ����� ���� �� ���� 0.1�� �̵�
	if (0.5 + DeltaY < 1.0) {
		DeltaY += 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MyIdleYM() { // vertex ��ǥ�� �����츦 ����� ���� �� �Ʒ��� 0.1�� �̵�
	if (-0.5 + DeltaY > -0.9) {
		DeltaY -= 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: // �� ����Ű�� ������ �� MyIdleYP ȣ��
		glutIdleFunc(MyIdleYP);
		break;
	case GLUT_KEY_DOWN: // �Ʒ� ����Ű�� ������ �� MyIdleYM ȣ��
		glutIdleFunc(MyIdleYM);
		break;
	case GLUT_KEY_LEFT: // ���� ����Ű�� ������ �� MyIdleXM ȣ��
		glutIdleFunc(MyIdleXM);
		break;
	case GLUT_KEY_RIGHT: // ������ ����Ű�� ������ �� MyIdleXP ȣ��
		glutIdleFunc(MyIdleXP);
		break;
	}
	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // ���������� ��ȯ
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // ���÷��� ��带 ����. RGB�� GLUT_RGBA, DOUBLE�� ������� ���
	glutInitWindowSize(300, 300); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("Idle Callback"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutSpecialFunc(MySpecial); // ����� Ű���� �ݹ��Լ� ���. ����� Ű���� (Ư�� Ű) �̺�Ʈ �߻��� ȣ��

	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/