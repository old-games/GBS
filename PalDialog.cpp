///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar  8 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx_pch.h"

#include "PalDialog.h"

///////////////////////////////////////////////////////////////////////////

OpenPaletteDialog::OpenPaletteDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 1, 2, 0, 0 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Settings:") ), wxVERTICAL );
	
	offsetCtrl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	offsetCtrl->SetToolTip( wxT("Offset in file") );
	
	sbSizer4->Add( offsetCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 1, 3, 0, 0 );
	
	RGBBtn = new wxRadioButton( m_panel2, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	RGBBtn->SetValue( true ); 
	RGBBtn->SetToolTip( wxT("Standard palette using 3 bytes on colour") );
	
	gSizer6->Add( RGBBtn, 0, wxRIGHT, 5 );
	
	RGBABtn = new wxRadioButton( m_panel2, wxID_ANY, wxT("RGBA"), wxDefaultPosition, wxDefaultSize, 0 );
	RGBABtn->SetToolTip( wxT("BMP like palette, using 4 bytes on colour") );
	
	gSizer6->Add( RGBABtn, 0, wxLEFT, 5 );
	
	shlCheck = new wxCheckBox( m_panel2, wxID_ANY, wxT("Shift left 2"), wxDefaultPosition, wxDefaultSize, 0 );
	shlCheck->SetToolTip( wxT("If your image is too dark try to turn this oprion on.") );
	
	gSizer6->Add( shlCheck, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	sbSizer4->Add( gSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	gSizer5->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("File:") ), wxVERTICAL );
	
	palPicker = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	palPicker->SetToolTip( wxT("Select file") );
	
	sbSizer6->Add( palPicker, 0, wxTOP|wxBOTTOM, 5 );
	
	gSizer5->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	fgSizer2->Add( gSizer5, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 1, 2, 0, 0 );
	
	OKBtn = new wxButton( m_panel2, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	gSizer8->Add( OKBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	CancelBtn = new wxButton( m_panel2, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	gSizer8->Add( CancelBtn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizer2->Add( gSizer8, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( fgSizer2 );
	m_panel2->Layout();
	fgSizer2->Fit( m_panel2 );
	gSizer4->Add( m_panel2, 1, wxEXPAND, 5 );
	
	this->SetSizer( gSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	palPicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( OpenPaletteDialog::FileChanged ), NULL, this );
	OKBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OpenPaletteDialog::OKPressed ), NULL, this );
}

OpenPaletteDialog::~OpenPaletteDialog()
{
	// Disconnect Events
	palPicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( OpenPaletteDialog::FileChanged ), NULL, this );
	OKBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OpenPaletteDialog::OKPressed ), NULL, this );
	
}
