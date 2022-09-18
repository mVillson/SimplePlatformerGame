#pragma once

class VertexArray
{
private:
	unsigned int mArrayID;
public:
	VertexArray();
	void Create();
	void Bind() const;
	void Unbind() const;
};