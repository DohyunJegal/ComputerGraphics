/***********************************************************************/
/*                   HW#3 : Idle Callback 응용                         */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   다음과 같이 수행되도록 코드 작성                     */
/*                                                                     */
/*  기능 :        ↑ : vertex 좌표가 위 쪽으로 0.1 씩 이동             */
/*                ↓ : vertex 좌표가 아래 쪽으로 0.1 씩 이동           */
/*                ← : vertex 좌표가 왼 쪽으로 0.1 씩 이동             */
/*                → : vertex 좌표가 오른쪽으로 0.1 씩 이동            */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <windows.h>

GLfloat DeltaX = 0.0, DeltaY = 0.0; // 물체의 위치를 정할 변수

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거
	glBegin(GL_POLYGON); // 4개의 꼭짓점으로 Polygon을 표현
	glColor3f(0.0, 0.5, 0.8); // 물체의 색상을 (0.0, 0.5, 0.8)로 설정
		glVertex3f(-1.0 + DeltaX, -0.5 + DeltaY, 0.0); // 좌표를 이동시키기 위해 기존 좌표에 DeltaX, DeltaY를 더함
		glVertex3f(0.0 + DeltaX, -0.5 + DeltaY, 0.0);
		glVertex3f(0.0 + DeltaX, 0.5 + DeltaY, 0.0);
		glVertex3f(-1.0 + DeltaX, 0.5 + DeltaY, 0.0);
	glEnd();
	glutSwapBuffers(); // 프레임버퍼를 교환
}

void MyIdleXP() { // vertex 좌표가 윈도우를 벗어나지 않을 때 오른쪽으로 0.1씩 이동
	if (0.0 + DeltaX < 1.0) {
		DeltaX += 0.1;
		Sleep(50); // 50ms 동안 정지
	}
	glutPostRedisplay(); // 강제로 디스플레이 이벤트를 발생
}

void MyIdleXM() { // vertex 좌표가 윈도우를 벗어나지 않을 때 왼쪽으로 0.1씩 이동
	if (-1.0 + DeltaX > -0.9) {
		DeltaX -= 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MyIdleYP() { // vertex 좌표가 윈도우를 벗어나지 않을 때 위로 0.1씩 이동
	if (0.5 + DeltaY < 1.0) {
		DeltaY += 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MyIdleYM() { // vertex 좌표가 윈도우를 벗어나지 않을 때 아래로 0.1씩 이동
	if (-0.5 + DeltaY > -0.9) {
		DeltaY -= 0.1;
		Sleep(50);
	}
	glutPostRedisplay();
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: // 위 방향키를 눌렀을 때 MyIdleYP 호출
		glutIdleFunc(MyIdleYP);
		break;
	case GLUT_KEY_DOWN: // 아래 방향키를 눌렀을 때 MyIdleYM 호출
		glutIdleFunc(MyIdleYM);
		break;
	case GLUT_KEY_LEFT: // 왼쪽 방향키를 눌렀을 때 MyIdleXM 호출
		glutIdleFunc(MyIdleXM);
		break;
	case GLUT_KEY_RIGHT: // 오른쪽 방향키를 눌렀을 때 MyIdleXP 호출
		glutIdleFunc(MyIdleXP);
		break;
	}
	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); // 직교투영을 변환
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 디스플레이 모드를 설정. RGB는 GLUT_RGBA, DOUBLE은 더블버퍼 사용
	glutInitWindowSize(300, 300); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("Idle Callback"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutSpecialFunc(MySpecial); // 스페셜 키보드 콜백함수 등록. 스페셜 키보드 (특정 키) 이벤트 발생시 호출

	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/