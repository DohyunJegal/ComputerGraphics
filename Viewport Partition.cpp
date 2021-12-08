/***********************************************************************/
/*               HW#6. glViewport()을 통한 뷰폿변환                    */
/*  작성자 : 제갈도현                        날짜 : 2021년 11월 10일   */
/*                                                                     */
/*  문제 정의 :   한 뷰폿에 2개 이상의 물체를 표현                     */
/*                하나의 윈도우를 4개의 뷰폿으로 분할 				   */
/*                원근투영과 평행투영 이용		                       */
/*                Keyboard Callback을 사용하여 카메라 이동 (시점변환)  */
/*                뷰폿들은 객체를 기본적으로 뷰폿의 중심에 위치        */
/*                                                                     */
/*  기능 :        W,w / S,s - 카메라의 y좌표를 증가/감소               */
/*                D,d / A,a - 카메라의 x좌표를 증가/감소               */
/*                E,e / Q,q - 카메라의 z좌표를 증가/감소               */
/*                R,r - 카메라를 기존 위치로 이동                      */
/***********************************************************************/
/*
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric을 생성
static double cx = 0, cy = 0, cz = 0;	// 카메라의 위치를 변경시킬 변수
int Width, Height;	// 창의 크기를 나타낼 변수

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);	// 윈도우의 색상을 (1.0, 1.0, 1.0, 1.0)로 초기화
	glMatrixMode(GL_PROJECTION);	// 투영행렬 연산 조작 선택
	glLoadIdentity();	// 현재 행렬을 항등행렬을 사용해 초기화

	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); // 직교투영을 변환
	glMatrixMode(GL_MODELVIEW);	// 모델뷰행렬 연산 조작 선택
	glLoadIdentity();
}

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);	// 물체의 색상을 (0.7, 0.7, 0.7)로 설정
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);	// 물체를 (0.0, -1.0, 0.0) 만큼 이동
	glBegin(GL_QUADS);	// 정점을 통해 사각형을 그림
	glVertex3f(2.0, 0.0, 2.0);	// 정점의 좌표를 설정
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);	// 크기가 1.0인 주전자를 그림
	glPopMatrix();

	glColor3f(0.3, 0.3, 0.3);
	glPushMatrix();
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric의 Draw Style을 Wire-frame 형태로 모델링
	glTranslatef(0.0, 0.0, 1.1);
	gluSphere(qobj, 0.5, 30, 30); // 반지름이 0.5, Z축 중심 Subdivision이 30, Z축을 따르는 Subdivision이 30인 구를 그림
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);	// 컬러 버퍼를 초기화
	glColor3f(1.0, 1.0, 1.0);

	glViewport(0, 0, Width / 2, Height / 2);	// 투영변환 함수를 호출, 좌측 하단
	glPushMatrix();
	gluLookAt(0.0 + cx, 0.0 + cy, 1.0 + cz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // 카메라를(0.0 + cx, 0.0 + cy, 1.0 + cz)에 위치, (0.0, 0.0, 0.0)을 바라보게, y축으로 1만큼 기울이게 설정
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);	// 투영변환 함수를 호출, 우측 상단
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	if (Width <= Height)	// 윈도우의 가로와 세로 크기를 비교하여 적절하게 원근 투영함수를 호출하여 물체 투영
		gluPerspective(30 * ((GLfloat)Height / (GLfloat)500), (GLfloat)Height / Width, 3.0, 50.0);
	else
		gluPerspective(30 * ((GLfloat)Height / (GLfloat)500), (GLfloat)Width / Height, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0 + cx, 5.0 + cy, 5.0 + cz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A': case 'a':	// A,a 입력시 카메라의 위치 x좌표 0.1만큼 감소
		cx -= 0.1;
		break;
	case 'D': case 'd':	// D,d 입력시 카메라의 위치 x좌표 0.1만큼 증가
		cx += 0.1;
		break;
	case 'W': case 'w':	// W,w 입력시 카메라의 위치 y좌표 0.1만큼 증가
		cy += 0.1;
		break;
	case 'S': case 's':	// S,s 입력시 카메라의 위치 y좌표 0.1만큼 감소
		cy -= 0.1;
		break;
	case 'Q': case 'q':	// Q,q 입력시 카메라의 위치 z좌표 0.1만큼 감소
		cz -= 0.1;
		break;
	case 'E': case 'e':	// E,e 입력시 카메라의 위치 z좌표 0.1만큼 증가
		cz += 0.1;
		break;
	case 'R': case 'r':	// R,r 입력시 카메라의 위치 x,y,z좌표 0으로 설정
		cx = 0.0; cy = 0.0; cz = 0.0;
		break;
	}
	glutPostRedisplay();	// 강제로 디스플레이 이벤트를 발생
}

void MyReshape(int w, int h) {
	Width = w;
	Height = h;

	GLfloat WidthRatio = (GLfloat)Width / (GLfloat)500;		// 기본 윈도우 크기와 변화한 윈도우 크기의 가로,세로비
	GLfloat HeightRatio = (GLfloat)Height / (GLfloat)500;

	glViewport(0, 0, Width, Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-2.0 * WidthRatio, 2.0 * WidthRatio, -2.0 * HeightRatio, 2.0 * HeightRatio, 0.5, 5.0); // 변화한 윈도우 크기의 가로,세로비를 적용해 직교투영을 변환
}

int main(int argc, char** argv) {
	Width = 500;
	Height = 500;
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);  // 디스플레이 모드를 설정. SINGLE은 싱글버퍼, RGB는 GLUT_RGBA버퍼 사용
	glutInitWindowSize(Width, Height);	// 윈도우의 기본 크기를 (Width, Height)로 설정
	glutInitWindowPosition(0, 0);	// 윈도우의 기본 위치 좌표 설정
	glutCreateWindow("Viewpory Partition");	// 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(MyReshape);	// 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutKeyboardFunc(MyKeyboard);	// 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutMainLoop();	// GLUT 이벤트 처리 루프 입력
	return 0;
}
*/