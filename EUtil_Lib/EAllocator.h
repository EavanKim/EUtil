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
	class E_F_DLL EAllocator
	{
	public:
		explicit EAllocator();
		explicit EAllocator(const EAllocator<T>& _allocator);

		virtual ~EAllocator();

		T* allocate(size_t _size, const T* _ptr = nullptr);
		void reallocate(size_t _size, const T* _ptr);
		void delocate(T* _ptr, size_t);

		void CheckThreadVaildation(EBOOL& _IsOK);
		void CheckMemoryVaildation(T* _ptr, EBOOL& _IsOK);

	private:
		EVINT64 m_memorySize = 0;
		EVINT64 m_allocCount = 0;
		EVINT64 m_threadID = 0;
		HANDLE m_heap = INVALID_HANDLE_VALUE;
	};
}

