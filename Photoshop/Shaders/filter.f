#version 430 core
//Copyright (c) 2012, Romain Dura romain@shazbits.com
uniform sampler2D bTexture;
uniform sampler2D cTexture;
out vec4 fColor;
in vec2 textCoor;

vec4 Negative(vec3 color, float Negative)
{
	vec3 negative = vec3(0.5, 0.5, 0.5);
	vec3 gray = vec3(dot(negative, negative));
	return vec4(mix(color, gray, Negative), 1.0);
}

void main()
{
	vec4 texel = texture(bTexture,textCoor);
	vec4 texel2= texture(cTexture,textCoor);
    fColor = mix(texel,texel2,1.00f);
	fColor=Negative(fColor.rgb, 2.0f);
}
