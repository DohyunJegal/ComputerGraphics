/***********************************************************************/
/*                     HW#4 : 계층적 모델링                            */
/*  작성자 : 제갈도현                        날짜 : 2021년 10월 27일   */
/*                                                                     */
/*  문제 정의 :   전신 Can Robot 구현				                   */
/*                                                                     */
/*  기능 :        머리와 팔, 다리를 움직인 후 돌아오게 하는 메뉴       */
/***********************************************************************/
/*
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj *qobj = gluNewQuadric();	// 새로운 Quadric을 생성

GLboolean StopTrig = false;	// 움직임을 정지하기 위한 부울형 변수
static int head = 0;	// 머리의 각도를 조절
static int shoulderL = 20, shoulderR = 20, armL = 20, armR = 20;	// 팔 관련 부위의 각도를 조절
static int legL = 0, legR = 0, kneeR = 0;	// 다리의 각도 조절

void moveheadL(int); void moveheadR(int);
void armLup(int); void armLdown(int);
void armRup(int); void armRdown(int);
void legLup(int); void legLdown(int);
void legRup(int); void legRdown(int);

void MyMainMenu(int entryID) {
	if (entryID == 1) {
		StopTrig = false;
		glutTimerFunc(25, moveheadL, 1);	// 타이머 이벤트의 특성상 인위적으로 타이머 이벤트를 발생시킴. moveheadL 함수를 25ms 후에 실행
	}
	if (entryID == 2) {
		StopTrig = false;
		glutTimerFunc(25, armLup, 1);
	}
	if (entryID == 3) {
		StopTrig = false;
		glutTimerFunc(25, armRup, 1);
	}
	if (entryID == 4) {
		StopTrig = false;
		glutTimerFunc(25, legLup, 1);
	}
	if (entryID == 5) {
		StopTrig = false;
		glutTimerFunc(25, legRup, 1);
	}
	if (entryID == 6) exit(0);
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// 윈도우의 색상을 초기화
	glShadeModel(GL_FLAT);

	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // 주변광의 세기
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 반사광의 세기
	GLfloat mat_shininess[] = { 50.0 }; // 선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // 광원의 위치
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);	// 조명 모델에 대한 재질 매개 변수를 지정
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// 광원 매개 변수 값을 반환
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);	// 조명 모델 매개 변수를 설정

	glEnable(GL_LIGHTING);	// 조명모드를 활성화
	glEnable(GL_LIGHT0);	// 0번 조명을 활성화
	glEnable(GL_DEPTH_TEST);	// 깊이 버퍼를 활성화

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);	// 메뉴 콜백함수 등록
	glutAddMenuEntry("Move head", 1);	// pop-up 메뉴에 항목 'Move head' 추가
	glutAddMenuEntry("Move left arm", 2);
	glutAddMenuEntry("Move right arm", 3);
	glutAddMenuEntry("Move left leg", 4);
	glutAddMenuEntry("Move right leg", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	// 지정한 마우스 버튼에 현재 설정 메뉴 할당, 버튼을 누르면 메뉴 팝업
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 컬러 버퍼와 깊이 버퍼를 초기화

	glMatrixMode(GL_MODELVIEW);	// 모델뷰행렬 연산 조작 선택
	glLoadIdentity();	// 현재 행렬을 항등행렬을 사용해 초기화

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	gluQuadricDrawStyle(qobj, GLU_LINE);	// Quadric의 Draw Style을 LINE으로 설정
	gluQuadricNormals(qobj, GLU_SMOOTH);	// 객체의 모서리를 부드럽게 보이도록 법선벡터 생성
	gluQuadricOrientation(qobj, GLU_OUTSIDE);	// 바깥쪽을 가리키는 벡터를 가진 Quadric 그리기
	gluQuadricTexture(qobj, GL_FALSE);	// Texture 좌표 미생성

	glViewport(0, 0, 500, 500);	// 투영변환 함수를 호출
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.1, -0.1, 0.0, 1.0, 0.0);	// 카메라를 (0, 1, 0)에 위치, (0, 0.1, -0.1)을 바라보게, y축으로 1만큼 기울이게 설정
	
	glPushMatrix();	// 몸통
		glTranslatef(0.0, 0.0, -1.0);	// 물체를 (0, 0, -1) 만큼 이동
		gluCylinder(qobj, 1.5, 1.5, 4.0, 30, 1); // 반지름이 1.5, 높이가 4, Z축 중심으로 회전하는 Subdivision이 30, Z축을 따르는 Subdivision이 1인 실린더
	glPopMatrix();

	glPushMatrix();	// 목
		glTranslatef(0.0, 0.0, -1.9);
		gluCylinder(qobj, 0.5, 0.5, 1.0, 30, 1);
	glPopMatrix();

	glPushMatrix();	// 머리
		glTranslatef(0.0, 0.0, -2.0);
		glRotatef(head, 0.0, 0.0, -1.0);	// (0, 0, -1)를 기준으로 head만큼 회전
		glTranslatef(0.0, 0.0, -2.0);
		gluCylinder(qobj, 1.0, 1.5, 2.0, 30, 1);

		glPushMatrix();	// 오른쪽 눈
			glTranslatef(-0.5, 1.15, 0.8);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			gluQuadricDrawStyle(qobj, GLU_FILL);	// Quadric의 Draw Style을 FILL으로 설정
			gluDisk(qobj, 0.0, 0.15, 20, 3); // 디스크의 바깥쪽 반지름이 0.15, Z축 중심 Subdivision이 20, 세분화 되는 동심원이 3인 디스크
		glPopMatrix();

		glPushMatrix();	// 왼쪽 눈
			glTranslatef(0.5, 1.15, 0.8);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			gluQuadricDrawStyle(qobj, GLU_FILL);
			gluDisk(qobj, 0.0, 0.15, 20, 3);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glPushMatrix();	// 왼쪽 팔뚝
			gluQuadricDrawStyle(qobj, GLU_LINE);
			glTranslatef(1.0, 0.0, -0.15);
			glRotatef(shoulderL , 0.0, 5.0, 0.0);
			glTranslatef(1.0, 0.0, -0.15);
			gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);
		glPopMatrix();

		glPushMatrix();	// 왼쪽 팔
			glTranslatef(1.325, 0.0, 0.1);
			glRotatef(armL, 0.0, -5.0, 0.0);
			glTranslatef(1.325, 0.0, 0.1);
			gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);
		
			// 왼쪽 손
			glTranslatef(0.0, 0.0, 1.8);
			gluSphere(qobj, 0.5, 10, 10);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glPushMatrix();	// 오른쪽 팔뚝
			glTranslatef(-1.0, 0.0, -0.15);
			glRotatef(shoulderR, 0.0, -5.0, 0.0);
			glTranslatef(-1.0, 0.0, -0.15);
			gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);
		glPopMatrix();

		glPushMatrix();	// 오른쪽 팔
			glTranslatef(-1.325, 0.0, 0.1);
			glRotatef(armR, 0.0, 5.0, 0.0);
			glTranslatef(-1.325, 0.0, 0.1);
			gluCylinder(qobj, 0.5, 0.5, 1.5, 30, 1);

			// 오른쪽 손
			glTranslatef(0.0, 0.0, 1.8);
			gluSphere(qobj, 0.5, 10, 10);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		// 왼쪽 허벅지
		glTranslatef(0.35, 0.0, 1.5);
		glRotatef(legL, 0.0, 5.0, 0.0);
		glTranslatef(0.35, 0.0, 1.5);
		gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

		// 왼쪽 종아리
		glTranslatef(0.0, 0.0, 2.0);
		gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

		// 왼쪽 발
		glTranslatef(0.2, 0.0, 2.0);
		gluCylinder(qobj, 0.8, 0.8, 0.5, 30, 1);
	glPopMatrix();


	glPushMatrix();	
		// 오른쪽 허벅지
		glTranslatef(-0.35, 0.0, 1.5);
		glRotatef(legR, 0.0, -5.0, 0.0);
		glTranslatef(-0.35, 0.0, 1.5);
		gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

		// 오른쪽 종아리
		glTranslatef(0.0, 0.0, 1.0);
		glRotatef(kneeR, 0.0, -5.0, 0.0);
		glTranslatef(0.0, 0.0, 1.0);
		gluCylinder(qobj, 0.6, 0.6, 2.0, 30, 1);

		// 오른쪽 발
		glTranslatef(-0.2, 0.0, 2.0);
		gluCylinder(qobj, 0.8, 0.8, 0.5, 30, 1);
	glPopMatrix();

	glutSwapBuffers();	// 프레임버퍼를 교환
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	GLfloat wf = (GLfloat)w / (GLfloat)500;
	GLfloat hf = (GLfloat)h / (GLfloat)500;

	glMatrixMode(GL_PROJECTION);	// 투영행렬 연산 조작 선택
	glLoadIdentity();

	glOrtho(-10.0 * wf, 10.0 * hf, -10.0 * hf, 10.0 * wf, -10.0, 10.0);	// 변경된 비와 기존의 직교투영과 곱하여 비율 유지

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void moveheadL(int Value) {
	head += 1;	// 머리 각도 증가
	glutPostRedisplay();	// 강제로 디스플레이 이벤트를 발생

	if (!StopTrig) {
		if (head < 45)
			glutTimerFunc(25, moveheadL, 1);
		else
			glutTimerFunc(25, moveheadR, 1);
	}
}

void moveheadR(int Value) {
	head -= 1;	// 머리 각도 감소
	glutPostRedisplay();

	if (!StopTrig)
		if (head != 0)
			glutTimerFunc(25, moveheadR, 1);

	if(head == 0)
		StopTrig = true;
}

void armLup(int Value) {
	shoulderL += 1; armL -= 1.0;	// 왼쪽 어깨 각도 증가, 팔꿈치 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderL < 90)
			glutTimerFunc(25, armLup, 1);
		else
			glutTimerFunc(25, armLdown, 1);
	}
}

void armLdown(int Value) {
	shoulderL -= 1; armL += 1.0;	// 왼쪽 어깨 각도 감소, 팔꿈치 각도 증가
	glutPostRedisplay();

	if (!StopTrig)
		if (shoulderL != 20)
			glutTimerFunc(25, armLdown, 1);

	if (shoulderL == 20)
		StopTrig = true;
}

void armRup(int Value) {
	shoulderR += 1; armR -= 1.0;	// 오른쪽 어깨 각도 증가, 팔꿈치 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (shoulderR < 90)
			glutTimerFunc(25, armRup, 1);
		else
			glutTimerFunc(25, armRdown, 1);
	}
}

void armRdown(int Value) {
	shoulderR -= 1; armR += 1.0;	// 오른쪽 어깨 각도 감소, 팔꿈치 각도 증가
	glutPostRedisplay();

	if (!StopTrig)
		if (shoulderR != 20 )
			glutTimerFunc(25, armRdown, 1);

	if (shoulderR == 20)
		StopTrig = true;
}

void legLup(int Value) {
	legL += 1;	// 왼다리 각도 증가
	glutPostRedisplay();

	if (!StopTrig) {
		if (legL < 30)
			glutTimerFunc(25, legLup, 1);
		else
			glutTimerFunc(25, legLdown, 1);
	}
}

void legLdown(int Value) {
	legL -= 1;	// 오른다리 각도 증가
	glutPostRedisplay();

	if (!StopTrig)
		if (legL != 0)
			glutTimerFunc(25, legLdown, 1);

	if (legL == 0)
		StopTrig = true;
}

void legRup(int Value) {
	legR += 1; kneeR -= 1;	// 오른다리 각도 증가, 무릎 각도 감소
	glutPostRedisplay();

	if (!StopTrig) {
		if (legR < 30)
			glutTimerFunc(25, legRup, 1);
		else
			glutTimerFunc(25, legRdown, 1);
	}
}

void legRdown(int Value) {
	legR -= 1; kneeR += 1;	// 오른다리 각도 감소, 무릎 각도 증가
	glutPostRedisplay();

	if (!StopTrig)
		if (legR != 0)
			glutTimerFunc(25, legRdown, 1);

	if (legR == 0)
		StopTrig = true;
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'S':	// 키보드의 S 키를 누르면 정지
	case 's':
		StopTrig = true;
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// 디스플레이 모드를 설정. DOUBLE은 더블버퍼, RGB는 GLUT_RGBA버퍼 사용
	glutInitWindowSize(500, 500);	// 윈도우의 기본 크기 지정
	glutInitWindowPosition(100, 100);	// 윈도우의 기본 위치 좌표 설정
	glutCreateWindow("Can Robot");	// 윈도우의 타이틀 설정
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	MyInit();
	glutDisplayFunc(MyDisplay);	// 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(MyReshape);	// 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutKeyboardFunc(MyKeyboard);	// 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutMainLoop();	// GLUT 이벤트 처리 루프 입력
	return 0;
}
*/