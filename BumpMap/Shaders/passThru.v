#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 texture;

uniform mat4 mTransform;
uniform vec3 myLightPosition;
out vec2 textCoor;
out vec4 newPos;
out vec3 lightv;

void main()
{
	newPos=vPosition;
	textCoor = texture;
	lightv = normalize( myLightPosition - newPos.xyz);
	gl_Position = mTransform * vPosition;
}
