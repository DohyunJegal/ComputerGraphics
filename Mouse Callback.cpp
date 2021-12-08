/***********************************************************************/
/*                   HW#3 : Mouse Callback 응용                        */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   다음과 같은 기능이 수행되도록 코드 작성              */
/*                                                                     */
/*  기능 :        마우스 왼쪽 버튼을 click                             */
/*                    vertex 좌표가 오른쪽으로 0.1 씩 연속적으로 이동  */
/*                마우스 오른쪽 버튼을 click                           */
/*                    이동하고 있는 Polygon 이 멈춤                    */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <windows.h>

GLfloat vax = -0.5, vay = -0.5; // Polygon의 꼭짓점 좌표를 표현하기 위한 변수
GLfloat vbx = 0.5, vby = -0.5;
GLfloat vcx = 0.5, vcy = 0.5;
GLfloat vdx = -0.5, vdy = 0.5;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거
	glColor3f(0.5f, 0.5f, 0.5f); // 물체의 색상을 (0.5, 0.5, 0.5)로 설정
	glBegin(GL_POLYGON); // 4개의 꼭짓점으로 Polygon을 표현
		glVertex3f(vax, vay, 0.0);
		glVertex3f(vbx, vby, 0.0);
		glVertex3f(vcx, vcy, 0.0);
		glVertex3f(vdx, vdy, 0.0);
	glEnd();
	glutSwapBuffers(); // 프레임버퍼를 교환
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': // q나 Q를 누른 경우 프로그램 종료
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	}
	glutPostRedisplay(); // 강제로 디스플레이 이벤트를 발생
}

void MyIdle() {
	if (vbx <= 1.0 && vcx <= 1.0){ // vertex 좌표가 윈도우를 벗어나지 않을 때 오른쪽으로 0.1씩 이동
		vax += 0.1f; vbx += 0.1f; vcx += 0.1f; vdx += 0.1f;
		Sleep(250); // 250ms 동안 정지
	}
	glutPostRedisplay();
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) // 마우스 왼버튼을 눌렀을 때 MyIdle 호출
		glutIdleFunc(MyIdle);
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) // 마우스 왼버튼을 눌렀을 때 Idle 종료
		glutIdleFunc(NULL);
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 직교투영을 변환
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE); // 디스플레이 모드를 설정. RGB는 GLUT_RGBA, DOUBLE은 더블버퍼 사용
	glutInitWindowSize(300, 300); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("Keyboard Callback"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutKeyboardFunc(MyKeyboard); // 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutMouseFunc(MyMouse); // 마우스 콜백함수 등록. 마우스 이벤트 발생시 호출

	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/