#include "stdafx.h"
#include "Texture.h"
#include "Shaders.h"

Texture::Texture()
{
}


Texture::~Texture()
{
}
void Texture::Init(char* File) {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	GLint width, height, bpp;
	char *imageData = LoadTGA(File, &width, &height, &bpp);
	if (bpp == 24) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	}
	else if (bpp == 32) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D);
	//creation of shaders and program 
	

	
}

void Texture::CubeTexture(char *Left, char*Right, char* Top, char*Bottom, char*Front, char*Back)
{
	// Generate a texture object
	glGenTextures(1, &cubeTextureID);
	// Bind the texture object
	GLint width, height, bpp;
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTextureID);
	char *imageDataLeft = LoadTGA(Left , &width, &height, &bpp);
	char *imageDataRight = LoadTGA(Right, &width, &height, &bpp);
	char *imageDataTop = LoadTGA(Top, &width, &height, &bpp);
	char *imageDataBottom = LoadTGA(Bottom, &width, &height, &bpp);
	char *imageDataFront = LoadTGA(Front, &width, &height, &bpp);
	char *imageDataBack = LoadTGA(Back, &width, &height, &bpp);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataRight);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataLeft);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataTop);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataBottom);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataBack);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageDataFront);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

}
void Texture::CubeRender(Shaders myShaders)
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTextureID);
	glUniform1i(myShaders.textureCubeAttribute, 0);
}
void Texture::Render(Shaders myShaders) {
	glBindTexture(GL_TEXTURE_2D, textureID);
	glUniform1i(myShaders.unifAttribute, 0);
}
