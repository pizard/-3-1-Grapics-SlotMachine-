
#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>	
#include <math.h>
#include "header/MATRIX.h"
#include "header/VECTOR.h"
#include "header/VERTEX.h"
#include "header/FACE.h"
#include "header/Mesh.h"
// #include "./Template.h"


using namespace std;

// 1���� �����ּ���!!!!!
	int counter = 100;

	GLfloat vertices_a[][3] = {
		{ 0, 3, 0},
		{ 0, 3, 4},
		{ 4, 3, 4},
		{ 4, 3, 0}};
  
	GLfloat vertices_b[][3] = {
		{ 0, 15, 0 },
		{ 0, 15, 4 },
		{ 4, 15, 4 },
		{ 4, 15, 0 } };
	GLfloat vertices_c[][3] = {
		{ -1, 15, -1 },
		{ -1, 15, 4 },
		{ 5, 15, 5 },
		{ 5, 15, -1 } };

	GLfloat vertices_d[][3] = {
		{ -1, 21, -1 },
		{ -1, 21, 5 },
		{ 5, 21, 5 },
		{ 5, 21, -1}};

	VERTEX  v0 = VERTEX( 0.0f, 0.0f, 0.0f);		// �ʱ�ȭ VERTEX
	VERTEX v_x = VERTEX(1000.0f, 0.0f, 0.0f);		// �ʱ�ȭ VERTEX
	VERTEX v_y = VERTEX(0.0f, 1000.0f, 0.0f);		// �ʱ�ȭ VERTEX
    VERTEX v_z = VERTEX(0.0f, 0.0f, 1000.0f);		// �ʱ�ȭ VERTEX

  VERTEX a1 = VERTEX(0,3,0);
  VERTEX a2 = VERTEX(0,3,4);
  VERTEX a3 = VERTEX(4,3,4);
  VERTEX a4 = VERTEX(4,3,0);
  
  VERTEX b1 = VERTEX(0, 15, 0);
  VERTEX b2 = VERTEX(0, 15, 4);
  VERTEX b3 = VERTEX(4, 15, 4);
  VERTEX b4 = VERTEX(4, 15, 0);

  VERTEX c1 = VERTEX(-1, 15, -1);
  VERTEX c2 = VERTEX(-1, 15, 5);
  VERTEX c3 = VERTEX(5, 15, 5);
  VERTEX c4 = VERTEX(5, 15, -1);

  VERTEX d1 = VERTEX(-1, 21, -1);
  VERTEX d2 = VERTEX(-1, 21, 5);
  VERTEX d3 = VERTEX(5, 21, 5);
  VERTEX d4 = VERTEX(5, 21, -1);
  
  FACE r1 = FACE(a1, a2, a3, a4);
  
  FACE r2 = FACE(b1, a1, a2, b2);
  FACE r3 = FACE(b2, a2, a3, b3);
  FACE r4 = FACE(b3, a3, a4, b4);
  FACE r5 = FACE(b4, a4, a1, b1);
  
  FACE r6 = FACE(c1, c2, c3, c4);
 
  FACE r7 = FACE(d1, c1, c2, d2);
  FACE r8 = FACE(d2, c2, c3, d3);
  FACE r9 = FACE(d3, c3, c4, d4);
  FACE r10 = FACE(d4, c4, c1, d1);

  FACE r11 = FACE(d1, d2, d3, d4);
  
  
 Mesh a;
 MATRIX m;
 

 void MyTimer(int value) {
	 MATRIX m_xyz;
	 m_xyz = m.Transpose(0.15, r1.R_pos , r1.R_pos2);
	 a1 = m.Trans(m_xyz, a1);
	 a2 = m.Trans(m_xyz, a2);
	 a3 = m.Trans(m_xyz, a3);
	 a4 = m.Trans(m_xyz, a4);
	 b1 = m.Trans(m_xyz, b1);
	 b2 = m.Trans(m_xyz, b2);
	 b3 = m.Trans(m_xyz, b3);
	 b4 = m.Trans(m_xyz, b4);
	 c1 = m.Trans(m_xyz, c1);
	 c2 = m.Trans(m_xyz, c2);
	 c3 = m.Trans(m_xyz, c3);
	 c4 = m.Trans(m_xyz, c4);
	 d1 = m.Trans(m_xyz, d1);
	 d2 = m.Trans(m_xyz, d2);
	 d3 = m.Trans(m_xyz, d3);
	 d4 = m.Trans(m_xyz, d4);
	 glutPostRedisplay();
 }

 void MyTimer2(int value) {
	 MATRIX m_xyz;
	 m_xyz = m.Transpose(-0.045, r1.R_pos, r1.R_pos2);
	 a1 = m.Trans(m_xyz, a1);
	 a2 = m.Trans(m_xyz, a2);
	 a3 = m.Trans(m_xyz, a3);
	 a4 = m.Trans(m_xyz, a4);
	 b1 = m.Trans(m_xyz, b1);
	 b2 = m.Trans(m_xyz, b2);
	 b3 = m.Trans(m_xyz, b3);
	 b4 = m.Trans(m_xyz, b4);
	 c1 = m.Trans(m_xyz, c1);
	 c2 = m.Trans(m_xyz, c2);
	 c3 = m.Trans(m_xyz, c3);
	 c4 = m.Trans(m_xyz, c4);
	 d1 = m.Trans(m_xyz, d1);
	 d2 = m.Trans(m_xyz, d2);
	 d3 = m.Trans(m_xyz, d3);
	 d4 = m.Trans(m_xyz, d4);
	 glutPostRedisplay();
 }
 void DoTimer(int value)
 {

	 int counter1 = 0;
	 int counter2 = 0;
	 for (counter1; counter1 < 600; counter1++) {
		 glutTimerFunc(counter1, MyTimer, 1);       // 30�и��ʸ��� ȣ��
		 glutPostRedisplay();
	 }
	 for (counter2; counter2 < 2000; counter2++) {
		 glutTimerFunc(counter2+1000, MyTimer2, 1);       // 30�и��ʸ��� ȣ��
		 glutPostRedisplay();

	 }

 }

 
void Render(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear the color buffer
	glLoadIdentity();								  // clear the current matrix
	gluLookAt ( 0.0f, 0.0f, 50.0f,				   	  // current camera location (0, 0 , 20)
				0.0f, 0.0f, 0.0f,					  // camera looks (0, 0, 0)
				0.0f, 3.0f, 0.0f);					  // camera's up direction is (0, 3, 0) equal to y axis
	// ���������� �̵��� ȸ���� ���� ����� ����
	// glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // �������!!... ��ߵ��ٵ�...
	glEnable(GL_DEPTH_TEST);
	

	r1.normalization(a3, a2, a1); // r1�� ����ü�� �߾ӹ������� normalization
	r1.position();
	r1.R_position();
	r1.R_position2();


	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a1.x, a1.y, a1.z);
	glVertex3f(a2.x, a2.y, a2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a2.x, a2.y, a2.z);
	glVertex3f(a3.x, a3.y, a3.z);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a3.x, a3.y, a3.z);
	glVertex3f(a4.x, a4.y, a4.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a4.x, a4.y, a4.z);
	glVertex3f(a1.x, a1.y, a1.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a1.x, a1.y, a1.z);
	glVertex3f(b1.x, b1.y, b1.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a2.x, a2.y, a2.z);
	glVertex3f(b2.x, b2.y, b2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a3.x, a3.y, a3.z);
	glVertex3f(b3.x, b3.y, b3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(a4.x, a4.y, a4.z);
	glVertex3f(b4.x, b4.y, b4.z);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d1.x, d1.y, d1.z);
	glVertex3f(d2.x, d2.y, d2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d2.x, d2.y, d2.z);
	glVertex3f(d3.x, d3.y, d3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d3.x, d3.y, d3.z);
	glVertex3f(d4.x, d4.y, d4.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d4.x, d4.y, d4.z);
	glVertex3f(d1.x, d1.y, d1.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d1.x, d1.y, d1.z);
	glVertex3f(c1.x, c1.y, c1.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d2.x, d2.y, d2.z);
	glVertex3f(c2.x, c2.y, c2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d3.x, d3.y, d3.z);
	glVertex3f(c3.x, c3.y, c3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(d4.x, d4.y, d4.z);
	glVertex3f(c4.x, c4.y, c4.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(c1.x, c1.y, c1.z);
	glVertex3f(c2.x, c2.y, c2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(c2.x, c2.y, c2.z);
	glVertex3f(c3.x, c3.y, c3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(c3.x, c3.y, c3.z);
	glVertex3f(c4.x, c4.y, c4.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(c4.x, c4.y, c4.z);
	glVertex3f(c1.x, c1.y, c1.z);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(v0.x, v0.y, v0.z);
	glVertex3f(v_x.x, v_x.y, v_x.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(v0.x, v0.y, v0.z);
	glVertex3f(v_y.x, v_y.y, v_y.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(v0.x, v0.y, v0.z);
	glVertex3f(v_z.x, v_z.y, v_z.z);
	glEnd();



	glutSwapBuffers();
}




void Reshape(int w, int h) // �����찡 ������ų� �������ų� �ٽ� ��������� �� ���ؿ� ���缭 ȭ���� �ٽ� �׷��ּ���!! �մ� �ʿ� �����!!
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); // ��������� ��ȯ������� �����϶�
	glLoadIdentity(); // �� ��Ŀ� �ϴ� �׵������ �϶�
	gluPerspective(60.0f, w/h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Mouse(int mouse_event, int state, int x, int y) // ��� Ŭ��, ��Ŭ��, ��Ŭ�� 
{
	switch(mouse_event)
	{
		case GLUT_LEFT_BUTTON: 
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;

		default:
			break;		
	}
	glutPostRedisplay();
}


void Motion(int x, int y) // ���콺�� �巡���ϴ� ��� �����ϴ� ���
{	
	glutPostRedisplay();
}





void Keyboard(unsigned char key, int x, int y) // ������ 6���ϱ� cpp�� 6���������ϳ�? ��� point
{
	switch (key)
	{
	case ' ': {
		DoTimer(10);
		glutPostRedisplay();
		break;
	}
	case '1': {
		printf(" r1.R_pos.x: %f   %f   %f \n", r1.R_pos.x, r1.R_pos.y, r1.R_pos.z);
		printf(" r1.R_pos2.x: %f   %f   %f \n", r1.R_pos2.x, r1.R_pos2.y, r1.R_pos2.z);	
		break;
	}	
	case VK_ESCAPE:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void SpecialKey(int key, int x, int y) // f1, f2��ư�� ���� �̺�Ʈ
{
	switch(key) 
	{
		case GLUT_KEY_F1:
			printf("Hellow World \n");
			break;

		case GLUT_KEY_UP:
		{
		
			break;
		}
		case GLUT_KEY_DOWN:
		{
		
			break;
		}
		case GLUT_KEY_RIGHT:
		{

			break;
		}
		case GLUT_KEY_LEFT:
		{

			break;
		}
			
		
	}
	glutPostRedisplay();
}

void Idle(void) //�ƹ��� �Է��� ������ �߻��ϴ� event
{	
	glutPostRedisplay();
}
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0, 0);
	
	//Console Window ��ġ ����
	HWND hWnd = ::FindWindow("ConsoleWindowClass" ,NULL );
	::MoveWindow(hWnd , 420 , 0 , 500 , 500, TRUE );

	//Window ������ �й��� �л� �̸����� �ۼ��Ͻʽÿ�.
	glutCreateWindow("2014210057_���ظ�");

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(Render); // Render�̶�� �Լ��� ���÷��� �̺�Ʈ�� ���� Callback�Լ��� ����Ѵٴ� �ǹ�
	glutReshapeFunc(Reshape);

	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKey);
	glutIdleFunc(Idle);
	
	glutMainLoop();

	return 0;
}




/*
////////////// r1/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r1.v1.x, r1.v1.y, r1.v1.z);
glVertex3f(r1.v2.x, r1.v2.y, r1.v2.z);
glVertex3f(r1.v3.x, r1.v3.y, r1.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r1.v3.x, r1.v3.y, r1.v3.z);
glVertex3f(r1.v4.x, r1.v4.y, r1.v4.z);
glVertex3f(r1.v1.x, r1.v1.y, r1.v1.z);
glEnd();

//////////////r2/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r2.v1.x, r2.v1.y, r2.v1.z);
glVertex3f(r2.v2.x, r2.v2.y, r2.v2.z);
glVertex3f(r2.v3.x, r2.v3.y, r2.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r2.v3.x, r2.v3.y, r2.v3.z);
glVertex3f(r2.v4.x, r2.v4.y, r2.v4.z);
glVertex3f(r2.v1.x, r2.v1.y, r2.v1.z);
glEnd();

//////////////r3/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r3.v1.x, r3.v1.y, r3.v1.z);
glVertex3f(r3.v2.x, r3.v2.y, r3.v2.z);
glVertex3f(r3.v3.x, r3.v3.y, r3.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r3.v3.x, r3.v3.y, r3.v3.z);
glVertex3f(r3.v4.x, r3.v4.y, r3.v4.z);
glVertex3f(r3.v1.x, r3.v1.y, r3.v1.z);
glEnd();

//////////////r4/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r4.v1.x, r4.v1.y, r4.v1.z);
glVertex3f(r4.v2.x, r4.v2.y, r4.v2.z);
glVertex3f(r4.v3.x, r4.v3.y, r4.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r4.v3.x, r4.v3.y, r4.v3.z);
glVertex3f(r4.v4.x, r4.v4.y, r4.v4.z);
glVertex3f(r4.v1.x, r4.v1.y, r4.v1.z);
glEnd();

////////////// r5/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r5.v1.x, r5.v1.y, r5.v1.z);
glVertex3f(r5.v2.x, r5.v2.y, r5.v2.z);
glVertex3f(r5.v3.x, r5.v3.y, r5.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r5.v3.x, r5.v3.y, r5.v3.z);
glVertex3f(r5.v4.x, r5.v4.y, r5.v4.z);
glVertex3f(r5.v1.x, r5.v1.y, r5.v1.z);
glEnd();

//////////////r6/////////////////
glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(r6.v1.x, r6.v1.y, r6.v1.z);
glVertex3f(r6.v2.x, r6.v2.y, r6.v2.z);
glVertex3f(r6.v3.x, r6.v3.y, r6.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r6.v3.x, r6.v3.y, r6.v3.z);
glVertex3f(r6.v4.x, r6.v4.y, r6.v4.z);
glVertex3f(r6.v1.x, r6.v1.y, r6.v1.z);
glEnd();

////////////// r7/////////////////
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r7.v1.x, r7.v1.y, r7.v1.z);
glVertex3f(r7.v2.x, r7.v2.y, r7.v2.z);
glVertex3f(r7.v3.x, r7.v3.y, r7.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r7.v3.x, r7.v3.y, r7.v3.z);
glVertex3f(r7.v4.x, r7.v4.y, r7.v4.z);
glVertex3f(r7.v1.x, r7.v1.y, r7.v1.z);
glEnd();

//////////////r8/////////////////
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r8.v1.x, r8.v1.y, r8.v1.z);
glVertex3f(r8.v2.x, r8.v2.y, r8.v2.z);
glVertex3f(r8.v3.x, r8.v3.y, r8.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r8.v3.x, r8.v3.y, r8.v3.z);
glVertex3f(r8.v4.x, r8.v4.y, r8.v4.z);
glVertex3f(r8.v1.x, r8.v1.y, r8.v1.z);
glEnd();

////////////// r9/////////////////
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r9.v1.x, r9.v1.y, r9.v1.z);
glVertex3f(r9.v2.x, r9.v2.y, r9.v2.z);
glVertex3f(r9.v3.x, r9.v3.y, r9.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r9.v3.x, r9.v3.y, r9.v3.z);
glVertex3f(r9.v4.x, r9.v4.y, r9.v4.z);
glVertex3f(r9.v1.x, r9.v1.y, r9.v1.z);
glEnd();

//////////////r10/////////////////
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r10.v1.x, r10.v1.y, r10.v1.z);
glVertex3f(r10.v2.x, r10.v2.y, r10.v2.z);
glVertex3f(r10.v3.x, r10.v3.y, r10.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r10.v3.x, r10.v3.y, r10.v3.z);
glVertex3f(r10.v4.x, r10.v4.y, r10.v4.z);
glVertex3f(r10.v1.x, r10.v1.y, r10.v1.z);
glEnd();

//////////////r11/////////////////
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r11.v1.x, r11.v1.y, r11.v1.z);
glVertex3f(r11.v2.x, r11.v2.y, r11.v2.z);
glVertex3f(r11.v3.x, r11.v3.y, r11.v3.z);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(r11.v3.x, r11.v3.y, r11.v3.z);
glVertex3f(r11.v4.x, r11.v4.y, r11.v4.z);
glVertex3f(r11.v1.x, r11.v1.y, r11.v1.z);
glEnd();
*/