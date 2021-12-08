/***********************************************************************/
/*                   HW#3 : Menu Callback 응용                         */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 01일   */
/*                                                                     */
/*  문제 정의 :   다음과 같은 기능이 수행되도록 코드 작성              */
/*                                                                     */
/*  기능 : 주메뉴                                                      */
/*           Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit  */
/*                                                                     */
/*           Draw Sphere 하부 메뉴 : Small Sphere, Large Sphere        */
/*           Draw Torus 하부 메뉴 : Small Torus , Large Torus          */
/*           Draw Teapot 하부 메뉴 : Small Teapot , Large Teapot       */
/*           Change Color 하부 메뉴 : Red, Green, Blue                 */
/***********************************************************************/
/*
#include <GL/glut.h>

GLint Shape = 1; // 1 = Small Sphere, 2 = Large Sphere 
				 // 3 = Small Torus,  4 = Large Torus
				 // 5 = Small Teapot, 6 = Large Teapot

GLfloat r = 0.0, g = 0.5, b = 0.5; // 물체의 색상을 나타내기 위한 변수

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거
	glColor3f(r, g, b); // 물체의 색상을 (r, g, b)로 설정

	if (Shape == 1)
		glutWireSphere(0.5, 30, 30); // 선분만으로 이루어진 구 생성
	else if (Shape == 2)
		glutWireSphere(0.7, 30, 30);
	else if (Shape == 3)
		glutWireTorus(0.1, 0.2, 40, 20); // 선분만으로 이루어진 원환체 생성
	else if (Shape == 4)
		glutWireTorus(0.3, 0.5, 40, 20);
	else if (Shape == 5)
		glutWireTeapot(0.2); // 선분만으로 이루어진 주전자 생성
	else
		glutWireTeapot(0.5);
	glFlush(); // 큐를 삭제하여 아직 실행되지 않은 명령을 실행
}

void MyMainMenu(int entryID) {
	if (entryID == 5)       exit(0);

	glutPostRedisplay(); // 강제로 디스플레이 이벤트를 발생
}

void MySphereMenu(int entryID) {
	if (entryID == 1)           Shape = 1;
	else if (entryID == 2)      Shape = 2;

	glutPostRedisplay();
}

void MyTorusMenu(int entryID) {
	if (entryID == 1)           Shape = 3;
	else if (entryID == 2)      Shape = 4;

	glutPostRedisplay();
}

void MyTeapotMenu(int entryID) {
	if (entryID == 1)           Shape = 5;
	else if (entryID == 2)      Shape = 6;

	glutPostRedisplay();
}

void MyColorMenu(int entryID) {
	if (entryID == 1) { r = 1.0; g = 0.0; b = 0.0; } // 물체의 색상을 변경
	else if (entryID == 2) { r = 0.0; g = 1.0; b = 0.0; }
	else if (entryID == 3) { r = 0.0; g = 0.0; b = 1.0; }

	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // 윈도우의 색상을 초기화
	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 직교투영을 변환

	GLint MySphereID = glutCreateMenu(MySphereMenu); // 메뉴 콜백함수 등록
	glutAddMenuEntry("Small Sphere", 1); // 현재 pop-up 메뉴에 메뉴항목 추가. 현재 이름 / 콜백함수에 전달할 정수 값
	glutAddMenuEntry("Large Sphere", 2);

	GLint MyTorusID = glutCreateMenu(MyTorusMenu);
	glutAddMenuEntry("Small Torus", 1);
	glutAddMenuEntry("Large Torus", 2);

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu);
	glutAddMenuEntry("Small Teapot", 1);
	glutAddMenuEntry("Large Teapot", 2);

	GLint MyColorID = glutCreateMenu(MyColorMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySphereID); // 현 메뉴 항목 중 하나로서 서브 메뉴 항목을 추가. 서브 메뉴명 / 리턴된 메뉴 아이디 값
	glutAddSubMenu("Draw Tours", MyTorusID);
	glutAddSubMenu("Draw Teapot", MyTeapotID);
	glutAddSubMenu("Change Color", MyColorID);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON); // 지정한 마우스 버튼에 현 메뉴 할당. 버튼을 누르면 메뉴 팝업
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_RGB); // 디스플레이 모드를 설정. GLUT_RGBA 사용
	glutInitWindowSize(500, 500); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("Menu Callback"); // 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출

	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/
