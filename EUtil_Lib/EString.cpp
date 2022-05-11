#include "pch.h"

namespace Eavan
{
    EString EString::Printf(const wchar_t* _format, ...)
    {
        va_list args;

        va_start(args, _format);
        EINT64 size = vswprintf(nullptr, 0, _format, args);
        va_end(args);

        wchar_t* result = new wchar_t[size + 2];
        ZeroMemory(result, (size + 1) * sizeof(wchar_t));

        va_start(args, _format);
        vswprintf(result, size + 1, _format, args);
        va_end(args);

        return EString(result);
    }

    wchar_t* EString::ANSI_TO_UNICODE(const char* _string)
    {
        wchar_t* Result = nullptr;
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

    wchar_t* EString::UTF8_TO_UNICODE(const char* _string)
    {
        wchar_t* Result = nullptr;
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

    char* EString::UNICODE_TO_UTF8(const wchar_t* _string)
    {
        char* Result = nullptr;
        if (nullptr == _string)
            return Result;

        EINT required_cch = WideCharToMultiByte(CP_UTF8, 0, _string, static_cast<EINT>(wcslen(_string)), nullptr, 0, nullptr, nullptr);
        if (0 == required_cch)
            throw GetLastError();

        Result = new char[required_cch + 2];
        ZeroMemory(Result, (required_cch + 1) * sizeof(char));

        if(0 == WideCharToMultiByte(CP_UTF8, 0, _string, static_cast<EINT>(wcslen(_string)), Result, required_cch + 1, nullptr, nullptr))
            throw GetLastError();

        return Result;
    }

    EString::EString()
        : m_data(nullptr)
        , m_length(0)
    {

    }

    EString::EString(const wchar_t* _string)
        : m_length(wcslen(_string))
        , m_data(new wchar_t[m_length + 1])
    {
        ZeroMemory(*m_data, (m_length + 1) * sizeof(wchar_t));
    }

    EString::~EString()
    {
        m_data = nullptr;
        m_length = 0;
    }

    const wchar_t* EString::getData()
    {
        return *m_data;
    }

    const wchar_t* EString::operator*()
    {
        return *m_data;
    }

    char* EString::CreateUTF8()
    {
        return nullptr;
    }
}
