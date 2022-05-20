#pragma once

namespace Eavan
{
	/**
	*
	* @brief 문자열 처리 클래스
	* @details 라이브러리 형태로 빼내는 문자열은 std를 사용할 경우 proxy등에서 문제가 날 수 있으므로 별도로 문자열 클래스 생성
	* @author EavanKim
	* @date 2022-04-28
	* @version 0.0.1
	*
	*/

	class EHash;
	class E_F_DLL EString
	{
	public:
		static EString Printf(const ECHAR* _format, ...);
		static EPtr<CHARW> UTF8_TO_UNICODE(const EPtr<ECHAR> _string);
		static EPtr<ECHAR> UNICODE_TO_UTF8(const EPtr<CHARW> _string);
		static EPtr<CHARW> ANSI_TO_UNICORD(const EPtr<ECHAR> _string);
		static EPtr<ECHAR> ANSI_TO_UTF8(const EPtr<ECHAR> _string);

		explicit EString();
		explicit EString(const CHARS* _string);
		explicit EString(EPtr<ECHAR>& _string);
		~EString();

		const EPtr<ECHAR> getData();
		const EPtr<ECHAR> operator*();

		EPtr<CHARW> CreateUNICODE();
		EHash CreateHash();

	private:
		EVINT64 m_length = 0;
		EPtr<ECHAR> m_data = EPtr<ECHAR>(nullptr);
	};
}

