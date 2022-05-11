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
	class E_F_DLL EString
	{
	public:
		static EString Printf(const wchar_t* _format, ...);
		static wchar_t* ANSI_TO_UNICODE(const char* _string);
		static wchar_t* UTF8_TO_UNICODE(const char* _string);
		static char* UNICODE_TO_UTF8(const wchar_t* _string);

		explicit EString();
		explicit EString(const wchar_t* _string);
		~EString();

		const wchar_t* getData();
		const wchar_t* operator*();
		char* CreateUTF8();

	private:
		EVINT64 m_length;
		EPtr<wchar_t> m_data;
	};
}

