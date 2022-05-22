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
		static CHARW* UTF8_TO_UNICODE(const ECHAR* _string);
		static ECHAR* UNICODE_TO_UTF8(const CHARW* _string);
		static CHARW* ANSI_TO_UNICORD(const ECHAR* _string);
		static ECHAR* ANSI_TO_UTF8(const ECHAR* _string);

		explicit EString();
		explicit EString(const CHARS* _string);
		explicit EString(ECHAR*& _string);
		~EString();

		virtual void InitData(EPtr<EInfomation> _info) {};

		const ECHAR* getData();
		const ECHAR* operator*();

		CHARW* CreateUNICODE();
		EHash CreateHash();

	private:
		EVINT64 m_length = 0;
		ECHAR* m_data = nullptr;
	};
}

