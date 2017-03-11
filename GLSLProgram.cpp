#include "GLSLProgram.h"
#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() :_numAttribute(0),_programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}


GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::CompileShaders(const std::string & vertexShaderFilePath, const std::string & fragmentShaderFilePath)
{
	_programID = glCreateProgram();
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0) {
		FatalError("Vertex shader failed to be created!");
	}
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0) {
		FatalError("Fragment shader failed to be created!");
	}
	CompileShaders(vertexShaderFilePath, _vertexShaderID);
	CompileShaders(fragmentShaderFilePath, _fragmentShaderID);
}

void GLSLProgram::LinkShaders()
{
	

	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);
	glLinkProgram(_programID);
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int*)&isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);
		glDeleteProgram(_programID);
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);
		std::printf("%s\n", &errorLog[0]);
		FatalError("Filed to linkedShader");
	}
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::AddAttribute(const std::string & attributeName)
{
	glBindAttribLocation(_programID, _numAttribute, attributeName.c_str());
	_numAttribute++;
}

void GLSLProgram::use()
{
	glUseProgram(_programID);
	for (int i = 0; i < _numAttribute; i++) {
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < _numAttribute; i++) {
		glDisableVertexAttribArray(i);
	}
}

void GLSLProgram::CompileShaders(const std::string & filePath, GLuint id)
{
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		FatalError("Failed to open " + filePath);
	}
	std::string fileContent = "";
	std::string line;

	while (std::getline(vertexFile, line)) {
		fileContent += line + "\n";
	}
	vertexFile.close();
	const char * contentsPtr = fileContent.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);
	glCompileShader(id);
	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
		glDeleteShader(id);
		std::printf("%s\n", &errorLog[0]);
		FatalError("Vertex " + filePath +" filed to copile");
		return;
	}
}
