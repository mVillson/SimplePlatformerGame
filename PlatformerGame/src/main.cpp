#include <iostream>

#define GLEW_STATIC
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include "renderer/ShaderProgram.h"
#include "renderer/VertexBufferLayout.h"

GLFWwindow* gWindow = nullptr;
const char* windowTitle = "2D Platformer";
int windowWidth = 800;
int windowHeight = 600;

bool InitOpenGL();

int main()
{
	if (!InitOpenGL())
		return -1;

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	unsigned int indices[]
	{
		0, 1, 2,
		2, 3, 0
	};

	VertexArray vao;
	vao.Create();

	VertexBuffer vbo;
	vbo.CreateDynamic(1000 * sizeof(float));

	IndexBuffer ibo;
	ibo.CreateStatic(sizeof(indices), indices);

	VertexBufferLayout va;
	va.AddLayout(Type::FLOAT, 3);
	va.AddLayout(Type::FLOAT, 4);
	va.AddLayout(Type::FLOAT, 1);
	
	ShaderProgram sp;
	sp.Create("shaders/basicVertex.shader", "shaders/basicFragment.shader");

	while (!glfwWindowShouldClose(gWindow))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		float vertices[]
		{
		//	 x		y	  z		red	  green	blue  alpha
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, -1.0f, // v1
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, // v2
			 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f, // v3
			 0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.5f, 1.0f, -1.0f  // v4
		};
		vbo.SubData(0, sizeof(vertices), vertices);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(gWindow);
	}

	glfwTerminate();
	return 0;
}

bool InitOpenGL()
{
	if (!glfwInit())
	{
		std::cerr << "ERROR: GLFW FAILED TO INITIALIZE!" << std::endl;
		return false;
	}

	gWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
	if (!gWindow)
	{
		std::cerr << "ERROR: GLFW WINDOW FAILED TO CREATE!" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(gWindow);

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "ERROR: GLEW FAILED TO INITIALIZE!" << std::endl;
		return false;
	}

	glewExperimental = GL_TRUE;
	return true;
}