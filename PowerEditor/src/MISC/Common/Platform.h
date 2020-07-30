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

typedef int32_t LONG;
typedef unsigned int UINT;
typedef wchar_t TCHAR, *PTCHAR;
typedef QWidget HWND;

#define TEXT(quote) L##quote

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

#endif
