/***********************************************************************/
/*                     HW#4 : 계층적 모델링                            */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 27일   */
/*                                                                     */
/*  문제 정의 :   손가락 3 개를 가진 Robot Arm 제작				       */
/*                                                                     */
/*  기능 :        손가락을 접고, 특정 물체를 잡는 것 처럼 움직임       */
/***********************************************************************/
/*
#include <stdlib.h>
#include <GL/glut.h>

void finger1_in(int); void finger1_out(int);
void finger2_in(int); void finger2_out(int);
void finger3_in(int); void finger3_out(int);
void finger_in(int); void finger_out(int);

static int shoulder = -45, elbow = 45;	// 어깨와 팔꿈치 부위의 각도 조절
static int finger1A = 0, finger1B = 0, finger1C = 0;	// 손가락들의 각도 조절
static int finger2A = 0, finger2B = 0, finger2C = 0;
static int finger3A = 0, finger3B = 0, finger3C = 0;

GLboolean StopTrig = false;	// 움직임을 정지하기 위한 부울형 변수

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// 윈도우의 색상을 초기화
	glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);	// 컬러 버퍼 사용
	glPushMatrix();	// 어깨
		glTranslatef(-3.0, 0.5, 0.0);	// 물체를 (-3, 0.5, 0) 만큼 이동
		glRotatef((GLfloat)shoulder, -0.5, 0.0, 1.0);	// (-0.5, 0, 1)를 기준으로 shoulder만큼 회전
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);	// 물체의 색상을 (1, 1, 1)로 설정
			glScalef(2.0, 0.4, 1.0);	// 물체의 크기를 x축 2배 확대, y축 0.4배 축소
			glutWireCube(1.0);	// 정육각형 생성
		glPopMatrix();

		// 팔꿈치
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();

		// 첫번째 손가락
		glPushMatrix();	
			glTranslatef(0.75, 0.0, -0.15);	// 첫번째 마디
			glRotatef((GLfloat)finger1A, 0.2, 0.0, 1.0);
			glTranslatef(0.75, 0.0, -0.15);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 두번째 마디
			glRotatef((GLfloat)finger1B, 0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 세번째 마디
			glRotatef((GLfloat)finger1C, 0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);	
			glPopMatrix();
		glPopMatrix();

		// 두번째 손가락
		glPushMatrix();	
			glTranslatef(0.75, 0.0, 0.0);	// 첫번째 마디
			glRotatef((GLfloat)finger2A, 0.0, 0.0, 1.0);
			glTranslatef(0.75, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 두번째 마디
			glRotatef((GLfloat)finger2B, 0.0, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 세번째 마디
			glRotatef((GLfloat)finger2C, 0.0, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);	
			glPopMatrix();
		glPopMatrix();

		// 세번째 손가락
		glPushMatrix();
			glTranslatef(0.75, 0.0, 0.15);	// 첫번째 마디
			glRotatef((GLfloat)finger3A, -0.2, 0.0, 1.0);
			glTranslatef(0.75, 0.0, 0.15);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 두번째 마디
			glRotatef((GLfloat)finger3B, -0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();

			glTranslatef(0.5, 0.0, 0.0);	// 세번째 마디
			glRotatef((GLfloat)finger3C, -0.2, 0.0, 1.0);
			glTranslatef(0.5, 0.0, 0.0);
			glPushMatrix();
				glColor3f(1.0, 1.0, 1.0);
				glScalef(1.0, 0.2, 0.2);
				glutWireCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();	// 프레임버퍼를 교환
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);	// 투영변환 함수를 호출
	glMatrixMode(GL_PROJECTION);	// 투영행렬 연산 조작 선택
	glLoadIdentity();	// 현재 행렬을 항등행렬을 사용해 초기화
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);	// 시야각이 65, 종횡비가 w/h, 전방 절단면 1, 후방 절단면 20인 가시부피
	glMatrixMode(GL_MODELVIEW);	// 모델뷰행렬 연산 조작 선택
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void finger1_in(int Value) {
	finger1A += 1; finger1B += 1; finger1C += 1;	// 첫번째 손가락 각도 증가
	glutPostRedisplay();	// 강제로 디스플레이 이벤트를 발생

	if (!StopTrig) {
		if (finger1A < 90)
			glutTimerFunc(25, finger1_in, 1);	// 타이머 이벤트의 특성상 인위적으로 타이머 이벤트를 발생시킴. finger1_in 함수를 25ms 후에 실행
		else 
			glutTimerFunc(25, finger1_out, 1);
	}
}

void finger1_out(int Value) {
	finger1A -= 1; finger1B -= 1; finger1C -= 1;	// 첫번째 손가락 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A > 0)
			glutTimerFunc(25, finger1_out, 1);
		else
			glutTimerFunc(25, finger1_in, 1);
	}
}

void finger2_in(int Value) {
	finger2A += 1; finger2B += 1; finger2C += 1;	// 두번째 손가락 각도 증가
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger2A < 90)
			glutTimerFunc(25, finger2_in, 1);
		else
			glutTimerFunc(25, finger2_out, 1);
	}
}

void finger2_out(int Value) {
	finger2A -= 1; finger2B -= 1; finger2C -= 1;	// 두번째 손가락 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger2A > 0)
			glutTimerFunc(25, finger2_out, 1);
		else
			glutTimerFunc(25, finger2_in, 1);
	}
}

void finger3_in(int Value) {
	finger3A += 1; finger3B += 1; finger3C += 1;	// 세번째 손가락 각도 증가
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger3A < 90)
			glutTimerFunc(25, finger3_in, 1);
		else
			glutTimerFunc(25, finger3_out, 1);
	}
}

void finger3_out(int Value) {
	finger3A -= 1; finger3B -= 1; finger3C -= 1;	// 세번째 손가락 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger3A > 0)
			glutTimerFunc(25, finger3_out, 1);
		else
			glutTimerFunc(25, finger3_in, 1);
	}
}

void finger_in(int Value) {
	finger1A += 1; finger1B += 1; finger1C += 1;	// 모든 손가락의 각도 증가
	finger2A += 1; finger2B += 1; finger2C += 1;
	finger3A += 1; finger3B += 1; finger3C += 1;
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A < 90 || finger2A < 90 || finger3A < 90)
			glutTimerFunc(25, finger_in, 1);
		else
			glutTimerFunc(25, finger_out, 1);
	}
}

void finger_out(int Value) {
	finger1A -= 1; finger1B -= 1; finger1C -= 1;	// 모든 손가락의 각도 감소
	finger2A -= 1; finger2B -= 1; finger2C -= 1;
	finger3A -= 1; finger3B -= 1; finger3C -= 1;
	glutPostRedisplay();

	if (!StopTrig) {
		if (finger1A > 0 || finger2A > 0 || finger3A > 0)
			glutTimerFunc(25, finger_out, 1);
		else
			glutTimerFunc(25, finger_in, 1);
	}
}

void grab_in(int Value) {
	shoulder -= 1; elbow += 1;	// 어깨 각도 감소, 팔꿈치 각도 증가
	finger1A += 2; finger1B += 2; finger1C += 2;
	finger2A += 2; finger2B += 2; finger2C += 2;
	finger3A += 2; finger3B += 2; finger3C += 2;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulder > -90)
			glutTimerFunc(25, grab_in, 1);
	}
}

void grab_out(int Value) {
	shoulder += 1; elbow -= 1;	// 어깨 각도 증가, 팔꿈치 각도 감소
	finger1A -= 2; finger1B -= 2; finger1C -= 2;
	finger2A -= 2; finger2B -= 2; finger2C -= 2;
	finger3A -= 2; finger3B -= 2; finger3C -= 2;
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulder < -45)
			glutTimerFunc(25, grab_out, 1);
	}
}

void MyMouse(GLint Button, GLint State, GLint X, GLint Y) {
	if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN)) {	// 마우스 왼쪽 버튼을 눌렀을 때 grab_in 함수 작동
		StopTrig = false;
		glutTimerFunc(25, grab_in, 1);
	}	
	if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN)) {	// 마우스 오른쪽 버튼을 눌렀을 때 grab_out 함수 작동
		StopTrig = false;
		glutTimerFunc(25, grab_out, 1);
	}
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		StopTrig = false;
		glutTimerFunc(25, finger1_in, 1);
		break;
	case '2':
		StopTrig = false;
		glutTimerFunc(25, finger2_in, 1);
		break;
	case '3':
		StopTrig = false;
		glutTimerFunc(25, finger3_in, 1);
		break;
	case '4':
		StopTrig = false;
		glutTimerFunc(25, finger_in, 1);
		break;
	case 'S':	// 키보드의 S 키를 누르면 정지
	case 's':
		StopTrig = true;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// 디스플레이 모드를 설정. DOUBLE은 더블버퍼, RGB는 GLUT_RGBA버퍼 사용
	glutInitWindowSize(800, 600);	// 윈도우의 기본 크기 지정
	glutInitWindowPosition(100, 100);	// 윈도우의 기본 위치 좌표 설정
	glutCreateWindow("Robot Arm");	// 윈도우의 타이틀 설정
	MyInit();
	glutDisplayFunc(MyDisplay);	// 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(MyReshape);	// 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutKeyboardFunc(MyKeyboard);	// 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutMouseFunc(MyMouse); // 마우스 콜백함수 등록. 마우스 이벤트 발생시 호출
	glutMainLoop();	// GLUT 이벤트 처리 루프 입력
	return 0;
}
*/