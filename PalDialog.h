///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PALDIALOG_H__
#define __PALDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_ALPHA_CHOICE 1000

///////////////////////////////////////////////////////////////////////////////
/// Class OpenPaletteDialog
///////////////////////////////////////////////////////////////////////////////
class OpenPaletteDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxStaticText* m_staticText2;
		wxSpinCtrl* offsetCtrl;
		wxRadioButton* RGBBtn;
		wxRadioButton* BGRBtn;
		wxStaticText* m_staticText1;
		wxChoice* mAlphaChoice;
		wxCheckBox* shlCheck;
		wxFilePickerCtrl* palPicker;
		wxButton* OKBtn;
		wxButton* CancelBtn;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void FileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OKPressed( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		OpenPaletteDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Read palette from file"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 512,246 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~OpenPaletteDialog();
	
};

#endif //__PALDIALOG_H__
