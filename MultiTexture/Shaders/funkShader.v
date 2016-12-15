#version 430 core

layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;
uniform vec3 myLightPosition;

out vec3 newNormal;
out vec3 lightv;
out vec4 color;
out vec4 vNewVec;

//Derivada parcial de "x"
float Dx(float x, float z) 
{
	return	2*sin(fTime*x)*-2*sin(fTime*z)+2*fTime*cos(fTime*x)*2*cos(fTime*z);
}

//Derivada parcial de "z"
float Dz(float x, float z) 
{
	return	2*sin(fTime*x)*-2*fTime*sin(fTime*z)+2*cos(fTime*x)*2*cos(fTime*z);
}

float F(float x, float z) 
{
	return 2*sin(fTime*vPosition.x)*2*cos(fTime*vPosition.z);
}

//calculamos la normal antes de aplicar transformaciones
vec3 calculateNormal (vec4 v)
{
	vec3 vt1 = vec3(1.0, Dx(v.x, v.z), 0.0);
	vec3 vt2 = vec3(0.0, Dz(v.z, v.x), 1.0);

	return cross (vt1, vt2);
}

void main()
{
	vNewVec = vPosition;
	//calculamos la altura de este vertice
	vNewVec.y = F(vNewVec.x, vNewVec.z);

	//CALCULO DE NORMALES
	vec3 normal = normalize(calculateNormal (vNewVec));
	mat4 matForNormals = transpose(inverse(mTransform));
	newNormal = normalize(matForNormals * vec4(normal, 1.0)).xyz;

	//calculo de posicion de luz
	lightv = normalize( myLightPosition - vNewVec.xyz);

	gl_Position = mTransform * vNewVec;
}