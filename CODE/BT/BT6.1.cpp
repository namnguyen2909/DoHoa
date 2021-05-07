#include <stdlib.h>
#include <glut.h>

struct Point 
{
	float x;
	float y;
	float z;
};

Point Points[4][4] = {
	{
		{ -1.5,-1.5,4.0 },
		{  -0.5,-1.5,2.0 },
		{ 0.5,-1.5,-1.0 },
		{1.5,-1.5,2.0 }
	},
	{
		{ -1.5,0.5,4.0 },
		{  -0.5,0.5,0.0 },
		{ 0.5,0.5,3.0 },
		{1.5,0.5,4.0 }
	},
	{
		{ -1.5,-0.5,1.0 },
		{  -0.5,-0.5,3.0 },
		{ 0.5,-0.5,0.0 },
		{1.5,-0.5,-1.0 }
	},
	{
		{ -1.5,1.5,-2.0 },
		{  -0.5,1.5,-2.0 },
		{ 0.5,1.5,0.0 },
		{1.5,1.5,-1.0 }
	}
};

unsigned int LOD = 20;

Point CalculateU(float t, int row) 
{
	Point p;

	float it = 1.0f - t;

	float b0 = t * t * t;
	float b1 = 3 * t * t * it;
	float b2 = 3 * t * it * it;
	float b3 = it * it * it;

	p.x = b0 * Points[row][0].x +
		b1 * Points[row][1].x +
		b2 * Points[row][2].x +
		b3 * Points[row][3].x;

	p.y = b0 * Points[row][0].y +
		b1 * Points[row][1].y +
		b2 * Points[row][2].y +
		b3 * Points[row][3].y;

	p.z = b0 * Points[row][0].z +
		b1 * Points[row][1].z +
		b2 * Points[row][2].z +
		b3 * Points[row][3].z;

	return p;
}

Point CalculateV(float t, Point* pnts) 
{
	Point p;

	float it = 1.0f - t;

	float b0 = t * t * t;
	float b1 = 3 * t * t * it;
	float b2 = 3 * t * it * it;
	float b3 = it * it * it;

	p.x = b0 * pnts[0].x +
		b1 * pnts[1].x +
		b2 * pnts[2].x +
		b3 * pnts[3].x;

	p.y = b0 * pnts[0].y +
		b1 * pnts[1].y +
		b2 * pnts[2].y +
		b3 * pnts[3].y;

	p.z = b0 * pnts[0].z +
		b1 * pnts[1].z +
		b2 * pnts[2].z +
		b3 * pnts[3].z;

	return p;
}

Point Calculate(float u, float v) 
{
	Point temp[4];

	temp[0] = CalculateU(u, 0);
	temp[1] = CalculateU(u, 1);
	temp[2] = CalculateU(u, 2);
	temp[3] = CalculateU(u, 3);
	return CalculateV(v, temp);
}

void OnReshape(int w, int h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, (float)w / h, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OnDraw() 
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(5, 16, 20,	
		0, 0, 0,	
		0, 1, 0);	

	glColor3f(1, 0, 1);
	glPointSize(2);
	glBegin(GL_POINTS);

	for (int i = 0; i != LOD; ++i) 
	{
		float u = (float)i / (LOD - 1);
		for (int j = 0; j != LOD; ++j) 
		{
			float v = (float)j / (LOD - 1);
			Point p = Calculate(u, v);
			glVertex3f(p.x, p.y, p.z);
		}
	}
	glEnd();
	glutSwapBuffers();
}

void OnInit() 
{
	glEnable(GL_DEPTH_TEST);
}

void OnExit() 
{

}

void OnKeyPress(unsigned char key, int, int) 
{
	switch (key) 
	{
		case '+':
			++LOD;
			break;

		case '-':
			--LOD;

			if (LOD < 3)
				LOD = 3;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640, 480);
	glutCreateWindow("BT6.1");
	glutDisplayFunc(OnDraw);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	OnInit();
	atexit(OnExit);
	glutMainLoop();
	return 0;
}