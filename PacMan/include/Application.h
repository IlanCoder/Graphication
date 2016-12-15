#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/vec4.hpp"
#include "glm/vec3.hpp"
#include "GLFW\glfw3.h"
#define SIZEX 20
#define SIZEY 10

class Application {
public:
	Application();
	~Application();
	void update();
	void setup();
	void orthoDis();
	void orthoDisPill();
	void display();
	void displayPill();
	void collisionPill();
	void collisionWall();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int action, int mods);
	void rotatePlayer(float angle);
	void mouseButtonX(int button, int action, int mods);
	void mousePos(int x, int y);
	bool editor;
	glm::vec2 screen;
private:	
	Object3D triangle;
	Object3D pills;
	float angle;
	bool walkingFront, walkingBack, rotateLeft, rotateRight, movePlayer;
	int mouseX, mouseY;
	float speed;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 transform;
	glm::vec3 eye, prevEye;
	glm::vec3 target, prevTarget;
	glm::vec3 up;
	glm::vec3 movement;
	glm::mat4 lookAt;
	glm::mat4 perspective;
	glm::mat4 ortho;
	glm::mat4 newPosis;
	int labrynth[SIZEX][SIZEY] = {
		/*'0','0','0','0','0','0',
		'0','0','0','0','0','0',
		'0','0','0','0','0','0',
		'0','0','0','0','0','0',
		'0','0','0','0','0','0'*/
	};
};

