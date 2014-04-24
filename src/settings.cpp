#include "wx_pch.h"

#include "settings.h"

#define AUTO_SAVE_MASK (1 << 31)
//#define SETTINGS_FILE "gbs.ini"

static const int gsRAW[4] = {8, 16, 24, 32};
static const int gsBMP[2] = {8, 24};


///* static */ int SettingsDlg::RawBits = 0;
///* static */ int SettingsDlg::BMPBits = 0;
///* static */ bool SettingsDlg::AutoSave = false;


SettingsDlg::SettingsDlg(wxWindow* parent):
	SettingsDialog(parent)
{
//	LoadSettings();
//	rawSettings->SetSelection(RawBits);
//	bmpSettings->SetSelection(BMPBits);
//	mAutoSaveProjectCheck->SetValue(AutoSave);
}

int SettingsDlg::getRAWBits()
{
	return gsRAW[rawSettings->GetSelection()];
}

int SettingsDlg::getBMPBits()
{
	return gsBMP[bmpSettings->GetSelection()];
}

int SettingsDlg::getIncrement()
{
	return mIncrementValue->GetValue();
}

void SettingsDlg::setIncrement(int v)
{
	mIncrementValue->SetValue(v);
}

bool SettingsDlg::isAutoSave()
{
	return mAutoSaveProjectCheck->IsChecked();
}

void SettingsDlg::SaveState(wxFile* tmp)
{
	wxInt32 mRAWBits = rawSettings->GetSelection();
	wxInt32 mBMPBits = bmpSettings->GetSelection();

	if (mAutoSaveProjectCheck->IsChecked())
	{
		mRAWBits |= AUTO_SAVE_MASK;
	}

	tmp->Write(&mRAWBits, 4);
	tmp->Write(&mBMPBits, 4);
}


void SettingsDlg::LoadState(wxFile* tmp)
{
	wxInt32 mRAWBits = 0;
	wxInt32 mBMPBits = 0;
	if (tmp->Read(&mRAWBits, sizeof(wxInt32)) != sizeof(wxInt32)) return;
	if (tmp->Read(&mBMPBits, sizeof(wxInt32)) != sizeof(wxInt32)) return;

	bool autoSave = (mRAWBits & AUTO_SAVE_MASK) != 0;
	mRAWBits = mRAWBits & 0xFF;
	rawSettings->SetSelection(mRAWBits);
	bmpSettings->SetSelection(mBMPBits);
	mAutoSaveProjectCheck->SetValue(autoSave);
//	RawBits = mRAWBits;
//	BMPBits = mBMPBits;
}


int SettingsDlg::ShowModal()
{
	int res;
	int oldRaw = rawSettings->GetSelection();
	int oldBmp = bmpSettings->GetSelection();
	bool oldAuto = mAutoSaveProjectCheck->IsChecked();
	int oldIncrement = mIncrementValue->GetValue();

	if (res = SettingsDialog::ShowModal() != wxID_OK)
	{
		rawSettings->SetSelection(oldRaw);
		bmpSettings->SetSelection(oldBmp);
		mAutoSaveProjectCheck->SetValue(oldAuto);
		mIncrementValue->SetValue(oldIncrement);
	}
//	else
//	{
//		RawBits = rawSettings->GetSelection();
//		BMPBits = bmpSettings->GetSelection();
//		AutoSave = mAutoSaveProjectCheck->IsChecked();
//		SaveSettings();
//	}

	return res;
}

SettingsDlg::~SettingsDlg()
{
}

//
///* static */ wxString SettingsDlg::GetSettingsPath()
//{
//	wxString path;
//
//	if (wxPlatformInfo::Get().GetOperatingSystemId() == wxOS_WINDOWS)
//	{
//		path = wxStandardPaths::Get().GetExecutablePath();
//	}
//	else
//	{
//		path = wxStandardPaths::Get().GetUserConfigDir();
//	}
//
//	return path + wxFileName::GetPathSeparator() + SETTINGS_FILE;
//}
//
//
//
///* static */ void SettingsDlg::LoadSettings()
//{
//	wxString fname = GetSettingsPath();
//	wxFile f;
//
//	if (!f.Open(fname))
//	{
//		SaveSettings();
//		return;
//	}
//
//	wxInt32 val = 0;
//	bool res = true;
//
//	if (res = f.Read(&val, sizeof(val)) == sizeof(val))
//	{
//		RawBits = val;
//	}
//
//	if (res && (res = f.Read(&val, sizeof(val)) == sizeof(val)))
//	{
//		BMPBits = val;
//	}
//
//	if (res && (res = f.Read(&val, sizeof(val)) == sizeof(val)))
//	{
//		AutoSave = (bool) val;
//	}
//
//	if (!res)
//	{
//		wxLogError("There was an error while loading settings file: %s", fname);
//	}
//}
//
//
//
///* static */ void SettingsDlg::SaveSettings()
//{
//	wxString fname = GetSettingsPath();
//	wxFile f;
//
//	if (!f.Create(fname, true))
//	{
//		wxLogError("Unable to create settings file: %s", fname);
//		return;
//	}
//
//	wxInt32 val = RawBits;
//	bool res = f.Write(&val, sizeof(val)) == sizeof(val);
//	val = BMPBits;
//	res = res && f.Write(&val, sizeof(val)) == sizeof(val);
//	val = AutoSave ? 1 : 0;
//	res = res && f.Write(&val, sizeof(val)) == sizeof(val);
//
//	if (!res)
//	{
//		wxLogError("There was an error while writing to settings file: %s", fname);
//	}
//}



