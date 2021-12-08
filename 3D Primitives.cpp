/***********************************************************************/
/*                      HW#2 : 3D Primitives                           */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 9�� 24��    */
/*                                                                     */
/*  ���� ���� :   �پ��� 3D Primitive���� ����                         */
/*                                                                     */
/*  ��� :        ������ ������ �����ϴ� �� ��ü�� ǥ���ϴ� �⺻ ���  */
/*				  3D �������� �������� 3D ��ü�� ����				   */
/***********************************************************************/

/*
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

GLuint listA, listB, listC, listD; // ���� ���� ���÷��� ����Ʈ�� ����, ���� ID�� ���� �ĺ���
GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric�� ����

void MyCreateList(){
	listA = glGenLists(4); // ������ ���� ���̵� 4���� ��ȯ�Ͽ� ������ ���� ���÷��� ����Ʈ�� �Ҵ�
	listB = listA + 1;
	listC = listB + 1;
	listD = listC + 1;

	glNewList(listA, GL_COMPILE); // ���÷��� ����Ʈ�� ����, �������� �ʰ� ������ �Ϸ�� ������ �����Ѵ�.
	gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric�� Draw Style�� Solid���·� �𵨸�
	gluSphere(qobj, 1.0, 50, 50); // �������� 1, Z�� �߽� Subdivision�� 50, Z���� ������ Subdivision�� 50�� ��
	glTranslatef(-2, -2, 2); // ��ǥ �����̵�
	glEndList();

	glNewList(listB, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� Draw Style�� Wire-frame ���·� �𵨸�
	gluCylinder(qobj, 1.0, 1.0, 2.0, 8, 8); // z=0�� �Ǹ����� z=������ �Ǹ����� �������� 1, ���̰� 2, Z�� �߽����� ȸ���ϴ� Subdivision�� 8, Z���� ������ Subdivision�� 8�� �Ǹ���
	glTranslatef(2, 2, 0);
	glEndList();

	glNewList(listC, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE); // Quadric�� Draw Style�� �ܺ� �𼭸��� �𵨸�
	gluDisk(qobj, 0.25, 1, 20, 3); // ��ũ�� ���� �������� 0.25, �ٱ��� �������� 1, Z�� �߽� Subdivision�� 50, ����ȭ �Ǵ� ���ɿ��� 3�� ��ũ
	glTranslatef(-2, 2, 0);
	glEndList();

	glNewList(listD, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_POINT); // Quadric�� Draw Style�� �������� ǥ���Ͽ� �𵨸�
	gluPartialDisk(qobj, 0.5, 1.0, 26, 13, 0, 180); // �κе�ũ�� ���� �������� 0.5, �ٱ��� �������� 1, Z�� �ֺ� Subdivision�� 26, ����ȭ �Ǵ� ���ɿ��� 13, ��ũ �κ��� ������ 0, ��ũ �����Ǵ� ������ 180�� �κе�ũ
	glTranslatef(2, -2, 0);
	glEndList();
}

void MyInit(void){
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // �ֺ����� ����
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // �ݻ籤�� ����
	GLfloat mat_shininess[] = { 50.0 }; // ����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // ������ ��ġ
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); // ���� �𵨿� ���� ���� �Ű� ������ ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // ���� �Ű� ���� ���� ��ȯ
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient); // ���� �� �Ű� ������ ����

	glEnable(GL_LIGHTING); // �����带 Ȱ��ȭ
	glEnable(GL_LIGHT0); // 0�� ������ Ȱ��ȭ
	glEnable(GL_DEPTH_TEST); // ���� ���۸� Ȱ��ȭ
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �÷� ���ۿ� ���� ���۸� �ʱ�ȭ

	glMatrixMode(GL_MODELVIEW); // �𵨺���� ���� ���� ����
	glLoadIdentity(); // ���� ����� �׵������ ����� �ʱ�ȭ

	glViewport(0, 0, 500, 500); // ������ȯ �Լ��� ȣ��
	gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 1.0, 0.0); // ī�޶� (0, 1, -1) ��ǥ ��������, y������ 1��ŭ ����̰� ����

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH); // ���� �迭 ���

	gluQuadricNormals(qobj, GLU_SMOOTH); // ��ü�� �𼭸��� �ε巴�� ���̵��� �������� ����
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // �ٱ����� ����Ű�� ���͸� ���� Quadric �׸���
	gluQuadricTexture(qobj, GL_FALSE); // Texture ��ǥ �̻���

	glCallList(listA); // ���÷��� ����Ʈ�� ȣ��
	glCallList(listB);
	glCallList(listC);
	glCallList(listD);

	glutSwapBuffers(); // �����ӹ��۸� ��ȯ
}

void Reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // ������ȯ �Լ��� ȣ��

	glMatrixMode(GL_PROJECTION); // ������� ���� ���� ����
	glLoadIdentity();

	glOrtho(-5.0, 5.0, -5.0*((GLfloat)height/(GLfloat)width), 5.0*((GLfloat)height/(GLfloat)height), -5.0, 5.0);; // ����� ��� ������ ���������� ���Ͽ� ���� ����

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv){
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // ���÷��� ��带 ����. DOUBLE�� �������, RGB�� GLUT_RGBA, DEPTH�� ���̹��� ���
	glutInitWindowSize(500, 500); // �⺻ �������� ũ�� ����
	glutInitWindowPosition(0, 0); // �������� ��ġ ��ǥ ����
	glutCreateWindow("3D Primitives"); // �������� Ÿ��Ʋ ����

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // ���������� ��ȯ

	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(Reshape); // �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	MyCreateList();

	glutMainLoop(); // GLUT �̺�Ʈ ó�� ���� �Է�
}
*/