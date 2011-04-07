/***************************************************************
 * Name:      GraphBitStreamerApp.h
 * Purpose:   Defines Application Class
 * Author:    Pavlovets Ilia (steelrat@list.ru)
 * Created:   2010-10-19
 * Copyright: Pavlovets Ilia (www.old-games.ru)
 * License:
 **************************************************************/

#ifndef GRAPHBITSTREAMERAPP_H
#define GRAPHBITSTREAMERAPP_H

#include <wx/app.h>

class GraphBitStreamerApp : public wxApp
{
    public:
        virtual bool OnInit();
        //
        int FilterEvent(wxEvent& event);
        //
        wxFrame* mFrame;
};

#endif // GRAPHBITSTREAMERAPP_H
