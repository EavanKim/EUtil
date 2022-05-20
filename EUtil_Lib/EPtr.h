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

	template <class C = EBase>
	class EPtr
	{
	public:
		explicit EPtr();
		explicit EPtr(C* _ptr);
		EPtr(const EPtr<C>& _ptr);
		EPtr(const EPtr<C>&& _ptr);
		~EPtr();

		C* operator*();
		C* operator->();
		void operator=(EBase* _ptr);
		void operator=(EPtr<C> _ptr);

		EBOOL IsNull();

	private:
		virtual void DestroyPtr();

		EBase* m_ptr;
	};

	template<class C>
	EPtr<C>::EPtr()
		: m_ptr(nullptr)
	{
	}

	template<class C>
	EPtr<C>::EPtr(C* _ptr)
		: m_ptr(nullptr)
	{
		m_ptr = reinterpret_cast<EBase*>(_ptr);
		m_ptr->IncreaseReferenceCount();
	}

	template<class C>
	EPtr<C>::EPtr(const EPtr<C>& _ptr)
		: m_ptr(nullptr)
	{
		m_ptr = _ptr.m_ptr;
		m_ptr->IncreaseReferenceCount();
	}

	template<class C>
	EPtr<C>::EPtr(const EPtr<C>&& _ptr)
		: m_ptr(nullptr)
	{
		m_ptr = _ptr.m_ptr;
		m_ptr->IncreaseReferenceCount();
	}

	template<class C>
	EPtr<C>::~EPtr()
	{
		DestroyPtr();
	}

	template<class C>
	inline C* EPtr<C>::operator*()
	{
		return reinterpret_cast<C*>(m_ptr);
	}

	template<class C>
	inline C* EPtr<C>::operator->()
	{
		return reinterpret_cast<C*>(m_ptr);
	}

	template<class C>
	inline void EPtr<C>::operator=(EBase* _ptr)
	{
		DestroyPtr();

		m_ptr = _ptr;

		if (nullptr != m_ptr)
			m_ptr->IncreaseReferenceCount();
	}

	template<class C>
	inline void EPtr<C>::operator=(EPtr<C> _ptr)
	{
		DestroyPtr();

		m_ptr = reinterpret_cast<EBase*>(*_ptr);

		if (nullptr != m_ptr)
			m_ptr->IncreaseReferenceCount();
	}

	template<class C>
	inline void EPtr<C>::DestroyPtr()
	{
		if (nullptr != m_ptr)
		{
			EVINT64 refCount = m_ptr->DecreaseReferenceCount();
			if (!refCount)
				delete m_ptr;

			m_ptr = nullptr;
		}
	}

	template<class C>
	inline EBOOL EPtr<C>::IsNull()
	{
		EBOOL result = 0;

		if (nullptr == m_ptr)
			InterlockedExchange(&result, 1);

		return result;
	}
}

