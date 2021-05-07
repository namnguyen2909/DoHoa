// VE DUONG TRON BANG THUAT TOAN TRUNG DIEM VOI BAN KINH VA TAM CHO TRUOC
#include <glut.h>
#include <stdio.h>
class screenPoint
{
private:
	GLint x, y;
public:
	screenPoint() {
		x = 0;
		y = 0;
	}
	void setCoordinates(GLint xCoordinateValue, GLint yCoordinateValue) {
		x = xCoordinateValue;
		y = yCoordinateValue;
	}
	GLint getx() const {
		return x;
	}
	GLint gety() const {
		return y;
	}
	void incrementx() {
		x++;
	}
	void decrementy() {
		y--;
	}
};
void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

void circleMidPoint(GLint xc, GLint yc, GLint raduis) //Ham ve duong tron
{
	screenPoint circlePoint;
	GLint p = 1 - raduis;
	circlePoint.setCoordinates(0, raduis);
	void circlePlotPoints(GLint, GLint, screenPoint);
	circlePlotPoints(xc, yc, circlePoint);
	while (circlePoint.getx() < circlePoint.gety())
	{
		circlePoint.incrementx();
		if (p < 0)
			p += 2 * circlePoint.getx() + 1;
		else {
			circlePoint.decrementy();
			p += 2 * (circlePoint.getx() - circlePoint.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circlePoint);
	}
}

void circlePlotPoints(GLint xc, GLint yc, screenPoint circPoint) //Ham ve 8 diem doi xung
{
	setPixel(xc + circPoint.getx(), yc + circPoint.gety());
	setPixel(xc - circPoint.getx(), yc + circPoint.gety());
	setPixel(xc + circPoint.getx(), yc - circPoint.gety());
	setPixel(xc - circPoint.getx(), yc - circPoint.gety());

	setPixel(xc + circPoint.gety(), yc + circPoint.getx());
	setPixel(xc - circPoint.gety(), yc + circPoint.getx());
	setPixel(xc + circPoint.gety(), yc - circPoint.getx());
	setPixel(xc - circPoint.gety(), yc - circPoint.getx());
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}
void drawMyCircle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(3.0);
	GLint xCenter = 150;
	GLint yCenter = 150;
	GLint raduis = 50;
	circleMidPoint(xCenter, yCenter, raduis);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Bai Tap 2.1");
	init();
	glutDisplayFunc(drawMyCircle);
	glutMainLoop();
	return 0;
}