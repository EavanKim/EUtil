#include "pch.h"

namespace Eavan
{
	EScopeLock::EScopeLock(ELock* _lock)
		: m_lock(_lock)
	{
		m_lock->Lock();
	}

	EScopeLock::EScopeLock(const EScopeLock& _lock)
	{
		m_lock = EPtr<ELock>(_lock.m_lock);
	}

	EScopeLock::~EScopeLock()
	{
		m_lock->Release();
	}
}
