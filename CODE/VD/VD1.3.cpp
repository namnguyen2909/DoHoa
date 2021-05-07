//Hien thi xau ky tu
#include <glut.h>
#include <gl/gl.h>
#include <string.h>
void bitmap_output(int x, int y, int z, const char* string, void* font)
{
	int len, i;
	glRasterPos3f(x, y, 0); // Locate Raster Position in 3-space
	len = (int)strlen(string); // Find length of string
	for (i = 0; i < len; i++) { // Loop through plotting all characters in font style
		glutBitmapCharacter(font, string[i]);
	}
}
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 0, 0);
	bitmap_output(0, 0, 0, "Hello OpenGL!", GLUT_BITMAP_TIMES_ROMAN_24);
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("VD1.3");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
