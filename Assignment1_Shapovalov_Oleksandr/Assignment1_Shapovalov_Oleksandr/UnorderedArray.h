#pragma once
#include <iostream>
#include <cassert>
#include "Array.h"
using namespace std;

template<class T>
class UnorderedArray : public Array<int>
{
public:
	UnorderedArray(int size, int growBy = 1) : Array(NULL, 0, 0, 0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	
	void push(T val)
	{
		assert(m_array != nullptr); 

		if (m_numElements >= m_maxSize)	
		{
			Expand();
		}

		m_array[m_numElements] = val;
		m_numElements++;
	}
	
	int search(T val)
	{
		assert(m_array != nullptr);

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;	
			}
		}

		return -1;
	}
	
};