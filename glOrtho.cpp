/*
#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.0, -30.0);
		glVertex3f(10.0, 0.0, -30.0);
		glVertex3f(10.0, 10.0, -30.0);
		glVertex3f(0.0, 10.0, -30.0);
	glEnd();
	glFlush();
}

void MyInit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION); // ������� ����
	glLoadIdentity(); // ���� ��������� �׵���ķ� �ʱ�ȭ
	glOrtho(0.0, 20.0, 0.0, 20.0, 10.0, 50.0); // ��ĺ�ȯ

	glMatrixMode(GL_MODELVIEW); // �𵨺���� ����
	glLoadIdentity(); // ���� �𵨺� ����� �׵���ķ� �ʱ�ȭ
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
*/