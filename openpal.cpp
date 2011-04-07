#include "wx_pch.h"
#include "openpal.h"
#include "slstrings.h"

PalDialog::PalDialog(wxWindow* parent) : OpenPaletteDialog(parent)
{
    mFileName = "";
}

PalDialog::~PalDialog()
{

}

void PalDialog::FileChanged( wxFileDirPickerEvent& event )
{
    wxFile file;
    file.Open(palPicker->GetPath(), wxFile::read);
    offsetCtrl->SetRange(0, file.Length()-3);
    file.Close();
}

void PalDialog::OKPressed( wxCommandEvent& event )
{
    wxFile file;
    if (palPicker->GetPath().IsEmpty() || !file.Open(palPicker->GetPath(), wxFile::read))
    {
        return;
    }
    file.Seek(offsetCtrl->GetValue(), wxFromStart);
    for (int i = 0; i < 256; i ++)
    {
        if (file.Read((mPalBuf+(i*3)), 3) != 3) break;
        if (RGBABtn->GetValue()) file.Seek(1, wxFromCurrent);
    }
    if (shlCheck->IsChecked())
        for (int i = 0; i<768; i++)
            mPalBuf[i]<<=2;
    file.Close();
    mFileName = palPicker->GetPath();
    event.Skip();
}

void PalDialog::SaveState(wxFile* tmp)
{
    saveString(tmp, mFileName);
    unsigned int val;
    val = (unsigned int) RGBBtn->GetValue();
    tmp->Write(&val, 4);
    val = (unsigned int) RGBABtn->GetValue();
    tmp->Write(&val, 4);
    val = (unsigned int) shlCheck->IsChecked();
    tmp->Write(&val, 4);
}

void PalDialog::LoadState(wxFile* tmp)
{
    tmp->Read(mPalBuf, 768);
    loadString(tmp, mFileName);
    palPicker->SetPath(mFileName);
    uint val;
    tmp->Read(&val, 4);
    RGBBtn->SetValue((bool) val);
    tmp->Read(&val, 4);
    RGBABtn->SetValue((bool) val);
    tmp->Read(&val, 4);
    shlCheck->SetValue((bool) val);
}
