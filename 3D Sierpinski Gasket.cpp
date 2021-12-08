/***********************************************************************/
/*                      HW#1 : 3D Sierpinski Gasket                    */
/*  작성자 : 제갈도현                        날짜 : 2021년 9월 17일    */
/*                                                                     */
/*  문제 정의 :                                                        */
/*                3D Sierpinski Gasket 구현                            */
/*  기능 :                                                             */
/*                2D로 생성된 Sierpinski Gasket을 3D로 변환            */
/***********************************************************************/

/*

#include <GL/glut.h>
#include <stdlib.h>  //rand() 함수 사용 용도

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // 창의 색을 초기화 
	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION); // 행렬 연산 시 조작하고자 하는 행렬을 선택. GL_PROJECTION은 투영
	glLoadIdentity(); // 현재 모델뷰 행렬을 항등행렬을 사용해 초기화
	glOrtho(0.0, 500.0, 0.0, 500.0, 0, -250); // 직교투영을 변환
}

void MyDisplay(void) {
	float vertices[4][3] = { { 0.0, 0.0, 0.0 },{ 250.0, 500.0, 100.0 },{ 500.0, 250.0, 250.0 },{ 250.0 , 100.0 , 250.0 } }; // 삼각뿔의 꼭짓점을 초기화
	int i, j;
	float p[3] = { 250.0, 100.0, 250.0 };  // 내부에 무작위로 찍을 점

	glClear(GL_COLOR_BUFFER_BIT); // 특정이나 혼합된 색 버퍼를 제거

	for (j = 0; j<50000; j++) {
		i = rand() % 4; // 삼각뿔의 꼭짓점 중 무작위로 선택
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0; // 꼭짓점과 무작위 점의 중간을 찍음

		glBegin(GL_POINTS);
		glVertex3fv(p);  // 3차원 float형 정점
		glEnd();
	}

	glFlush(); // 큐를 삭제. 아직 실행되지 않은 명령을 실행
}

void MyReshape(int NewWidth, int NewHeight){
	glViewport(0, 0, NewWidth, NewHeight); // 투영변환 함수 호출
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0*Widthfactor, 500.0*Widthfactor, 0.0*Heightfactor, 500.0*Heightfactor, 0, -250); // 가로 세로비를 다시 측정하여 직교투영 변환
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결. GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 디스플레이 모드 설정. SINGLE은 싱글버퍼, RGB는 GLUT_RGBA 사용
	glutInitWindowSize(500, 500); // 윈도우의 크기
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski Gasket"); // 윈도우의 타이틀
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	MyInit();
	glutReshapeFunc(MyReshape); // 리셰이프 콜백함수 등록. 화면 크기 변환시 호출
	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}

*/