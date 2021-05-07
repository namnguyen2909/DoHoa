//Ve lap phuong trong khoi quan sat phoi canh tong quat
#include <glut.h> // GLUT
#include <GL/glu.h> // GLU
#include <GL/gl.h> // OpenGL
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity(); /* clear the matrix */
	/* viewing transformation */
	gluLookAt(2.0, 2.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutWireCube(1.0);
	glFlush();
}
void myReshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // OpenGL initializations
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400); // create a 400x400 window
	glutInitWindowPosition(0, 0); // ...in the upper left
	glutCreateWindow("Thi du 5.3"); // create the window
	glutDisplayFunc(myDisplay); // setup callbacks
	glutReshapeFunc(myReshape);
	init();
	glutMainLoop(); // start it running
	return 0; // ANSI C expects this
}
