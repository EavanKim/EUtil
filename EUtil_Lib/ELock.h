#pragma once

namespace Eavan
{
	class E_F_DLL ELock
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

