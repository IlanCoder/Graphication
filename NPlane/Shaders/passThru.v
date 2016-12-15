#version 430 core

layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;
vec4 nPosition;
out vec4 color;

void main()
{
	nPosition=vPosition;
	nPosition.y=2*sin(fTime*vPosition.x)*2*cos(fTime*vPosition.z);
	color = vec4(1.0, 1.0, 1.0, 1.0);
	gl_Position = mTransform * nPosition;
}
