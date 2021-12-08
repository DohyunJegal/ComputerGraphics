/*
#include <GL/glut.h>

void MyDisplay(){
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

void MyReshape(int NewWidth, int NewHeight){
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0*Widthfactor, 20.0*Widthfactor, 0.0*Heightfactor, 20.0*Heightfactor, 10.0, 50.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics");
	MyReshape(400, 400);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
*/