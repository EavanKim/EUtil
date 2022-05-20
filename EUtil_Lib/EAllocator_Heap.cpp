#include "pch.h"

namespace Eavan
{
	EAllocator_Heap::EAllocator_Heap()
		: m_heap(INVALID_HANDLE_VALUE)
	{
		m_heap = HeapCreate(0, 1024, 1024 * 1024);
		if (m_heap == INVALID_HANDLE_VALUE || m_heap == NULL)
		{
			throw 0;
		}
	}

	EAllocator_Heap::EAllocator_Heap(const EAllocator_Heap& _allocator)
		: m_heap(INVALID_HANDLE_VALUE)
		, m_memorySize(0)
		, m_allocCount(0)
		, m_threadID(GetCurrentThreadId())
	{
		if (m_heap != INVALID_HANDLE_VALUE)
		{
			HeapDestroy(m_heap);
		}
		m_heap = _allocator.m_heap;
	}

	EAllocator_Heap::~EAllocator_Heap()
	{
		HeapDestroy(m_heap);
	}

	void* EAllocator_Heap::allocate(EUINT64 _size)
	{
		return HeapAlloc(m_heap, 0, _size);
	}

	void* EAllocator_Heap::allocate(EUINT64 _size, void** _ptr)
	{
		*_ptr = HeapAlloc(m_heap, 0, _size);
		return *_ptr;
	}

	void EAllocator_Heap::reallocate(EUINT64 _size, void** _ptr)
	{
		*_ptr = HeapReAlloc(m_heap, 0, *_ptr, _size);
	}

	void EAllocator_Heap::delocate(void* _ptr)
	{
		HeapFree(m_heap, 0, _ptr);
	}

	void EAllocator_Heap::CheckThreadVaildation(EBOOL& _IsOK)
	{
		DWORD GetThreadId = GetCurrentThreadId();
		if (m_threadID == GetThreadId)
			InterlockedExchange(&_IsOK, 1);
		else
			InterlockedExchange(&_IsOK, 0);
	}

	void EAllocator_Heap::CheckMemoryVaildation(void* _ptr, EBOOL& _IsOK)
	{
		if (HeapValidate(m_heap, 0, _ptr))
			InterlockedExchange(&_IsOK, 1);
		else
			InterlockedExchange(&_IsOK, 0);
	}
}