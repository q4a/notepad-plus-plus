#pragma once

#if defined(_WIN32)
#define NPP_PLATFORM_WINDOWS
#elif defined(__linux__)
#define NPP_PLATFORM_LINUX
#else
#error Unsupported platform
#endif

#if defined(_M_IX86) || defined(__i386__) || defined(_X86_)
#define NPP_ARCHITECTURE_X86
#elif defined(_M_X64) || defined(__amd64__) || defined(__x86_64__)
#define NPP_ARCHITECTURE_X64
#elif defined(_M_ARM) || defined(__arm__)
#define NPP_ARCHITECTURE_ARM
#elif defined (_M_ARM64) || defined(__aarch64__)
#define NPP_ARCHITECTURE_ARM64
#else
#error Unsupported architecture
#endif

#ifndef NPP_PLATFORM_WINDOWS

#include <QtWidgets>

#define WINAPI
#define CALLBACK
#define MAX_PATH PATH_MAX + 1

#if defined(XR_ARCHITECTURE_X64) || defined(XR_ARCHITECTURE_ARM64)
typedef int64_t INT_PTR;
typedef uint64_t UINT_PTR;
typedef int64_t LONG_PTR;
#else
typedef int INT_PTR;
typedef unsigned int UINT_PTR;
typedef long LONG_PTR;
#endif

typedef void* HANDLE, HGLOBAL;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM, LRESULT;
typedef long HRESULT;
typedef unsigned int UINT;
typedef long LONG;
typedef unsigned short WORD;
typedef unsigned long DWORD;

typedef wchar_t TCHAR, *PTCHAR;
typedef char* PTSTR, LPTSTR;
typedef const char* LPCTSTR;
typedef const wchar_t* LPCWSTR;

typedef long int HWND; // QWidget
typedef QRgb COLORREF;
typedef QLocale _locale_t;
typedef QBitmap HBITMAP;
typedef QPixmap HICON; // or QImage
typedef QFileDialog DLGTEMPLATE;
typedef QFileDialog OPENFILENAME;


typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

// ADDLINUX
typedef char HINSTANCE;


#define TEXT(quote) L##quote
//#define wsprintf sprintf

typedef struct
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT;

#include <iostream>
inline void OutputDebugString(const wchar_t *str) // for linux debugger
{
    std::cerr << str;
}

#endif
