#version 430 core

uniform sampler2D bTexture;
uniform sampler2D cTexture;
out vec4 fColor;
in vec2 textCoor;

void main()
{
	vec3 texel = texture(bTexture,textCoor).xyz;
	texel=sqrt(texel.x*texel.x+texel.y*texel.y+texel.z*texel.z);
    fColor = texel;
}
