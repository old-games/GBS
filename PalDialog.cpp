///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
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
	fgSizer2 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer2->AddGrowableCol( 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Settings:") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2 = new wxStaticText( m_panel2, wxID_ANY, wxT("Offset (decimal):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	offsetCtrl = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	offsetCtrl->SetToolTip( wxT("Offset in file") );
	
	fgSizer5->Add( offsetCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	
	sbSizer4->Add( fgSizer5, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	RGBBtn = new wxRadioButton( m_panel2, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	RGBBtn->SetValue( true ); 
	RGBBtn->SetToolTip( wxT("Standard palette using 3 bytes on colour") );
	
	fgSizer3->Add( RGBBtn, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	BGRBtn = new wxRadioButton( m_panel2, wxID_ANY, wxT("BGR"), wxDefaultPosition, wxDefaultSize, 0 );
	BGRBtn->SetToolTip( wxT("Standard palette using 3 bytes on colour") );
	
	fgSizer3->Add( BGRBtn, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer3, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer21->AddGrowableCol( 1 );
	fgSizer21->AddGrowableRow( 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( m_panel2, wxID_ANY, wxT("Alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer21->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString mAlphaChoiceChoices;
	mAlphaChoice = new wxChoice( m_panel2, wxID_ALPHA_CHOICE, wxDefaultPosition, wxDefaultSize, mAlphaChoiceChoices, 0 );
	mAlphaChoice->SetSelection( 0 );
	fgSizer21->Add( mAlphaChoice, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer21, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer4->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	shlCheck = new wxCheckBox( m_panel2, wxID_ANY, wxT("Shift left 2"), wxDefaultPosition, wxDefaultSize, 0 );
	shlCheck->SetToolTip( wxT("If your image is too dark try to turn this option on.") );
	
	sbSizer4->Add( shlCheck, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer2->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("File:") ), wxVERTICAL );
	
	palPicker = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL );
	palPicker->SetToolTip( wxT("Select file") );
	
	sbSizer6->Add( palPicker, 0, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 1, 2, 0, 0 );
	
	OKBtn = new wxButton( m_panel2, wxID_OK, wxT("OK"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	gSizer8->Add( OKBtn, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	CancelBtn = new wxButton( m_panel2, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	gSizer8->Add( CancelBtn, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	
	fgSizer2->Add( gSizer8, 1, wxEXPAND, 5 );
	
	
	m_panel2->SetSizer( fgSizer2 );
	m_panel2->Layout();
	fgSizer2->Fit( m_panel2 );
	gSizer4->Add( m_panel2, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( gSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	mAlphaChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( OpenPaletteDialog::OnChoice ), NULL, this );
	palPicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( OpenPaletteDialog::FileChanged ), NULL, this );
	OKBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OpenPaletteDialog::OKPressed ), NULL, this );
}

OpenPaletteDialog::~OpenPaletteDialog()
{
	// Disconnect Events
	mAlphaChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( OpenPaletteDialog::OnChoice ), NULL, this );
	palPicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( OpenPaletteDialog::FileChanged ), NULL, this );
	OKBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( OpenPaletteDialog::OKPressed ), NULL, this );
	
}
