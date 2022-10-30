#include "GL/glut.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <assert.h>

#define GetNumberOfPoints(Polygons, SpaceType) \
	(sizeof (Polygons) / sizeof *(Polygons) / (SpaceType))

GLfloat BatPolygons[] =
{
	0, 4, 0,
	4, 4, 0,
	5, 8, 0,

	4, 4, 0,
	5, 8, 0,
	6, 3, 0,

	5, 8, 0,
	6, 3, 0,
	8, 6, 0,

	6, 3, 0,
	8, 6, 0,
	9, 0, 0,

	8, 6, 0,
	9, 0, 0,
	10, 6, 0,

	9, 0, 0,
	10, 6, 0,
	12, 3, 0,

	10, 6, 0,
	12, 3, 0,
	13, 8, 0,

	12, 3, 0,
	13, 8, 0,
	14, 4, 0,

	13, 8, 0,
	14, 4, 0,
	18, 4, 0,

	7, 8, 0,
	8, 6, 0,
	9, 7, 0,

	8, 6, 0,
	9, 7, 0,
	10, 6, 0,

	9, 7, 0,
	10, 6, 0,
	11, 8, 0,

	0, 4, 2,
	4, 4, 2,
	5, 8, 2,

	4, 4, 2,
	5, 8, 2,
	6, 3, 2,

	5, 8, 2,
	6, 3, 2,
	8, 6, 2,

	6, 3, 2,
	8, 6, 2,
	9, 0, 2,

	8, 6, 2,
	9, 0, 2,
	10, 6, 2,

	9, 0, 2,
	10, 6, 2,
	12, 3, 2,

	10, 6, 2,
	12, 3, 2,
	13, 8, 2,

	12, 3, 2,
	13, 8, 2,
	14, 4, 2,

	13, 8, 2,
	14, 4, 2,
	18, 4, 2,

	7, 8, 2,
	8, 6, 2,
	9, 7, 2,

	8, 6, 2,
	9, 7, 2,
	10, 6, 2,

	9, 7, 2,
	10, 6, 2,
	11, 8, 2,

	0, 4, 0,
	0, 4, 2,
	5, 8, 0,
	
	0, 4, 2,
	5, 8, 0,
	5, 8, 2,
	
	5, 8, 0,
	5, 8, 2,
	8, 6, 0,
	
	5, 8, 2,
	8, 6, 0,
	8, 6, 2,
	
	8, 6, 0,
	8, 6, 2,
	7, 8, 0,
	
	8, 6, 2,
	7, 8, 0,
	7, 8, 2,
	
	7, 8, 0,
	7, 8, 2,
	9, 7, 0,
	
	7, 8, 2,
	9, 7, 0,
	9, 7, 2,
	
	9, 7, 0,
	9, 7, 2,
	11, 8, 0,
	
	9, 7, 2,
	11, 8, 0,
	11, 8, 2,
	
	11, 8, 0,
	11, 8, 2,
	10, 6, 0,
	
	11, 8, 2,
	10, 6, 0,
	10, 6, 2,
	
	10, 6, 0,
	10, 6, 2,
	13, 8, 0,
	
	10, 6, 2,
	13, 8, 0,
	13, 8, 2,
	
	13, 8, 0,
	13, 8, 2,
	18, 4, 0,
	
	13, 8, 2,
	18, 4, 0,
	18, 4, 2,
	
	18, 4, 0,
	18, 4, 2,
	14, 4, 0,
	
	18, 4, 2,
	14, 4, 0,
	14, 4, 2,
	
	14, 4, 0,
	14, 4, 2,
	12, 3, 0,
	
	14, 4, 2,
	12, 3, 0,
	12, 3, 2,
	
	12, 3, 0,
	12, 3, 2,
	9, 0, 0,
	
	12, 3, 2,
	9, 0, 0,
	9, 0, 2,
	
	9, 0, 0,
	9, 0, 2,
	6, 3, 0,
	
	9, 0, 2,
	6, 3, 0,
	6, 3, 2,
	
	6, 3, 0,
	6, 3, 2,
	4, 4, 0,
	
	6, 3, 2,
	4, 4, 0,
	4, 4, 2,
	
	4, 4, 0,
	4, 4, 2,
	0, 4, 0,
	
	4, 4, 2,
	0, 4, 0,
	0, 4, 2,
};

GLfloat BatNormalMap[] =
{
	0, 4, 3,
	4, 4, 3,
	5, 8, 3,

	4, 4, 3,
	5, 8, 3,
	6, 3, 3,

	5, 8, 3,
	6, 3, 3,
	8, 6, 3,

	6, 3, 3,
	8, 6, 3,
	9, 0, 3,

	8, 6, 3,
	9, 0, 3,
	10, 6, 3,

	9, 0, 3,
	10, 6, 3,
	12, 3, 3,

	10, 6, 3,
	12, 3, 3,
	13, 8, 3,

	12, 3, 3,
	13, 8, 3,
	14, 4, 3,

	13, 8, 3,
	14, 4, 3,
	18, 4, 3,

	7, 8, 3,
	8, 6, 3,
	9, 7, 3,

	8, 6, 3,
	9, 7, 3,
	10, 6, 3,

	9, 7, 3,
	10, 6, 3,
	11, 8, 3,
	
	0, 4, 3,
	4, 4, 3,
	5, 8, 3,

	4, 4, 3,
	5, 8, 3,
	6, 3, 3,

	5, 8, 3,
	6, 3, 3,
	8, 6, 3,

	6, 3, 3,
	8, 6, 3,
	9, 0, 3,

	8, 6, 3,
	9, 0, 3,
	10, 6, 3,

	9, 0, 3,
	10, 6, 3,
	12, 3, 3,

	10, 6, 3,
	12, 3, 3,
	13, 8, 3,

	12, 3, 3,
	13, 8, 3,
	14, 4, 3,

	13, 8, 3,
	14, 4, 3,
	18, 4, 3,

	7, 8, 3,
	8, 6, 3,
	9, 7, 3,

	8, 6, 3,
	9, 7, 3,
	10, 6, 3,

	9, 7, 3,
	10, 6, 3,
	11, 8, 3,

	0, 4, 3,
	0, 4, 3,
	5, 8, 3,

	0, 4, 3,
	5, 8, 3,
	5, 8, 3,

	5, 8, 3,
	5, 8, 3,
	8, 6, 3,

	5, 8, 3,
	8, 6, 3,
	8, 6, 3,

	8, 6, 3,
	8, 6, 3,
	7, 8, 3,

	8, 6, 3,
	7, 8, 3,
	7, 8, 3,

	7, 8, 3,
	7, 8, 3,
	9, 7, 3,

	7, 8, 3,
	9, 7, 3,
	9, 7, 3,

	9, 7, 3,
	9, 7, 3,
	11, 8, 3,

	9, 7, 3,
	11, 8, 3,
	11, 8, 3,

	11, 8, 3,
	11, 8, 3,
	10, 6, 3,

	11, 8, 3,
	10, 6, 3,
	10, 6, 3,

	10, 6, 3,
	10, 6, 3,
	13, 8, 3,

	10, 6, 3,
	13, 8, 3,
	13, 8, 3,

	13, 8, 3,
	13, 8, 3,
	18, 4, 3,

	13, 8, 3,
	18, 4, 3,
	18, 4, 3,

	18, 4, 3,
	18, 4, 3,
	14, 4, 3,

	18, 4, 3,
	14, 4, 3,
	14, 4, 3,

	14, 4, 3,
	14, 4, 3,
	12, 3, 3,

	14, 4, 3,
	12, 3, 3,
	12, 3, 3,

	12, 3, 3,
	12, 3, 3,
	9, 0, 3,

	12, 3, 3,
	9, 0, 3,
	9, 0, 3,

	9, 0, 3,
	9, 0, 3,
	6, 3, 3,

	9, 0, 3,
	6, 3, 3,
	6, 3, 3,

	6, 3, 3,
	6, 3, 3,
	4, 4, 3,

	6, 3, 3,
	4, 4, 3,
	4, 4, 3,

	4, 4, 3,
	4, 4, 3,
	0, 4, 3,

	4, 4, 3,
	0, 4, 3,
	0, 4, 3,
};

GLfloat LampPolygons[] =
{
	-1, -1, 0,
	1, -1, 0,
	1, 1, 0,
	-1, 1, 0,
};

GLfloat LampNormalMap[] =
{
	-1, -1, 3,
	1, -1, 3,
	1, 1, 3,
	-1, 1, 3,
};

GLFWwindow *WindowInitialize(GLsizei width, GLsizei height, const GLbyte *title)
{
	GLint InitResult = glfwInit();
	if (InitResult != GLFW_TRUE)
	{
		return NULL;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow *WindowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
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
		static float angle = 1;
		glRotatef(angle += 1, 0, 1, 0);
		glTranslatef(0, 0, 20);
		DrawLamp();

		GLfloat lightPosition[] = { 0, 0, 1, 0 };
		GLfloat lightDiffuse[] = { 0, 0, 1, 1 };
		GLfloat lightAmbient[] = { -0.05, -0.05, -0.05, 1 };


		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	}
	glPopMatrix();

	glPushMatrix();
	{
		static float angle = 1;
		glRotatef(angle += 1, 0, 1, 0);
		glTranslatef(0, 0, 20);
		DrawLamp();

		GLfloat lightPosition[] = { 0, 0, 1, 0 };
		GLfloat lightDiffuse[] = { 1, 0, 0, 1 };
		GLfloat lightAmbient[] = { -0.05, -0.05, -0.05, 1 };

		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
		glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
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