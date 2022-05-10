#pragma once

namespace Eavan
{
	/**
	*
	* @brief 자체적인 예외처리 객체
	* @details 자체적인 Log를 위해 별도 Exception을 선언하고 Log와 연동되도록 사용합니다.
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/

	class E_F_DLL EException
	{
	public:
		explicit EException();
		explicit EException(const EString& _exceptionDescript);
		explicit EException(const EString& _exceptionDescript, EVINT64 _returnCode);

	private:
		EString m_ExceptionDescription;
	};
}

