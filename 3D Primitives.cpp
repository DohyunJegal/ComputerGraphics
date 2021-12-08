/***********************************************************************/
/*                      HW#2 : 3D Primitives                           */
/*  작성자 : 제갈도현                        날짜 : 2021년 9월 24일    */
/*                                                                     */
/*  문제 정의 :   다양한 3D Primitive들을 구현                         */
/*                                                                     */
/*  기능 :        가상의 공간을 구성하는 각 물체를 표현하는 기본 요소  */
/*				  3D 공간에서 기하학적 3D 객체를 생성				   */
/***********************************************************************/

/*
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

GLuint listA, listB, listC, listD; // 여러 개의 디스플레이 리스트를 생성, 정수 ID에 의해 식별됨
GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric을 생성

void MyCreateList(){
	listA = glGenLists(4); // 사용되지 않은 아이디 4개를 반환하여 생성한 값을 디스플레이 리스트에 할당
	listB = listA + 1;
	listC = listB + 1;
	listD = listC + 1;

	glNewList(listA, GL_COMPILE); // 디스플레이 리스트를 생성, 실행하지 않고 컴파일 완료된 버전을 생성한다.
	gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric의 Draw Style을 Solid형태로 모델링
	gluSphere(qobj, 1.0, 50, 50); // 반지름이 1, Z축 중심 Subdivision이 50, Z축을 따르는 Subdivision이 50인 구
	glTranslatef(-2, -2, 2); // 좌표 평행이동
	glEndList();

	glNewList(listB, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric의 Draw Style을 Wire-frame 형태로 모델링
	gluCylinder(qobj, 1.0, 1.0, 2.0, 8, 8); // z=0의 실린더와 z=높이인 실린더의 반지름이 1, 높이가 2, Z축 중심으로 회전하는 Subdivision이 8, Z축을 따르는 Subdivision이 8인 실린더
	glTranslatef(2, 2, 0);
	glEndList();

	glNewList(listC, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_SILHOUETTE); // Quadric의 Draw Style을 외부 모서리만 모델링
	gluDisk(qobj, 0.25, 1, 20, 3); // 디스크의 안쪽 반지름이 0.25, 바깥쪽 반지름이 1, Z축 중심 Subdivision이 50, 세분화 되는 동심원이 3인 디스크
	glTranslatef(-2, 2, 0);
	glEndList();

	glNewList(listD, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_POINT); // Quadric의 Draw Style을 점만으로 표현하여 모델링
	gluPartialDisk(qobj, 0.5, 1.0, 26, 13, 0, 180); // 부분디스크의 안쪽 반지름이 0.5, 바깥쪽 반지름이 1, Z축 주변 Subdivision이 26, 세분화 되는 동심원이 13, 디스크 부분의 각도가 0, 디스크 생성되는 각도가 180인 부분디스크
	glTranslatef(2, -2, 0);
	glEndList();
}

void MyInit(void){
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; // 주변광의 세기
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 반사광의 세기
	GLfloat mat_shininess[] = { 50.0 }; // 선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // 광원의 위치
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); // 조명 모델에 대한 재질 매개 변수를 지정
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // 광원 매개 변수 값을 반환
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient); // 조명 모델 매개 변수를 설정

	glEnable(GL_LIGHTING); // 조명모드를 활성화
	glEnable(GL_LIGHT0); // 0번 조명을 활성화
	glEnable(GL_DEPTH_TEST); // 깊이 버퍼를 활성화
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 컬러 버퍼와 깊이 버퍼를 초기화

	glMatrixMode(GL_MODELVIEW); // 모델뷰행렬 연산 조작 선택
	glLoadIdentity(); // 현재 행렬을 항등행렬을 사용해 초기화

	glViewport(0, 0, 500, 500); // 투영변환 함수를 호출
	gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 1.0, 0.0); // 카메라를 (0, 1, -1) 좌표 방향으로, y축으로 1만큼 기울이게 설정

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH); // 색상 배열 사용

	gluQuadricNormals(qobj, GLU_SMOOTH); // 객체의 모서리를 부드럽게 보이도록 법선벡터 생성
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 바깥쪽을 가리키는 벡터를 가진 Quadric 그리기
	gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 미생성

	glCallList(listA); // 디스플레이 리스트를 호출
	glCallList(listB);
	glCallList(listC);
	glCallList(listD);

	glutSwapBuffers(); // 프레임버퍼를 교환
}

void Reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // 투영변환 함수를 호출

	glMatrixMode(GL_PROJECTION); // 투영행렬 연산 조작 선택
	glLoadIdentity();

	glOrtho(-5.0, 5.0, -5.0*((GLfloat)height/(GLfloat)width), 5.0*((GLfloat)height/(GLfloat)height), -5.0, 5.0);; // 변경된 비와 기존의 직교투영과 곱하여 비율 유지

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv){
	glutInit(&argc, argv); // 윈도우 OS와 세션 연결 후 GLUT 라이브러리 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // 디스플레이 모드를 설정. DOUBLE은 더블버퍼, RGB는 GLUT_RGBA, DEPTH는 깊이버퍼 사용
	glutInitWindowSize(500, 500); // 기본 윈도우의 크기 지정
	glutInitWindowPosition(0, 0); // 윈도우의 위치 좌표 설정
	glutCreateWindow("3D Primitives"); // 윈도우의 타이틀 설정

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // 직교투영을 변환

	MyInit();
	glutDisplayFunc(MyDisplay); // 디스플레이 콜백함수 등록. 디스플레이 이벤트 발생시 호출
	glutReshapeFunc(Reshape); // 리셰이프 콜백함수 등록. 윈도우의 크기를 변환시 자동호출
	MyCreateList();

	glutMainLoop(); // GLUT 이벤트 처리 루프 입력
}
*/