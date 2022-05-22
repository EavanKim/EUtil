#pragma once

namespace Eavan
{
	class EBase;
	class E_F_DLL ELock : public EBase
	{
	public:
		explicit ELock();
		explicit ELock(const ELock& _lock);
		~ELock();

		void Lock();
		EBOOL TryLock();
		void Release();

		virtual void InitData(EPtr<EInfomation> _info) {};

	private:
		CRITICAL_SECTION* m_lock = nullptr;
	};
}

