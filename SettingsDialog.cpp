///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx_pch.h"

#include "SettingsDialog.h"

///////////////////////////////////////////////////////////////////////////

SettingsDialog::SettingsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 1, 0, 0 );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer2->AddGrowableCol( 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rawSettingsChoices[] = { wxT("Byte (8 bits)"), wxT("Word (16 bits)"), wxT("RGB (24 bits)"), wxT("Integer (32 bits)") };
	int rawSettingsNChoices = sizeof( rawSettingsChoices ) / sizeof( wxString );
	rawSettings = new wxRadioBox( m_panel2, wxID_ANY, wxT("RAW export:"), wxDefaultPosition, wxDefaultSize, rawSettingsNChoices, rawSettingsChoices, 2, wxRA_SPECIFY_COLS );
	rawSettings->SetSelection( 0 );
	gbSizer1->Add( rawSettings, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString bmpSettingsChoices[] = { wxT("8 bits per pixel"), wxT("24 bits per pixel") };
	int bmpSettingsNChoices = sizeof( bmpSettingsChoices ) / sizeof( wxString );
	bmpSettings = new wxRadioBox( m_panel2, wxID_ANY, wxT("BMP Export:"), wxDefaultPosition, wxDefaultSize, bmpSettingsNChoices, bmpSettingsChoices, 1, wxRA_SPECIFY_COLS );
	bmpSettings->SetSelection( 0 );
	gbSizer1->Add( bmpSettings, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	fgSizer2->Add( gbSizer1, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 2, 2, 0, 0 );
	
	OKBtn = new wxButton( m_panel2, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	gSizer5->Add( OKBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	CancelBtn = new wxButton( m_panel2, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	gSizer5->Add( CancelBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	fgSizer2->Add( gSizer5, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panel2->SetSizer( fgSizer2 );
	m_panel2->Layout();
	fgSizer2->Fit( m_panel2 );
	gSizer4->Add( m_panel2, 1, wxEXPAND, 5 );
	
	this->SetSizer( gSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

SettingsDialog::~SettingsDialog()
{
}
