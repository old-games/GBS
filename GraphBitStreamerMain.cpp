/***************************************************************
 * Name:      GraphBitStreamerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Pavlovets Ilia (steelrat@list.ru)
 * Created:   2010-10-19
 * Copyright: Pavlovets Ilia (www.old-games.ru)
 * License:
 **************************************************************/


#include "wx_pch.h"
#include "GraphBitStreamerMain.h"
#include "slstrings.h"
#include "bmpie.h"
#include "version.h"
#include "vgapal.h"

// меняет порядок байтов в слове32
inline void swap(unsigned int& x)
{
    x = (x>>24) |
        ((x>>8) & 0x0000FF00) |
        ((x<<8) & 0x00FF0000) |
        (x << 24);
}
// меняет порядок байтов в слове64
inline void swap64(uint64 &x)
{
    unsigned int x1 = (x << 32) >> 32;
    unsigned int x2 = x >> 32;
    swap(x1);
    swap(x2);
    x = x1;
    x <<= 32;
    x |= x2;
}

GraphBitStreamerFrame::GraphBitStreamerFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    mUnpackedSize = widthSlider->GetMax()*heightSlider->GetMax()*sizeof(mUnpacked[0]);
    mUnpacked=(uint64 *) malloc(mUnpackedSize);
    mImage = new ScrolledImageComponent(m_panel1, wxID_ANY);
    mImage->Connect( wxEVT_MOTION, wxMouseEventHandler( GraphBitStreamerFrame::OnOutputMotion ), NULL, this );
    mImage->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GraphBitStreamerFrame::OnOutputLeftClick), NULL, this );
    mImage->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( GraphBitStreamerFrame::OnOutputRightClick), NULL, this );
    outSizer->Add( mImage, 1, wxALL | wxEXPAND, 0 );
    Layout();
    dc=new wxClientDC(mImage);
    mOpenPal = new PalDialog(this);
    mGetHex = new HexNum(this);
    mSettings = new SettingsDlg(this);
    mImageSize = 0;
    mBitImageSize = 0;
    mBitByteSize = 0;
    mCurrentColor = 0;
    bmp = NULL;
    mCustomPal = NULL;
    mMaxColors = 256;
    mProjectName = "";
    mFileName = "";
    mRotate = 0;
    memset(mPos, 0, sizeof(Position) * MAXPOS);
	memcpy(mVgaPal, VGA_PAL, 768);
    palChoice->SetSelection(GREY2);
    SetGreyPal(16);
    PreparePalBMP();
    changed = false;
    TurnControls(false);
    wxBitmap bitmap(splash_xpm);
    wxSplashScreen* splashScreen = new wxSplashScreen(bitmap,
              wxSPLASH_CENTRE_ON_PARENT|wxSPLASH_TIMEOUT,
              6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
              wxBORDER_SIMPLE|wxSTAY_ON_TOP|wxFRAME_NO_TASKBAR);
	wxYield();
}

GraphBitStreamerFrame::~GraphBitStreamerFrame()
{
    mFile.Close();
    DeleteBMP();
    delete dc;
    delete mImage;
    free(mUnpacked);
    delete mOpenPal;
    delete mGetHex;
    delete mSettings;
}

void GraphBitStreamerFrame::updateStatus()
{
    statusBar->SetStatusText(mFileName, 0);
}

void GraphBitStreamerFrame::SetPal(unsigned char* pal)
{
    if (pal == NULL)
    {
        wxLogError("Palette is not defined!");
        return;
    }
    for (int i = 0; i < 256; i++)
    {
        red[i] = pal[i*3];
        green[i] = pal[i*3+1];
        blue[i] = pal[i*3+2];
    }

}

void GraphBitStreamerFrame::SetStandardPal()
{
    SetPal(mVgaPal);
}

void GraphBitStreamerFrame::SetGreyPal(int step)
{
    unsigned char col = 0;
    for (int i = 0; i < 256; i++)
    {
        red[i] = col;
        green[i] = col;
        blue[i] = col;
        col+=step;
    }
}

bool GraphBitStreamerFrame::OpenMainFile(wxString name)
{
    if (mFile.IsOpened()) mFile.Close();
    int mode = wxFile::read_write;
    mReadOnly = false;
    if (!mFile.Access(name, wxFile::write))
    {
        mode = wxFile::read;
        mReadOnly = true;
    }
    if (!mFile.Open(name, (wxFile::OpenMode) mode))
    {
        wxLogError("Cannot open file '%s'.", name);
        return false;
    }
    mTotalBits = mFile.Length() * 8;
    return true;
}

void GraphBitStreamerFrame::onMenuFileLoad( wxCommandEvent& event )
{
    wxFileDialog openFileDialog(this, _("Open any file"), "", "",
                           "All files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;
    if (!OpenMainFile(openFileDialog.GetPath())) return;
    TurnControls(true);
    mFileName = openFileDialog.GetPath();
    updateControls();
}

void GraphBitStreamerFrame::OnLoadState( wxCommandEvent& event )
{
    wxFileDialog openStateDialog(this, _("Open project file"), "", "",
                           "GBS files (*.GBS)|*.GBS", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openStateDialog.ShowModal() == wxID_CANCEL) return;
    wxFile tmp;
    wxString tmpString;
    if (!tmp.Open(openStateDialog.GetPath()))
        {
            wxLogError("Unable to open project: %s", openStateDialog.GetFilename());
            return;
        }
    loadString(&tmp, tmpString);
    if (!OpenMainFile(tmpString)) return;
    startSlider->SetRange(0, mFile.Length() * 8);
    startCtrl->SetRange(0, mFile.Length() * 8);
    TurnControls(true);
    unsigned int val;
    tmp.Read(&val, 4);
    bitSlider->SetValue(val);
    bitsCtrl->SetValue(val);
    tmp.Read(&val, 4);
    startSlider->SetValue(val);
    startCtrl->SetValue(val);
    tmp.Read(&val, 4);
    widthSlider->SetValue(val);
    widthCtrl->SetValue(val);
    tmp.Read(&val, 4);
    heightSlider->SetValue(val);
    heightCtrl->SetValue(val);
    tmp.Read(&val, 4);
    zoomSlider->SetValue(val);
    zoomCtrl->SetValue(val);
    tmp.Read(&val, 4);
    if (val != 0)
    {
        mOpenPal->LoadState(&tmp);
        mCustomPal = mOpenPal->getPal();
        palChoice->SetSelection(CUSTOM);
        PalChanged(event);
    }
    tmp.Read(mPos, sizeof(Position) * MAXPOS);
    mSettings->LoadState(&tmp);
    if (tmp.Read(&val, 4) != 0)
    {
        palChoice->SetSelection(val);
        PalChanged(event);
    }
    int x;
    if (tmp.Read(&x, 4) != 0)
    {
        tmp.Read(&val, 4);
        this->SetSize(x, val);
    }
    tmp.Close();
    mFileName = tmpString;
    mProjectName = openStateDialog.GetFilename();
    updateControls();

}

void GraphBitStreamerFrame::OnSaveState( wxCommandEvent& event )
{
    if (mFileName == "")
    {
        wxLogError("There are nothing to save!");
        return;
    }
    wxFileName name(mFileName);
    if (mProjectName == "") mProjectName = name.GetName()+".GBS";
    wxFileDialog saveStateDialog(this, _("Save project file"), "", mProjectName,
                           "GBS files (*.GBS)|*.GBS", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveStateDialog.ShowModal() == wxID_CANCEL) return;
    wxFile tmp;
    tmp.Create(saveStateDialog.GetPath(), true);
    saveString(&tmp, mFileName);
    unsigned int val = bitSlider->GetValue();
    tmp.Write(&val, 4);
    val = startSlider->GetValue();
    tmp.Write(&val, 4);
    val = widthSlider->GetValue();
    tmp.Write(&val, 4);
    val = heightSlider->GetValue();
    tmp.Write(&val, 4);
    val = zoomSlider->GetValue();
    tmp.Write(&val, 4);
    if (mCustomPal == NULL)
    {
        val = 0;
        tmp.Write(&val, 4);
    } else
    {
        val = 768;
        tmp.Write(&val, 4);
        tmp.Write(mCustomPal, 768);
        mOpenPal->SaveState(&tmp);
    }
    tmp.Write(mPos, sizeof(Position) * MAXPOS);
    mSettings->SaveState(&tmp);
    val = palChoice->GetSelection();
    tmp.Write(&val, 4);
    int x;
    this->GetSize(&x, (int*) &val);
    tmp.Write(&x, 4);
    tmp.Write(&val, 4);
    tmp.Close();
}

void GraphBitStreamerFrame::updateControls(bool reload)
{
    if (!mFile.IsOpened()) return;
    if (reload)
    {
        mImageSize = widthSlider->GetValue() * heightSlider->GetValue();
        mBitByteSize = (mImageSize / 8) * bitSlider->GetValue();
        mBitImageSize = mImageSize * bitSlider->GetValue();
        int max = mTotalBits - mBitImageSize;
        if (max < 0) max = 0;
        startSlider->SetRange(0, max);
        startCtrl->SetRange(0, max);
        unpack();
        PrepareBMP();
        mImage->setBitmap(bmp, widthSlider->GetValue(), heightSlider->GetValue());
    }
    mImage->setScale(zoomSlider->GetValue());
    updateStatus();
}

void GraphBitStreamerFrame::pack()
{
    unsigned char* buf = (unsigned char *) malloc(mBitByteSize+8);
    unsigned int bitPos = startSlider->GetValue();
    unsigned int seekPos = bitPos / 8;
    bitPos = bitPos % 8;
    unsigned char bitCount = bitSlider->GetValue();
    unsigned int byteCount = 0;
    memset(buf, 0, mBitByteSize + 8);
    do
    {
        unsigned int bytePos = bitPos >> 3; // div 8
        unsigned int diffPos = bitPos % 8;
        uint64* dest = (uint64 *) (buf + bytePos);  // ЭТО PACK
        uint64 code = mUnpacked[byteCount];
        uint64 op=dest[0];
        char BIT_COUNT=(64-bitCount) - diffPos;
        //
        code<<=BIT_COUNT;
        swap64(code);
        op|=code;
        dest[0]=op;
        //
        bitPos += bitCount;
        ++byteCount;
    } while (byteCount < mImageSize);
    ::wxCopyFile(mFileName, mFileName+".bak", true);
    mFile.Seek(seekPos, wxFromStart);
    mFile.Write(buf, mBitByteSize);
    free(buf);
}

void GraphBitStreamerFrame::unpack()
{
    unsigned char* buf = (unsigned char *) malloc(mBitByteSize+8);
    unsigned int bitPos = startSlider->GetValue();
    mFile.Seek(bitPos / 8, wxFromStart);
    bitPos = bitPos % 8;
    unsigned char bitCount = bitSlider->GetValue();
    unsigned int byteCount = 0;
    memset(mUnpacked, 0, mUnpackedSize);
    mFile.Read(buf, mBitByteSize+8);
    do
    {
        unsigned int bytePos = bitPos / 8;
        unsigned int diffPos = bitPos % 8;
        uint64* src = (uint64 *) (buf + bytePos);
        uint64 op=src[0];
        uint64 mask=1;
        mask <<= bitCount;
        --mask;
        char BIT_COUNT=(64-bitCount) - diffPos;
        //
        swap64(op);
        op>>=BIT_COUNT;
        op&=mask;
        //
        mUnpacked[byteCount] = op;
        bitPos += bitCount;
        ++byteCount;
    } while (byteCount < mImageSize && bitPos < mTotalBits);
    if (byteCount < mImageSize)
    {
        for (unsigned int i = byteCount; i < mImageSize; i+=2)
            mUnpacked[i] = 1;
    }
    free(buf);
}

void GraphBitStreamerFrame::Rotate(int step)
{
    int width = widthSlider->GetValue();
    int height = heightSlider->GetValue();
    int start = height - 1;
    int height_step = height;
    if (step == COUNTER_CLOCKWISE)
    {
        start = height * (width - 1);
        height_step = -height;
    }
    uint64* buf = (uint64*) malloc(mUnpackedSize);
    uint pos_out = start;
    for (uint i = 0; i < mImageSize; i++)
    {
        buf[pos_out] = mUnpacked[i];
        pos_out += height_step;
        if (pos_out >= mImageSize)
        {
            start += step;
            pos_out = start;
        }

    }
    memcpy(mUnpacked, buf, mUnpackedSize);
    free(buf);
    widthSlider->SetValue(height);
    widthCtrl->SetValue(height);
    heightSlider->SetValue(width);
    heightCtrl->SetValue(width);
    PrepareBMP();
    mImage->setBitmap(bmp, height, width);
    updateControls(false);
    if (!mReadOnly)
    {
        changed = true;
        TurnControls(false);
    }
}

void GraphBitStreamerFrame::Flip()
{
    int width = widthSlider->GetValue();
    int nwidth = -width;
    int mwidth = width << 3; // * 4
    int height = heightSlider->GetValue();
    uint64* buf = (uint64*) malloc(mUnpackedSize);
    buf += width * height;   // отступаем к последней линии
    unsigned int pos_in = 0;
    for (int i = 0; i < height; i++)
    {
        buf += nwidth;
        memcpy(buf, (mUnpacked + pos_in), mwidth);
        pos_in += width;
    }
    memcpy(mUnpacked, buf, mUnpackedSize);
    free(buf);
    PrepareBMP();
    mImage->setOnlyBitmap(bmp);
    mImage->Refresh();
    if (!mReadOnly)
    {
        changed = true;
        TurnControls(false);
    }
}

void GraphBitStreamerFrame::PrepareBMP()
{
    DeleteBMP();
    int width = widthSlider->GetValue();
    int height = heightSlider->GetValue();
    bmpdata=(unsigned char *)malloc(width * height * 3);
    memset(bmpdata, 0, width*height*3);
    unsigned char col;
    unsigned int offset = 0;
    unsigned int offset3 = 0;
    if (palChoice->GetSelection()!=TRUECOLOR)
    {
        for (int i=0; i<height; i++)
        {
            for (int j=0; j<width; j++)
            {
                col = mUnpacked[offset];
                if (col < mMaxColors)
                {
                        bmpdata[offset3] = red[col];      ++offset3;
                        bmpdata[offset3] = green[col];    ++offset3;
                        bmpdata[offset3] = blue[col];     ++offset3;
                }
                else    offset3+=3;

                ++offset;
            }
        }
    }
    else
    {
        wxColour color;
        for (uint i = 0; i < mImageSize; i++)
        {
            color.SetRGB(mUnpacked[i]);
            bmpdata[offset3] = color.Red();     ++offset3;
            bmpdata[offset3] = color.Green();   ++offset3;
            bmpdata[offset3] = color.Blue();    ++offset3;
        }
    }
    wxImage image(width, height, true );
    image.SetData(bmpdata );
    bmp = new wxBitmap( image );
}

//
bool GraphBitStreamerFrame::Quit()
{
    if (changed)
        if (wxMessageDialog(this, "Are you sure to quit?", "There are changes were made", wxYES_NO | wxNO_DEFAULT).ShowModal()==wxID_NO) return false;
    return true;
}

void GraphBitStreamerFrame::OnClose(wxCloseEvent &event)
{
    if (!Quit()) return;
    Destroy();
}

void GraphBitStreamerFrame::OnQuit(wxCommandEvent &event)
{
    if (!Quit()) return;
    Destroy();
}

void GraphBitStreamerFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(wxString::Format(wxT("Graphic Bit Streamer v%d.%d.%d\nAuthor: Ilia \"SteelRat\" Pavlovets\nwww.old-games.ru\nsteelrat@list.ru\nThanks to Black Doomer for icons\nand to wxWidgets, Code::Blocks, CodeLite, MSVS Express developers."),
        AutoVersion::MAJOR, AutoVersion::MINOR, AutoVersion::BUILD),"About...");
}

void GraphBitStreamerFrame::OnScrollChanged( wxScrollEvent& event )
{
    wxSlider* slider = (wxSlider*) event.GetEventObject();
    wxSpinCtrl* spin = getSliderTextBox(event.GetId());
    bool reload = true;
    if (event.GetId() == wxID_ZOOM_SLIDER) reload = false;
    spin->SetValue(slider->GetValue());
    updateControls(reload);
    event.Skip();
}

void GraphBitStreamerFrame::OnKeyUp( wxKeyEvent& event )
{
    wxSpinCtrl* spin = (wxSpinCtrl*) event.GetEventObject();
    wxSlider* slider = getSliderById(event.GetId());
    bool reload = true;
    if (event.GetId() == wxID_ZOOM_CTRL) reload = false;
    if (event.GetKeyCode() == WXK_RETURN)
    {
        slider->SetValue(spin->GetValue());
        updateControls(reload);
    }
    event.Skip();
}

void GraphBitStreamerFrame::OnSpinStrl( wxSpinEvent& event )
{
    wxSpinCtrl* spin = (wxSpinCtrl*) event.GetEventObject();
    wxSlider* slider = getSliderById(event.GetId());
    bool reload = true;
    if (event.GetId() == wxID_ZOOM_CTRL) reload = false;
    slider->SetValue(spin->GetValue());
    updateControls(reload);
    event.Skip();
}

wxSpinCtrl* GraphBitStreamerFrame::getSliderTextBox(int id)
{
    wxSpinCtrl* ret = NULL;
    switch (id)
    {
        case wxID_BITS_SLIDER:
            ret = bitsCtrl;
            break;
        case wxID_START_SLIDER:
            ret = startCtrl;
            break;
        case wxID_WIDTH_SLIDER:
            ret = widthCtrl;
            break;
        case wxID_HEIGHT_SLIDER:
            ret = heightCtrl;
            break;
        case wxID_ZOOM_SLIDER:
            ret = zoomCtrl;
            break;
        default: wxLogError("Unknown slider ID: %d", id);
    }
    return ret;
}

wxSlider* GraphBitStreamerFrame::getSliderById(int id)
{
    wxSlider* ret = NULL;
    switch (id)
    {
        case wxID_BITS_CTRL:
            ret = bitSlider;
            break;
        case wxID_START_CTRL:
            ret = startSlider;
            break;
        case wxID_WIDTH_CTRL:
            ret = widthSlider;
            break;
        case wxID_HEIGHT_CTRL:
            ret = heightSlider;
            break;
        case wxID_ZOOM_CTRL:
            ret = zoomSlider;
            break;
        default: wxLogError("Unknown spinCtrl ID: %d", id);
    }
    return ret;
}

void GraphBitStreamerFrame::OnPaint( wxPaintEvent& event )
{
    event.Skip();
}

void GraphBitStreamerFrame::OnGridCheck( wxCommandEvent& event )
{
    mImage->setGrid(gridCheck->IsChecked());
}

void GraphBitStreamerFrame::OnMenuPalLoad( wxCommandEvent& event )
{
    if (mOpenPal->ShowModal() != wxID_OK) return;
    mCustomPal = mOpenPal->getPal();
    palChoice->SetSelection(CUSTOM);
    PalChanged(event);
}

void GraphBitStreamerFrame::PalChanged( wxCommandEvent& event )
{
    CGACheck->Enable(false);
    mMaxColors = 256;
    switch (palChoice->GetSelection())
    {
        case EGA:
            SetPal(mVgaPal);
            mMaxColors = 16;
            break;
        case VGA:
            SetPal(mVgaPal);
            break;
        case GREY1:
            SetGreyPal(1);
            break;
        case GREY2:
            SetGreyPal(16);
            break;
        case TRUECOLOR:
            break;
        case CUSTOM:
            if (mCustomPal == NULL) OnMenuPalLoad(event);
            SetPal(mCustomPal);
            break;
        default:
            SetCGAPal(palChoice->GetSelection());
            CGACheck->Enable();
            mMaxColors = 4;
    }
    if (mCurrentColor > mMaxColors) mCurrentColor = 0;
    PreparePalBMP();
    PrepareBMP();
    mImage->setOnlyBitmap(bmp);
    Refresh();
    //palBitmap->Refresh();
}

void GraphBitStreamerFrame::SetCGAPal(int n)
{
    int light = 0;
    unsigned char root = 0;
    if (CGACheck->IsChecked()) light = LIGHT;
    red[0] = 0; green[0] = 0; blue[0] = 0;
    for (int i = 1; i < 4; i++)
    {
        root = 3 * (CGAPAL[n][i] + light);
        red[i] = mVgaPal[root];
        green[i] = mVgaPal[root + 1];
        blue[i] = mVgaPal[root + 2];
    }
}

void GraphBitStreamerFrame::PreparePalBMP()
{
    wxBitmap palBmp(128, 128);
    wxMemoryDC mdc;
	mdc.SelectObject(palBmp);
    int xx, yy, col = 0;
    wxBrush brush;
    for (int y=0; y < 16; y++)
    {
        yy = y << 3;
        for (int x=0; x < 16; x++)
        {
            if (col < mMaxColors)
            {
                brush.SetColour(wxColour(red[col], green[col], blue[col]));
                if (col == mCurrentColor)
				{
						mdc.SetPen(wxPen(*wxWHITE, 2));
				}
                else
				{
					mdc.SetPen(wxPen(*wxBLACK, 1));
				}
            } else
            {
                brush.SetColour(*wxBLACK);
                mdc.SetPen(wxPen(*wxBLACK, 1));
            }
            xx = x << 3;
            mdc.SetBrush(brush);
            mdc.DrawRectangle(xx, yy, 8, 8);
            ++col;
        }
    }
    palBitmap->SetBitmap(palBmp);
}

// РИСОВАНИЕ ЛЕВОЙ КНОПКОЙ МЫШИ
void GraphBitStreamerFrame::OnOutputLeftClick( wxMouseEvent& event )
{
    if (mReadOnly)
    {
        wxLogError("Read only mode!");
        event.Skip();
        return;
    }
    wxMouseState mState;
    bool drawed = false;
    int mx, my, dx, dy;
    int scale = zoomSlider->GetValue();
    wxColour color(red[mCurrentColor], green[mCurrentColor], blue[mCurrentColor]);
    dc->SetBrush(wxBrush(color));
    if (gridCheck->IsChecked())
        dc->SetPen(wxPen(*wxBLACK, 1));
    else
        dc->SetPen(wxPen(color, 1));
    do
    {
        mState =  wxGetMouseState  ( );
        mx = mState.GetX();
        my = mState.GetY();
        mImage->ScreenToClient(&mx, &my);
        mImage->CalcScrolledPosition(mx, my, &dx, &dy);
        dx = mx / scale;
        dy = my / scale;
        mImage->CalcUnscrolledPosition(mx, my, &mx, &my);
        px = mx / scale;
        py = my / scale;
        if (px < widthSlider->GetValue() && py < heightSlider->GetValue())
        {
            int pos = (py * widthSlider->GetValue()) + px;
            mUnpacked[pos] = mCurrentColor;
            drawed = true;
            dc->DrawRectangle(dx * scale, dy * scale, scale, scale);
        }
    }
    while (mState.LeftIsDown());
    if (drawed)
    {
        changed = true;
        PrepareBMP();
        mImage->setOnlyBitmap(bmp);
        mImage->Refresh();
        TurnControls(false);
    }
}

void GraphBitStreamerFrame::OnOutputMotion( wxMouseEvent& event )
{
    int mx, my;
    mImage->CalcUnscrolledPosition(event.GetX(), event.GetY(), &mx, &my);
    px = mx / zoomSlider->GetValue();
    py = my / zoomSlider->GetValue();
}


void GraphBitStreamerFrame::OnOutputRightClick( wxMouseEvent& event )
{
    if (px < widthSlider->GetValue() && py < heightSlider->GetValue())
    {
        int pos = (py * widthSlider->GetValue()) + px;
        mCurrentColor = mUnpacked[pos];
        PreparePalBMP();
        palBitmap->Refresh();
    }
}

void GraphBitStreamerFrame::OnPaletteClick( wxMouseEvent& event )
{
    int mx, my;
    event.GetPosition(&mx, &my);
    int col = (my >> 3 << 4) + (mx >> 3);
    if (col >= mMaxColors) return;
    mCurrentColor = col;
    PreparePalBMP();
    palBitmap->Refresh();
}

void GraphBitStreamerFrame::TurnControls(bool b)
{
    bitSlider->Enable(b);
    bitsCtrl->Enable(b);
	startSlider->Enable(b);
	startCtrl->Enable(b);
	pageLeftBtn->Enable(b);
	pageRigthBtn->Enable(b);
	lineLeftBtn->Enable(b);
	lineRightBtn->Enable(b);
	widthSlider->Enable(b);
	widthCtrl->Enable(b);
	heightSlider->Enable(b);
	heightCtrl->Enable(b);
    menuSaveState->Enable(b);
    menuImportBMP->Enable(b);
    menuExportBMP->Enable(b);
    menuExportRAW->Enable(b);
    mainToolBar->EnableTool(idMenuSaveState, b);
    mainToolBar->EnableTool(idImportBMP, b);
    mainToolBar->EnableTool(idExportBMP, b);
    mainToolBar->EnableTool(idFlipImage, b);
    mainToolBar->EnableTool(idRotateLeft, b);
    mainToolBar->EnableTool(idRotateRight, b);
    jumpBtn->Enable(b);
	if (mFileName != "")
	{
        menuSaveState->Enable(true);
        menuImportBMP->Enable(true);
        menuExportBMP->Enable(true);
        menuExportRAW->Enable(true);
        mainToolBar->EnableTool(idMenuSaveState, true);
        mainToolBar->EnableTool(idImportBMP, true);
        mainToolBar->EnableTool(idExportBMP, true);
        mainToolBar->EnableTool(idFlipImage, true);
        mainToolBar->EnableTool(idRotateLeft, true);
        mainToolBar->EnableTool(idRotateRight, true);
	}
	saveBtn->Enable(!b);
	cancelBtn->Enable(!b);
	if ((!b && mReadOnly) || mFileName == "")
	{
	    saveBtn->Enable(false);
	    cancelBtn->Enable(false);
	}
}

void GraphBitStreamerFrame::SaveChanges( wxCommandEvent& event )
{
    if (!changed) return;
    if (wxMessageDialog(this, "Are you sure to apply changes?", "Save changes?", wxYES_NO | wxNO_DEFAULT).ShowModal()==wxID_NO) return;
    pack();
    changed = false;
    updateControls();
    TurnControls(true);
}

void GraphBitStreamerFrame::CancelChanges( wxCommandEvent& event )
{
    if (!changed) return;
    if (wxMessageDialog(this, "Are you sure to cancel changes?", "Cancel changes?", wxYES_NO | wxNO_DEFAULT).ShowModal()==wxID_NO) return;
    changed = false;
    updateControls();
    TurnControls(true);
}

void GraphBitStreamerFrame::OnPrevFrame( wxCommandEvent& event )
{
    int val = startSlider->GetValue() - mBitImageSize;
    if (val < 0) val = 0;
    startSlider->SetValue(val);
    startCtrl->SetValue(val);
    updateControls();
}

void GraphBitStreamerFrame::OnPrevLine( wxCommandEvent& event )
{
    int bitWidth = widthSlider->GetValue() * bitSlider->GetValue();
    int val = startSlider->GetValue() - bitWidth;
    if (val < 0) val = 0;
    startSlider->SetValue(val);
    startCtrl->SetValue(val);
    updateControls();
}

void GraphBitStreamerFrame::OnNextLine( wxCommandEvent& event )
{
    int bitWidth = widthSlider->GetValue() * bitSlider->GetValue();
    int val = startSlider->GetValue() + bitWidth;
    if (val > startSlider->GetMax()) val = startSlider->GetMax();
    startSlider->SetValue(val);
    startCtrl->SetValue(val);
    updateControls();
}

void GraphBitStreamerFrame::OnNextFrame( wxCommandEvent& event )
{
    int val = startSlider->GetValue() + mBitImageSize;
    if (val > startSlider->GetMax()) val = startSlider->GetMax();
    startSlider->SetValue(val);
    startCtrl->SetValue(val);
    updateControls();
}

void GraphBitStreamerFrame::OnExportRAW( wxCommandEvent& event )
{
    wxFileName name(mFileName);
    wxFileDialog saveRawDialog(this, _("Save RAW file"), "", name.GetName()+".RAW",
                           "RAW files (*.RAW)|*.RAW", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveRawDialog.ShowModal() == wxID_CANCEL) return;
    int bpp = mSettings->getRAWBits();
    wxFile tmp;
    tmp.Create(saveRawDialog.GetPath(), true);
    for (uint i = 0; i < mImageSize; i++)
    {
        switch (bpp)
        {
            case  8: tmp.Write(&mUnpacked[i], 1);
                    break;
            case 16: tmp.Write(&mUnpacked[i], 2);
                    break;
            case 24: tmp.Write(&mUnpacked[i], 3);
                    break;
            case 32: tmp.Write(&mUnpacked[i], 4);
                    break;
        }

    }
    tmp.Close();
    name = saveRawDialog.GetPath();
    wxMessageBox(name.GetFullName() + wxT(" was created."));
}

void GraphBitStreamerFrame::OnExportBMP( wxCommandEvent& event )
{
    int bpp = mSettings->getBMPBits();
    if (bitSlider->GetValue() >= 8 && bitSlider->GetValue() - bpp < 0) wxMessageBox(wxString::Format("Bpp of image: %d, bpp of BMP: %d", bitSlider->GetValue(), bpp), "Warning! Loss of data!");
    wxFileName name(mFileName);
    wxFileDialog saveBmpDialog(this, _("Save BMP file"), "", name.GetName()+".BMP",
                           "BMP files (*.BMP)|*.BMP", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveBmpDialog.ShowModal() == wxID_CANCEL) return;
    BMPIE bexport(red, green, blue);
    bexport.saveBMP(mUnpacked, saveBmpDialog.GetPath(), widthSlider->GetValue(), heightSlider->GetValue(), bpp);
}

void GraphBitStreamerFrame::OnImportBMP( wxCommandEvent& event )
{
    wxFileDialog loadBmpDialog(this, _("Open BMP file"), "", "",
                           "BMP files (*.BMP)|*.BMP", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (loadBmpDialog.ShowModal() == wxID_CANCEL) return;
    BMPIE bimport(red, green, blue);
    int bpp;
    if (bimport.loadBMP(mUnpacked, loadBmpDialog.GetPath(), widthSlider->GetValue(), heightSlider->GetValue(), &bpp))
    {
        Flip();
    }
}

void GraphBitStreamerFrame::OnJumpBtn( wxCommandEvent& event )
{
    if (mGetHex->ShowModal() == wxID_CANCEL) return;
    startSlider->SetValue(mGetHex->GetNumber() * 8);
    startCtrl->SetValue(mGetHex->GetNumber() * 8);
    updateControls();
}

void GraphBitStreamerFrame::OnInvertChange( wxCommandEvent& event )
{
    mImage->setInvert(gridInvert->IsChecked());
}

void GraphBitStreamerFrame::OnFlipImage( wxCommandEvent& event )
{
    Flip();
}

void GraphBitStreamerFrame::OnRotateLeft( wxCommandEvent& event )
{
    Rotate(COUNTER_CLOCKWISE);
}

void GraphBitStreamerFrame::OnRotateRight( wxCommandEvent& event )
{
    Rotate(CLOCKWISE);
}

void GraphBitStreamerFrame::OnKeyDown( wxKeyEvent& event )
{
    int key = event.GetKeyCode() - 48;
    if (key >= 0 && key <= 9)
    {
        if (event.ControlDown() && !event.ShiftDown()) StorePos(key);
        if (event.ShiftDown() && !event.ControlDown()) RestorePos(key);
    }
    event.Skip();
}

void GraphBitStreamerFrame::StorePos(int pos)
{
    mPos[pos].bits = bitSlider->GetValue();
    mPos[pos].bitPos = startSlider->GetValue();
    mPos[pos].width = widthSlider->GetValue();
    mPos[pos].height = heightSlider->GetValue();
    mPos[pos].scale = zoomSlider->GetValue();
    mPos[pos].maxstart = startSlider->GetMax();
}

void GraphBitStreamerFrame::RestorePos(int pos)
{
    bitSlider->SetValue(mPos[pos].bits);
    bitsCtrl->SetValue(mPos[pos].bits);
    widthSlider->SetValue(mPos[pos].width);
    widthCtrl->SetValue(mPos[pos].width);
    heightSlider->SetValue(mPos[pos].height);
    heightCtrl->SetValue(mPos[pos].height);
    zoomSlider->SetValue(mPos[pos].scale);
    zoomCtrl->SetValue(mPos[pos].scale);
    startSlider->SetRange(0, mPos[pos].maxstart);
    startCtrl->SetRange(0, mPos[pos].maxstart);
    startSlider->SetValue(mPos[pos].bitPos);
    startCtrl->SetValue(mPos[pos].bitPos);
    updateControls();
}

void GraphBitStreamerFrame::OnSettingsMenu( wxCommandEvent& event )
{
    mSettings->ShowModal();
}
