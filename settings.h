#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "SettingsDialog.h"

class SettingsDlg: public SettingsDialog
{
    public:
        SettingsDlg(wxWindow* parent);
        int getRAWBits();
        int getBMPBits();
        void SaveState(wxFile* tmp);
        void LoadState(wxFile* tmp);
        virtual int ShowModal();
        ~SettingsDlg();
};


#endif // SETTINGS_H_INCLUDED
