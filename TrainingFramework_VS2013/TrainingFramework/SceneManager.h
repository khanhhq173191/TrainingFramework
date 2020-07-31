#pragma once
#include"Object.h"
#include"ResourceManager.h"
#include<string>
#include<string.h>
#include"Camera.h"

class SceneManager
{
public:
	Object** m_obj;
	ResourceManager * m_RM;
	Camera * m_cam;

	void Render();
	int m_iNumObj;
	int* m_aObjID;
	float m_nearCam;
	float m_farCam;
	float m_fovCam;
	float m_speedCam;
	int Init();
	void Update(float deltaTime);
	SceneManager();
	~SceneManager();
};

