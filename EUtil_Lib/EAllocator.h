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
	class EAllocator : std::allocator<T>
	{
	public:
		template<class C>
		struct rebind 
		{
			typedef std::allocator<C> other;
		};

		explicit EAllocator();
		explicit EAllocator(const EAllocator<T>& _allocator);

		virtual ~EAllocator();

		virtual T* allocate(size_t _size, const void* _ptr = nullptr);
		virtual void delocate(void* _ptr, size_t);

	private:
		HANDLE m_heap;
	};
}

