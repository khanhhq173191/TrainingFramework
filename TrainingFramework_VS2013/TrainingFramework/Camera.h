#pragma once
#include <math.h>
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include

class Camera
{
public:

	Vector3 m_up = Vector3(0.0, 1.0, 0.0);
	Vector3 m_position = Vector3(0.0, 0.0, 2.0);
	Vector3 m_target = Vector3(0.0, 0.0, 0.0);
	Matrix m_wMatrixCam;
	Matrix m_sMatrixCam;
	Matrix m_rMatrixCam;
	Matrix m_tMatrixCam;
	Vector3 zaxis;
	Vector3 xaxis;
	Vector3 yaxis;
	float speed = 0.1;
	float angleX = 0.0;
	float angleY = 0.0;
	Matrix m_vMatrix;
	Matrix m_R;
	Matrix m_T;
	Camera();
	~Camera();
	void Init();
	void MoveForward(float deltaTime);
	void MoveBackward(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);
	void RotationUp(float angle);
	void RotationDown(float angle);
	void RotationLeft(float angle);
	void RotationRight(float angle);
	void viewMatrix();
	void set_perspective();
};

