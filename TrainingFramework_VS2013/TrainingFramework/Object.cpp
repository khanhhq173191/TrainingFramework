#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Object.h"
#include "Model.h"
#include"Globals.h"


void Object::Init(Matrix view, int ID) {
	m_ID = ID;
	this->m_wMatrix.SetZero();
	m_translationMatrix.SetTranslation(m_xTranslation, m_yTranslation, m_zTranslation);
	m_scaleMatrix.SetScale(m_xScale, m_yScale, m_zScale);
	m_rotationXMatrix.SetRotationX(m_xRotation);
	m_rotationYMatrix.SetRotationY(m_yRotation);
	m_rotationZMatrix.SetRotationZ(m_zRotation);
	m_rotationMatrix = m_rotationZMatrix * m_rotationXMatrix * m_rotationYMatrix;
	m_vMatrix = view;
	set_perspective();
	m_wMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	m_wvpMatrix = m_wMatrix * m_vMatrix * m_pMatrix;

}


Object::Object()
{

}


Object::~Object()
{
}

void Object::Update(float detalTime, Matrix view)
{	
	m_vMatrix = view;
	m_wvpMatrix = m_wMatrix * m_vMatrix * m_pMatrix;
	glUniformMatrix4fv(myShaders.wvpAttribute, 1, GL_FALSE, (GLfloat*)m_wvpMatrix.m);
	m_model->Update(detalTime);
}
void Object::Scale(float x) {
	m_xScale += x;
	m_yScale += x;
	m_zScale += x;
	wvpMatrix();
}
void Object::Translation(float x, float y, float z)
{
	m_xTranslation += x;
	m_xTranslation += y;
	m_xTranslation += z;
	wvpMatrix();
	
}
void Object::Rotation(float x, float y, float z) {
	m_xRotation += x;
	m_yRotation += y;
	m_zRotation += z;
	wvpMatrix();
}
void Object::wvpMatrix() {
	m_translationMatrix.SetTranslation(m_xTranslation, m_yTranslation, m_zTranslation);
	m_scaleMatrix.SetScale(m_xScale, m_yScale, m_zScale);
	m_rotationXMatrix.SetRotationX(m_xRotation);
	m_rotationYMatrix.SetRotationY(m_yRotation);
	m_rotationZMatrix.SetRotationZ(m_zRotation);
	m_rotationMatrix = m_rotationZMatrix * m_rotationXMatrix * m_rotationYMatrix;
	m_wMatrix = m_scaleMatrix * m_rotationMatrix * m_translationMatrix;
	this->m_wvpMatrix = m_wMatrix * m_vMatrix * m_pMatrix;
}
void Object::set_perspective() {
	float nearPlane = 0.5;
	float farPlane = 100.0f;
	float aspect = Globals::screenWidth / Globals::screenHeight;
	float fov = 1.0f;
	m_pMatrix.SetPerspective(fov, aspect, nearPlane, farPlane);
}
void Object::Render() {
	glUseProgram(myShaders.program);
	glUniformMatrix4fv(myShaders.wvpAttribute, 1, GL_FALSE, (GLfloat*)m_wvpMatrix.m);
	m_model->Render(myShaders);
	for (int i = 0; i < m_iNumTexture; i++) {
		m_texture[i].Render(myShaders);
	}
	glDrawElements(GL_TRIANGLES, m_model->m_iNumIntices, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//m_texture->Render(myShaders);
}