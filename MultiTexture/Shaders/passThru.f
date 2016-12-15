#version 430 core

uniform sampler2D bTexture;
uniform sampler2D cTexture;
out vec4 fColor;
in vec2 textCoor;

void main()
{
	vec4 texel = texture(bTexture,textCoor);
	vec4 texel2 = texture(cTexture,textCoor);
    fColor = mix(texel,texel2,1.00);
}
