//Ve diem anh tai vi tri nhan phim trai chuot
#include <windows.h>
#include <math.h>
#include <glut.h>
#include <gl/gl.h>	
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void myMouse(int button, int state, int x, int y)
{
	int yy;
	yy = glutGet(GLUT_WINDOW_HEIGHT);
	y = yy - y; /* In Glut, Y coordinate increases from top to bottom */
	glColor3f(1.0, 1.0, 1.0);
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 1.4");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}