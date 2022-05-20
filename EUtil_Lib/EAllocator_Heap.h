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

	class EAllocator_Heap : public EAllocator
	{
	public:
		explicit EAllocator_Heap();
		explicit EAllocator_Heap(const EAllocator_Heap& _allocator);

		virtual ~EAllocator_Heap();

		virtual void* allocate(EUINT64 _size);
		virtual void* allocate(EUINT64 _size, void** _ptr = nullptr);
		virtual void reallocate(EUINT64 _size, void** _ptr);
		virtual void delocate(void* _ptr);

		virtual void CheckThreadVaildation(EBOOL& _IsOK);
		virtual void CheckMemoryVaildation(void* _ptr, EBOOL& _IsOK);

	private:
		HANDLE m_heap = INVALID_HANDLE_VALUE;
	};
}

