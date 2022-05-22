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

	CHARW* EString::UTF8_TO_UNICODE(const ECHAR* _string)
	{
		CHARW* Result = nullptr;
		if (nullptr == _string)
			return Result;

		EINT required_cch = MultiByteToWideChar(CP_UTF8, 0, _string, static_cast<EINT>(strlen(_string)), nullptr, 0);
		if (0 == required_cch)
			throw GetLastError();

		Result = new wchar_t[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(wchar_t));

		if (0 == MultiByteToWideChar(CP_UTF8, 0, _string, static_cast<EINT>(strlen(_string)), Result, required_cch + 1))
			throw GetLastError();

		return Result;
	}

	ECHAR* EString::UNICODE_TO_UTF8(const CHARW* _string)
	{
		ECHAR* Result = nullptr;
		if (nullptr == _string)
			return Result;

		EINT required_cch = WideCharToMultiByte(CP_UTF8, 0, _string, static_cast<EINT>(wcslen(_string)), nullptr, 0, nullptr, nullptr);
		if (0 == required_cch)
			throw GetLastError();

		Result = new char[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(char));

		if (0 == WideCharToMultiByte(CP_UTF8, 0, _string, static_cast<EINT>(wcslen(_string)), Result, required_cch + 1, nullptr, nullptr))
			throw GetLastError();

		return Result;
	}

	CHARW* EString::ANSI_TO_UNICORD(const ECHAR* _string)
	{
		CHARW* Result = nullptr;
		if (nullptr == _string)
			return Result;

		EINT required_cch = MultiByteToWideChar(CP_ACP, 0, _string, static_cast<EINT>(strlen(_string)), nullptr, 0);
		if (0 == required_cch)
			throw GetLastError();

		Result = new wchar_t[required_cch + 2];
		ZeroMemory(Result, (required_cch + 1) * sizeof(wchar_t));

		if (0 == MultiByteToWideChar(CP_ACP, 0, _string, static_cast<EINT>(strlen(_string)), Result, required_cch + 1))
			throw GetLastError();

		return Result;
	}

	ECHAR* EString::ANSI_TO_UTF8(const ECHAR* _string)
	{
		CHARW* ParseData = ANSI_TO_UNICORD(_string);
		CHARS* Result = nullptr;
		if (nullptr != ParseData)
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
		ZeroMemory(m_data, (m_length + 2) * sizeof(ECHAR));
		errno_t err = memcpy_s(m_data, (m_length + 2), _string, m_length);
	}

	EString::EString(ECHAR*& _string)
		: m_length(strlen(_string))
		, m_data(new ECHAR[m_length + 2])
	{
		ZeroMemory(m_data, (m_length + 2) * sizeof(ECHAR));
		errno_t err = memcpy_s(m_data, (m_length + 2), _string, m_length);
	}

	EString::~EString()
	{
		m_data = nullptr;
		m_length = 0;
	}

	const  ECHAR* EString::getData()
	{
		return m_data;
	}

	const  ECHAR* EString::operator*()
	{
		return m_data;
	}

	CHARW* EString::CreateUNICODE()
	{
		return UTF8_TO_UNICODE(m_data);
	}
	EHash EString::CreateHash()
	{
		return EHash(m_data);
	}
}
