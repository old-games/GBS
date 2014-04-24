#ifndef OPENPAL_H_INCLUDED
#define OPENPAL_H_INCLUDED
#include "PalDialog.h"

class PalDialog : public OpenPaletteDialog
{
    public:
        PalDialog(wxWindow* parent);
        ~PalDialog();
        unsigned char* getPal() { return mPalBuf; }
        void SaveState(wxFile* tmp);
        void LoadState(wxFile* tmp);
    private:
        unsigned char mPalBuf[1024];
        wxString mFileName;
        virtual void FileChanged( wxFileDirPickerEvent& event );
		virtual void OKPressed( wxCommandEvent& event );
};


#endif // OPENPAL_H_INCLUDED
