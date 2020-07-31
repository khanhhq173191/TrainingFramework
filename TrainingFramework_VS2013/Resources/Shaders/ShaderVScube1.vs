attribute vec3 a_posL;
attribute vec3 a_norm;
//attribute vec3 a_binorm;
attribute vec3 a_tgt;
attribute vec2 a_uv;
uniform mat4 u_wvpMatrix;   

varying vec2 v_uv;
varying vec4 v_color;
varying vec3 v_pos;

void main()
{

vec4 posL = u_wvpMatrix * vec4(a_posL, 1.0);
gl_Position =  posL;


//gl_Norm = vec4(a_norm, 1.0);
//gl_Binorm = vec4(a_binorm,1.0);
//gl_Tangent = vec4(a_tgt,1.0);
v_pos = a_posL;
v_uv = a_uv;
}
   