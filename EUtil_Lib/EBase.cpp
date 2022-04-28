#include "pch.h"

namespace Eavan
{
	EBase::EBase()
	{
		InterlockedExchange64(&m_refCount, 0);
	}

	EBase::~EBase()
	{
		throw std::exception("");
	}

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
