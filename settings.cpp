#include "wx_pch.h"

#include "settings.h"

static const int gsRAW[4] = {8, 16, 24, 32};
static const int gsBMP[2] = {8, 24};

SettingsDlg::SettingsDlg(wxWindow* parent) : SettingsDialog(parent)
{
}

int SettingsDlg::getRAWBits()
{
    return gsRAW[rawSettings->GetSelection()];
}

int SettingsDlg::getBMPBits()
{
    return gsBMP[bmpSettings->GetSelection()];
}

void SettingsDlg::SaveState(wxFile* tmp)
{
    int mRAWBits = rawSettings->GetSelection();
    int mBMPBits = bmpSettings->GetSelection();
    tmp->Write(&mRAWBits, 4);
    tmp->Write(&mBMPBits, 4);
}

void SettingsDlg::LoadState(wxFile* tmp)
{
    int mRAWBits = 0;
    int mBMPBits = 0;
    if (tmp->Read(&mRAWBits, 4) != 4) return;
    if (tmp->Read(&mBMPBits, 4) != 4) return;
    rawSettings->SetSelection(mRAWBits);
    bmpSettings->SetSelection(mBMPBits);
}

int SettingsDlg::ShowModal()
{
    int mRAWBits = rawSettings->GetSelection();
    int mBMPBits = bmpSettings->GetSelection();
    int res;
    if (res = SettingsDialog::ShowModal() != wxID_OK)
    {
        rawSettings->SetSelection(mRAWBits);
        bmpSettings->SetSelection(mBMPBits);
    }
    return res;
}

SettingsDlg::~SettingsDlg()
{
}
