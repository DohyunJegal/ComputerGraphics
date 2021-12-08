/***********************************************************************/
/*                HW#5-1. gluLookAt()의 실시간 제어                    */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 29일   */
/*                                                                     */
/*  문제 정의 :   시점 좌표계를 Keyboard Callback 함수로               */
/*                실시간 제어가 가능하도록 구현				           */
/*                                                                     */
/*  기능 :        카메라와 초점의 좌표를 증가/감소                     */
/*                S,s - 좌표 이동 정지                                 */
/***********************************************************************/
/*
#include <GL/glut.h>

GLboolean StopTrig = false;	// 움직임을 정지하기 위한 부울형 변수
static double cx = 0, cy = 0, fx = 0, fy = 0, fz = 0;	// 카메라의 위치나 카메라의 초점을 변경시킬 변수

void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);	// 물체의 색상을 (0.5, 0.5, 0.5)로 설정
	glBegin(GL_POLYGON);	// 4개의 꼭짓점으로 평면의 Polygon을 표현
		glVertex3f(-2.0, -0.71, 2.0);
		glVertex3f(2.0, -0.71, 2.0);
		glVertex3f(2.0, -0.71, -2.0);
		glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);	// 2개의 꼭짓점으로 선분을 반복적으로 표현
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 컬러 버퍼와 깊이 버퍼를 초기화
	glMatrixMode(GL_MODELVIEW);	// 모델뷰행렬 연산 조작 선택
	glLoadIdentity();	// 현재 행렬을 항등행렬을 사용해 초기화
	
	gluLookAt(0.0 + cx, 3.5 + cy, 3.5, 0.0 + fx, 0.0 + fy, 0.0 + fz, 0.0, 1.0, 0.0); 
	// 카메라를 (0.0 + cx, 3.5 + cy, 3.5)에 위치, (0.0 + fx, 0.0 + fy, 0.0 + fz)을 바라보게, y축으로 1만큼 기울이게 설정

	DrawGround();

	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0);	// 크기가 1인 주전자 생성

	glFlush(); // 큐를 삭제하여 아직 실행되지 않은 명령을 실행
}

void fxp(int Value) {
	fx += 0.1;
	glutPostRedisplay();	// 강제로 디스플레이 이벤트를 발생

	if (!StopTrig)
		glutTimerFunc(50, fxp, 1);	// 타이머 이벤트의 특성상 인위적으로 타이머 이벤트를 발생시킴. fxp 함수를 50ms 후에 실행
}

void fxm(int Value) {
	fx -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fxm, 1);
}

void fyp(int Value) {
	fy += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fyp, 1);
}

void fym(int Value) {
	fy -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fym, 1);
}

void fzp(int Value) {
	fz += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fzp, 1);
}

void fzm(int Value) {
	fz -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, fzm, 1);
}

void cxp(int Value) {
	cx += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cxp, 1);
}

void cxm(int Value) {
	cx -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cxm, 1);
}

void cyp(int Value) {
	cy += 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cyp, 1);
}

void cym(int Value) {
	cy -= 0.1;
	glutPostRedisplay();

	if (!StopTrig)
		glutTimerFunc(50, cym, 1);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A':	// A,a 입력시 카메라의 초점 x좌표 0.1만큼 증가
	case 'a':
		StopTrig = FALSE;
		glutTimerFunc(50, fxp, 1);
		break;
	case 'F':	// F,f 입력시 카메라의 초점 x좌표 0.1만큼 감소
	case 'f':
		StopTrig = FALSE;
		glutTimerFunc(50, fxm, 1);
		break;
	case 'R':	// R,r 입력시 카메라의 초점 y좌표 0.1만큼 증가
	case 'r':
		StopTrig = FALSE;
		glutTimerFunc(50, fyp, 1);
		break;
	case 'V':	// V,v 입력시 카메라의 초점 y좌표 0.1만큼 감소
	case 'v':
		StopTrig = FALSE;
		glutTimerFunc(50, fym, 1);
		break;
	case 'Z':	// Z,z 입력시 카메라의 초점 z좌표 0.1만큼 증가
	case 'z':
		StopTrig = FALSE;
		glutTimerFunc(50, fzp, 1);
		break;
	case 'T':	// T,t 입력시 카메라의 초점 z좌표 0.1만큼 감소
	case 't':
		StopTrig = FALSE;
		glutTimerFunc(50, fzm, 1);
		break;
	case 'S':	// S,s 입력시 움직임 정지
	case 's':
		StopTrig = TRUE;
		break;
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:	// ↑ 입력시 카메라의 위치 y좌표 0.1만큼 증가
		StopTrig = FALSE;
		glutTimerFunc(50, cyp, 1);
		break;
	case GLUT_KEY_DOWN:	// ↓ 입력시 카메라의 위치 y좌표 0.1만큼 감소
		StopTrig = FALSE;
		glutTimerFunc(50, cym, 1);
		break;
	case GLUT_KEY_LEFT:	// ← 입력시 카메라의 위치 x좌표 0.1만큼 감소
		StopTrig = FALSE;
		glutTimerFunc(50, cxm, 1);
		break;
	case GLUT_KEY_RIGHT:	// → 입력시 카메라의 위치 x좌표 0.1만큼 증가
		StopTrig = FALSE;
		glutTimerFunc(50, cxp, 1);
		break;
	}
	glutPostRedisplay();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);	// 투영변환 함수를 호출
	glMatrixMode(GL_PROJECTION);	// 투영행렬 연산 조작 선택
	glLoadIdentity();

	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);	// 원근 투영함수를 호출하여 물체 투영
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);	// 디스플레이 모드를 설정. SINGLE은 단일버퍼, RGBA는 GLUT_RGBA버퍼 사용
	glutInitWindowSize(500, 500);	// 윈도우의 기본 크기 지정
	glutInitWindowPosition(0, 0);	// 윈도우의 기본 위치 좌표 설정
	glutCreateWindow("VCS (View Coordinate System)");	// 윈도우의 타이틀 설정
	glClearColor(0.0, 0.0, 0.0, 0.0);	// 윈도우의 색상을 초기화

	glutDisplayFunc(MyDisplay);	// 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(MyReshape);	// 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutKeyboardFunc(MyKeyboard);	// 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutSpecialFunc(MySpecial);	// 스페셜 키보드 콜백함수 등록. 특정 키 이벤트 발생시 호출

	glutMainLoop();	// GLUT 이벤트 처리 루프 입력
	return 0;
}
*/