#pragma once

namespace Eavan
{
	/**
	*
	* @brief Smart Ptr
	* @details 직접 여러가지 Smart Ptr을 구현해보고 각 방식의 장단점을 파악하기 위한 내용입니다.
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/

	template <class C = EBase, class Allocator = EAllocator<C>>
	class EPtr
	{
	public:
		explicit EPtr();
		explicit EPtr(C* _ptr);
		explicit EPtr(EPtr<C, Allocator>& _ptr);
		~EPtr();

	private:
		void DestroyPtr();

		EBase* m_ptr;
	};

	template<class C, class Allocator>
	EPtr<C, Allocator>::EPtr()
		: m_ptr(nullptr)
	{
	}

	template<class C, class Allocator>
	EPtr<C, Allocator>::EPtr(C* _ptr)
		: m_ptr(nullptr)
	{
		if (m_ptr)
			DestroyPtr();

		m_ptr = _ptr;
		m_ptr->IncreaseReferenceCount();
	}

	template<class C, class Allocator>
	EPtr<C, Allocator>::EPtr(EPtr<C, Allocator>& _ptr)
		: m_ptr(nullptr)
	{
		if (m_ptr)
			DestroyPtr();

		m_ptr = _ptr.m_ptr;
		m_ptr->IncreaseReferenceCount();
	}

	template<class C, class Allocator>
	EPtr<C, Allocator>::~EPtr()
	{
		DestroyPtr();
	}

	template<class C, class Allocator>
	inline void EPtr<C, Allocator>::DestroyPtr()
	{
		if (m_ptr)
		{
			EVINT64 refCount = m_ptr->DecreaseReferenceCount();
			if (!refCount)
				delete m_ptr;

			m_ptr = nullptr;
		}
	}
}

