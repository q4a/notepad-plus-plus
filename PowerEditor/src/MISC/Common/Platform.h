#pragma once

#if defined(_WIN32)
#define NPP_PLATFORM_WINDOWS
#elif defined(__linux__)
#define NPP_PLATFORM_LINUX
#else
#error Unsupported platform
#endif

#ifndef NPP_PLATFORM_WINDOWS

#include <QtWidgets>

typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned int UINT;
typedef wchar_t TCHAR, *PTCHAR;
typedef char* PTSTR, LPTSTR;
typedef const char* LPCTSTR;
typedef const wchar_t* LPCWSTR;

typedef QWidget HWND;
typedef QRgb COLORREF;
typedef QLocale _locale_t;

// ADDLINUX
typedef char HINSTANCE;

#define TEXT(quote) L##quote
//#define wsprintf sprintf

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

#include <iostream>
inline void OutputDebugString(const wchar_t *str) // for linux debugger
{
    std::cerr << str;
}

#endif
