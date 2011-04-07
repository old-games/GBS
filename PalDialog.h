///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar  8 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PalDialog__
#define __PalDialog__

#include <wx/string.h>
#include <wx/spinctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class OpenPaletteDialog
///////////////////////////////////////////////////////////////////////////////
class OpenPaletteDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxSpinCtrl* offsetCtrl;
		wxRadioButton* RGBBtn;
		wxRadioButton* RGBABtn;
		wxCheckBox* shlCheck;
		wxFilePickerCtrl* palPicker;
		wxButton* OKBtn;
		wxButton* CancelBtn;
		
		// Virtual event handlers, overide them in your derived class
		virtual void FileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OKPressed( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		OpenPaletteDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Read palette from file"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 453,128 ), long style = wxDEFAULT_DIALOG_STYLE );
		~OpenPaletteDialog();
	
};

#endif //__PalDialog__
