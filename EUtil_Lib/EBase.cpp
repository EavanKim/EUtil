#include "pch.h"

namespace Eavan
{
	EVINT64 EBase::IncreaseReferenceCount()
	{
		InterlockedIncrement64(&m_refCount);
		return m_refCount;
	}

	EVINT64 EBase::DecreaseReferenceCount()
	{
		InterlockedDecrement64(&m_refCount);
		return m_refCount;
	}
}
