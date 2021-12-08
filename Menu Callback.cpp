/***********************************************************************/
/*                   HW#3 : Menu Callback ����                         */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 10�� 01��   */
/*                                                                     */
/*  ���� ���� :   ������ ���� ����� ����ǵ��� �ڵ� �ۼ�              */
/*                                                                     */
/*  ��� : �ָ޴�                                                      */
/*           Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit  */
/*                                                                     */
/*           Draw Sphere �Ϻ� �޴� : Small Sphere, Large Sphere        */
/*           Draw Torus �Ϻ� �޴� : Small Torus , Large Torus          */
/*           Draw Teapot �Ϻ� �޴� : Small Teapot , Large Teapot       */
/*           Change Color �Ϻ� �޴� : Red, Green, Blue                 */
/***********************************************************************/
/*
#include <GL/glut.h>

GLint Shape = 1; // 1 = Small Sphere, 2 = Large Sphere 
				 // 3 = Small Torus,  4 = Large Torus
				 // 5 = Small Teapot, 6 = Large Teapot

GLfloat r = 0.0, g = 0.5, b = 0.5; // ��ü�� ������ ��Ÿ���� ���� ����

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����
	glColor3f(r, g, b); // ��ü�� ������ (r, g, b)�� ����

	if (Shape == 1)
		glutWireSphere(0.5, 30, 30); // ���и����� �̷���� �� ����
	else if (Shape == 2)
		glutWireSphere(0.7, 30, 30);
	else if (Shape == 3)
		glutWireTorus(0.1, 0.2, 40, 20); // ���и����� �̷���� ��ȯü ����
	else if (Shape == 4)
		glutWireTorus(0.3, 0.5, 40, 20);
	else if (Shape == 5)
		glutWireTeapot(0.2); // ���и����� �̷���� ������ ����
	else
		glutWireTeapot(0.5);
	glFlush(); // ť�� �����Ͽ� ���� ������� ���� ����� ����
}

void MyMainMenu(int entryID) {
	if (entryID == 5)       exit(0);

	glutPostRedisplay(); // ������ ���÷��� �̺�Ʈ�� �߻�
}

void MySphereMenu(int entryID) {
	if (entryID == 1)           Shape = 1;
	else if (entryID == 2)      Shape = 2;

	glutPostRedisplay();
}

void MyTorusMenu(int entryID) {
	if (entryID == 1)           Shape = 3;
	else if (entryID == 2)      Shape = 4;

	glutPostRedisplay();
}

void MyTeapotMenu(int entryID) {
	if (entryID == 1)           Shape = 5;
	else if (entryID == 2)      Shape = 6;

	glutPostRedisplay();
}

void MyColorMenu(int entryID) {
	if (entryID == 1) { r = 1.0; g = 0.0; b = 0.0; } // ��ü�� ������ ����
	else if (entryID == 2) { r = 0.0; g = 1.0; b = 0.0; }
	else if (entryID == 3) { r = 0.0; g = 0.0; b = 1.0; }

	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // ���������� ��ȯ

	GLint MySphereID = glutCreateMenu(MySphereMenu); // �޴� �ݹ��Լ� ���
	glutAddMenuEntry("Small Sphere", 1); // ���� pop-up �޴��� �޴��׸� �߰�. ���� �̸� / �ݹ��Լ��� ������ ���� ��
	glutAddMenuEntry("Large Sphere", 2);

	GLint MyTorusID = glutCreateMenu(MyTorusMenu);
	glutAddMenuEntry("Small Torus", 1);
	glutAddMenuEntry("Large Torus", 2);

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu);
	glutAddMenuEntry("Small Teapot", 1);
	glutAddMenuEntry("Large Teapot", 2);

	GLint MyColorID = glutCreateMenu(MyColorMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySphereID); // �� �޴� �׸� �� �ϳ��μ� ���� �޴� �׸��� �߰�. ���� �޴��� / ���ϵ� �޴� ���̵� ��
	glutAddSubMenu("Draw Tours", MyTorusID);
	glutAddSubMenu("Draw Teapot", MyTeapotID);
	glutAddSubMenu("Change Color", MyColorID);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON); // ������ ���콺 ��ư�� �� �޴� �Ҵ�. ��ư�� ������ �޴� �˾�
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB); // ���÷��� ��带 ����. GLUT_RGBA ���
	glutInitWindowSize(500, 500); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("Menu Callback"); // �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��

	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/
