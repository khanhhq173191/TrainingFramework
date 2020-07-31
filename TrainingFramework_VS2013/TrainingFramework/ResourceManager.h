#pragma once
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	char**m_cTextureFile;
	int* m_iTextureID;
	int m_iNumTexture;
	char**m_cModelFile;
	int* m_iModelID;
	int m_iNumModel;
	char**m_cVSFile;
	char**m_cFSFile;
	int* m_iShadersID;
	int m_iNumShaders;
	void Init();
};

