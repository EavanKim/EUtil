#include "pch.h"

namespace Eavan
{
	template<class C>
	inline EPtr<C>::EPtr(EBase* _ptr)
	{
		if (m_ptr)
		{
			m_ptr = _ptr;
		}
	}

	template<class C>
	inline EPtr<C>::~EPtr()
	{
		if (!m_ptr)
		{
			EVINT64 refCount = m_ptr->DecreaseReferenceCount();
			if (!refCount)
				delete m_ptr;

			m_ptr = nullptr;
		}
	}
}
