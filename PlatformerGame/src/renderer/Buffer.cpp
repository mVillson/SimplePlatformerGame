#include "Buffer.h"

#include "GLEW/glew.h"

// ---------------------------------------------------------------------
// VertexBuffer Class
// ---------------------------------------------------------------------
VertexBuffer::VertexBuffer()
	:mBufferID(0)
{
	
}

void VertexBuffer::CreateStatic(unsigned int size, const float* data)
{
	glCreateBuffers(1, &mBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
	glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
}

void VertexBuffer::CreateDynamic(unsigned int size)
{
	glCreateBuffers(1, &mBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
	glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

void VertexBuffer::SubData(int* offset, unsigned int size, const float* data)
{
	glBufferSubData(GL_ARRAY_BUFFER, (GLintptr)offset, size, &data[0]);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// ---------------------------------------------------------------------
// IndexBuffer Class
// ---------------------------------------------------------------------
IndexBuffer::IndexBuffer()
	:mBufferID(0)
{

}

void IndexBuffer::CreateStatic(unsigned int size, const unsigned int* data)
{
	glCreateBuffers(1, &mBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
}

void IndexBuffer::CreateDynamic(unsigned int size)
{
	glCreateBuffers(1, &mBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

void IndexBuffer::SubData(int* offset, unsigned int size, const unsigned int* data)
{
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, (GLintptr)offset, size, &data[0]);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}