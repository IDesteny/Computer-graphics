#include "GL/glut.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <assert.h>

#include "PolygonsAndNormalMap.h"

#define GetNumberOfPoints(Polygons, SpaceType) \
	(sizeof (Polygons) / sizeof *(Polygons) / (SpaceType))

GLFWwindow *WindowInitialize(GLsizei Width, GLsizei Height, const GLbyte *Title)
{
	GLint InitResult = glfwInit();
	if (InitResult != GLFW_TRUE)
	{
		return NULL;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow *WindowHandle = glfwCreateWindow(Width, Height, Title, NULL, NULL);
	if (WindowHandle == NULL)
	{
		return NULL;
	}

	glfwMakeContextCurrent(WindowHandle);

	return WindowHandle;
}

GLvoid GameLoop(GLFWwindow *WindowHandle, GLvoid (*UpdateCallback)(GLvoid *Context), GLvoid *Context)
{
	assert(WindowHandle != NULL);
	assert(UpdateCallback != NULL);

	while (!glfwWindowShouldClose(WindowHandle))
	{
		UpdateCallback(Context);

		glfwSwapBuffers(WindowHandle);
		glfwPollEvents();
	}
}

GLvoid WindowDeinitialize(GLFWwindow *WindowHandle)
{
	assert(WindowHandle != NULL);

	glfwDestroyWindow(WindowHandle);
	glfwTerminate();
}

GLvoid ErrorHandler()
{
	GLbyte *Description;
	GLint ErrorCode = glfwGetError(&Description);

	if (ErrorCode == GLFW_NO_ERROR)
	{
		printf("No mistakes\n");
		return;
	}

	assert(Description != NULL);

	printf("Error code: %i\nDescription: %s\n", ErrorCode, Description);
}

GLvoid OutputSystemInfo()
{
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("OpenGL version supported: %s\n", glGetString(GL_VERSION));
}

GLvoid SpecifyingInitialSettings()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
}

GLvoid DrawBat()
{
	glColor3f(0.5, 0.5, 0.5);
	glVertexPointer(3, GL_FLOAT, 0, BatPolygons);
	glNormalPointer(GL_FLOAT, 0, BatNormalMap);
	glDrawArrays(GL_TRIANGLES, 0, GetNumberOfPoints(BatPolygons, 3));
}

GLvoid DrawLamp()
{
	glColor3f(1, 1, 1);
	glVertexPointer(3, GL_FLOAT, 0, LampPolygons);
	glNormalPointer(GL_FLOAT, 0, LampNormalMap);
	glDrawArrays(GL_TRIANGLE_FAN, 0, GetNumberOfPoints(LampPolygons, 3));
}

GLvoid CoordNormalizeAndNormMaps()
{
	for (GLint i = 0; i < GetNumberOfPoints(BatPolygons, 3) * 3; i += 3)
	{
		BatPolygons[i] -= 9;
		BatPolygons[i + 1] -= 4;
		BatNormalMap[i] -= 9;
		BatNormalMap[i + 1] -= 4;
	}
}

GLvoid Update(GLFWwindow *WindowHandle)
{
	GLint WindowWidth, WindowHeight;
	glfwGetWindowSize(WindowHandle, &WindowWidth, &WindowHeight);
	glViewport(0, 0, WindowWidth, WindowHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLdouble)WindowWidth / WindowHeight, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glTranslatef(0, 0, -30);
	glRotatef(20, 1, 0, 0);

	glPushMatrix();
	{
		glRotatef(180, 0, 1, 0);
		static GLfloat Angle = 1;
		glRotatef(Angle += 1, 0, 1, 0);
		glTranslatef(0, 0, 20);
		DrawLamp();

		GLfloat LightPosition[] = { 0, 0, 1, 0 };
		GLfloat LightDiffuse[] = { 0, 0, 1, 1 };
		GLfloat LightAmbient[] = { -0.05, -0.05, -0.05, 1 };

		glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	}
	glPopMatrix();

	glPushMatrix();
	{
		static GLfloat Angle = 1;
		glRotatef(Angle += 1, 0, 1, 0);
		glTranslatef(0, 0, 20);
		DrawLamp();

		GLfloat LightPosition[] = { 0, 0, 1, 0 };
		GLfloat LightDiffuse[] = { 1, 0, 0, 1 };
		GLfloat LightAmbient[] = { -0.05, -0.05, -0.05, 1 };

		glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
		glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	}
	glPopMatrix();

	DrawBat();
}

GLint main(GLint Argc, GLbyte **Argv)
{
	GLFWwindow *WindowHandle = WindowInitialize(1280, 720, "Computer graphics");
	if (WindowHandle == NULL)
	{
		ErrorHandler();
		return;
	}

	OutputSystemInfo();
	SpecifyingInitialSettings();
	CoordNormalizeAndNormMaps();

	GameLoop(WindowHandle, Update, WindowHandle);

	WindowDeinitialize(WindowHandle);
}