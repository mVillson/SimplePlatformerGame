#pragma once

class VertexBuffer
{
private:
	unsigned int mBufferID;
public:
	VertexBuffer();
	void CreateStatic(unsigned int size, const float* data);
	void CreateDynamic(unsigned int size);
	void SubData(int* offset, unsigned int size, const float* data);

	void Bind() const;
	void Unbind() const;
};

class IndexBuffer
{
private:
	unsigned int mBufferID;
	unsigned int* mIndexBuffer;
public:
	IndexBuffer();
	void CreateStatic(unsigned int size, const unsigned int* data);
	void CreateDynamic(unsigned int size);
	void SubData(int* offset, unsigned int size, const unsigned int* data);

	void Bind() const;
	void Unbind() const;
};
