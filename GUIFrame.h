///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar  8 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/valtext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/toolbar.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuLoad 1000
#define idMenuLoadState 1001
#define idMenuSaveState 1002
#define idMenuQuit 1003
#define idImportBMP 1004
#define idExportBMP 1005
#define idExportRAW 1006
#define idSettingsMenu 1007
#define idLoadPlatte 1008
#define idMenuAbout 1009
#define wxID_ANY_PANEL 1010
#define wxID_BITS_SLIDER 1011
#define wxID_BITS_CTRL 1012
#define wxID_START_SLIDER 1013
#define wxID_START_CTRL 1014
#define wxID_WIDTH_SLIDER 1015
#define wxID_WIDTH_CTRL 1016
#define wxID_HEIGHT_SLIDER 1017
#define wxID_HEIGHT_CTRL 1018
#define wxID_ZOOM_SLIDER 1019
#define wxID_ZOOM_CTRL 1020
#define idFlipImage 1021
#define idRotateLeft 1022
#define idRotateRight 1023

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenuItem* menuSaveState;
		wxMenu* editMenu;
		wxMenuItem* menuImportBMP;
		wxMenuItem* menuExportBMP;
		wxMenuItem* menuExportRAW;
		wxMenu* palMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxSlider* bitSlider;
		wxSpinCtrl* bitsCtrl;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText2;
		wxSlider* startSlider;
		wxSpinCtrl* startCtrl;
		wxButton* pageLeftBtn;
		wxButton* lineLeftBtn;
		wxButton* lineRightBtn;
		wxButton* pageRigthBtn;
		wxButton* jumpBtn;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText3;
		wxSlider* widthSlider;
		wxSpinCtrl* widthCtrl;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticText4;
		wxSlider* heightSlider;
		wxSpinCtrl* heightCtrl;
		wxStaticText* m_staticText5;
		wxSlider* zoomSlider;
		wxSpinCtrl* zoomCtrl;
		wxStaticLine* m_staticline5;
		wxCheckBox* gridCheck;
		wxCheckBox* gridInvert;
		wxStaticLine* m_staticline51;
		wxStaticText* m_staticText6;
		wxChoice* palChoice;
		wxCheckBox* CGACheck;
		wxStaticBitmap* palBitmap;
		wxStaticLine* m_staticline6;
		wxButton* saveBtn;
		wxButton* cancelBtn;
		wxStaticBoxSizer* outSizer;
		wxToolBar* mainToolBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void onMenuFileLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadState( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveState( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportBMP( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportBMP( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExportRAW( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSettingsMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuPalLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScrollChanged( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnSpinStrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnPrevFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrevLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNextFrame( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnJumpBtn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGridCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInvertChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void PalChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPaletteClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void SaveChanges( wxCommandEvent& event ) { event.Skip(); }
		virtual void CancelChanges( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFlipImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateLeft( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRotateRight( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("GBS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 712,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

#endif //__GUIFrame__