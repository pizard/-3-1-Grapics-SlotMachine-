
#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>	
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "./header/FACE.h"
#include "./header/MATRIX.h"
#include "./header/Mesh.h"
#include "./header/VECTOR.h"
#include "./header/VERTEX.h"

using namespace std;
// spacebar���� �����ּ���!!!!!
	
	GLfloat vertices_A[][3] = {
		{ 0, 0, -10 },
		{ 0, 9, -5 },
		{ 0, 9, 5 },
		{ 0, 0, 10 },
		{ 0,-9, 5 },
		{ 0,-9,-5 } };

	GLfloat vertices_B[][3] = {
		{ 20, 0, -10 },
		{ 20, 9, -5 },
		{ 20, 9, 5 },
		{ 20, 0, 10 },
		{ 20,-9, 5 },
		{ 20,-9,-5 }};


	VERTEX  v0 = VERTEX(0.0f, 0.0f, 0.0f);		// �ʱ�ȭ VERTEX
	VERTEX v_x = VERTEX(1000.0f, 0.0f, 0.0f);		// �ʱ�ȭ VERTEX
	VERTEX v_y = VERTEX(0.0f, 1000.0f, 0.0f);		// �ʱ�ȭ VERTEX
	VERTEX v_z = VERTEX(0.0f, 0.0f, 1000.0f);		// �ʱ�ȭ VERTEX


	VERTEX A1 = VERTEX(-10, 0, -10);
	VERTEX A2 = VERTEX(-10, 9, -5);
	VERTEX A3 = VERTEX(-10, 9, 5);
	VERTEX A4 = VERTEX(-10, 0, 10);
	VERTEX A5 = VERTEX(-10, -9, 5);
	VERTEX A6 = VERTEX(-10,-9,-5) ;

	VERTEX B1 = VERTEX( 10, 0, -10);
	VERTEX B2 = VERTEX( 10, 9, -5);
	VERTEX B3 = VERTEX( 10, 9, 5);
	VERTEX B4 = VERTEX( 10, 0, 10);
	VERTEX B5 = VERTEX( 10, -9, 5);
	VERTEX B6 = VERTEX( 10,-9,-5);
	
	FACE H1 = FACE(A1, A2, A3, A4, A5, A6);
	FACE H2 = FACE(B1, B2, B3, B4, B5, B6);
	
	
Mesh a;
MATRIX m;
static double checker;

 void MyTimer1(int value) {
	 MATRIX m_xyz;
	 
	 checker += 0.0003;
	 m_xyz = m.Transpose(checker, H1.H_pos , H2.H_pos);
	 A1 = m.Trans(m_xyz, A1);
	 A2 = m.Trans(m_xyz, A2);
	 A3 = m.Trans(m_xyz, A3);
	 A4 = m.Trans(m_xyz, A4);
	 A5 = m.Trans(m_xyz, A5);
	 A6 = m.Trans(m_xyz, A6);
	 B1 = m.Trans(m_xyz, B1);
	 B2 = m.Trans(m_xyz, B2);
	 B3 = m.Trans(m_xyz, B3);
	 B4 = m.Trans(m_xyz, B4);
	 B5 = m.Trans(m_xyz, B5);
	 B6 = m.Trans(m_xyz, B6);
	 glutPostRedisplay();
 }

 void MyTimer2(int value) {
	 MATRIX m_xyz;

	 m_xyz = m.Transpose(checker, H1.H_pos, H2.H_pos);
	 A1 = m.Trans(m_xyz, A1);
	 A2 = m.Trans(m_xyz, A2);
	 A3 = m.Trans(m_xyz, A3);
	 A4 = m.Trans(m_xyz, A4);
	 A5 = m.Trans(m_xyz, A5);
	 A6 = m.Trans(m_xyz, A6);
	 B1 = m.Trans(m_xyz, B1);
	 B2 = m.Trans(m_xyz, B2);
	 B3 = m.Trans(m_xyz, B3);
	 B4 = m.Trans(m_xyz, B4);
	 B5 = m.Trans(m_xyz, B5);
	 B6 = m.Trans(m_xyz, B6);
	 glutPostRedisplay();
 }

 void MyTimer3(int value) {
	 MATRIX m_xyz;

	 checker -= 0.0003;
	 m_xyz = m.Transpose(checker, H1.H_pos, H2.H_pos);
	 A1 = m.Trans(m_xyz, A1);
	 A2 = m.Trans(m_xyz, A2);
	 A3 = m.Trans(m_xyz, A3);
	 A4 = m.Trans(m_xyz, A4);
	 A5 = m.Trans(m_xyz, A5);
	 A6 = m.Trans(m_xyz, A6);
	 B1 = m.Trans(m_xyz, B1);
	 B2 = m.Trans(m_xyz, B2);
	 B3 = m.Trans(m_xyz, B3);
	 B4 = m.Trans(m_xyz, B4);
	 B5 = m.Trans(m_xyz, B5);
	 B6 = m.Trans(m_xyz, B6);
	 glutPostRedisplay();
 }
 
 void DoTimer(int value)
 {

	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter = 0;
	int r;
	srand((unsigned int)time(NULL));
	r = (rand() % 6) * 100;

	checker = 0;
	for (counter1; counter1 < 2000; counter1++) {
		glutTimerFunc(counter1, MyTimer1, 1);       // 30�и��ʸ��� ȣ��
		glutPostRedisplay();
	}
	for (counter2; counter2 < 3000; counter2++) {
		glutTimerFunc(counter2+ 2000, MyTimer2, 1);
		glutPostRedisplay();
	}
	for (counter; counter < r; counter++) {
		glutTimerFunc(counter + 5000, MyTimer2, 1);
		glutPostRedisplay();
	}
	for (counter3; counter3 < 2000; counter3++) {
		glutTimerFunc(counter3 + 5000 + r, MyTimer3, 1);
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
	H1.H_position();
	H2.H_position();

	
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(H1.H_pos.x, H1.H_pos.y, H1.H_pos.z);
	glVertex3f(H2.H_pos.x, H2.H_pos.y, H2.H_pos.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(H1.H_pos.x, H1.H_pos.y, H1.H_pos.z);
	glVertex3f(A2.x, A2.y, A2.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A1.x, A1.y, A1.z);
	glVertex3f(B1.x, B1.y, B1.z);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A2.x, A2.y, A2.z);
	glVertex3f(B2.x, B2.y, B2.z);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A3.x, A3.y, A3.z);
	glVertex3f(B3.x, B3.y, B3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A4.x, A4.y, A4.z);
	glVertex3f(B4.x, B4.y, B4.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A5.x, A5.y, A5.z);
	glVertex3f(B5.x, B5.y, B5.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(A6.x, A6.y, A6.z);
	glVertex3f(B6.x, B6.y, B6.z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(A1.x, A1.y, A1.z);
	glVertex3f(A2.x, A2.y, A2.z);
	glVertex3f(A3.x, A3.y, A3.z);
	glVertex3f(A4.x, A4.y, A4.z);
	glVertex3f(A5.x, A5.y, A5.z);
	glVertex3f(A6.x, A6.y, A6.z);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(B1.x, B1.y, B1.z);
	glVertex3f(B2.x, B2.y, B2.z);
	glVertex3f(B3.x, B3.y, B3.z);
	glVertex3f(B4.x, B4.y, B4.z);
	glVertex3f(B5.x, B5.y, B5.z);
	glVertex3f(B6.x, B6.y, B6.z);
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

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ': {
		DoTimer(10);
		glutPostRedisplay();
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

