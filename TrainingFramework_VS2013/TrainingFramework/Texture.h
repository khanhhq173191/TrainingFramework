#pragma once
#include "stdafx.h"
#include "../Utilities/utilities.h"
#include<string.h>
#include<vector>
#include"Shaders.h"

class Texture
{
public:
	Texture();
	~Texture();
	void Init(char *File );
	void Render(Shaders myShaders);
	GLuint textureID;
	GLuint cubeTextureID;
	int m_ID;
	void CubeTexture(char *Left, char*Right,char* Top, char*Bottom,char*Front, char*Back);
	void CubeRender(Shaders myShaders);
};

