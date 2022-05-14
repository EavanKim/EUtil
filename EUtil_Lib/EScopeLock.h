#pragma once

namespace Eavan
{
	class E_F_DLL EScopeLock
	{
	public:
		explicit EScopeLock(ELock* _lock);
		~EScopeLock();

	private:
		EPtr<ELock> m_lock;
	};
}

