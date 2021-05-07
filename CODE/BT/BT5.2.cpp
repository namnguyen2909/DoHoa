//Hien thi lap phuong tu diem quan sat, su dung chieu phoi canh, nhan chuot trai de thay doi goc quan sat fovy
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLdouble _fovy = 10;
GLfloat _gocX = 0;
GLfloat _gocY = 0;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, 1, 6, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 0, 0, 0, 0, 1, 0, 0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(45, 1, 1, 1);
	glutWireCube(1);
	glPopMatrix();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			_fovy += 1;
			myInit();
			myDisplay();
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			_fovy -= 1;
			myInit();
			myDisplay();
		break;
	default:
		break;
	}
}

void run(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Bai 5.2");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}

void main(int argc, char** argv) {
	run(argc, argv);
}