uniform samplerCube u_texture;
precision mediump float;
varying vec4 v_color;
varying vec2 v_uv;
varying vec3 v_pos

void main()
{
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	//gl_FragColor = v_color;
	vec4 pos4 = vec4(v_pos,0.0);
	gl_FragColor = textureCube(pos4,v_uv);
}