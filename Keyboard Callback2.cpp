/***********************************************************************/
/*                   HW#3 : Keyboard Callback 응용II                   */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   다음과 같은 기능이 수행되도록 코드 작성              */
/*                                                                     */
/*  기능 :        ↑ : vertex 좌표가 위 쪽으로 0.1 씩 이동             */
/*                ↓ : vertex 좌표가 아래 쪽으로 0.1 씩 이동           */
/*                ← : vertex 좌표가 왼 쪽으로 0.1 씩 이동             */
/*                → : vertex 좌표가 오른쪽으로 0.1 씩 이동            */
/***********************************************************************/
/*
#include <GL/glut.h>
#include <cmath>

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
	glFlush(); // 큐를 삭제하여 아직 실행되지 않은 명령을 실행
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

void MySpecial(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP: // vertex 좌표가 윈도우를 벗어나지 않을 때 위 방향키를 누른 경우 위로 0.1씩 이동
			if (vcy <= 1.0 && vdy <= 1.0){
				vay += 0.1; vby += 0.1; vcy += 0.1; vdy += 0.1; 
			} break;
		case GLUT_KEY_DOWN: // vertex 좌표가 윈도우를 벗어나지 않을 때 아래 방향키를 누른 경우 아래로 0.1씩 이동
			if (vay >= -1.0 && vby >= -1.0) {
				vay -= 0.1; vby -= 0.1; vcy -= 0.1; vdy -= 0.1;
			} break;
		case GLUT_KEY_LEFT: // vertex 좌표가 윈도우를 벗어나지 않을 때 왼쪽 방향키를 누른 경우 왼쪽으로 0.1씩 이동
			if (vax >= -1.0 && vdx >= -1.0) {
				vax -= 0.1; vbx -= 0.1; vcx -= 0.1; vdx -= 0.1; 
			} break;
		case GLUT_KEY_RIGHT: // vertex 좌표가 윈도우를 벗어나지 않을 때 오른쪽 방향키를 누른 경우 오른쪽으로 0.1씩 이동
			if (vbx <= 1.0 && vcx <= 1.0) {
				vax += 0.1; vbx += 0.1; vcx += 0.1; vdx += 0.1;
			} break;
		case GLUT_KEY_PAGE_UP: // vertex 좌표가 윈도우에 붙지 않을 때 Page Up을 누른 경우 전체적으로 0.1씩 확대
			if (vax >= -1.0 && vay >= -1.0 && vbx <= 1.0 && vby >= -1.0 && vcx <= 1.0 && vcy <= 1.0 && vdx >= -1.0 && vdy <= 1.0) {
				vax -= 0.1; vbx += 0.1; vcx += 0.1; vdx -= 0.1;
				vay -= 0.1; vby -= 0.1; vcy += 0.1; vdy += 0.1;
			} break;
		case GLUT_KEY_PAGE_DOWN: // vertex 좌표가 서로 만나지 않을 때 Page Down을 누른 경우 전체적으로 0.1씩 축소
			if (vbx - vax >= 0.3) {
				vax += 0.1; vbx -= 0.1; vcx -= 0.1; vdx += 0.1;
				vay += 0.1; vby += 0.1; vcy -= 0.1; vdy -= 0.1; 
			} break;
	}
	glutPostRedisplay();
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
	glutCreateWindow("Keyboard Callback2"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutKeyboardFunc(MyKeyboard); // 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutSpecialFunc(MySpecial); // 스페셜 키보드 콜백함수 등록. 스페셜 키보드 (특정 키) 이벤트 발생시 호출
	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/