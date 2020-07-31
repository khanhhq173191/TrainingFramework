#include "stdafx.h"
#include "Model.h"
#include"Shaders.h"
//#include "../Utilities/utilities.h"


Model::Model()
{
	
}


Model::~Model()
{
}

void Model::Init(char*File)
{
	FILE * f;
	int id;//load id
	f = fopen(File, "r");
	fscanf(f, "NrVertices: %d\n", &this->m_iNumVertex);
	printf("%d \n", this->m_iNumVertex);
	m_vertexData = new Vertex[this->m_iNumVertex];
	for (int i = 0; i < this->m_iNumVertex; i++)
	{
		fscanf(f, "%d. pos:[%f,%f,%f]; norm:[%f,%f,%f]; binorm:[%f,%f,%f]; tgt:[%f,%f,%f]; uv:[%f,%f];\n",&id, 
			&(this->m_vertexData[i].pos.x), &(this->m_vertexData[i].pos.y), &(this->m_vertexData[i].pos.z), 
			&(this->m_vertexData[i].normal.x), &(this->m_vertexData[i].normal.y), &(this->m_vertexData[i].normal.z), 
			&(this->m_vertexData[i].binormal.x), &(this->m_vertexData[i].binormal.y), &(this->m_vertexData[i].binormal.z),
			&(this->m_vertexData[i].tangent.x), &(this->m_vertexData[i].tangent.y), &(this->m_vertexData[i].tangent.z), 
			&(this->m_vertexData[i].uv.x), &(this->m_vertexData[i].uv.y));
	}
	fscanf(f, "NrIndices: %d\n", &this->m_iNumIntices);
	m_inticesData = new int[m_iNumIntices];
	for (int i = 0; i < (m_iNumIntices / 3); i++)
	{
		fscanf(f, "%d. %d, %d, %d \n", &id, &m_inticesData[i*3], &m_inticesData[i*3 + 1], &m_inticesData[i*3 + 2]);
	}
	fclose(f);

	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*(m_iNumVertex), m_vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &iboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*(m_iNumIntices), m_inticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
}
void Model::Render(Shaders myShaders) {
	
	

	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);

	if (myShaders.positionAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.positionAttribute);
		glVertexAttribPointer(myShaders.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}
	if (myShaders.uvAttribute != -1)
	{
		glEnableVertexAttribArray(myShaders.uvAttribute);
		glVertexAttribPointer(myShaders.uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (char*)0 + sizeof(Vector3) * 4);
	}

	//glDrawArrays(GL_TRIANGLES, 0,obj->m_moldel->m_iNumVertex );

	
	
}
void Model::Update(float deltaTime) {

	//Render();
}


