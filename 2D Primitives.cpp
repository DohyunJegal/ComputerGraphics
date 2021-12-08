/***********************************************************************/
/*                      HW#2 : 2D Primitives                           */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 9�� 24��    */
/*                                                                     */
/*  ���� ���� :   �پ��� 2D Primitive���� ����                         */
/*                                                                     */
/*  ��� :        ������ ������ �����ϴ� �� ��ü�� ǥ���ϴ� �⺻ ���  */
/*				  2D �������� 2D ��ü�� ���� 	                       */
/***********************************************************************/

/*
#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.4, 0.3); // ��ü�� ������ (0.5, 0.4, 0.3)�� ����

	glBegin(GL_POLYGON); // 6���� ���������� ���� Polygon�� ǥ��
		glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
		glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
		glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glBegin(GL_POINTS); // 6���� ���������� �����θ� ǥ��
		glVertex3f(0.0, 3.5, 0.0); glVertex3f(-1.0, 3.0, 0.0);
		glVertex3f(-1.0, 2.0, 0.0); glVertex3f(0.0, 1.5, 0.0);
		glVertex3f(1.0, 2.0, 0.0); glVertex3f(1.0, 3.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // 6���� ������ �� 2���� ��� ���� ǥ��
		glVertex3f(2.5, 1.0, 0.0); glVertex3f(1.5, 0.5, 0.0);
		glVertex3f(1.5, -0.5, 0.0); glVertex3f(2.5, -1.0, 0.0);
		glVertex3f(3.5, -0.5, 0.0); glVertex3f(3.5, 0.5, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); // 6���� ������ �� 2���� ��� ���� ���� �� �ٷ� ����
		glVertex3f(2.5, 3.5, 0.0); glVertex3f(1.5, 3.0, 0.0);
		glVertex3f(1.5, 2.0, 0.0); glVertex3f(2.5, 1.5, 0.0);
		glVertex3f(3.5, 2.0, 0.0); glVertex3f(3.5, 3.0, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP); // 6���� ���������� ���� �� ���� ó���� ���� �ٽ� ������ ����
		glVertex3f(2.5, -1.5, 0.0); glVertex3f(1.5, -2.0, 0.0);
		glVertex3f(1.5, -3.0, 0.0); glVertex3f(2.5, -3.5, 0.0);
		glVertex3f(3.5, -3.0, 0.0); glVertex3f(3.5, -2.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES); // 6���� ������ �� 3���� ��� �ﰢ���� ǥ��
		glVertex3f(0.0, -1.5, 0.0); glVertex3f(-1.0, -2.0, 0.0);
		glVertex3f(-1.0, -3.0, 0.0); glVertex3f(0.0, -3.5, 0.0);
		glVertex3f(1.0, -3.0, 0.0); glVertex3f(1.0, -2.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // 6���� ������ �� 3���� ���� ���� �ﰢ���� ��� ����
		glVertex3f(-2.5, -1.5, 0.0); glVertex3f(-4.5, -1.5, 0.0);
		glVertex3f(-6.5, -1.5, 0.0); glVertex3f(-3.5, -3.0, 0.0);
		glVertex3f(-5.5, -3.0, 0.0); glVertex3f(-7.5, -3.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // 6���� ������ �� 3���� ���� ���� �ﰢ���� ��ä ������� ����
		glVertex3f(-2.5, -1.0, 0.0); glVertex3f(-3.0, 1.0, 0.0);
		glVertex3f(-3.2, 0.7, 0.0); glVertex3f(-4.0, 0.0, 0.0);
		glVertex3f(-4.2, -0.5, 0.0); glVertex3f(-4.5, -1.0, 0.0);
	glEnd();

	glBegin(GL_QUADS); // 8���� ������ �� 4���� ���� �� ���� �𼭸��� ���� Polygon ǥ��
		glVertex3f(5.2, 0.0, 0.0); glVertex3f(5.5, 1.0, 0.0);
		glVertex3f(6.0, 1.5, 0.0); glVertex3f(6.5, 1.0, 0.0);

		glVertex3f(6.7, 1.0, 0.0); glVertex3f(7.5, 1.5, 0.0);
		glVertex3f(8.0, 0.5, 0.0); glVertex3f(7.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_QUAD_STRIP); // 8���� ���������� ���� Polygon�� ��� ������ ����
		glVertex3f(5.2, -2.5, 0.0); glVertex3f(5.5, -1.5, 0.0);
		glVertex3f(6.5, -1.5, 0.0); glVertex3f(6.0, -1.0, 0.0);

		glVertex3f(7.0, -2.5, 0.0); glVertex3f(7.5, -1.0, 0.0);
		glVertex3f(6.7, -1.5, 0.0); glVertex3f(8.0, -2.0, 0.0);
	glEnd();

	glFlush(); // ť�� �����㿩 ���� ������� ���� ����� ����
}

void Reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // ������ȯ �Լ��� ȣ��

	GLfloat Widthfactor = (GLfloat)width / (GLfloat)500; // ���� ����� ���ο� ���θ� ���� ũ���� 500���� ������
	GLfloat Heightfactor = (GLfloat)height / (GLfloat)500;

	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-9.0*Widthfactor, 9.0*Widthfactor, -9.0*Heightfactor, 9.0*Heightfactor, -9, 9); // ����� ��� ������ ���������� ���ϱ�

	glMatrixMode(GL_MODELVIEW); // �𵨺���� ���� ���� ����
	glLoadIdentity();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // ���÷��� ��带 ����. SINGLE�� �̱۹���, RGB�� GLUT_RGBA ���
	glutInitWindowSize(500, 500); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("2D Primitives"); // �������� Ÿ��Ʋ ����
	glClearColor(1.0, 1.0, 1.0, 1.0); // �������� ������ �ʱ�ȭ
	glOrtho(-9.0, 9.0, -9.0, 9.0, -9.0, 9.0); // ���������� ��ȯ
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(Reshape); // �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/