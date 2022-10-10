#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Array
{
private:
	T* m_array;
	
	int m_maxSize;
	int m_growSize;
	int m_numElements;

	bool Expand() 
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[m_maxSize * m_maxSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = nullptr;

		m_maxSize += m_maxSize;

		return true;
	}

public:
	Array(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)	
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];		
			memset(m_array, 0, sizeof(T) * m_maxSize);	

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~Array()
	{
		if (m_array != nullptr)
		{
			cout << "\n\tDestructor called." << endl;
			delete[] m_array;
			m_array = nullptr;
		}
	}
	
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;	
		}
	}
	
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			return;	
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)	
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}

	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	
	void clear()
	{
		m_numElements = 0;	 
	}
	
	int GetSize()
	{
		return m_numElements;
	}

	int GetMaxSize()
	{
		return m_maxSize;
	}

	int GetGrowSize()
	{
		return m_growSize;
	}

	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

};