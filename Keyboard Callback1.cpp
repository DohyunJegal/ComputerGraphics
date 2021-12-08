/***********************************************************************/
/*                   HW#3 : Keyboard Callback ����I                    */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ������ ���� ����� ����ǵ��� �ڵ� �ۼ�              */
/*                                                                     */
/*  ��� :        a �Ǵ� A : vertex ��ǥ�� �������� 0.1 �� �̵�        */
/*				  f �Ǵ� F : vertex ��ǥ�� ���������� 0.1 �� �̵�      */
/*                r �Ǵ� R : vertex ��ǥ�� �Ʒ������� 0.1 �� �̵�,     */
/*				             ���������� Polygon ĥ��                   */
/*                v �Ǵ� V : vertex ��ǥ�� �������� 0.1 �� �̵�        */
/*                b �Ǵ� B : �Ķ������� Polygon ĥ��                   */
/***********************************************************************/
/*
#include <GL/glut.h>

GLfloat ca = 0.5f, cb = 0.5f, cc = 0.5f, DeltaX = 0.0, DeltaY = 0.0; // ��ü�� ����� ��ġ�� ���� ����

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����
	glColor3f(ca, cb, cc); // ��ü�� ������ (ca, cb, cc)�� ����
	glBegin(GL_POLYGON); // 4���� ���������� Polygon�� ǥ��
		glVertex3f(-0.5 + DeltaX, -0.5 + DeltaY, 0.0); // ��ǥ�� �̵���Ű�� ���� ���� ��ǥ�� DeltaX, DeltaY�� ����
		glVertex3f(0.5 + DeltaX, -0.5 + DeltaY, 0.0);
		glVertex3f(0.5 + DeltaX, 0.5 + DeltaY, 0.0);
		glVertex3f(-0.5 + DeltaX, 0.5 + DeltaY, 0.0);
	glEnd();
	glFlush(); // ť�� �����Ͽ� ���� ������� ���� ����� ����
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a': // a�� A�� ���� ��� ������ �������� 0.1 �̵�
		DeltaX += -0.1; break;
	case 'A':
		DeltaX += -0.1; break;
	case 'f': // f�� F�� ���� ��� ������ ���������� 0.1 �̵�
		DeltaX += 0.1; break;
	case 'F':
		DeltaX += 0.1; break;
	case 'r': // r�̳� R�� ���� ��� ������ �Ʒ������� 0.1 �̵� �� ������ ���� ���������� ����
		DeltaY += -0.1;
		ca = 1.0f; cb = 0.0; cc = 0.0; break;
	case 'R':
		DeltaY += -0.1;
		ca = 1.0f; cb = 0.0; cc = 0.0; break;
	case 'v':// v�� V�� ���� ��� ������ �������� 0.1 �̵�
		DeltaY += 0.1; break;
	case 'V':
		DeltaY += 0.1; break;
	case 'b': // b�� B�� ���� ��� ������ �Ķ������� ����
		ca = 0; cb = 0; cc = 1.0f; break;
	case 'B':
		ca = 0; cb = 0; cc = 1.0f; break;
	case 'Q': // q�� Q�� ���� ��� ���α׷� ����
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	}
	glutPostRedisplay(); // ������ ���÷��� �̺�Ʈ�� �߻�
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // ���������� ��ȯ
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB); // ���÷��� ��带 ����. GLUT_RGBA ���
	glutInitWindowSize(300, 300); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("Keyboard Callback1"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutKeyboardFunc(MyKeyboard); // Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/