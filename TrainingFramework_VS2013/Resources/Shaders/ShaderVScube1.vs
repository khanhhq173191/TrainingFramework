attribute vec3 a_posL;
uniform mat4 u_wvpMatrix;   

varying vec3 v_posL;

void main()
{
vec4 posL = u_wvpMatrix * vec4(a_posL, 1.0);
gl_Position =  posL;
v_posL = a_posL;
}
   