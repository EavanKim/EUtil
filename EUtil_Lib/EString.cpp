#include "pch.h"

namespace Eavan
{
	EString EString::Printf(const ECHAR* _format, ...)
	{
		va_list args;

		va_start(args, _format);
		EINT64 size = vsnprintf(nullptr, 0, _format, args);
		va_end(args);

		char* result = new char[size + 2];
		ZeroMemory(result, (size + 1) * sizeof(char));

		va_start(args, _format);
		vsnprintf(result, size + 1, _format, args);
		va_end(args);

		return EString(result);
	}

	EPtr<CHARW> EString::UTF8_TO_UNICODE(EPtr<ECHAR> _string)
	{
		wchar_t* Result = nullptr;
		if (_string.IsNull())
			return EPtr<CHARW>(Result);

		EINT required_cch = MultiByteToWideChar(CP_UTF8, 0, *_string, static_cast<EINT>(strlen(*_string)), nullptr, 0);
		if (0 == required_cch)
			throw GetLastError();

		Result = new wchar_t[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(wchar_t));

		if (0 == MultiByteToWideChar(CP_UTF8, 0, *_string, static_cast<EINT>(strlen(*_string)), Result, required_cch + 1))
			throw GetLastError();

		return EPtr<CHARW>(Result);
	}

	EPtr<ECHAR> EString::UNICODE_TO_UTF8(EPtr<CHARW> _string)
	{
		char* Result = nullptr;
		if (_string.IsNull())
			return EPtr<ECHAR>(Result);

		EINT required_cch = WideCharToMultiByte(CP_UTF8, 0, *_string, static_cast<EINT>(wcslen(*_string)), nullptr, 0, nullptr, nullptr);
		if (0 == required_cch)
			throw GetLastError();

		Result = new char[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(char));

		if (0 == WideCharToMultiByte(CP_UTF8, 0, *_string, static_cast<EINT>(wcslen(*_string)), Result, required_cch + 1, nullptr, nullptr))
			throw GetLastError();

		return EPtr<ECHAR>(Result);
	}

	EPtr<CHARW> EString::ANSI_TO_UNICORD( EPtr<ECHAR> _string)
	{
		wchar_t* Result = nullptr;
		if (nullptr == _string)
			return Result;

		EINT required_cch = MultiByteToWideChar(CP_ACP, 0, *_string, static_cast<EINT>(strlen(*_string)), nullptr, 0);
		if (0 == required_cch)
			throw GetLastError();

		Result = new wchar_t[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(wchar_t));

		if (0 == MultiByteToWideChar(CP_ACP, 0, *_string, static_cast<EINT>(strlen(*_string)), Result, required_cch + 1))
			throw GetLastError();

		return Result;
	}

	EPtr<ECHAR> EString::ANSI_TO_UTF8(EPtr<ECHAR> _string)
	{
		EPtr<CHARW> ParseData = ANSI_TO_UNICORD(_string);
		EPtr<CHARS> Result(nullptr);
		if (ParseData.IsNull())
		{
			Result = UNICODE_TO_UTF8(ParseData);
		}

		return Result;
	}

	EString::EString()
		: m_data(nullptr)
		, m_length(0)
	{

	}

	EString::EString(const CHARS* _string)
		: m_length(strlen(_string))
		, m_data(new ECHAR[m_length + 2])
	{
		ZeroMemory(*m_data, (m_length + 2) * sizeof(ECHAR));
		errno_t err = memcpy_s(*m_data, (m_length + 2), _string, m_length);
	}

	EString::~EString()
	{
		m_data = nullptr;
		m_length = 0;
	}

	const  EPtr<ECHAR> EString::getData()
	{
		return m_data;
	}

	const  EPtr<ECHAR> EString::operator*()
	{
		return m_data;
	}

	EPtr<CHARW> EString::CreateUNICODE()
	{
		return UTF8_TO_UNICODE(*m_data);
	}
	EHash EString::CreateHash()
	{
		return EHash(*m_data);
	}
}
