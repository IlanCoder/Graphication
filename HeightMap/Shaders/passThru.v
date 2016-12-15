#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 texture;

uniform sampler2D cTexture;
uniform mat4 mTransform;
out vec2 textCoor;

float luminosity (vec3 color) {
	return (0.49*color.r + 0.50*color.g + 0.14*color.b);
}

void main()
{
	vec4 newPos=vPosition;
	newPos.y = 5.0*luminosity(texture(cTexture, texture).rgb);
	textCoor = texture;
	gl_Position = mTransform * newPos;
}
