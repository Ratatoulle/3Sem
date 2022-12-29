#include "utils.h"

void display()
{
	float PI = 3.14159265358979323846;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);

	for (int i = 0; i < 12; i++)
	{
		float x = sin(2 * PI / 12 * i);
		float y = cos(2 * PI / 12 * i);
		glVertex2f(400 * x, 400 * y);
		glVertex2f(380 * x, 380 * y);
	}
	time_t t = time(0);
	tm* lt = localtime(&t);

	int hours = lt->tm_hour;
	int minutes = lt->tm_min;
	int seconds = lt->tm_sec;

	float x = sin(2 * PI * (hours * 60 + minutes) / 12 / 60);
	float y = cos(2 * PI * (hours * 60 + minutes) / 12 / 60);
	glVertex2f(0, 0);
	glVertex2f(200 * x, 200 * y);

	x = sin(2 * PI * minutes / 60);
	y = cos(2 * PI * minutes / 60);
	glVertex2f(0, 0);
	glVertex2f(350 * x, 350 * y);

	x = sin(2 * PI * seconds / 60);
	y = cos(2 * PI * seconds / 60);
	glVertex2f(0, 0);
	glVertex2f(380 * x, 380 * y);

	glEnd();
	glutSwapBuffers();
}

void timer(int a = 0)
{
	display();
	glutTimerFunc(10, timer, 0);
}