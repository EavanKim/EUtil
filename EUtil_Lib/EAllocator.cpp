#include "pch.h"

namespace Eavan
{
	template<typename T>
	EAllocator<T>::EAllocator()
		: std::allocator<T>()
		, m_heap(INVALID_HANDLE_VALUE)
	{
		m_heap = HeapCreate(0, sizeof(T) * 10, sizeof(T) * 1024);
		if (m_heap == INVALID_HANDLE_VALUE || m_heap == NULL)
		{
			throw EException();
		}
	}

	template<typename T>
	EAllocator<T>::EAllocator(const EAllocator<T>& _allocator)
		: std::allocator<T>()
		, m_heap(INVALID_HANDLE_VALUE)
	{
		if (m_heap != INVALID_HANDLE_VALUE)
		{
			HeapDestroy(m_heap);
		}
		m_heap = _allocator.m_heap;
	}

	template<typename T>
	EAllocator<T>::~EAllocator()
	{
		HeapDestroy(m_heap);
	}

	template<typename T>
	inline T* EAllocator<T>::allocate(size_t _size, const void* _ptr)
	{
		T* result = static_cast<T*>(HeapAlloc(m_heap, 0, _size));
		return result;
	}

	template<typename T>
	inline void EAllocator<T>::delocate(void* _ptr, size_t)
	{
		HeapFree(m_heap, 0, _ptr);
	}
}