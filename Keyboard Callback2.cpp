/***********************************************************************/
/*                   HW#3 : Keyboard Callback ����II                   */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ������ ���� ����� ����ǵ��� �ڵ� �ۼ�              */
/*                                                                     */
/*  ��� :        �� : vertex ��ǥ�� �� ������ 0.1 �� �̵�             */
/*                �� : vertex ��ǥ�� �Ʒ� ������ 0.1 �� �̵�           */
/*                �� : vertex ��ǥ�� �� ������ 0.1 �� �̵�             */
/*                �� : vertex ��ǥ�� ���������� 0.1 �� �̵�            */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <cmath>

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
	glFlush(); // ť�� �����Ͽ� ���� ������� ���� ����� ����
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

void MySpecial(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP: // vertex ��ǥ�� �����츦 ����� ���� �� �� ����Ű�� ���� ��� ���� 0.1�� �̵�
			if (vcy <= 1.0 && vdy <= 1.0){
				vay += 0.1; vby += 0.1; vcy += 0.1; vdy += 0.1; 
			} break;
		case GLUT_KEY_DOWN: // vertex ��ǥ�� �����츦 ����� ���� �� �Ʒ� ����Ű�� ���� ��� �Ʒ��� 0.1�� �̵�
			if (vay >= -1.0 && vby >= -1.0) {
				vay -= 0.1; vby -= 0.1; vcy -= 0.1; vdy -= 0.1;
			} break;
		case GLUT_KEY_LEFT: // vertex ��ǥ�� �����츦 ����� ���� �� ���� ����Ű�� ���� ��� �������� 0.1�� �̵�
			if (vax >= -1.0 && vdx >= -1.0) {
				vax -= 0.1; vbx -= 0.1; vcx -= 0.1; vdx -= 0.1; 
			} break;
		case GLUT_KEY_RIGHT: // vertex ��ǥ�� �����츦 ����� ���� �� ������ ����Ű�� ���� ��� ���������� 0.1�� �̵�
			if (vbx <= 1.0 && vcx <= 1.0) {
				vax += 0.1; vbx += 0.1; vcx += 0.1; vdx += 0.1;
			} break;
		case GLUT_KEY_PAGE_UP: // vertex ��ǥ�� �����쿡 ���� ���� �� Page Up�� ���� ��� ��ü������ 0.1�� Ȯ��
			if (vax >= -1.0 && vay >= -1.0 && vbx <= 1.0 && vby >= -1.0 && vcx <= 1.0 && vcy <= 1.0 && vdx >= -1.0 && vdy <= 1.0) {
				vax -= 0.1; vbx += 0.1; vcx += 0.1; vdx -= 0.1;
				vay -= 0.1; vby -= 0.1; vcy += 0.1; vdy += 0.1;
			} break;
		case GLUT_KEY_PAGE_DOWN: // vertex ��ǥ�� ���� ������ ���� �� Page Down�� ���� ��� ��ü������ 0.1�� ���
			if (vbx - vax >= 0.3) {
				vax += 0.1; vbx -= 0.1; vcx -= 0.1; vdx += 0.1;
				vay += 0.1; vby += 0.1; vcy -= 0.1; vdy -= 0.1; 
			} break;
	}
	glutPostRedisplay();
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
	glutCreateWindow("Keyboard Callback2"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutKeyboardFunc(MyKeyboard); // Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutSpecialFunc(MySpecial); // ����� Ű���� �ݹ��Լ� ���. ����� Ű���� (Ư�� Ű) �̺�Ʈ �߻��� ȣ��
	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/