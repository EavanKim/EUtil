#include "pch.h"

namespace Eavan
{
	ELock::ELock()
	{
		m_lock = new CRITICAL_SECTION();
		InitializeCriticalSection(m_lock);
	}

	ELock::ELock(const ELock& _lock)
		: m_lock(_lock.m_lock)
	{
	}

	ELock::~ELock()
	{
		DeleteCriticalSection(m_lock);
	}

	void ELock::Lock()
	{
		EnterCriticalSection(m_lock);
	}

	EBOOL ELock::TryLock()
	{
		EBOOL result = TryEnterCriticalSection(m_lock);
		return result;
	}

	void ELock::Release()
	{
		LeaveCriticalSection(m_lock);
	}
}
