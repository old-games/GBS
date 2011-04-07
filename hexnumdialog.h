///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar  8 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __hexnumdialog__
#define __hexnumdialog__

#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class HexNumberDialog
///////////////////////////////////////////////////////////////////////////////
class HexNumberDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxTextCtrl* textCtrl;
		wxButton* OKBtn;
		wxButton* CancelBtn;
	
	public:
		
		HexNumberDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 198,127 ), long style = wxDEFAULT_DIALOG_STYLE );
		~HexNumberDialog();
	
};

#endif //__hexnumdialog__
