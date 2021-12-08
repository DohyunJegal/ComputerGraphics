/***********************************************************************/
/*                      HW#2 : 2D Primitives                           */
/*  작성자 : 제갈도현                        날짜 : 2021년 9월 24일    */
/*                                                                     */
/*  문제 정의 :   다양한 2D Primitive들을 구현                         */
/*                                                                     */
/*  기능 :        가상의 공간을 구성하는 각 물체를 표현하는 기본 요소  */
/*				  2D 공간에서 2D 객체를 생성 	                       */
/***********************************************************************/

/*
#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.4, 0.3); // 물체의 색상을 (0.5, 0.4, 0.3)로 설정

	glBegin(GL_POLYGON); // 6개의 꼭짓점으로 볼록 Polygon을 표현
		glVertex3f(0.0, 1.0, 0.0); glVertex3f(-1.0, 0.5, 0.0);
		glVertex3f(-1.0, -0.5, 0.0); glVertex3f(0.0, -1.0, 0.0);
		glVertex3f(1.0, -0.5, 0.0); glVertex3f(1.0, 0.5, 0.0);
	glEnd();

	glBegin(GL_POINTS); // 6개의 꼭짓점들을 점으로만 표현
		glVertex3f(0.0, 3.5, 0.0); glVertex3f(-1.0, 3.0, 0.0);
		glVertex3f(-1.0, 2.0, 0.0); glVertex3f(0.0, 1.5, 0.0);
		glVertex3f(1.0, 2.0, 0.0); glVertex3f(1.0, 3.0, 0.0);
	glEnd();

	glBegin(GL_LINES); // 6개의 꼭짓점 중 2개씩 묶어서 선을 표현
		glVertex3f(2.5, 1.0, 0.0); glVertex3f(1.5, 0.5, 0.0);
		glVertex3f(1.5, -0.5, 0.0); glVertex3f(2.5, -1.0, 0.0);
		glVertex3f(3.5, -0.5, 0.0); glVertex3f(3.5, 0.5, 0.0);
	glEnd();

	glBegin(GL_LINE_STRIP); // 6개의 꼭짓점 중 2개씩 묶어서 만든 선을 한 줄로 연결
		glVertex3f(2.5, 3.5, 0.0); glVertex3f(1.5, 3.0, 0.0);
		glVertex3f(1.5, 2.0, 0.0); glVertex3f(2.5, 1.5, 0.0);
		glVertex3f(3.5, 2.0, 0.0); glVertex3f(3.5, 3.0, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP); // 6개의 꼭짓점으로 만든 한 줄의 처음과 끝을 다시 연결한 형태
		glVertex3f(2.5, -1.5, 0.0); glVertex3f(1.5, -2.0, 0.0);
		glVertex3f(1.5, -3.0, 0.0); glVertex3f(2.5, -3.5, 0.0);
		glVertex3f(3.5, -3.0, 0.0); glVertex3f(3.5, -2.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES); // 6개의 꼭짓점 중 3개씩 묶어서 삼각형을 표현
		glVertex3f(0.0, -1.5, 0.0); glVertex3f(-1.0, -2.0, 0.0);
		glVertex3f(-1.0, -3.0, 0.0); glVertex3f(0.0, -3.5, 0.0);
		glVertex3f(1.0, -3.0, 0.0); glVertex3f(1.0, -2.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); // 6개의 꼭짓점 중 3개씩 묶어 만든 삼각형을 길게 연결
		glVertex3f(-2.5, -1.5, 0.0); glVertex3f(-4.5, -1.5, 0.0);
		glVertex3f(-6.5, -1.5, 0.0); glVertex3f(-3.5, -3.0, 0.0);
		glVertex3f(-5.5, -3.0, 0.0); glVertex3f(-7.5, -3.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // 6개의 꼭짓점 중 3개씩 묶어 만든 삼각형을 부채 모양으로 연결
		glVertex3f(-2.5, -1.0, 0.0); glVertex3f(-3.0, 1.0, 0.0);
		glVertex3f(-3.2, 0.7, 0.0); glVertex3f(-4.0, 0.0, 0.0);
		glVertex3f(-4.2, -0.5, 0.0); glVertex3f(-4.5, -1.0, 0.0);
	glEnd();

	glBegin(GL_QUADS); // 8개의 꼭짓점 중 4개씩 묶어 네 개의 모서리를 가진 Polygon 표현
		glVertex3f(5.2, 0.0, 0.0); glVertex3f(5.5, 1.0, 0.0);
		glVertex3f(6.0, 1.5, 0.0); glVertex3f(6.5, 1.0, 0.0);

		glVertex3f(6.7, 1.0, 0.0); glVertex3f(7.5, 1.5, 0.0);
		glVertex3f(8.0, 0.5, 0.0); glVertex3f(7.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_QUAD_STRIP); // 8개의 꼭짓점으로 만든 Polygon을 길게 연결한 형태
		glVertex3f(5.2, -2.5, 0.0); glVertex3f(5.5, -1.5, 0.0);
		glVertex3f(6.5, -1.5, 0.0); glVertex3f(6.0, -1.0, 0.0);

		glVertex3f(7.0, -2.5, 0.0); glVertex3f(7.5, -1.0, 0.0);
		glVertex3f(6.7, -1.5, 0.0); glVertex3f(8.0, -2.0, 0.0);
	glEnd();

	glFlush(); // 큐를 삭제허여 아직 실행되지 않은 명령을 실행
}

void Reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // 투영변환 함수를 호출

	GLfloat Widthfactor = (GLfloat)width / (GLfloat)500; // 새로 변경된 가로와 세로를 기존 크기인 500으로 나누기
	GLfloat Heightfactor = (GLfloat)height / (GLfloat)500;

	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-9.0*Widthfactor, 9.0*Widthfactor, -9.0*Heightfactor, 9.0*Heightfactor, -9, 9); // 변경된 비와 기존의 직교투영과 곱하기

	glMatrixMode(GL_MODELVIEW); // 모델뷰행렬 연산 조작 선택
	glLoadIdentity();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 디스플레이 모드를 설정. SINGLE은 싱글버퍼, RGB는 GLUT_RGBA 사용
	glutInitWindowSize(500, 500); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("2D Primitives"); // 윈도우의 타이틀 설정
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glOrtho(-9.0, 9.0, -9.0, 9.0, -9.0, 9.0); // 직교투영을 변환
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(Reshape); // 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/