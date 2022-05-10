#pragma once

namespace Eavan
{
	/**
	*
	* @brief Smart Ptr
	* @details 직접 여러가지 Smart Ptr을 구현해보고 각 방식의 장단점을 파악하기 위한 내용입니다.
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/

	template <class C = EBase>
	class E_F_DLL EPtr
	{
	public:
		explicit EPtr(C* _ptr);
		~EPtr();

	private:
		EBase* m_ptr;
	};
}

