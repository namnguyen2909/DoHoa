//Ve doan thang co he so goc tu 0 den 1 bang thuat toan trung diem
#include <glut.h>
#include <gl/gl.h>
class GLintPoint {
public:
	GLint x, y;
};
void drawPoint(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void midPointLine(int x0, int y0, int x1, int y1)
{
	int dx, dy, incrE, incrNE, d, x, y;
	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx; //dstart
	incrE = 2 * dy; //DE
	incrNE = 2 * (dy - dx); //DNE
	x = x0; y = y0;
	drawPoint(x, y);
	while (x < x1)
	{
		if (d <= 0) // select E
		{
			d += incrE;
			x++;
		}
		else
		{ // select NE
			d += incrNE;
			x++; y++;
		}
		drawPoint(x, y);
	}
}
void myDisplay(void) {
	glClearColor(1., 1., 1., 1.);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 0., 0.);
	midPointLine(100, 200, 400, 300);
	glFlush();
}
void myReshape(int w, int h) { // window is reshaped
	glViewport(0, 0, w, h); // update the viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); // map unit square to viewport
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay(); // request redisplay
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 150);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Thi du 2.2");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
