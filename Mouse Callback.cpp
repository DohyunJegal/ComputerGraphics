/***********************************************************************/
/*                   HW#3 : Mouse Callback ����                        */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ������ ���� ����� ����ǵ��� �ڵ� �ۼ�              */
/*                                                                     */
/*  ��� :        ���콺 ���� ��ư�� click                             */
/*                    vertex ��ǥ�� ���������� 0.1 �� ���������� �̵�  */
/*                ���콺 ������ ��ư�� click                           */
/*                    �̵��ϰ� �ִ� Polygon �� ����                    */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <windows.h>

GLfloat vax = -0.5, vay = -0.5; // Polygon�� ������ ��ǥ�� ǥ���ϱ� ���� ����
GLfloat vbx = 0.5, vby = -0.5;
GLfloat vcx = 0.5, vcy = 0.5;
GLfloat vdx = -0.5, vdy = 0.5;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����
	glColor3f(0.5f, 0.5f, 0.5f); // ��ü�� ������ (0.5, 0.5, 0.5)�� ����
	glBegin(GL_POLYGON); // 4���� ���������� Polygon�� ǥ��
		glVertex3f(vax, vay, 0.0);
		glVertex3f(vbx, vby, 0.0);
		glVertex3f(vcx, vcy, 0.0);
		glVertex3f(vdx, vdy, 0.0);
	glEnd();
	glutSwapBuffers(); // �����ӹ��۸� ��ȯ
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': // q�� Q�� ���� ��� ���α׷� ����
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	}
	glutPostRedisplay(); // ������ ���÷��� �̺�Ʈ�� �߻�
}

void MyIdle() {
	if (vbx <= 1.0 && vcx <= 1.0){ // vertex ��ǥ�� �����츦 ����� ���� �� ���������� 0.1�� �̵�
		vax += 0.1f; vbx += 0.1f; vcx += 0.1f; vdx += 0.1f;
		Sleep(250); // 250ms ���� ����
	}
	glutPostRedisplay();
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) // ���콺 �޹�ư�� ������ �� MyIdle ȣ��
		glutIdleFunc(MyIdle);
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) // ���콺 �޹�ư�� ������ �� Idle ����
		glutIdleFunc(NULL);
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // ���������� ��ȯ
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE); // ���÷��� ��带 ����. RGB�� GLUT_RGBA, DOUBLE�� ������� ���
	glutInitWindowSize(300, 300); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("Keyboard Callback"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutKeyboardFunc(MyKeyboard); // Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutMouseFunc(MyMouse); // ���콺 �ݹ��Լ� ���. ���콺 �̺�Ʈ �߻��� ȣ��

	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/