#version 430 core

uniform sampler2D bTexture;

out vec4 fColor;
in vec2 textCoor;

void main()
{
	vec4 texel = texture(bTexture,textCoor);
    fColor = texel;
}
