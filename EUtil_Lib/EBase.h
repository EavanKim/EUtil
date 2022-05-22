#pragma once

namespace Eavan
{
	/**
	*
	* @brief 기본 객체
	* @details Util을 통해 사용할 객체가 반드시 상속해야하는 최상위 객체
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/
	template <class C>
	class EPtr;
	class EInfomation;
	class E_F_DLL EBase
	{
	public:
		explicit EBase();
		virtual ~EBase();

		EVINT64 IncreaseReferenceCount();
		EVINT64 DecreaseReferenceCount();

		virtual void InitData(EPtr<EInfomation> _info) = 0;

	private:
		EVINT64 m_refCount;
	};
}

