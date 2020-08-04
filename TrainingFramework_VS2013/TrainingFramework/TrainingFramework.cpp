// TrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Vertex.h"
#include "Shaders.h"
#include "Globals.h"
#include <conio.h>
#include"Model.h"
#include"Object.h"
#include<math.h>
#include<iostream>
#include"SceneManager.h"
using namespace std;

bool bMoveForward, bMoveBack, bMoveRight, bMoveLeft, bRotateUp, bRotateDown, bRotateLeft, bRotateRight;
SceneManager* sce = new SceneManager();
int Init ( ESContext *esContext )
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	
	//buffer object
	sce->Init();
	//creation of shaders and program 
	return 0;
}

void Draw ( ESContext *esContext )
{
	sce->Render();

	eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

void Update ( ESContext *esContext, float deltaTime )
{
	if (bRotateUp) {
		//printf(" u \n");
		//cam->MoveBackward(deltaTime);
		sce->m_cam->RotationUp(deltaTime);
		sce->Update(deltaTime);
		bRotateUp = false;
	}

	if (bRotateDown) {
		//printf(" d \n");
		//cam->MoveForward(deltaTime);
		sce->m_cam->RotationDown(deltaTime);
		sce->Update(deltaTime);
		bRotateDown = false;
	}
	if (bRotateLeft) {
		//printf(" l \n");
		//cam->MoveLeft(deltaTime);
		sce->m_cam->RotationLeft(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bRotateLeft = false;
	}
	if (bRotateRight) {
		//printf(" r \n");
		//cam->MoverRight(deltaTime);
		sce->m_cam->RotationRight(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bRotateRight = false;
	}

	if (bMoveForward) {
		//printf(" r \n");
		//cam->MoverRight(deltaTime);
		sce->m_cam->MoveForward(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bMoveForward = false;
	}
	if (bMoveBack) {
		//printf(" r \n");
		//cam->MoverRight(deltaTime);
		sce->m_cam->MoveBackward(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bMoveBack = false;
	}
	if (bMoveLeft) {
		//printf(" r \n");
		//cam->MoverRight(deltaTime);
		sce->m_cam->MoveLeft(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bMoveLeft = false;
	}
	if (bMoveRight) {
		//printf(" r \n");
		//cam->MoverRight(deltaTime);
		sce->m_cam->MoveRight(deltaTime);
		sce->Update(deltaTime);
		//obj->Update(deltaTime, cam->m_vMatrix);
		bMoveRight = false;
	}
}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{
	if (key == VK_UP && bIsPressed && !bRotateUp) {
		bRotateUp = true;
	}
	if (key == VK_DOWN && bIsPressed && !bRotateDown) {
		bRotateDown = true;
	}
	if (key == VK_LEFT && bIsPressed && !bRotateLeft) {
		bRotateLeft = true;
	}
	if (key == VK_RIGHT && bIsPressed && !bRotateRight) {
		bRotateRight = true;
	}
	switch (key)
	{
	case 'W':bMoveForward = true;
	case 'w':bMoveForward = true;
		break;
	case 'S':bMoveBack = true;
	case 's':bMoveBack = true;
		break;
	case 'A':bMoveLeft = true;
	case 'a':bMoveLeft = true;
		break;
	case 'D':bMoveRight = true;
	case 'd':bMoveRight = true;
		break;
	}
}

void CleanUp()
{
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

