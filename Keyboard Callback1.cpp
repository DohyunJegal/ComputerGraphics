/***********************************************************************/
/*                   HW#3 : Keyboard Callback 응용I                    */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   다음과 같은 기능이 수행되도록 코드 작성              */
/*                                                                     */
/*  기능 :        a 또는 A : vertex 좌표가 왼쪽으로 0.1 씩 이동        */
/*				  f 또는 F : vertex 좌표가 오른쪽으로 0.1 씩 이동      */
/*                r 또는 R : vertex 좌표가 아래쪽으로 0.1 씩 이동,     */
/*				             빨간색으로 Polygon 칠함                   */
/*                v 또는 V : vertex 좌표가 위쪽으로 0.1 씩 이동        */
/*                b 또는 B : 파란색으로 Polygon 칠함                   */
/***********************************************************************/
/*
#include <GL/glut.h>

GLfloat ca = 0.5f, cb = 0.5f, cc = 0.5f, DeltaX = 0.0, DeltaY = 0.0; // 물체의 색상과 위치를 정할 변수

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거
	glColor3f(ca, cb, cc); // 물체의 색상을 (ca, cb, cc)로 설정
	glBegin(GL_POLYGON); // 4개의 꼭짓점으로 Polygon을 표현
		glVertex3f(-0.5 + DeltaX, -0.5 + DeltaY, 0.0); // 좌표를 이동시키기 위해 기존 좌표에 DeltaX, DeltaY를 더함
		glVertex3f(0.5 + DeltaX, -0.5 + DeltaY, 0.0);
		glVertex3f(0.5 + DeltaX, 0.5 + DeltaY, 0.0);
		glVertex3f(-0.5 + DeltaX, 0.5 + DeltaY, 0.0);
	glEnd();
	glFlush(); // 큐를 삭제하여 아직 실행되지 않은 명령을 실행
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a': // a나 A를 누른 경우 도형을 왼쪽으로 0.1 이동
		DeltaX += -0.1; break;
	case 'A':
		DeltaX += -0.1; break;
	case 'f': // f나 F를 누른 경우 도형을 오른쪽으로 0.1 이동
		DeltaX += 0.1; break;
	case 'F':
		DeltaX += 0.1; break;
	case 'r': // r이나 R을 누른 경우 도형을 아래쪽으로 0.1 이동 후 도형의 색을 빨간색으로 변경
		DeltaY += -0.1;
		ca = 1.0f; cb = 0.0; cc = 0.0; break;
	case 'R':
		DeltaY += -0.1;
		ca = 1.0f; cb = 0.0; cc = 0.0; break;
	case 'v':// v나 V를 누른 경우 도형을 위쪽으로 0.1 이동
		DeltaY += 0.1; break;
	case 'V':
		DeltaY += 0.1; break;
	case 'b': // b나 B를 누른 경우 도형을 파란색으로 변경
		ca = 0; cb = 0; cc = 1.0f; break;
	case 'B':
		ca = 0; cb = 0; cc = 1.0f; break;
	case 'Q': // q나 Q를 누른 경우 프로그램 종료
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	}
	glutPostRedisplay(); // 강제로 디스플레이 이벤트를 발생
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 직교투영을 변환
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 설정. GLUT_RGBA 사용
	glutInitWindowSize(300, 300); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("Keyboard Callback1"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutKeyboardFunc(MyKeyboard); // 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/