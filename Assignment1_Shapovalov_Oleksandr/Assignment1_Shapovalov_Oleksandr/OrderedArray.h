#pragma once
#include <iostream>
#include <cassert>
#include "Array.h"
using namespace std;

template<class T>
class OrderedArray : public Array<int>
{
public:
	OrderedArray(int size, int growBy = 1) : Array(NULL, 0, 0, 0)
	{
		if (size)	
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];		
			memset(m_array, 0, sizeof(T) * m_maxSize);	

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~OrderedArray()
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

		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				cout << "\n\tDuplicate detected" << endl;
				exit(0);
				break;
			}
		}

		int i, k;
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		m_array[i] = val;

		m_numElements++;
	}
	
	int search(T searchKey)
	{
		assert(m_array != nullptr);

		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)	
		{
			current = (lowerBound + upperBound) >> 1;	

			if (m_array[current] == searchKey)
			{
				return current;
			}
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;	
				}
				else
				{
					upperBound = current - 1;	
				}
			}
		}

		return -1;	
	}

};