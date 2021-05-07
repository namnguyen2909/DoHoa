//Su dung chuot de ve duong gap khuc
#include <windows.h>
#include <math.h>
#include <glut.h>
#include <gl/gl.h>
const int screenHeight = 480;
const int screenWidth = 640;
int startflag = 1;
class GLintPoint {
public:
	GLint x, y;
};
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();
}
void myMouse(int button, int state, int x, int y)
{
	static GLintPoint List[2];
	if (startflag == 1) {
		List[0].x = x;
		List[0].y = y;
		startflag = 0;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		List[1].x = x;
		List[1].y = y;
		drawLine(List[0].x, screenHeight - List[0].y, List[1].x, screenHeight - List[1].y);
		List[0].x = List[1].x;
		List[0].y = List[1].y;
	}
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Thi du 2.3");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}