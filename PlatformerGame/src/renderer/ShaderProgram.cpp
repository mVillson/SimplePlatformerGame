#include "ShaderProgram.h"

#include "GLEW/glew.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string src;
std::string FileToString(const std::string& filePath)
{
	std::fstream file(filePath);

	std::string line;
	std::stringstream ss;
	while (std::getline(file, line))
	{
		ss << line << "\n";
	}

	src = ss.str();
	return src;
}

void ShaderProgram::Create(const std::string& vsFilePath, const std::string& fsFilePath)
{
	shaderSrc.vertexShaderSource = FileToString(vsFilePath);
	shaderSrc.fragmentShaderSource = FileToString(fsFilePath);
	
	const char* vsSrc = shaderSrc.vertexShaderSource.c_str();
	const char* fsSrc = shaderSrc.fragmentShaderSource.c_str();

	mProgramID = glCreateProgram();

	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vsSrc, nullptr);
	glCompileShader(vs);
	glAttachShader(mProgramID, vs);

	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fsSrc, nullptr);
	glCompileShader(fs);
	glAttachShader(mProgramID, fs);

	glLinkProgram(mProgramID);
	glUseProgram(mProgramID);
}

void ShaderProgram::Bind() const
{
	glUseProgram(mProgramID);
}

void ShaderProgram::Unbind() const
{
	glUseProgram(0);
}