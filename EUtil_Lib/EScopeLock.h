#pragma once

namespace Eavan
{
	class E_F_DLL EScopeLock
	{
	public:
		explicit EScopeLock(ELock* _lock);
		explicit EScopeLock(const EScopeLock& _lock);
		~EScopeLock();

	private:
		EPtr<ELock> m_lock = EPtr<ELock>(nullptr);
	};
}

