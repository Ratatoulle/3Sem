#include<gl/glut.h>
#include<math.h>
#include<stdlib.h>

float WIDTH = 400.0;
float HEIGHT = 400.0;
float Angle = 0.0, Scale = 1.0;

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	Scale = 1.0 - fabs(sin(3.14 * Angle / 90.0) / sqrt(3.0) / 2);
	glRotatef(Angle, 0.0, 0.0, 1.0);
	glScalef(Scale, Scale, 1.0);
	glBegin(GL_LINES);
	for (float i = -WIDTH / 2; i <= WIDTH / 2; i += 20.0)
	{
		glVertex2f(i, -HEIGHT / 2);
		glVertex2f(i, HEIGHT / 2);
	}
	for (float i = -HEIGHT / 2; i <= HEIGHT / 2; i += 20.0)
	{
		glVertex2f(-WIDTH / 2, i);
		glVertex2f(WIDTH / 2, i);
	}
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void Timer(int value)
{
	switch (value)
	{
	case 0: glColor3f(1.0, 1.0, 1.0);
		break;
	case 1: glColor3f(1.0, 0.0, 0.0);
		break;
	}
	++Angle;
	//Draw();
	glutPostRedisplay();
	glutTimerFunc(50, Timer, rand() % 2);
}

void Timer2(int)
{
	glColor3f(0.0, 1.0, 0.0);
	glutPostRedisplay();
	glutTimerFunc(1000, Timer2, 0);
}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("CRAZY SQUARE");
	glutDisplayFunc(Draw);
	glutTimerFunc(50, Timer, 0);
	glutTimerFunc(1000, Timer2, 0);
	Initialize();
	glutMainLoop();
	return 0;
}