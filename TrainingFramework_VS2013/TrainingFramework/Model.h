#pragma once


#include "../Utilities/utilities.h"
#include"Vertex.h"
#include "Shaders.h"


class Model
{
public:
	int m_ID;
	int m_iNumVertex;
	int m_iNumIntices;
	Vertex *m_vertexData ;
	int *m_inticesData;
	void Init(char* File);
	Model();
	~Model();
	void Render(Shaders myShaders);
	GLuint vboId;
	GLuint iboId;
	void Update(float deltaTime);


};

