#pragma once

#include "GLEW/glew.h"
#include <vector>
#include <sstream>
#include <cstdlib>

//void VertexBufferLayout(unsigned int index, int size, int type, bool normalized, size_t stride, const void* offset)
//{
//glVertexAttribPointer(index, size, type, normalized, stride, offset);
//	glEnableVertexAttribArray(0);
//}

enum class Type
{
	FLOAT = 0,
	INT = 1,
	UNSIGNED_INT = 2
};

struct LayoutElements
{
	int size;
	int type;
	bool normalized;
};

class VertexBufferLayout
{
private:
	std::vector<LayoutElements> mElements;
	int mCount;
	int mStride;
	int mOffset;
public:
	VertexBufferLayout() { mCount = 0; mStride = 0; mOffset = 0; }

	void AddLayout(Type type, int count, bool writeLayout = false)
	{
		static bool written = false;

		mOffset = 0;

		if (type == Type::FLOAT)
		{
			mElements.push_back({ count, GL_FLOAT, false });
			mStride += mElements.at(mCount).size * sizeof(float);
		}

		for (int i = 0; i <= mCount; i++)
		{
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, mElements.at(i).size, mElements.at(i).type, mElements.at(i).normalized, mStride, (const void*)mOffset); 
			
			if (writeLayout)
			{
				std::stringstream layout;
				if (written == false)
				{
					layout << "\t\t" << "size\t" << "type\t" << "normalized\t" << "stride\t" << "offset";
					written = true;
				}

				layout << "\n" << "layout " << i << ": " << "\t" << mElements.at(i).size;
				if (type == Type::FLOAT)
					layout << "\t" << "FLOAT\t";
				layout << mElements.at(i).normalized << "\t\t";
				layout << mStride << "\t" << mOffset << "\n";

				//layout << "layout " << i << ": size: " << mElements.at(i).size << mElements.at(i).type, mElements.at(i).normalized, mStride, (const void*)mOffset;
				printf(layout.str().c_str());
			}

			if (type == Type::FLOAT)
				mOffset += mElements.at(i).size * sizeof(float);
		}

		mCount++;
	}
};