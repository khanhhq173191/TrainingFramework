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
	int m_ID;
};

