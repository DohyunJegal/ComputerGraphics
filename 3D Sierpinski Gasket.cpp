/***********************************************************************/
/*                      HW#1 : 3D Sierpinski Gasket                    */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 9�� 17��    */
/*                                                                     */
/*  ���� ���� :                                                        */
/*                3D Sierpinski Gasket ����                            */
/*  ��� :                                                             */
/*                2D�� ������ Sierpinski Gasket�� 3D�� ��ȯ            */
/***********************************************************************/

/*

#include <GL/glut.h>
#include <stdlib.h>  //rand() �Լ� ��� �뵵

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // â�� ���� �ʱ�ȭ 
	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION); // ��� ���� �� �����ϰ��� �ϴ� ����� ����. GL_PROJECTION�� ����
	glLoadIdentity(); // ���� �𵨺� ����� �׵������ ����� �ʱ�ȭ
	glOrtho(0.0, 500.0, 0.0, 500.0, 0, -250); // ���������� ��ȯ
}

void MyDisplay(void) {
	float vertices[4][3] = { { 0.0, 0.0, 0.0 },{ 250.0, 500.0, 100.0 },{ 500.0, 250.0, 250.0 },{ 250.0 , 100.0 , 250.0 } }; // �ﰢ���� �������� �ʱ�ȭ
	int i, j;
	float p[3] = { 250.0, 100.0, 250.0 };  // ���ο� �������� ���� ��

	glClear(GL_COLOR_BUFFER_BIT); // Ư���̳� ȥ�յ� �� ���۸� ����

	for (j = 0; j<50000; j++) {
		i = rand() % 4; // �ﰢ���� ������ �� �������� ����
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0; // �������� ������ ���� �߰��� ����

		glBegin(GL_POINTS);
		glVertex3fv(p);  // 3���� float�� ����
		glEnd();
	}

	glFlush(); // ť�� ����. ���� ������� ���� ����� ����
}

void MyReshape(int NewWidth, int NewHeight){
	glViewport(0, 0, NewWidth, NewHeight); // ������ȯ �Լ� ȣ��
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0*Widthfactor, 500.0*Widthfactor, 0.0*Heightfactor, 500.0*Heightfactor, 0, -250); // ���� ���κ� �ٽ� �����Ͽ� �������� ��ȯ
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ����. GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // ���÷��� ��� ����. SINGLE�� �̱۹���, RGB�� GLUT_RGBA ���
	glutInitWindowSize(500, 500); // �������� ũ��
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski Gasket"); // �������� Ÿ��Ʋ
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	MyInit();
	glutReshapeFunc(MyReshape); // �������� �ݹ��Լ� ���. ȭ�� ũ�� ��ȯ�� ȣ��
	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}

*/