/***************************************************************
 * Name:      GraphBitStreamerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Pavlovets Ilia (steelrat@list.ru)
 * Created:   2010-10-19
 * Copyright: Pavlovets Ilia (www.old-games.ru)
 * License:
 **************************************************************/

#ifndef GRAPHBITSTREAMERMAIN_H
#define GRAPHBITSTREAMERMAIN_H

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define WHITE 7
#define LIGHT 8
#define CGA_PALS 3

//#define CGA1 0
//#define CGA2 1
//#define CGA3 2
//#define EGA 3
//#define VGA 4
//#define GREY1 5
//#define GREY2 6
//#define TRUECOLOR 7
//#define CUSTOM 8

#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1

#define MAXPOS 10

//#include "GraphBitStreamerApp.h"
#include "GUIFrame.h"
#include "scrolled.h"
#include "openpal.h"
#include "hexnum.h"
#include "settings.h"
#include <wx/dcclient.h>
#include "datamode.h"

static const unsigned char CGAPAL [CGA_PALS][4] =
{
    {BLACK, GREEN, RED, BROWN},
    {BLACK, CYAN, MAGENTA, WHITE},
    {BLACK, CYAN, RED, WHITE}
};

struct Position
{
    int bits;
    int bitPos;
    int width;
    int height;
    int scale;
    int maxstart;
};

class GraphBitStreamerFrame: public GUIFrame
{
    public:
        GraphBitStreamerFrame(wxFrame *frame);
        ~GraphBitStreamerFrame();
        virtual void OnKeyDown( wxKeyEvent& event );
		bool LoadFromCmdLine(const wxString& path);

    private:

        DataProcessor	mDataProcessor;
        DataMode::Mode	mDataMode;
        wxClientDC *dc;
        ScrolledImageComponent* mImage;
        wxFile mFile;
        wxString mFileName;
        wxString mProjectName;
        unsigned int mImageSize;    // размер картинки в байтах
        unsigned int mBitImageSize; // размер картинки в байтах учитывая бит на пиксел
        unsigned int mBitByteSize;
        unsigned int mTotalBits;    // всего бит в файле
        unsigned int mUnpackedSize;
        DataBuffer*    mUnpacked;
        unsigned char red[256], green[256], blue[256];
        unsigned char mVgaPal[768];
        unsigned char* mCustomPal;
        wxBitmap *bmp;
        unsigned char *bmpdata;
        unsigned char mCurrentColor;
        unsigned short mMaxColors;
        int px, py;
        bool changed;
        bool mReadOnly;
        int mRotate;
        Position mPos[MAXPOS];
        //
        PalDialog* mOpenPal;
        HexNum*    mGetHex;
        SettingsDlg *mSettings;
        // функции
        void          pack();
        void          unpack(uint bitPos, uchar bitCount);
        void          updateControls(bool reaload = true);
        void          SetStandardPal();
        void          SetGreyPal(int step);
        void          SetPal(unsigned char* pal);
        void          SetCGAPal(int n);
        void          updateStatus();
        wxSlider*     getSliderById(int id);
        wxSpinCtrl*   getSliderTextBox(int id);
        void          TurnControls(bool b);
        bool          OpenMainFile(wxString name, bool findIfLost);
        void          StorePos(int pos);
        void          RestorePos(int pos);
        void          PalChanged(bool redraw = true);
        void          PalLoad();
        bool          IsEGASpecialMode() const;
		void          FillSizeChoice(wxChoice* choice);
		void          SetStandardSize(bool width, int size);
		bool          LoadProject(const wxString& path);
		bool          SaveProject();
		bool          SaveProject(const wxString& path);
		wxString      SelectFile(bool project);

		virtual void OnSizeChoice( wxCommandEvent& event );
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnScrollChanged( wxScrollEvent& event );
        virtual void OnSpinStrl( wxSpinEvent& event );
		virtual void onMenuFileLoad( wxCommandEvent& event );
		virtual void OnPaint( wxPaintEvent& event );
		virtual void OnGridCheck( wxCommandEvent& event );
        virtual void OnMenuPalLoad( wxCommandEvent& event );
		virtual void OnPalChanged( wxCommandEvent& event );
        virtual void OnOutputLeftClick( wxMouseEvent& event );
        virtual void OnOutputMotion( wxMouseEvent& event );
        virtual void OnOutputRightClick( wxMouseEvent& event );
        virtual void OnPaletteClick( wxMouseEvent& event );
		virtual void SaveChanges( wxCommandEvent& event );
		virtual void CancelChanges( wxCommandEvent& event );
        virtual void OnPrevFrame( wxCommandEvent& event );
		virtual void OnPrevLine( wxCommandEvent& event );
		virtual void OnNextLine( wxCommandEvent& event );
		virtual void OnNextFrame( wxCommandEvent& event );
        virtual void OnLoadState( wxCommandEvent& event );
		virtual void OnSaveState( wxCommandEvent& event );
		virtual void OnExportBMP( wxCommandEvent& event );
		virtual void OnImportBMP( wxCommandEvent& event );
		virtual void OnJumpBtn( wxCommandEvent& event );
        virtual void OnKeyUp( wxKeyEvent& event );
		virtual void OnInvertChange( wxCommandEvent& event );
		virtual void OnFlipImage( wxCommandEvent& event );
		virtual void OnRotateLeft( wxCommandEvent& event );
		virtual void OnRotateRight( wxCommandEvent& event );
		virtual void OnSettingsMenu( wxCommandEvent& event );
		virtual void OnExportRAW( wxCommandEvent& event );
		virtual void DataModeChanged( wxCommandEvent& event );
		virtual void OnUnpackLZexe( wxCommandEvent& event );
		
		void FillModeChoice();
        bool Quit();

        void Rotate(int step);
        void Flip();
        void PreparePalBMP();
		void PrepareBMP();
        void DeleteBMP()
        {
            delete bmp;
        }
};

#endif // GRAPHBITSTREAMERMAIN_H
