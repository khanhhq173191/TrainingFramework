#include "stdafx.h"
#include "ResourceManager.h"
#include<string.h>
using namespace std;
ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}
void ResourceManager::Init()
{
	char File[70];
	FILE * f;
	int id;//load id
	f = fopen("../Resources/RM.txt", "r");
	fscanf(f, "#Models: %d \n", &m_iNumModel);
	m_iModelID = new int[m_iNumModel];
	m_cModelFile = new char*[m_iNumModel];
	for (int i = 0; i < m_iNumModel; i++)
	{
		fscanf(f, "ID %d\n", &m_iModelID[i]);
		m_cModelFile[i] = new char[70];
		fscanf(f, "FILE %s \n", &File);
		strcpy(m_cModelFile[i], File);
	}
	fscanf(f, "#2D Textures: %d\n", &m_iNumTexture);
	m_iTextureID = new int[m_iNumTexture];
	m_cTextureFile = new char*[m_iNumTexture];
	for (int i = 0; i < m_iNumTexture; i++) {
		fscanf(f, "ID %d\n", &m_iTextureID[i]);
		printf("%d \n", m_iTextureID);
		m_cTextureFile[i] = new char[70];
		fscanf(f, "FILE %s \n", &File);
		strcpy(m_cTextureFile[i], File);
	}
	fscanf(f, "#Shaders: %d\n", &m_iNumShaders);
	m_iShadersID = new int[m_iNumShaders];
	m_cVSFile = new char*[m_iNumShaders];
	m_cFSFile = new char*[m_iNumShaders];
	for (int i = 0; i < m_iNumShaders; i++)
	{
		fscanf(f, "ID %d \n", &m_iShadersID[i]);
		m_cVSFile[i] = new char[70];
		m_cFSFile[i] = new char[70];
		fscanf(f, "VS %s\n", &File);
		strcpy(m_cVSFile[i] , File);
		fscanf(f, "FS %s\n", &File);
		strcpy(m_cFSFile[i] , File);
	}
}