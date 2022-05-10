#pragma once

namespace Eavan
{
	/**
	*
	* @brief Thread Calss
	* @details Thread의 생명주기를 나타내는 클래스.
	* @author EavanKim
	* @date 2022-05-08
	* @version 0.0.1
	*
	*/

	class EThread : public EBase
	{
	public:
		explicit EThread();
		~EThread();

	private:
		virtual EINT64 Run() = 0;

		void CreateThread();
		void DestroyThread();

		HANDLE m_threadHandle = INVALID_HANDLE_VALUE;
		EVINT64 m_threadID = 0;
	};
}

