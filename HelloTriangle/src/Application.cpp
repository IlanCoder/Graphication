
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
//#include "GL/freeglut.h"
#include "ShaderFuncs.h"

GLfloat vertexPositions[] = {
	-0.75f, 0.75f, 0.75f, 1.0f,
	-0.75f,-0.75f, 0.75f, 1.0f,
	0.75f,  -0.75f, 0.75f, 1.0f,//t1
};

GLfloat vertexColors[] = {
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
};

Application::Application() {}

Application::~Application() {}

void Application::update(){
	triangle.angleX += 0.1f;
	triangle.angleY+= 0.1f;
	triangle.angleZ+= 0.1f;
}

void Application::setup(){
	std::string strVertexShader = loadTextFile("Shaders/passThru.vs");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.fs");
	InitializeProgram(triangle.shader, strVertexShader, strFragmentShader);
	triangle.uniform = glGetUniformLocation(triangle.shader, "transform");
	triangle.angleX = 0;
	triangle.angleY = 0;
	triangle.angleZ = 0;
	triangle.numVertex = 36;
	glGenVertexArrays(1, &triangle.vao);
	glBindVertexArray(triangle.vao);
	glGenBuffers(1, &triangle.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void Application::display(){
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);	
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);
	
	rotationX = glm::rotate(glm::mat4(1.0f), (triangle.angleX*3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f)); ////<-------------------------------------------------------------
	rotationY = glm::rotate(glm::mat4(1.0f), (triangle.angleY*3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotationZ = glm::rotate(glm::mat4(1.0f), (triangle.angleZ*3.141592f / 180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	transform = rotationX*rotationY*rotationZ;
	//pasar valores a var uniform
	glUniformMatrix4fv(triangle.uniform, 1,false,glm::value_ptr(transform));
	glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
}

void Application::reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::keyboard(int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		exit(0);
	}
	if (action == GLFW_RELEASE) {
		return;
	}
}
