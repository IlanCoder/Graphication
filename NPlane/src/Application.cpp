
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "ShaderFuncs.h"

Application::Application():oPlane(), nop(1){
	eye = glm::vec3(0.0f, 50.0f, 100.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	time = 0;
}

Application::~Application() {}

void Application::update(){
	time += 0.000005f;
}

void Application::setup(){
	oPlane.createPlane(60);
	std::string strVertexShader = loadTextFile("Shaders/gouradPlane.v");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.f");
	InitializeProgram(oPlane.shader[0], strVertexShader, strFragmentShader);
	oPlane.uTransform[0] = glGetUniformLocation(oPlane.shader[0], "mTransform");
	oPlane.uTime[0] = glGetUniformLocation(oPlane.shader[0], "fTime");
	oPlane.uEye[0] = glGetUniformLocation(oPlane.shader[0], "vEye");
	strVertexShader = loadTextFile("Shaders/funkShader.v");
	strFragmentShader = loadTextFile("Shaders/funkShader.f");
	InitializeProgram(oPlane.shader[1], strVertexShader, strFragmentShader);
	oPlane.uTransform[1] = glGetUniformLocation(oPlane.shader[1], "mTransform");
	oPlane.uTime[1] = glGetUniformLocation(oPlane.shader[1], "fTime");
	oPlane.uEye[1] = glGetUniformLocation(oPlane.shader[1], "vEye");
	glGenVertexArrays(1, &oPlane.vao);
	glBindVertexArray(oPlane.vao);
	glGenBuffers(1, &oPlane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, oPlane.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes() + oPlane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, oPlane.getVertexSizeInBytes(), oPlane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes(), oPlane.getTextureCoordsSizeInBytes(), oPlane.textureCoords);
	oPlane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(oPlane.getVertexSizeInBytes-

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnable(GL_DEPTH_TEST);
}

void Application::display(){
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_BACK, GL_LINE);
	//Seleccionamos los shaders a usar
	glUseProgram(oPlane.shader[nop]);
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(oPlane.vao);
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(45.0f, 640.0f / 480.0f, 0.1f, 200.0f);
	transform = perspective*lookAt;
	glUniformMatrix4fv(oPlane.uTransform[nop], 1, false, glm::value_ptr(transform));
	glUniform1f(oPlane.uTime[nop], time);
	glUniform3fv(oPlane.uEye[nop], 1, glm::value_ptr(eye));
	glDrawArrays(GL_TRIANGLES, 0, oPlane.getNumVertex());
}

void Application::reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::keyboard(int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		exit(0);
	}
	if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE) {
		nop = 1 - nop;
	
		std::cout << nop << std::endl;
	}
	if (action == GLFW_RELEASE) {
		return;
	}
}
