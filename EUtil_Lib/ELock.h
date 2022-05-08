#pragma once

namespace Eavan
{
	class ELock
	{
	public:
		explicit ELock();
		~ELock();

		void Lock();
		EBOOL TryLock();
		void Release();

	private:
		CRITICAL_SECTION m_lock;
	};
}

