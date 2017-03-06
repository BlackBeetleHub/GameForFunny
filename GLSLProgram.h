#pragma once
#include<string>
#include<GL\glew.h>
#include"Error.h"


class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void CompileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	void LinkShaders();
	void AddAttribute(const std::string& attributeName);
	void use();
	void unuse();
private:
	int _numAttribute;
	void CompileShaders(const std::string& filePath, GLuint id);
	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

