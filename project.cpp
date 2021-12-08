/***********************************************************************/
/*                             HW#8. 종합                              */
/*  작성자 : 제갈도현                        날짜 : 2021년 12월  8일   */
/*                                                                     */
/*  문제 정의 :   지금까지 수행한 실습과제의 내용을 종합하여           */
/*                객체를 모델링하고, 콜백프로그래밍, 모델변환,         */
/*                시점변환, 투영변환, 뷰폿변환, 가시성검사, 조명,      */
/*				  텍스춰 등 수업시간에 배웠던 기술이 모두 쓰일 수      */
/*				  있도록 프로그램을 만들어보시오.                      */
/*                                                                     */
/*  기능 :        퐁 게임                                              */
/*                R - 초기화          G - 게임시작                     */
/*                A - 좌측막대 위로   Z - 좌측막대 아래로              */
/*               ↑ - 우측막대 위로  ↓ - 우측막대 아래로              */
/***********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <GL/glaux.h>
#include <GL/glut.h>
#include <ctime>
using namespace std;

GLUquadricObj *qobj = gluNewQuadric();	// 새로운 Quadric을 생성
static double cx = 0.0, cy = 0.0, cz = 0.0, rx = 0.0, ry = 0.0, rz = 0.0;	// 카메라의 위치를 변경할 변수
static double ballx = 0.0, bally = 0.0, ballz = 0.0;	// 공의 위치를 변경할 변수
static double stickLz = 0.0, stickRz = 0.0;	// 좌, 우측 막대의 위치를 변경할 변수
static bool stickLUpStop = true, stickLDnStop = true, stickRUpStop = true, stickRDnStop = true, ballStop = true;	// 움직일 수 있는 물체들의 정지용 부울 변수
static int temp, ranNumA;	// 무작위 값을 담을 변수
static double deltaX;

void moveStickLUp(int); void moveStickLDn(int); void moveStickRUp(int); void moveStickRDn(int);
void moveBallUpL(int); void moveBallDnL(int); void moveBallUpR(int); void moveBallDnR(int);

char Filename[] = "brick.bmp";	// 텍스쳐 매핑에 사용될 파일의 이름
AUX_RGBImageRec *LoadBMP(char *Filename) {
	FILE * File = NULL;
	if (!Filename) return NULL;
	fopen_s(&File, Filename, "r");

	// seFilename을 유니코드 스트링으로 바꾸기
	int size = strlen(Filename);
	wchar_t* w_Filename = new wchar_t[size];

	for (int i = 0; i <size; ++i)  w_Filename[i] = Filename[i];
	w_Filename[size] = NULL;

	if (File) {
		fclose(File);
		return auxDIBImageLoad(w_Filename);     //파일로부터 메모리로
	}
	return NULL;
}

int LoadGLTextures() {
	int Status = FALSE;
	AUX_RGBImageRec *TextureImage[1];
	memset(TextureImage, 0, sizeof(void *) * 1);

	if (TextureImage[0] = LoadBMP(Filename)) {
		Status = TRUE;

		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);	// GLU 밉맵 생성

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// 텍스쳐 파라미터
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);	// 자동 텍스쳐 매핑
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);	// 객체의 MCS를 기반으로 텍스쳐 좌표 생성
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
	}

	if (TextureImage[0]) {
		if (TextureImage[0]->data) {
			free(TextureImage[0]->data);
		}

		free(TextureImage[0]);
	}

	return Status;
}

void MyInit(void) {
	LoadGLTextures();	// 텍스쳐 로드

	glClearColor(0.0, 0.0, 0.0, 1.0);	// 윈도우의 색상을 초기화
	glShadeModel(GL_SMOOTH);

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
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// 원근에 따른 텍스춰 보정을 위한 함수
	glEnable(GL_TEXTURE_2D);	// 텍스쳐 기능 활성화
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 컬러 버퍼와 깊이 버퍼를 초기화

	glMatrixMode(GL_MODELVIEW);	// 모델뷰행렬 연산 조작 선택
	glLoadIdentity();	// 현재 행렬을 항등행렬을 사용해 초기화

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);

	gluQuadricDrawStyle(qobj, GLU_FILL);	// Quadric의 Draw Style을 FILL로 설정
	gluQuadricNormals(qobj, GLU_SMOOTH);	// 객체의 모서리를 부드럽게 보이도록 법선벡터 생성
	gluQuadricOrientation(qobj, GLU_OUTSIDE);	// 바깥쪽을 가리키는 벡터를 가진 Quadric 그리기
	gluQuadricTexture(qobj, GL_FALSE);	// Texture 좌표 미생성

	glViewport(0, 0, 500, 500);	// 투영변환 함수를 호출
	gluLookAt(0.0 + cx, 1.0 + cy, 0.0 + cz, 0.0, 0.1, -0.1, 0.0 + rx, 1.0 + ry, 0.0 + rz);	// 카메라를 (0, 1, 0)에 위치, (0, 0.1, -0.1)을 바라보게, y축으로 1만큼 기울이게 설정

	glPushMatrix();	// 공
		glTranslatef(ballx, bally, ballz);
		gluSphere(qobj, 0.5, 10, 10);
	glPopMatrix();

	glPushMatrix();	// 상단바
		glTranslatef(0.0, 0.0, -9.0);
		glRotatef(45, 1.0, 0.0, 0.0);
		glScalef(18.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// 하단바
		glTranslatef(0.0, 0.0, 9.0);
		glRotatef(45, 1.0, 0.0, 0.0);
		glScalef(18.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// 좌측 막대
		glTranslatef(-9.0, 0.0, stickLz);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(30, 1.0, 0.0, 0.0);
		glScalef(6.0, 0.2, 0.2);
		glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();	// 우측 막대
		glTranslatef(9.0, 0.0, stickRz);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef(30, 1.0, 0.0, 0.0);
		glScalef(6.0, 0.2, 0.2);
		glutWireCube(1.0);
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

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A':	// 'A', 'a' 입력 시 좌측 막대를 위로 움직임
	case 'a':
		stickLUpStop = false; stickLDnStop = true;
		glutTimerFunc(20, moveStickLUp, 1);	// 타이머 이벤트의 특성상 인위적으로 타이머 이벤트를 발생시킴. moveStickLUp 함수를 20ms 후에 실행
		break;
	case 'Z':	// 'Z', 'z' 입력 시 좌측 막대를 아래로 움직임
	case 'z':
		stickLUpStop = true; stickLDnStop = false;
		glutTimerFunc(20, moveStickLDn, 1);
		break;
	case 'G':	// 'G', 'g' 입력 시 게임 시작
	case 'g':
		ballStop = false;

		srand((unsigned int)time(NULL));
		ranNumA = rand(); temp = rand(); deltaX = ((temp % 7) + 10);	// ranNumA, temp에 랜덤 수를 입력, deltaX에 랜덤 수를 변환하여 입력
		switch (ranNumA % 4) {	// 무작위로 공의 방향을 지정
			case 0:
				glutTimerFunc(20, moveBallUpL, 1);
				break;
			case 1:
				glutTimerFunc(20, moveBallDnL, 1);
				break;
			case 2:
				glutTimerFunc(20, moveBallUpR, 1);
				break;
			case 3:
				glutTimerFunc(20, moveBallDnR, 1);
				break;
		}
		break;
	case 'R':	// 'R', 'r' 입력 시 모든 요소 초기화
	case 'r':
		cx = 0.0; cz = 0.0;
		ballx = 0, bally = 0, ballz = 0;
		stickLz = 0, stickRz = 0;
		stickLUpStop = true, stickLDnStop = true, stickRUpStop = true, stickRDnStop = true, ballStop = true;
		glutPostRedisplay(); 	// 강제로 디스플레이 이벤트를 발생
		break;
	}
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:	// ↑ 입력시 우측 막대를 위로 움직임
		stickRUpStop = false; stickRDnStop = true;
		glutTimerFunc(20, moveStickRUp, 1);
		break;
	case GLUT_KEY_DOWN:	// ↓ 입력시 우측 막대를 아래로 움직임
		stickRUpStop = true; stickRDnStop = false;
		glutTimerFunc(20, moveStickRDn, 1);
		break;
	}
}

void moveStickLUp(int value) {
	if (!stickLUpStop && stickLz > -5.5) {	// 좌측 막대가 상단까지 도달하지 않은 경우
		stickLz -= 0.1;	// 막대를 이동시킴
		glutPostRedisplay();
		glutTimerFunc(20, moveStickLUp, 1);
	}	
}
void moveStickLDn(int value) {
	if (!stickLDnStop && stickLz < 5.5) {	// 좌측 막대가 하단까지 도달하지 않은 경우
		stickLz += 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickLDn, 1);
	}
}
void moveStickRUp(int value) {	// 우측 막대가 상단까지 도달하지 않은 경우
	if (!stickRUpStop && stickRz > -5.5) {
		stickRz -= 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickRUp, 1);
	}
}
void moveStickRDn(int value) {	// 우측 막대가 하단까지 도달하지 않은 경우
	if (!stickRDnStop && stickRz < 5.5) {
		stickRz += 0.1;
		glutPostRedisplay();
		glutTimerFunc(20, moveStickRDn, 1);
	}
}

void moveBallUpL(int value) {	// 공이 좌측 상단으로 이동
	if (!ballStop) {
		ballx = ballx - (0.016 * deltaX);	// 앞에서 설정한 deltaX x 0.016한 값 만큼 공의 x 좌표 이동
		ballz = ballz - (0.016 * (17 - deltaX));	// (17 - deltaX) x 0.016한 값 만큼 공의 y 좌표 이동
		cx -= 0.00005; cz -= 0.00005;	// 공의 이동에 따라 카메라의 초점 이동
		glutPostRedisplay();

		if (ballx < -8.7 || ballz < -8.7)	// 공이 필드를 벗어나는 경우 정지
			ballStop = true;
		else if (ballz < -8.2)	// 상단바에 맞는 경우 방향을 변경
			glutTimerFunc(20, moveBallDnL, 1);
		else if (ballx < -8.2) {	// 막대와 근접했을 때
			if (ballz <= stickLz && ballz >= stickLz - 3.0)	// 막대의 상단에 맞는 경우 우측 상단으로 튕겨냄
				glutTimerFunc(20, moveBallUpR, 1);
			else if (ballz <= stickLz + 3.0 && ballz > stickLz)	// 막대의 상단에 맞는 경우 우측 하단으로 튕겨냄
				glutTimerFunc(20, moveBallDnR, 1);
			else	// 막대를 안맞는 경우 통과
				glutTimerFunc(20, moveBallUpL, 1);	
		} 
		else
			glutTimerFunc(20, moveBallUpL, 1);
	}
}

void moveBallDnL(int value) {	// 공이 좌측 하단으로 이동
	if (!ballStop) {
		ballx = ballx - (0.016 * deltaX);
		ballz = ballz + (0.016 * (17 - deltaX));
		cx -= 0.00005; cz += 0.00005;
		glutPostRedisplay();

		if (ballx < -8.7 || ballz > 8.7)	
			ballStop = true;
		else if (ballz > 8.2)	// 하단바에 맞는 경우 방향을 변경
			glutTimerFunc(20, moveBallUpL, 1);
		else if (ballx < -8.2) {	// 막대와 근접했을 때
			if (ballz <= stickLz && ballz >= stickLz - 3.0)	// 막대의 상단에 맞는 경우 우측 상단으로 튕겨냄
				glutTimerFunc(20, moveBallUpR, 1);
			else if (ballz <= stickLz + 3.0 && ballz > stickLz)	// 막대의 상단에 맞는 경우 우측 하단으로 튕겨냄
				glutTimerFunc(20, moveBallDnR, 1);
			else	// 막대를 안맞는 경우 통과
				glutTimerFunc(20, moveBallDnL, 1);
		}
		else
			glutTimerFunc(20, moveBallDnL, 1);
	}
}

void moveBallUpR(int value) {	// 공이 우측 상단으로 이동
	if (!ballStop) {
		ballx = ballx + (0.016 * deltaX);
		ballz = ballz - (0.016 * (17 - deltaX));
		cx += 0.00005; cz -= 0.00005;
		glutPostRedisplay();

		if (ballx > 8.7 || ballz < -8.7)
			ballStop = true;
		else if (ballz < -8.2) 	// 상단바에 맞는 경우 방향을 변경
			glutTimerFunc(20, moveBallDnR, 1);
		else if (ballx > 8.2) {	// 막대와 근접했을 때
			if (ballz <= stickRz && ballz >= stickRz - 3.0)	// 막대의 상단에 맞는 경우 좌측 상단으로 튕겨냄
				glutTimerFunc(20, moveBallUpL, 1);
			else if (ballz <= stickRz + 3.0 && ballz > stickRz)	// 막대의 상단에 맞는 경우 좌측 하단으로 튕겨냄
				glutTimerFunc(20, moveBallDnL, 1);
			else	// 막대를 안맞는 경우 통과
				glutTimerFunc(20, moveBallUpR, 1);
		}
		else
			glutTimerFunc(20, moveBallUpR, 1);
	}
}

void moveBallDnR(int value) {	// 공이 우측 하단으로 이동
	if (!ballStop) {
		ballx = ballx + (0.016 * deltaX);
		ballz = ballz + (0.016 * (17 - deltaX));
		cx += 0.00005; cz += 0.00005;
		glutPostRedisplay();

		if (ballx > 8.7 || ballz > 8.7)
			ballStop = true;
		else if (ballz > 8.2)	// 하단바에 맞는 경우 방향을 변경
			glutTimerFunc(20, moveBallUpR, 1); 
		else if (ballx > 8.2) {		// 막대와 근접했을 때
			if (ballz <= stickRz && ballz >= stickRz - 3.0)	// 막대의 상단에 맞는 경우 좌측 상단으로 튕겨냄
				glutTimerFunc(20, moveBallUpL, 1);
			else if (ballz <= stickRz + 3.0 && ballz > stickRz)	// 막대의 상단에 맞는 경우 좌측 하단으로 튕겨냄
				glutTimerFunc(20, moveBallDnL, 1);
			else	// 막대를 안맞는 경우 통과
				glutTimerFunc(20, moveBallDnR, 1);
		}
		else
			glutTimerFunc(20, moveBallDnR, 1);
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);	// 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// 디스플레이 모드를 설정. DOUBLE은 더블버퍼, RGB는 GLUT_RGBA버퍼, DEPTH는 깊이버퍼 사용
	glutInitWindowSize(500, 500);	// 윈도우의 기본 크기 지정
	glutInitWindowPosition(100, 100);	// 윈도우의 기본 위치 좌표 설정
	glutCreateWindow("Pong");	// 윈도우의 타이틀 설정
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	MyInit();
	glutDisplayFunc(MyDisplay);	// 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(MyReshape);	// 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	glutKeyboardFunc(MyKeyboard);	// 키보드 콜백함수 등록. 키보드 이벤트 발생시 호출
	glutSpecialFunc(MySpecial);	// 스페셜 키보드 콜백함수 등록. 특정 키 이벤트 발생시 호출
	glutMainLoop();	// GLUT 이벤트 처리 루프 입력
	return 0;
}