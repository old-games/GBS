///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __HEXNUMDIALOG_H__
#define __HEXNUMDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
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
		
		HexNumberDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 238,116 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~HexNumberDialog();
	
};

#endif //__HEXNUMDIALOG_H__
