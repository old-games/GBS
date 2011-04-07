#include "wx_pch.h"
#include "scrolled.h"

void ScrolledImageComponent::SetCorrXY(int x, int y)
{
    corrX = x;
    corrY = y;
}

void ScrolledImageComponent::OnDraw(wxDC& dc)
{
    if (bitmap == NULL || width == 0 || height == 0) return;
    dc.SetLogicalFunction( wxCOPY );
    wxMemoryDC temp_dc;
    temp_dc.SelectObject(*bitmap);
    int x = 0, y = 0;
    int gWidth = width * scale, gHeight = height * scale;
    dc.StretchBlit(0, 0, gWidth, gHeight, &temp_dc, 0, 0, width, height);
    if ( grid && (scale>2) )
    {
        if (mInvertGrid) dc.SetLogicalFunction( wxINVERT );
        x = 0;
        for (int xx=0; xx<=gWidth; xx+=scale)
        {
            if (mShowCorr && (x == corrX || x == corrX + 1))
                dc.SetPen(wxPen(*wxRED, 1));
            else
                dc.SetPen(wxPen(*wxBLACK, 1));
            dc.DrawLine(xx, 0, xx, gHeight);
            ++x;
        }
        y = 0;
        for (int yy=0; yy<=gHeight; yy+=scale)
        {
            if (mShowCorr && (y == corrY || y == corrY + 1))
                dc.SetPen(wxPen(*wxRED, 1));
            else
                dc.SetPen(wxPen(*wxBLACK, 1));
            dc.DrawLine(0, yy, gWidth, yy);
            ++y;

        }
    }
}
