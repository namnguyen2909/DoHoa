//Ve doan thang va hinh tron
#include <windows.h>
#include <math.h>
#include <glut.h>
#include <gl/gl.h>
#define PI 3.14159265
class GLintPoint {
public:
	GLint x, y;
};
void drawPoint(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}
void drawCircle(GLintPoint point, float radius)
{
	float savex, savey;
	const int n = 50; // number of segments making up arc
	float angle = 0;
	float angleInc = 360.0 * PI / (180 * n); // angle increment in radians
	savex = point.x;
	savey = point.y;
	for (int k = 0; k <= n; k++, angle += angleInc) {
		drawLine(savex, savey,
			point.x + radius * cos(angle), point.y + radius * sin(angle));
		savex = point.x + radius * cos(angle);
		savey = point.y + radius * sin(angle);
	}
}
void myDisplay(void) {
	glClearColor(1., 1., 1., 1.);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 0., 0.);
	drawLine(100, 150, 500, 200);
	glColor3f(0., 0., 1.);
	GLintPoint point;
	point.x = 300;
	point.y = 200;
	drawCircle(point, 100.0);
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
	glutCreateWindow("Thi du 2.1");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}