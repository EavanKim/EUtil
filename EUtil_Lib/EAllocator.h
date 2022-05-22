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

	class E_F_DLL EAllocator
	{
	public:
		explicit EAllocator()
			: m_memorySize(0)
			, m_allocCount(0)
			, m_threadID(GetCurrentThreadId())
		{

		}

		explicit EAllocator(const EAllocator& _allocator)
			: m_memorySize(0)
			, m_allocCount(0)
			, m_threadID(GetCurrentThreadId())
		{

		}

		virtual ~EAllocator() {}

		virtual void* allocate(EUINT64 _size) = 0;
		virtual void* allocate(EUINT64 _size, void** _ptr) = 0;
		virtual void reallocate(EUINT64 _size, void** _ptr) = 0;
		virtual void delocate(void* _ptr) = 0;

		virtual void CheckThreadVaildation(EBOOL& _IsOK) = 0;
		virtual void CheckMemoryVaildation(void* _ptr, EBOOL& _IsOK) = 0;

	protected:
		EVINT64 m_memorySize = 0;
		EVINT64 m_allocCount = 0;
		EVINT64 m_threadID = 0;
	};
}

