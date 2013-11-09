#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "SettingsDialog.h"

class SettingsDlg: public SettingsDialog
{
	public:
		SettingsDlg(wxWindow* parent);
		int getRAWBits();
		int getBMPBits();
		bool isAutoSave();
		void SaveState(wxFile* tmp);
		void LoadState(wxFile* tmp);
		virtual int ShowModal();
		~SettingsDlg();

		int getIncrement();
		void setIncrement(int v);

//	static wxString GetSettingsPath();
//	static void LoadSettings();
//	static void SaveSettings();
//
//	static bool IsAutoSave() { return AutoSave; }
//private:
//	static int RawBits;
//	static int BMPBits;
//	static bool AutoSave;
};


#endif // SETTINGS_H_INCLUDED
