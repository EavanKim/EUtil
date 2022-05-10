#pragma once

namespace Eavan
{
	/**
	*
	* @brief 할당자 클래스
	* @details 할당 방식에 대한 탐색을 위해 만들어놓는 객체. 기본적으로 Windows Heap 사용
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/

	template<typename T>
	class EAllocator
	{
	public:
		explicit EAllocator();
		explicit EAllocator(const EAllocator<T>& _allocator);

		virtual ~EAllocator();

		T* allocate(const T*& _ptr = nullptr);
		void reallocate(size_t _count, const T*& _ptr);
		void delocate(T* _ptr, size_t _count = 1);

		void CheckThreadVaildation(EBOOL& _IsOK);
		void CheckMemoryVaildation(T* _ptr, EBOOL& _IsOK);

	private:
		EVINT64 m_memorySize = 0;
		EVINT64 m_allocCount = 0;
		EVINT64 m_threadID = 0;
		HANDLE m_heap = INVALID_HANDLE_VALUE;
	};

	template<typename T>
	EAllocator<T>::EAllocator()
		: m_heap(INVALID_HANDLE_VALUE)
		, m_memorySize(0)
		, m_allocCount(0)
		, m_threadID(GetCurrentThreadId())
	{
		m_heap = HeapCreate(0, sizeof(T) * 10, sizeof(T) * 1024);
		if (m_heap == INVALID_HANDLE_VALUE || m_heap == NULL)
		{
			throw EException();
		}
	}

	template<typename T>
	EAllocator<T>::EAllocator(const EAllocator<T>& _allocator)
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

	template<typename T>
	EAllocator<T>::~EAllocator()
	{
		HeapDestroy(m_heap);
	}

	template<typename T>
	inline T* EAllocator<T>::allocate(const T*& _ptr)
	{
		_ptr = static_cast<T*>(HeapAlloc(m_heap, 0, sizeof(T)));
		return _ptr;
	}

	template<typename T>
	void EAllocator<T>::reallocate(size_t _count, const T*& _ptr)
	{
		_ptr = HeapReAlloc(m_heap, 0, _ptr, _count * sizeof(T));
	}

	template<typename T>
	inline void EAllocator<T>::delocate(T* _ptr, size_t _count)
	{
		HeapFree(m_heap, 0, _ptr);
	}

	template<typename T>
	void EAllocator<T>::CheckThreadVaildation(EBOOL& _IsOK)
	{
		DWORD GetThreadId = GetCurrentThreadId();
		if (m_threadID == GetThreadId)
			InterlockedExchange(&_IsOK, 1);
		else
			InterlockedExchange(&_IsOK, 0);
	}

	template<typename T>
	void EAllocator<T>::CheckMemoryVaildation(T* _ptr, EBOOL& _IsOK)
	{
		if (HeapValidate(m_heap, 0, _ptr))
			InterlockedExchange(&_IsOK, 1);
		else
			InterlockedExchange(&_IsOK, 0);
	}
}

