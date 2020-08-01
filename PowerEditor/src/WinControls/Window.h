// This file is part of Notepad++ project
// Copyright (C)2020 Don HO <don.h@free.fr>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// Note that the GPL places important restrictions on "derived works", yet
// it does not provide a detailed definition of that term.  To avoid
// misunderstandings, we consider an application to constitute a
// "derivative work" for the purpose of this license if it does any of the
// following:
// 1. Integrates source code from Notepad++.
// 2. Integrates/includes/aggregates Notepad++ into a proprietary executable
//    installer, such as those produced by InstallShield.
// 3. Links to a library or executes a program that does any of the above.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#pragma once
#include "NppPlatform.h"
#ifdef NPP_PLATFORM_WINDOWS
#include <windows.h>
#endif

class Window
{
public:
	//! \name Constructors & Destructor
	//@{
	Window() = default;
	Window(const Window&) = delete;
	virtual ~Window() = default;
	//@}


	virtual void init(HINSTANCE hInst, HWND parent)
	{
		_hInst = hInst;
		_hParent = parent;
	}

	virtual void destroy() = 0;

	virtual void display(bool toShow = true) const
	{
#ifdef NPP_PLATFORM_WINDOWS
		::ShowWindow(_hSelf, toShow ? SW_SHOW : SW_HIDE);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::display";
#endif
	}


	virtual void reSizeTo(RECT & rc) // should NEVER be const !!!
	{
#ifdef NPP_PLATFORM_WINDOWS
		::MoveWindow(_hSelf, rc.left, rc.top, rc.right, rc.bottom, TRUE);
		redraw();
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::reSizeTo";
#endif
	}


	virtual void reSizeToWH(RECT& rc) // should NEVER be const !!!
	{
#ifdef NPP_PLATFORM_WINDOWS
		::MoveWindow(_hSelf, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);
		redraw();
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::reSizeToWH";
#endif
	}


	virtual void redraw(bool forceUpdate = false) const
	{
#ifdef NPP_PLATFORM_WINDOWS
		::InvalidateRect(_hSelf, nullptr, TRUE);
		if (forceUpdate)
			::UpdateWindow(_hSelf);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::redraw";
#endif
	}


    virtual void getClientRect(RECT & rc) const
	{
#ifdef NPP_PLATFORM_WINDOWS
		::GetClientRect(_hSelf, &rc);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::getClientRect";
#endif
	}

	virtual void getWindowRect(RECT & rc) const
	{
#ifdef NPP_PLATFORM_WINDOWS
		::GetWindowRect(_hSelf, &rc);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::getWindowRect";
#endif
	}

	virtual int getWidth() const
	{
#ifdef NPP_PLATFORM_WINDOWS
		RECT rc;
		::GetClientRect(_hSelf, &rc);
		return (rc.right - rc.left);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::getWidth";
		return 100;
#endif
	}

	virtual int getHeight() const
	{
#ifdef NPP_PLATFORM_WINDOWS
		RECT rc;
		::GetClientRect(_hSelf, &rc);
		if (::IsWindowVisible(_hSelf) == TRUE)
			return (rc.bottom - rc.top);
		return 0;
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::getHeight";
		return 100;
#endif
	}

	virtual bool isVisible() const
	{
#ifdef NPP_PLATFORM_WINDOWS
		return (::IsWindowVisible(_hSelf) ? true : false);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::isVisible";
		return true;
#endif
	}

	HWND getHSelf() const
	{
		return _hSelf;
	}

	HWND getHParent() const {
		return _hParent;
	}

	void getFocus() const {
#ifdef NPP_PLATFORM_WINDOWS
		::SetFocus(_hSelf);
#else
		// ADDLINUX
		std::cout << "ADDLINUX Window::getFocus";
#endif
	}

    HINSTANCE getHinst() const
	{
		//assert(_hInst != 0);
		return _hInst;
	}


	Window& operator = (const Window&) = delete;


protected:
	HINSTANCE _hInst = NULL;
	HWND _hParent = NULL;
	HWND _hSelf = NULL;
};