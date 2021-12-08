/***********************************************************************/
/*                   HW#3 : Timer Callback 응용                        */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   프로그램이 실행되면 도형이 오른쪽으로 0.1씩          */
/*                연속적으로 움직이게 하고, 오른쪽 경계에 부딪히면     */
/*                도형의 색깔이 변하게 한 후, 다시 도형이 왼쪽으로     */
/*                0.1씩 연속적으로 움직이는 과정을 반복함              */
/*                                                                     */
/*  기능 :        마우스 왼쪽 키를 누르면 움직이는 도형이 멈춤         */
/***********************************************************************/
/*
#include <GL/glut.h>

void MyTimerP(int);
void MyTimerM(int);

GLfloat Delta = 0.0; // 물체의 위치를 정할 변수
GLfloat r = 0.0, g = 0.5, b = 0.8;  // 물체의 색상을 정할 변수
GLboolean StopTrig = false; // 물체의 이동을 멈추기 위한 변수 생성

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거
	glBegin(GL_POLYGON); // 4개의 꼭짓점으로 Polygon을 표현
	glColor3f(r,g,b); // 물체의 색상을 (r, g, b)로 설정
		glVertex3f(-1.0 + Delta, -0.5, 0.0);  // 좌표를 이동시키기 위해 기존 좌표에 Delta를 더함
		glVertex3f(0.0 + Delta, -0.5, 0.0);
		glVertex3f(0.0 + Delta, 0.5, 0.0);
		glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers(); // 프레임버퍼를 교환
}

void MyTimerP(int Value) {
	r = 0.0; g = 0.5; b = 0.8; // 물체의 색상을 (0.0, 0.5, 0.8)으로 변경
	Delta += 0.1; // 물체의 좌표를 우측으로 이동
	glutPostRedisplay(); // 강제로 디스플레이 이벤트를 발생

	if (!StopTrig) {
		if(0.0 + Delta < 1.0) // 물체가 윈도우를 벗어나지 않을 때 오른쪽으로 이동
			glutTimerFunc(100, MyTimerP, 1); // 타이머 이벤트의 특성상 인위적으로 타이머 이벤트를 발생시킴. MyTimerP 함수를 100초 후에 실행
		else // 물체를 왼쪽으로 이동
			glutTimerFunc(100, MyTimerM, 1); // MyTimerM 함수를 100초 후에 실행
	}
}

void MyTimerM(int Value) {
	r = 0.5; g = 0.5; b = 0.8; // 물체의 색상을 (0.5, 0.5, 0.8)으로 변경
	Delta -= 0.1; // 물체의 좌표를 좌측으로 이동
	glutPostRedisplay();

	if (!StopTrig) {
		if (-1.0 + Delta > -0.9) // 물체가 윈도우를 벗어나지 않을 때 왼쪽으로 이동
			glutTimerFunc(100, MyTimerM, 1);
		else // 물체를 오른쪽으로 이동
			glutTimerFunc(100, MyTimerP, 1);
	}
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) // 마우스 왼버튼이 눌린 경우 물체의 이동을 멈춤
		StopTrig = true; 
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // 직교투영을 변환
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 디스플레이 모드를 설정. RGB는 GLUT_RGBA, DOUBLE은 더블버퍼 사용
	glutInitWindowSize(300, 300); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("Timer Callback"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutTimerFunc(100, MyTimerP, 1); // 타이머 콜백함수 등록. 타이머 이벤트 발생시 호출.
	glutMouseFunc(MyMouse); // 마우스 콜백함수 등록. 마우스 이벤트 발생시 호출

	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/