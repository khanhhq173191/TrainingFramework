uniform samplerCube u_samplerCubeMap;
precision mediump float;

varying vec3 v_posL;

void main()
{
	vec4 pos4 = vec4(v_posL,1.0);
	gl_FragColor = textureCube(u_samplerCubeMap, pos4.xyz);
}