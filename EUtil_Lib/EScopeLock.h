#pragma once

namespace Eavan
{
	class EScopeLock
	{
	public:
		explicit EScopeLock(ELock& _lock);
		~EScopeLock();

	private:
		ELock& m_lock;
	};
}

