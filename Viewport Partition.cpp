/***********************************************************************/
/*               HW#6. glViewport()�� ���� ������ȯ                    */
/*  �ۼ��� : ��������                        ��¥ : 2021�� 11�� 10��   */
/*                                                                     */
/*  ���� ���� :   �� ������ 2�� �̻��� ��ü�� ǥ��                     */
/*                �ϳ��� �����츦 4���� �������� ���� 				   */
/*                ���������� �������� �̿�		                       */
/*                Keyboard Callback�� ����Ͽ� ī�޶� �̵� (������ȯ)  */
/*                �������� ��ü�� �⺻������ ������ �߽ɿ� ��ġ        */
/*                                                                     */
/*  ��� :        W,w / S,s - ī�޶��� y��ǥ�� ����/����               */
/*                D,d / A,a - ī�޶��� x��ǥ�� ����/����               */
/*                E,e / Q,q - ī�޶��� z��ǥ�� ����/����               */
/*                R,r - ī�޶� ���� ��ġ�� �̵�                      */
/***********************************************************************/
/*
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric�� ����
static double cx = 0, cy = 0, cz = 0;	// ī�޶��� ��ġ�� �����ų ����
int Width, Height;	// â�� ũ�⸦ ��Ÿ�� ����

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);	// �������� ������ (1.0, 1.0, 1.0, 1.0)�� �ʱ�ȭ
	glMatrixMode(GL_PROJECTION);	// ������� ���� ���� ����
	glLoadIdentity();	// ���� ����� �׵������ ����� �ʱ�ȭ

	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // ���������� ��ȯ
	glMatrixMode(GL_MODELVIEW);	// �𵨺���� ���� ���� ����
	glLoadIdentity();
}

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);	// ��ü�� ������ (0.7, 0.7, 0.7)�� ����
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);	// ��ü�� (0.0, -1.0, 0.0) ��ŭ �̵�
	glBegin(GL_QUADS);	// ������ ���� �簢���� �׸�
	glVertex3f(2.0, 0.0, 2.0);	// ������ ��ǥ�� ����
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);	// ũ�Ⱑ 1.0�� �����ڸ� �׸�
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.3);
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� Draw Style�� Wire-frame ���·� �𵨸�
	glTranslatef(0.0, 0.0, 1.1);
	gluSphere(qobj, 0.5, 30, 30); // �������� 0.5, Z�� �߽� Subdivision�� 30, Z���� ������ Subdivision�� 30�� ���� �׸�
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// �÷� ���۸� �ʱ�ȭ
	glColor3f(1.0, 1.0, 1.0);

	glViewport(0, 0, Width / 2, Height / 2);	// ������ȯ �Լ��� ȣ��, ���� �ϴ�
	glPushMatrix();
	gluLookAt(0.0 + cx, 0.0 + cy, 1.0 + cz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // ī�޶�(0.0 + cx, 0.0 + cy, 1.0 + cz)�� ��ġ, (0.0, 0.0, 0.0)�� �ٶ󺸰�, y������ 1��ŭ ����̰� ����
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);	// ������ȯ �Լ��� ȣ��, ���� ���
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	if (Width <= Height)	// �������� ���ο� ���� ũ�⸦ ���Ͽ� �����ϰ� ���� �����Լ��� ȣ���Ͽ� ��ü ����
		gluPerspective(30 * ((GLfloat)Height / (GLfloat)500), (GLfloat)Height / Width, 3.0, 50.0);
	else
		gluPerspective(30 * ((GLfloat)Height / (GLfloat)500), (GLfloat)Width / Height, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0 + cx, 5.0 + cy, 5.0 + cz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A': case 'a':	// A,a �Է½� ī�޶��� ��ġ x��ǥ 0.1��ŭ ����
		cx -= 0.1;
		break;
	case 'D': case 'd':	// D,d �Է½� ī�޶��� ��ġ x��ǥ 0.1��ŭ ����
		cx += 0.1;
		break;
	case 'W': case 'w':	// W,w �Է½� ī�޶��� ��ġ y��ǥ 0.1��ŭ ����
		cy += 0.1;
		break;
	case 'S': case 's':	// S,s �Է½� ī�޶��� ��ġ y��ǥ 0.1��ŭ ����
		cy -= 0.1;
		break;
	case 'Q': case 'q':	// Q,q �Է½� ī�޶��� ��ġ z��ǥ 0.1��ŭ ����
		cz -= 0.1;
		break;
	case 'E': case 'e':	// E,e �Է½� ī�޶��� ��ġ z��ǥ 0.1��ŭ ����
		cz += 0.1;
		break;
	case 'R': case 'r':	// R,r �Է½� ī�޶��� ��ġ x,y,z��ǥ 0���� ����
		cx = 0.0; cy = 0.0; cz = 0.0;
		break;
	}
	glutPostRedisplay();	// ������ ���÷��� �̺�Ʈ�� �߻�
}

void MyReshape(int w, int h) {
	Width = w;
	Height = h;

	GLfloat WidthRatio = (GLfloat)Width / (GLfloat)500;		// �⺻ ������ ũ��� ��ȭ�� ������ ũ���� ����,���κ�
	GLfloat HeightRatio = (GLfloat)Height / (GLfloat)500;

	glViewport(0, 0, Width, Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-2.0 * WidthRatio, 2.0 * WidthRatio, -2.0 * HeightRatio, 2.0 * HeightRatio, 0.5, 5.0); // ��ȭ�� ������ ũ���� ����,���κ� ������ ���������� ��ȯ
}

int main(int argc, char** argv) {
	Width = 500;
	Height = 500;
	glutInit(&argc, argv); // ������ OS�� ���� ���� �� GLUT ���̺귯�� �ʱ�ȭ
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);  // ���÷��� ��带 ����. SINGLE�� �̱۹���, RGB�� GLUT_RGBA���� ���
	glutInitWindowSize(Width, Height);	// �������� �⺻ ũ�⸦ (Width, Height)�� ����
	glutInitWindowPosition(0, 0);	// �������� �⺻ ��ġ ��ǥ ����
	glutCreateWindow("Viewpory Partition");	// �������� Ÿ��Ʋ ����
	MyInit();
	glutDisplayFunc(MyDisplay); // ���÷��� �ݹ��Լ� ���. ���÷��� �̺�Ʈ �߻��� ȣ��
	glutReshapeFunc(MyReshape);	// �������� �ݹ��Լ� ���. �������� ũ�⸦ ��ȯ�� �ڵ�ȣ��
	glutKeyboardFunc(MyKeyboard);	// Ű���� �ݹ��Լ� ���. Ű���� �̺�Ʈ �߻��� ȣ��
	glutMainLoop();	// GLUT �̺�Ʈ ó�� ���� �Է�
	return 0;
}
*/