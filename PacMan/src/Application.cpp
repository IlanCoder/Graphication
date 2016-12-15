
#include "Application.h"
#include <iostream>
#include <vector>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
//#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include "ShaderFuncs.h"
//tu has tu mapita click dertecho para pastilla, y izquierda wall
GLfloat vertexPositions[] = {
//1
	-0.75f, 0.75f, 0.75f, 1.0f,
	-0.75f,-0.75f, 0.75f, 1.0f,
	0.75f,  -0.75f, 0.75f, 1.0f,//t1

	-0.75f, 0.75f, 0.75f, 1.0f,
	0.75f,-0.75f, 0.75f, 1.0f,
	0.75f,  0.75f, 0.75f, 1.0f,//t2
//2
	0.75f, 0.75f, 0.75f, 1.0f,
	0.75f,-0.75f, 0.75f, 1.0f,
	0.75f, -0.75f, -0.75f, 1.0f,//t3

	0.75f, 0.75f, 0.75f, 1.0f,
	0.75f,-0.75f, -0.75f, 1.0f,
	0.75f, 0.75f, -0.75f, 1.0f,//t4
//3
	0.75f, 0.75f, -0.75f, 1.0f,
	0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, -0.75f, -0.75f, 1.0f,//t5

	0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, 0.75f, -0.75f, 1.0f,//t6
//4
	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, -0.75f, 1.0f,
	-0.75f, -0.75f, 0.75f, 1.0f,//t7

	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f,-0.75f, 0.75f, 1.0f,
	-0.75f, 0.75f, 0.75f, 1.0f,//t8
//5
	-0.75f, 0.75f, -0.75f, 1.0f,
	-0.75f, 0.75f, 0.75f, 1.0f,
	0.75f, 0.75f, 0.75f, 1.0f,//t9

	-0.75f, 0.75f, -0.75f, 1.0f,
	0.75f, 0.75f, 0.75f, 1.0f,
	0.75f, 0.75f, -0.75f, 1.0f,//t10
//6
	-0.75f, -0.75f, 0.75f, 1.0f,
	-0.75f, -0.75f, -0.75f, 1.0f,
	0.75f, -0.75f, -0.75f, 1.0f,//t11

	-0.75f, -0.75f, 0.75f, 1.0f,
	0.75f, -0.75f, -0.75f, 1.0f,
	0.75f, -0.75f, 0.75f, 1.0f,//t12
};

GLfloat vertexColors[] = {
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 1

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 2

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 3

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 3

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 4

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 5

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,// face 6
};

GLfloat pillsVertexPositions[] = {
	//1
	-0.25f, 0.25f, 0.25f, 1.0f,
	-0.25f,-0.25f, 0.25f, 1.0f,
	0.25f,  -0.25f, 0.25f, 1.0f,//t1

	-0.25f, 0.25f, 0.25f, 1.0f,
	0.25f,-0.25f, 0.25f, 1.0f,
	0.25f,  0.25f, 0.25f, 1.0f,//t2
	//2
	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f,-0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,//t3

	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f,-0.25f, -0.25f, 1.0f,
	0.25f, 0.25f, -0.25f, 1.0f,//t4
	//3
	0.25f, 0.25f, -0.25f, 1.0f,
	0.25f,-0.25f, -0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,//t5

	0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f,-0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, -0.25f, 1.0f,//t6
	//4
	-0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f,-0.25f, -0.25f, 1.0f,
	-0.25f, -0.25f, 0.25f, 1.0f,//t7

	-0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f,-0.25f, 0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,//t8
	 //5
	-0.25f, 0.25f, -0.25f, 1.0f,
	-0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, 0.25f, 0.25f, 1.0f,//t9

	-0.25f, 0.25f, -0.25f, 1.0f,
	0.25f, 0.25f, 0.25f, 1.0f,
	0.25f, 0.25f, -0.25f, 1.0f,//t10
	 //6
	-0.25f, -0.25f, 0.25f, 1.0f,
	-0.25f, -0.25f, -0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,//t11

	-0.25f, -0.25f, 0.25f, 1.0f,
	0.25f, -0.25f, -0.25f, 1.0f,
	0.25f, -0.25f, 0.25f, 1.0f,//t12
};

GLfloat pillsVertexColors[] = {
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 1

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 2

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 3

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 3

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 4

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 5

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,

	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,
	1.0, 0.0, 1.0, 1.0,// face 6
};

Application::Application() {
	eye = glm::vec3(2.0f, 0.0f, 2.5f);
	prevEye = eye;
	movement = glm::vec3(1.0f, 0.0f, 0.0f);
	target= movement + eye;
	prevTarget = target;
	walkingFront = false;
	walkingBack = false;
	rotateLeft = false;
	rotateRight = false;
	editor = true;
	speed = 0.03;
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	mouseX = 0;
	mouseY = 0;
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			labrynth[i][j] = 0;
		}
	}
	if (SIZEX >= SIZEY) {
		float sizex = SIZEX;
		float sizey = SIZEY;
		float resScale = sizey / sizex;
		screen = glm::vec2(1024, 1024 * resScale);
	}
	else {
		int resScale = SIZEX / SIZEY;
		screen = glm::vec2(1024*resScale, 1024);
	}
}

Application::~Application() {
	
}

void Application::update(){
	prevEye = eye;
	prevTarget = target;
	pills.angleY+= 0.1;
	if (movePlayer) {
		if (walkingFront) {
			eye += glm::vec3(speed, speed, speed)* movement;
			target += glm::vec3(speed, speed, speed)* movement;
		}
		else if (walkingBack) {
			eye -= glm::vec3(speed, speed, speed)* movement;
			target -= glm::vec3(speed, speed, speed)* movement;
		}
	}
	if (rotateLeft) {
		rotatePlayer(-0.1);
	}else if(rotateRight) {
		rotatePlayer(0.1);
	}
	collisionPill();
	collisionWall();
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

	InitializeProgram(pills.shader, strVertexShader, strFragmentShader);
	pills.uniform = glGetUniformLocation(pills.shader, "transform");
	pills.angleX = 0;
	pills.angleY = 0;
	pills.angleZ = 0;
	pills.numVertex = 36;
	glGenVertexArrays(1, &pills.vao);
	glBindVertexArray(pills.vao);
	glGenBuffers(1, &pills.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, pills.vbo);
	
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pillsVertexPositions) + sizeof(pillsVertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(pillsVertexPositions), pillsVertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(pillsVertexPositions), sizeof(pillsVertexColors), pillsVertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(pillsVertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void Application::orthoDis() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);
	ortho = glm::ortho(-0.75f, SIZEX*1.5f - 0.75f, SIZEY*1.5f - 0.75f, -0.75f);
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 1) {
				newPosis = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 1.5f*j, 0.0));
				transform = ortho*newPosis;

				glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(transform));/////<--------------------------------------------
				glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
			}
		}
	}
}

void Application::orthoDisPill() {
	glUseProgram(pills.shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(pills.vao);

	ortho = glm::ortho(-0.75f, SIZEX*1.5f - 0.75f, SIZEY*1.5f - 0.75f, -0.75f);
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 2) {
				newPosis = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 1.5f*j, 0.0));
				transform = ortho*newPosis;

				glUniformMatrix4fv(pills.uniform, 1, false, glm::value_ptr(transform));/////<--------------------------------------------
				glDrawArrays(GL_TRIANGLES, 0, pills.numVertex);
			}
		}
	}
}

void Application::display(){
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shader);	
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.vao);
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(50.0f / 180.0f, screen.x/screen.y, 0.1f, 500.0f);
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 1) {
				newPosis = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
				transform = perspective*lookAt*newPosis;

				glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(transform));/////<--------------------------------------------
				glDrawArrays(GL_TRIANGLES, 0, triangle.numVertex);
			}
		}
	}
}

void Application::displayPill() {

	//Seleccionamos los shaders a usar
	glUseProgram(pills.shader);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(pills.vao);
	rotationY = glm::rotate(glm::mat4(1.0f), (pills.angleY*3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotationX = glm::rotate(glm::mat4(1.0f), (pills.angleY*3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	lookAt = glm::lookAt(eye, target, up);
	perspective = glm::perspective(50.0f / 180.0f, screen.x / screen.y, 0.1f, 500.0f);
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 2) {
				newPosis = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
				transform = perspective*lookAt*newPosis*rotationZ*rotationY*rotationX;

				glUniformMatrix4fv(pills.uniform, 1, false, glm::value_ptr(transform));/////<--------------------------------------------
				glDrawArrays(GL_TRIANGLES, 0, pills.numVertex);
			}
		}
	}
}

void Application::reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::keyboard(int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		exit(0);
	}
	/*if (key == GLFW_KEY_H && action == GLFW_PRESS) {
		printf("target at %f,%f,%f; eye at %f,%f,%f\n", target.x, target.y, target.z, eye.x, eye.y, eye.z);
	}*/
	if (key == GLFW_KEY_W	&& action == GLFW_PRESS) {
		walkingFront = true;
		walkingBack = false;
	}
	else if (key == GLFW_KEY_W	&& action == GLFW_RELEASE) {
		walkingFront = false;
	}
	if (key == GLFW_KEY_S	&& action == GLFW_PRESS) {
		walkingFront = false;
		walkingBack = true;
	}
	else if (key == GLFW_KEY_S	&& action == GLFW_RELEASE) {
		walkingBack = false;
	}
	if (key == GLFW_KEY_A	&& action == GLFW_PRESS) {
		rotateLeft = true;
		rotateRight = false;
	}
	else if (key == GLFW_KEY_A	&& action == GLFW_RELEASE) {
		rotateLeft = false;
	}
	if (key == GLFW_KEY_D	&& action == GLFW_PRESS) {
		rotateLeft = false;
		rotateRight = true;
	}
	else if (key == GLFW_KEY_D	&& action == GLFW_RELEASE) {
		rotateRight = false;
	}
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		editor = !editor;
	}
	if (action == GLFW_RELEASE) {
		return;
	}
}

void Application::mousePos(int x, int y){
	mouseX = x;
	mouseY = y;
}

void Application::collisionPill(){
	glm::vec2 playerPos = glm::vec2(eye.x, eye.z);
	float playerHit = 0.5f;
	float pillHit = 0.5f;
	glm::vec2 pillCoor;
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 2) {
				pillCoor = glm::vec2(1.5f*i, 1.5f*j);
				if (glm::distance(playerPos, pillCoor) <= (playerHit + pillHit)) {
					labrynth[i][j] = 0;
				}			
			}
		}
	}
}

void Application::collisionWall(){
	glm::vec2 playerPos = glm::vec2(eye.x, eye.z);
	float playerHit = 0.5f;
	float wallHit = 0.9f;
	glm::vec2 wallCoor;
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEY; j++) {
			if (labrynth[i][j] == 1) {
				wallCoor = glm::vec2(1.5f*i, 1.5f*j);
				if (glm::distance(playerPos, wallCoor) <= (playerHit + wallHit)) {
					eye = prevEye;
					target = prevTarget;
					movePlayer = false;
					return;
				}
			}
		}
	}
	movePlayer = true;
}

void Application::mouseButtonX(int button, int action, int mods){
	if (editor) {
		int i = mouseX / (screen.x / SIZEX);
		int j = mouseY / (screen.y / SIZEY);
		if (button == GLFW_MOUSE_BUTTON_LEFT&&action == GLFW_PRESS) {
			if (labrynth[i][j] == 1) {
				labrynth[i][j] = 0;
			}
			else {
				labrynth[i][j] = 1;
			}
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT&&action == GLFW_PRESS) {
			if (labrynth[i][j] == 2) {
				labrynth[i][j] = 0;
			}
			else {
				labrynth[i][j] = 2;
			}
		}
		if (action == GLFW_RELEASE) {
			return;
		}
	}
}

void Application::rotatePlayer(float angle) {
	this->angle += angle;
	float x = 0.1*cos(this->angle/180);
	float z = 0.1*sin(this->angle/180);
	movement.x = x;
	movement.z = z;
	target = eye + movement;
}
