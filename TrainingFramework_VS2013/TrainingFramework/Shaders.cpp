#include <stdafx.h>
#include "Shaders.h"

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	vertexShader = esLoadShader(GL_VERTEX_SHADER, fileVertexShader);
	if (fragmentShader == 0)
	{
		glDeleteShader(vertexShader);
		return -2;
	}
	if ( vertexShader == 0 )
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);



	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	//colorAttribute = glGetAttribLocation(program, "a_color");
	uvAttribute = glGetAttribLocation(program, "a_uv"); 
	unifAttribute = glGetUniformLocation(program, "u_texture");
	normAttribute = glGetAttribLocation(program, "a_norm");
	binormAttribute = glGetAttribLocation(program, "a_binorm");
	tgtAttribute = glGetAttribLocation(program, "a_tgt");
	wvpAttribute = glGetUniformLocation(program, "u_wvpMatrix");
	textureCubeAttribute = glGetUniformLocation(program, "u_samplerCubeMap");
	return 0;
}

Shaders::~Shaders()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}