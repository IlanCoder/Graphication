#version 430 core
uniform vec3 vEye;

uniform mat4 mTransform;
uniform sampler2D bTexture;
uniform sampler2D cTexture;
out vec4 fColor;
in vec2 textCoor;
in vec4 newPos;
in vec3 lightv;

vec3 getSpecular( in vec3 light, in vec3 mat, in vec3 lightv, in vec3 Normal, in float shininess, in vec3 myPos)
{
	vec3 viewv = normalize( vEye - myPos);
	vec3 refl = normalize(reflect(vEye - lightv, Normal ));

	//specular light computation
	vec3 specular = vec3( 0.0, 0.0, 0.0 );
	if( dot(lightv, viewv) > 0.0)
	{
		specular = pow(max(0.0, dot(viewv, refl)), shininess) * light * mat;
	}
	return specular;
}

vec3 getDifusse(in vec3 light, in vec3 mat, in vec3 lightv, in vec3 Normal)
{
	return max(0.0, dot(lightv, Normal)) * mat * light;
}

vec3 getAmbient(in vec3 light, in vec3 mat)
{
	return light * mat;
}

void main()
{
	//COLORES DE LUZ Y MATERIAL
	const vec3 lA = vec3( 0.2, 0.2, 0.2 );
	const vec3 lD = vec3( 0.4, 0.4, 0.4 );
	const vec3 lS = vec3( 1.0, 1.0, 1.0 );
	const vec3 mA = vec3( 1.0, 0.2, 0.4 );
	const vec3 mD = vec3( 1.0, 0.2, 0.4 );
	const vec3 mS = vec3( 1.0, 1.0, 1.0 );
	const float fShininess = 5.0;
	mat4 matForNormals = transpose(inverse(mTransform));
	vec4 newNormal=texture(cTexture,textCoor);
	vec4 imageColor=texture(bTexture,textCoor);
	newNormal=matForNormals*newNormal;
	newNormal=normalize(newNormal);
	fColor = clamp(
			  vec4(getAmbient(lA, mA), 1.0) 
			+ vec4(getDifusse(lD, mD, lightv, newNormal.xyz), 1.0)
			+ vec4(getSpecular(lS, mS, lightv, newNormal.xyz, fShininess, newPos.xyz), 1.0)
			,0.0, 1.0)*imageColor;
}