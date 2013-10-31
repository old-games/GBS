/***************************************************************
 * Name:      GraphBitStreamerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Pavlovets Ilia (steelrat@list.ru)
 * Created:   2010-10-19
 * Copyright: Pavlovets Ilia (www.old-games.ru)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "GraphBitStreamerApp.h"
#include "GraphBitStreamerMain.h"
#include "./icons/GBS480.xpm"

IMPLEMENT_APP(GraphBitStreamerApp);

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_PARAM,  NULL, NULL, "input file", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE },
    { wxCMD_LINE_NONE }
};


bool GraphBitStreamerApp::OnInit()
{
	check_types();
	GraphBitStreamerFrame* frame = new GraphBitStreamerFrame(0L);
	mFrame = frame;
#ifndef __WXMSW__
	frame->SetIcon(wxICON(GBS0)); // To Set App Icon
#else
	wxIconBundle icons(wxICON(wxSTD_MDIPARENTFRAME));
	icons.AddIcon(wxICON(wxSTD_MDICHILDFRAME));
	icons.AddIcon(wxICON(wxSTD_FRAME));
	frame->SetIcons(icons);
#endif
	frame->Show();
	SetTopWindow(frame);

	if (wxApp::argc > 1)
	{
		wxString fname(wxApp::argv[1]);
		wxLogDebug("argv[1]: %s", fname);
		frame->LoadFromCmdLine(fname);
	}

	return true;
}



int GraphBitStreamerApp::FilterEvent(wxEvent& event)
{
			GraphBitStreamerFrame* frame = (GraphBitStreamerFrame*) mFrame;
			if ( event.GetEventType()==wxEVT_KEY_UP && frame )
				{
					wxKeyEvent ev = (wxKeyEvent&) event;
						frame->OnKeyDown( ev );
				}
			return -1;
}

