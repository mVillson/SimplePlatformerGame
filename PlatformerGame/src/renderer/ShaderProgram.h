#pragma once

#include <string>

struct ShaderSource
{
	std::string vertexShaderSource;
	std::string fragmentShaderSource;
};

class ShaderProgram
{
private:
	unsigned int mProgramID = 0;
	ShaderSource shaderSrc;
public:
	ShaderProgram()
	{
		mProgramID = 0;
	}
	void Create(const std::string& vsFilePath, const std::string& fsFilePath);
	void Bind() const;
	void Unbind() const;
};