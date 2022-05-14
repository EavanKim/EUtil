#include "pch.h"

namespace Eavan
{
	EScopeLock::EScopeLock(ELock* _lock)
		: m_lock(_lock)
	{
		m_lock->Lock();
	}

	EScopeLock::~EScopeLock()
	{
		m_lock->Release();
	}
}
