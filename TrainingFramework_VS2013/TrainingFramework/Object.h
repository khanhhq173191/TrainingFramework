#pragma once
#include "Model.h" 
#include"Camera.h"
#include"Shaders.h"
#include"Texture.h"
#include"ResourceManager.h"
#include<vector>

using namespace std;


class Object
{
public:
	
	Shaders myShaders;
	Model* m_model;
	Texture *m_texture;
	int m_ID;

	Object();
	~Object();


	Matrix m_wvpMatrix;
	Matrix m_wMatrix;
	Matrix m_vMatrix;
	Matrix m_pMatrix;
	Matrix m_scaleMatrix;
	Matrix m_rotationMatrix;
	Matrix m_rotationXMatrix;
	Matrix m_rotationYMatrix;
	Matrix m_rotationZMatrix;
	Matrix m_translationMatrix;

	Matrix m_vScaleMatrix;
	Matrix m_vRotationMatrix;
	Matrix m_vRotationXMatrix;
	Matrix m_vRotationYMatrix;
	Matrix m_vRotationZMatrix;
	Matrix m_vTranslationMatrix;

	float m_xScale = 1.0;
	float m_yScale = 1.0;
	float m_zScale = 1.0;

	float m_xTranslation = 0.0;
	float m_yTranslation = 0.0;
	float m_zTranslation = 0.0;

	float m_xRotation = 0.0;
	float m_yRotation = 0.0;
	float m_zRotation = 0.0;

	int m_iNumMoldel;
	int m_iNumTexture;
	int m_iNumShaders;
	int m_iNumCubeTexture;
	void Init(Matrix view, int ID);
	
	void Update(float detalTime, Matrix view);
	void Scale(float x);
	void Translation(float x,float y, float z);
	void Rotation(float x, float y, float z);
	void wvpMatrix();
	void set_perspective();
	void Render();

};

