#include "stdafx.h"
#include "SceneManager.h"
#include<string.h>


SceneManager::SceneManager()
{
}

void SceneManager::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < m_iNumObj; i ++) {
		
		m_obj[i]->Render();
	}
}

int SceneManager::Init()
{
	m_cam = new Camera();
	m_RM = new ResourceManager();
	m_RM->Init();
	int id;
	char File[70];
	FILE * f;
	int texture = 0;//đếm texture
	f = fopen("../Resources/SM.txt", "r");
	fscanf(f, "#Objects: %d \n", &m_iNumObj);
	m_obj = new Object*[m_iNumObj];
	m_aObjID = new int[m_iNumObj];
	for (int i = 0; i < m_iNumObj; i++)
	{
		m_obj[i] = new Object();
		fscanf(f, "ID %d\n", &m_aObjID[i]);
		fscanf(f, "MODEL %d\n", &m_obj[i]->m_iNumMoldel);
		fscanf(f, "TEXTURES %d \n", &m_obj[i]->m_iNumTexture);
		fscanf(f, "TEXTURE %d\n", &m_obj[i]->m_textID);
		fscanf(f, "CUBETEXTURES %d\n", &m_obj[i]->m_iNumCubeTexture);
		fscanf(f, "CUBETEX %d\n", &id);
		fscanf(f, "SHADER %d\n", &m_obj[i]->m_iNumShaders);
		fscanf(f, "POSITION %f, %f, %f\n", &m_obj[i]->m_xTranslation, &m_obj[i]->m_yTranslation, &m_obj[i]->m_zTranslation);
		fscanf(f, "ROTATION %f, %f, %f\n", &m_obj[i]->m_xRotation, &m_obj[i]->m_yRotation, &m_obj[i]->m_zRotation);
		fscanf(f, "SCALE %f, %f, %f\n", &m_obj[i]->m_xScale, &m_obj[i]->m_yScale, &m_obj[i]->m_zScale);
	}
	fscanf(f, "%s\n", &File);
	fscanf(f, "NEAR %f\n", &m_nearCam);
	fscanf(f, "FAR %f\n", &m_farCam);
	fscanf(f, "FOV %f\n", &m_fovCam);
	fscanf(f, "SPEED %f\n", &m_speedCam);
	fclose(f);
	for (int i = 0; i < m_iNumObj; i++) {
		m_obj[i]->Init(m_cam->m_vMatrix, m_aObjID[i]);
		m_obj[i]->m_model = new Model();
		for (int j = 0; j < m_RM->m_iNumModel; j++)
		{
			if (m_obj[i]->m_ID == m_RM->m_iModelID[j]) {
				m_obj[i]->m_model->Init(m_RM->m_cModelFile[j]);
			}
		}
		if (m_obj[i]->m_iNumTexture != 0) {
			m_obj[i]->m_texture = new Texture[m_obj[i]->m_iNumTexture];
			//m_obj[i]->m_texture = new Texture();
			for (int j = 0; j < m_RM->m_iNumTexture; j++)
			{
				if (m_obj[i]->m_ID == m_RM->m_iTextureID[j]) {
					m_obj[i]->m_texture[texture].Init(m_RM->m_cTextureFile[j]);
					texture++;//Bien dem texture
				}
			}
		}
		if (m_obj[i]->m_iNumCubeTexture != 0) {
			//m_obj[i]->m_texture = new Texture[6];
			char**CubeTextureName = new char*[6];
			for (int n = 0; n < 6; n++) {
				CubeTextureName[n] = new char[70];
			}
			m_obj[i]->m_texture = new Texture[1];
			for (int j = 0; j < m_RM->m_iNumTexture; j++)
			{
				if (m_obj[i]->m_ID == m_RM->m_iTextureID[j]) {
					//m_obj[i]->m_texture[texture].Init(m_RM->m_cTextureFile[j]);
					strcpy(CubeTextureName[texture], m_RM->m_cTextureFile[j]);
					texture++;//Bien dem texture
				}
			}
			m_obj[i]->m_texture[0].CubeTexture(CubeTextureName[0], CubeTextureName[1], CubeTextureName[2], CubeTextureName[3], CubeTextureName[4], CubeTextureName[5]);
		}
		texture = 0;//reset bien dem texture
		for (int j = 0; j < m_RM->m_iNumShaders; j++)
		{
			if (m_obj[i]->m_ID == m_RM->m_iShadersID[j]) {
				int a = m_obj[i]->myShaders.Init(m_RM->m_cVSFile[j], m_RM->m_cFSFile[j]);
				printf("%d \n", a);
			}
		}
	}
	glEnable(GL_DEPTH_TEST);
	return 0;
}
SceneManager::~SceneManager()
{
}
void SceneManager::Update(float deltaTime)
{
	for (int i = 0; i < m_iNumObj; i++)
	{
		m_obj[i]->Update(deltaTime, m_cam->m_vMatrix);
	}
}