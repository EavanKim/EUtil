#pragma once

namespace Eavan
{
	class E_F_DLL EScopeLock
	{
	public:
		explicit EScopeLock(ELock& _lock);
		~EScopeLock();

	private:
		ELock& m_lock;
	};
}

