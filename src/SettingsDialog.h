///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SETTINGSDIALOG_H__
#define __SETTINGSDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/gbsizer.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_AUTO_SAVE_CHECK 1000

///////////////////////////////////////////////////////////////////////////////
/// Class SettingsDialog
///////////////////////////////////////////////////////////////////////////////
class SettingsDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxRadioBox* rawSettings;
		wxRadioBox* bmpSettings;
		wxCheckBox* mAutoSaveProjectCheck;
		wxStaticText* m_staticText1;
		wxSpinCtrl* mIncrementValue;
		wxButton* OKBtn;
		wxButton* CancelBtn;
	
	public:
		
		SettingsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Settings:"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SettingsDialog();
	
};

#endif //__SETTINGSDIALOG_H__
