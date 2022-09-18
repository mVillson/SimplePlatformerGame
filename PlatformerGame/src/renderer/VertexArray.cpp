#include "VertexArray.h"

#include "GLEW/glew.h"

VertexArray::VertexArray()
	:mArrayID(0)
{

}

void VertexArray::Create()
{
	glCreateVertexArrays(1, &mArrayID);
	glBindVertexArray(mArrayID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(mArrayID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}