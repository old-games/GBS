/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    Pavlovets Ilia (steelrat@list.ru)
 * Created:   2010-10-19
 * Copyright: Pavlovets Ilia (www.old-games.ru)
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#ifdef __WXMSW__
#include <wx/wxprec.h>
#else
#define WX_PRECOMP
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
    // put here all your rarely-changing header files
    #include <wx/app.h>
	#include <wx/splash.h>
    #include <wx/file.h>
	#include <wx/textfile.h>
    #include <wx/mstream.h>
	#include <wx/log.h>
	#include <wx/msgdlg.h>
    #include <wx/utils.h>
	#include <wx/dcmemory.h>
	#include <wx/stdpaths.h>
	#include <wx/platinfo.h>
	#include <wx/cmdline.h>
	#include "splash.xpm"
#endif // WX_PRECOMP


typedef unsigned char		uchar;
typedef unsigned short	ushort;
typedef unsigned int		uint;

#ifdef __VISUALC__

	#define STATIC_CHECK(expr, msg) \
	typedef char ERROR_##msg[1][(expr)]

	typedef signed __int64      sint64;
	typedef unsigned __int64 	uint64;

#else

	template<int> struct CompileTimeError;
    template<> struct CompileTimeError<true> {};

	#define STATIC_CHECK(expr, msg) \
    { CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; }

	typedef int64_t 	    	sint64;
	typedef unsigned long long 	uint64;

#endif

enum Standard_Type_Sizes
{
    CHAR_SIZE    	= 1,
    SHORT_SIZE    	= 2,
    INT_SIZE    	= 4,
    INT64_SIZE    	= 8,
    VOID_SIZE    	= 4,
    VOID64_SIZE    	= 8
};

template < class To, Standard_Type_Sizes val >
void size_check( )
{
    STATIC_CHECK( sizeof(To) == val, Non_standard_type_size );
}

void check_types();
#endif // WX_PCH_H_INCLUDED
