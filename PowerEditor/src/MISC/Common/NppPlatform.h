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
#define __inout
#define __cdecl

#define CP_ACP 0
#define MAX_PATH PATH_MAX + 1
#define SM_CXSCREEN 0
#define SM_CYSCREEN 1

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
typedef unsigned char BYTE;
typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef long LONG;
typedef unsigned short WORD;
typedef unsigned long DWORD;

typedef wchar_t TCHAR, *PTCHAR, *LPWSTR;
typedef char* PTSTR, LPTSTR;
typedef const char* LPCTSTR;
typedef const wchar_t* LPCWSTR;
typedef std::basic_string<TCHAR> generic_string;

typedef QColor RGB;
typedef QColor COLORREF;
typedef QLocale _locale_t;
typedef QBitmap HBITMAP;
typedef QPixmap HICON; // or QImage
typedef QFileDialog DLGTEMPLATE;
typedef QFileDialog OPENFILENAME;
typedef QToolButton TBBUTTON;
typedef QToolBar REBARBANDINFO;


#define VK_CAPITAL  Qt::Key_CapsLock
#define VK_SPACE    Qt::Key_Space
#define VK_DOWN     Qt::Key_Down
#define VK_UP       Qt::Key_Up
#define VK_LEFT     Qt::Key_Left
#define VK_RIGHT    Qt::Key_Right
#define VK_HOME     Qt::Key_Home
#define VK_END      Qt::Key_End
#define VK_PRIOR    Qt::Key_PageUp
#define VK_NEXT     Qt::Key_PageDown
#define VK_DELETE   Qt::Key_Delete
#define VK_INSERT   Qt::Key_Insert
#define VK_ESCAPE   Qt::Key_Escape
#define VK_BACK     Qt::Key_Backspace
#define VK_TAB      Qt::Key_Tab
#define VK_RETURN   Qt::Key_Return
#define VK_ADD      Qt::Key_Plus
#define VK_SUBTRACT Qt::Key_Minus
#define VK_DIVIDE   Qt::Key_Slash
#define VK_OEM_2    Qt::Key_Question // or Key_Slash (numpad_mod = QtCore.Qt.KeypadModifier, QtCore.Qt.Key_Slash and numpad_mod)
#define VK_OEM_3    Qt::Key_QuoteLeft // or Key_AsciiTilde
#define VK_OEM_4    Qt::Key_BracketLeft // or Key_BraceLeft
#define VK_OEM_5    Qt::Key_Backslash // or Key_Bar
#define VK_OEM_6    Qt::Key_BracketRight // or Key_BraceRight

// ADDLINUX
typedef char* ACCEL;
typedef char* HACCEL;
typedef char* HCURSOR;
typedef char* HFONT;
typedef char* HIMAGELIST; // QListView
typedef char* HINSTANCE;
typedef char* HMENU;
typedef char* HMODULE;
typedef char* HWND; // QWidget
typedef char* NMHDR;
//typedef char* HDC;

typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);


#define TEXT(quote) L##quote
#define lstrcmp(str1, str2) strcmp(reinterpret_cast<const char*>(str1), reinterpret_cast<const char*>(str2))
//#define wsprintf sprintf

typedef struct
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

typedef struct
{
    LONG  x;
    LONG  y;
} POINT;

typedef struct
{
    LONG        cx;
    LONG        cy;
} SIZE;

typedef struct
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

inline int MulDiv(int nNumber, int nNumerator,int nDenominator)
{
  return (int)(((long long)nNumber * (long long)nNumerator + nDenominator / 2) / nDenominator);
}

#include <iostream>
inline void OutputDebugString(const wchar_t *str) // for linux debugger
{
    std::cerr << str;
}

#endif
