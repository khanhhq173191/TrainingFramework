#include "stdafx.h"
#include "Camera.h"
#define PI 3.14

Camera::Camera()
{
	this->Init();
}


Camera::~Camera()
{
}

void Camera::Init()
{
	viewMatrix();
	m_sMatrixCam.SetIdentity();
	m_tMatrixCam.SetTranslation(m_position.x, m_position.y, m_position.z);
	m_rMatrixCam.m[0][0] = xaxis.x; m_rMatrixCam.m[0][1] = xaxis.y; m_rMatrixCam.m[0][2] = xaxis.z; m_rMatrixCam.m[0][3] = 0;
	m_rMatrixCam.m[1][0] = yaxis.x; m_rMatrixCam.m[1][1] = yaxis.y; m_rMatrixCam.m[1][2] = yaxis.z; m_rMatrixCam.m[1][3] = 0;
	m_rMatrixCam.m[2][0] = zaxis.x; m_rMatrixCam.m[2][1] = zaxis.y; m_rMatrixCam.m[2][2] = zaxis.z; m_rMatrixCam.m[2][3] = 0;
	m_rMatrixCam.m[3][0] = 0; m_rMatrixCam.m[3][1] = 0; m_rMatrixCam.m[3][2] = 0; m_rMatrixCam.m[3][3] = 1;
	m_wMatrixCam = m_sMatrixCam * m_rMatrixCam * m_tMatrixCam;
}
void Camera::RotationLeft(float angle)
{
	Matrix rotationMatrixX;
	Matrix rotationMatrixY;
	Vector4 localTarget = Vector4(0.0f, 0.0f, -(m_position - m_target).Length(), 1.0f);
	Vector4 newLocalTarget = localTarget * rotationMatrixX.SetRotationX(angleX) * rotationMatrixY.SetRotationY(angleY + angle * 1.0f);
	Vector4 worldNewTarger = newLocalTarget * m_wMatrixCam;
	m_target.x = worldNewTarger.x;
	m_target.y = worldNewTarger.y;
	m_target.z = worldNewTarger.z;
	viewMatrix();
	angleY += angle;
}
void Camera::RotationRight(float angle)
{
	Matrix rotationMatrixX;
	Matrix rotationMatrixY;
	Vector4 localTarget = Vector4(0.0, 0.0, -(m_position - m_target).Length(), 1.0);
	Vector4 newLocalTarget = localTarget * rotationMatrixX.SetRotationX(angleX) * rotationMatrixY.SetRotationY(angleY - angle*1.0f);
	Vector4 worldNewTarger = newLocalTarget * m_wMatrixCam;
	m_target.x = worldNewTarger.x;
	m_target.y = worldNewTarger.y;
	m_target.z = worldNewTarger.z;
	viewMatrix();
	angleY -= angle;
}


void Camera::RotationUp(float angle)
{
	Matrix rotationMatrixY;
	Matrix rotationMatrixX;
	Vector4 localTarget = Vector4(0.0, 0.0, -(m_position - m_target).Length(), 1.0);
	Vector4 newLocalTarget = localTarget * rotationMatrixX.SetRotationX(angleX + angle*1.0f) * rotationMatrixY.SetRotationY(angleY);
	Vector4 worldNewTarger = newLocalTarget * m_wMatrixCam;
	m_target.x = worldNewTarger.x;
	m_target.y = worldNewTarger.y;
	m_target.z = worldNewTarger.z;
	viewMatrix();
	if (angleX + angle < PI / 2) {
		angleX += angle;
	};
}

void Camera::RotationDown(float angle)
{

	Matrix rotationMatrixY;
	Matrix rotationMatrixX;
	Vector4 localTarget = Vector4(0.0, 0.0, -(m_position - m_target).Length(), 1.0);
	Vector4 newLocalTarget = localTarget * rotationMatrixX.SetRotationX(angleX - angle*1.0f) * rotationMatrixY.SetRotationY(angleY);
	Vector4 worldNewTarger = newLocalTarget * m_wMatrixCam;
	m_target.x = worldNewTarger.x;
	m_target.y = worldNewTarger.y;
	m_target.z = worldNewTarger.z;
	viewMatrix();
	//if (angleX - angle < -(PI/2)) {
		angleX -= angle;
	//};
}

void Camera::MoveLeft(float deltaTime) {
	Vector3 deltamove;
	deltamove = -xaxis*deltaTime*2.0f;
	m_position += deltamove;
	m_target += deltamove;

	viewMatrix();
}
void Camera::MoveRight(float deltaTime) {
	Vector3 deltamove;
	deltamove = xaxis*deltaTime*2.0f;
	m_position += deltamove;
	m_target += deltamove;
	viewMatrix();
	
}
void Camera::MoveForward(float deltaTime) {
	Vector3 deltamove;
	deltamove = zaxis*deltaTime*2.0f;
	m_position += deltamove;
	m_target += deltamove;
	
	viewMatrix();
}
void Camera::MoveBackward(float deltaTime) {
	Vector3 deltamove;
	deltamove = -zaxis*deltaTime*2.0f;
	m_position += deltamove;
	m_target += deltamove;
	
	viewMatrix();
}
void Camera::viewMatrix()
{
	zaxis = (m_position - m_target).Normalize();
	xaxis = (m_up.Cross(zaxis)).Normalize();
	yaxis = (zaxis.Cross(xaxis)).Normalize();
	m_T.SetTranslation(-m_position.x, -m_position.y, -m_position.z);
	m_R.m[0][0] = xaxis.x; m_R.m[0][1] = yaxis.x; m_R.m[0][2] = zaxis.x; m_R.m[0][3] = 0;
	m_R.m[1][0] = xaxis.y; m_R.m[1][1] = yaxis.y; m_R.m[1][2] = zaxis.y; m_R.m[1][3] = 0;
	m_R.m[2][0] = xaxis.z; m_R.m[2][1] = yaxis.z; m_R.m[2][2] = zaxis.z; m_R.m[2][3] = 0;
	m_R.m[3][0] = 0; m_R.m[3][1] = 0; m_R.m[3][2] = 0; m_R.m[3][3] = 1;
	m_vMatrix = m_T * m_R;
}