#ifndef SCROLLED_H_INCLUDED
#define SCROLLED_H_INCLUDED
#include <wx/scrolwin.h>

class ScrolledImageComponent : public wxScrolledWindow
{

private:

    wxBitmap* bitmap;
    int width, height;
    int scale;
    bool grid;
    int corrX;
    int corrY;
    bool mShowCorr;
    bool mInvertGrid;

public:
    ScrolledImageComponent(wxWindow* parent, wxWindowID id, wxBitmap *bmp = NULL, int w = 0, int h = 0);


    void setOnlyBitmap(wxBitmap *bmp)
    {
        bitmap = bmp;
    }

    void setBitmap(wxBitmap *bmp, int w, int h)
    {
        width = w;
        height = h;
        bitmap = bmp;
        /* init scrolled area size, scrolling speed, etc. */
        SetScrollbars(1,1, w, h, 0, 0);

    }

    void setScale(int s)
    {
        scale = s;
        SetVirtualSize( width * scale, height * scale);
        SetScrollRate( scale, scale );
        Refresh();
    }

    void setInvert(bool i)
    {
        mInvertGrid = i;
        Refresh();
    }

    void setGrid(bool g)
    {
        grid = g;
        Refresh();
    }
    void SetCorrXY(int x, int y);

    ~ScrolledImageComponent()
    {
    }
    void OnDraw(wxDC& dc);
};

#endif // SCROLLED_H_INCLUDED
