///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx_pch.h"

#include "GUIFrame.h"

#include "icons/FLIP.xpm"
#include "icons/about.xpm"
#include "icons/aclockwise1.xpm"
#include "icons/bmpin0.xpm"
#include "icons/bmpin1.xpm"
#include "icons/bmpout0.xpm"
#include "icons/bmpout1.xpm"
#include "icons/clockwise1.xpm"
#include "icons/close.xpm"
#include "icons/custompal0.xpm"
#include "icons/custompal1.xpm"
#include "icons/exportraw.xpm"
#include "icons/loadfile0.xpm"
#include "icons/loadfile1.xpm"
#include "icons/loadprj0.xpm"
#include "icons/loadprj1.xpm"
#include "icons/saveprj0.xpm"
#include "icons/saveprj1.xpm"
#include "icons/settings.xpm"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,600 ), wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileLoad;
	menuFileLoad = new wxMenuItem( fileMenu, idMenuLoad, wxString( _("&Load file") ) + wxT('\t') + wxT("Alt+L"), _("Loads file to explore"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuFileLoad->SetBitmaps( wxBitmap( loadfile1_xpm ) );
	#elif defined( __WXGTK__ )
	menuFileLoad->SetBitmap( wxBitmap( loadfile1_xpm ) );
	#endif
	fileMenu->Append( menuFileLoad );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* menuLoadState;
	menuLoadState = new wxMenuItem( fileMenu, idMenuLoadState, wxString( _("L&oad project") ) + wxT('\t') + wxT("Ctrl+L"), _("Load stored program state"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuLoadState->SetBitmaps( wxBitmap( loadprj1_xpm ) );
	#elif defined( __WXGTK__ )
	menuLoadState->SetBitmap( wxBitmap( loadprj1_xpm ) );
	#endif
	fileMenu->Append( menuLoadState );
	
	menuSaveState = new wxMenuItem( fileMenu, idMenuSaveState, wxString( _("Save &project") ) + wxT('\t') + wxT("Ctrl+S"), _("Strore program state"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuSaveState->SetBitmaps( wxBitmap( saveprj1_xpm ) );
	#elif defined( __WXGTK__ )
	menuSaveState->SetBitmap( wxBitmap( saveprj1_xpm ) );
	#endif
	fileMenu->Append( menuSaveState );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( _("&Quit") ) + wxT('\t') + wxT("Alt+F4"), _("Quit the application"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuFileQuit->SetBitmaps( wxBitmap( close_xpm ) );
	#elif defined( __WXGTK__ )
	menuFileQuit->SetBitmap( wxBitmap( close_xpm ) );
	#endif
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, _("&File") ); 
	
	editMenu = new wxMenu();
	menuImportBMP = new wxMenuItem( editMenu, idImportBMP, wxString( _("&Import BMP") ) + wxT('\t') + wxT("F8"), _("Replace current image with loaded from BMP file"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuImportBMP->SetBitmaps( wxBitmap( bmpin1_xpm ) );
	#elif defined( __WXGTK__ )
	menuImportBMP->SetBitmap( wxBitmap( bmpin1_xpm ) );
	#endif
	editMenu->Append( menuImportBMP );
	
	menuExportBMP = new wxMenuItem( editMenu, idExportBMP, wxString( _("&Export BMP") ) + wxT('\t') + wxT("F5"), _("Creates BMP file of current state"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuExportBMP->SetBitmaps( wxBitmap( bmpout1_xpm ) );
	#elif defined( __WXGTK__ )
	menuExportBMP->SetBitmap( wxBitmap( bmpout1_xpm ) );
	#endif
	editMenu->Append( menuExportBMP );
	
	editMenu->AppendSeparator();
	
	menuExportRAW = new wxMenuItem( editMenu, idExportRAW, wxString( _("&RAW export") ) + wxT('\t') + wxT("F6"), _("Exports raw data"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuExportRAW->SetBitmaps( wxBitmap( exportraw_xpm ) );
	#elif defined( __WXGTK__ )
	menuExportRAW->SetBitmap( wxBitmap( exportraw_xpm ) );
	#endif
	editMenu->Append( menuExportRAW );
	
	editMenu->AppendSeparator();
	
	wxMenuItem* menuSettings;
	menuSettings = new wxMenuItem( editMenu, idSettingsMenu, wxString( _("&Settings") ) + wxT('\t') + wxT("F12"), _("Current settings"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuSettings->SetBitmaps( wxBitmap( settings_xpm ) );
	#elif defined( __WXGTK__ )
	menuSettings->SetBitmap( wxBitmap( settings_xpm ) );
	#endif
	editMenu->Append( menuSettings );
	
	mbar->Append( editMenu, _("&Import/Export") ); 
	
	palMenu = new wxMenu();
	wxMenuItem* menuPaletteLoad;
	menuPaletteLoad = new wxMenuItem( palMenu, idLoadPlatte, wxString( _("Load palette") ) + wxT('\t') + wxT("F10"), _("Load palette from any file from any offset"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuPaletteLoad->SetBitmaps( wxBitmap( custompal1_xpm ) );
	#elif defined( __WXGTK__ )
	menuPaletteLoad->SetBitmap( wxBitmap( custompal1_xpm ) );
	#endif
	palMenu->Append( menuPaletteLoad );
	
	mbar->Append( palMenu, _("&Palette") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( _("&About") ) + wxT('\t') + wxT("F1"), _("Show info about this application"), wxITEM_NORMAL );
	#ifdef __WXMSW__
	menuHelpAbout->SetBitmaps( wxBitmap( about_xpm ) );
	#elif defined( __WXGTK__ )
	menuHelpAbout->SetBitmap( wxBitmap( about_xpm ) );
	#endif
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, _("&Help") ); 
	
	this->SetMenuBar( mbar );
	
	statusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 1, 0, 0 );
	
	m_panel1 = new wxPanel( this, wxID_ANY_PANEL, wxDefaultPosition, wxDefaultSize, wxCLIP_CHILDREN );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->AddGrowableRow( 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 1, 2, 0, 0 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Controls:") ), wxVERTICAL );
	
	m_staticText7 = new wxStaticText( m_panel1, wxID_ANY, _("Data mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	sbSizer1->Add( m_staticText7, 0, wxALL, 5 );
	
	wxArrayString mDataModeChoiceChoices;
	mDataModeChoice = new wxChoice( m_panel1, wxID_DATA_MODE_CHOICE, wxDefaultPosition, wxDefaultSize, mDataModeChoiceChoices, 0 );
	mDataModeChoice->SetSelection( 0 );
	sbSizer1->Add( mDataModeChoice, 0, wxEXPAND, 5 );
	
	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, _("Bits per pixel:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	sbSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	bitSlider = new wxSlider( m_panel1, wxID_BITS_SLIDER, 8, 1, 56, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bitSlider->SetToolTip( _("Bits: 1 - 8") );
	
	sbSizer1->Add( bitSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	bitsCtrl = new wxSpinCtrl( m_panel1, wxID_BITS_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 56, 8 );
	sbSizer1->Add( bitsCtrl, 0, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, _("Starting bit:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	sbSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	startSlider = new wxSlider( m_panel1, wxID_START_SLIDER, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer1->Add( startSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	startCtrl = new wxSpinCtrl( m_panel1, wxID_START_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	sbSizer1->Add( startCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 1, 4, 0, 0 );
	
	pageLeftBtn = new wxButton( m_panel1, wxID_ANY, _("<<"), wxDefaultPosition, wxSize( 40,17 ), 0 );
	pageLeftBtn->SetToolTip( _("Previous frame") );
	
	gSizer3->Add( pageLeftBtn, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	lineLeftBtn = new wxButton( m_panel1, wxID_ANY, _("<"), wxDefaultPosition, wxSize( 40,17 ), 0 );
	lineLeftBtn->SetToolTip( _("Previous line") );
	
	gSizer3->Add( lineLeftBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	lineRightBtn = new wxButton( m_panel1, wxID_ANY, _(">"), wxDefaultPosition, wxSize( 40,17 ), 0 );
	lineRightBtn->SetToolTip( _("Next line") );
	
	gSizer3->Add( lineRightBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	pageRigthBtn = new wxButton( m_panel1, wxID_ANY, _(">>"), wxDefaultPosition, wxSize( 40,17 ), 0 );
	pageRigthBtn->SetToolTip( _("Next frame") );
	
	gSizer3->Add( pageRigthBtn, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( gSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	jumpBtn = new wxButton( m_panel1, wxID_ANY, _("Jump to offset"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	sbSizer1->Add( jumpBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer1->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, _("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer2->Add( m_staticText3, 0, wxALL, 5 );
	
	wxArrayString mWidthChoiceChoices;
	mWidthChoice = new wxChoice( m_panel1, wxID_WIDTH_CHOICE, wxDefaultPosition, wxDefaultSize, mWidthChoiceChoices, 0 );
	mWidthChoice->SetSelection( 0 );
	fgSizer2->Add( mWidthChoice, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	
	sbSizer1->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	widthSlider = new wxSlider( m_panel1, wxID_WIDTH_SLIDER, 8, 1, 7680, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer1->Add( widthSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	widthCtrl = new wxSpinCtrl( m_panel1, wxID_WIDTH_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 7680, 8 );
	sbSizer1->Add( widthCtrl, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer1->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer21->AddGrowableCol( 1 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer21->Add( m_staticText4, 0, wxALL, 5 );
	
	wxArrayString mHeightChoiceChoices;
	mHeightChoice = new wxChoice( m_panel1, wxID_HEIGHT_CHOICE, wxDefaultPosition, wxDefaultSize, mHeightChoiceChoices, 0 );
	mHeightChoice->SetSelection( 0 );
	fgSizer21->Add( mHeightChoice, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	
	sbSizer1->Add( fgSizer21, 0, wxEXPAND, 5 );
	
	heightSlider = new wxSlider( m_panel1, wxID_HEIGHT_SLIDER, 8, 1, 4320, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer1->Add( heightSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	heightCtrl = new wxSpinCtrl( m_panel1, wxID_HEIGHT_CTRL, wxT("8"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4320, 8 );
	sbSizer1->Add( heightCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	gSizer2->Add( sbSizer1, 1, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Secondary:") ), wxVERTICAL );
	
	m_staticText5 = new wxStaticText( m_panel1, wxID_ANY, _("Zoom:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	sbSizer3->Add( m_staticText5, 0, wxALL, 5 );
	
	zoomSlider = new wxSlider( m_panel1, wxID_ZOOM_SLIDER, 1, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer3->Add( zoomSlider, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	zoomCtrl = new wxSpinCtrl( m_panel1, wxID_ZOOM_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS|wxSP_WRAP, 1, 20, 1 );
	sbSizer3->Add( zoomCtrl, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	m_staticline5 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer3->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 2, 0, 0 );
	
	gridCheck = new wxCheckBox( m_panel1, wxID_ANY, _("Show grid"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( gridCheck, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	gridInvert = new wxCheckBox( m_panel1, wxID_ANY, _("Invert grid"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( gridInvert, 0, wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	
	sbSizer3->Add( gSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticline51 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer3->Add( m_staticline51, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_panel1, wxID_ANY, _("Palette:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	sbSizer3->Add( m_staticText6, 0, wxALL, 5 );
	
	wxString palChoiceChoices[] = { _("CGA #1"), _("CGA #2"), _("CGA #3"), _("EGA"), _("VGA"), _("Grey #1"), _("Grey #2"), _("True Color"), _("Custom") };
	int palChoiceNChoices = sizeof( palChoiceChoices ) / sizeof( wxString );
	palChoice = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, palChoiceNChoices, palChoiceChoices, 0 );
	palChoice->SetSelection( 6 );
	sbSizer3->Add( palChoice, 0, wxEXPAND, 5 );
	
	CGACheck = new wxCheckBox( m_panel1, wxID_ANY, _("CGA High intensity"), wxDefaultPosition, wxDefaultSize, 0 );
	CGACheck->SetValue(true); 
	CGACheck->Enable( false );
	CGACheck->SetToolTip( _("High intensity of CGA mode") );
	
	sbSizer3->Add( CGACheck, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );
	
	palBitmap = new wxStaticBitmap( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 128,128 ), 0 );
	sbSizer3->Add( palBitmap, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_staticline6 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer3->Add( m_staticline6, 0, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	saveBtn = new wxButton( m_panel1, wxID_ANY, _("Save changes"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	saveBtn->Enable( false );
	
	sbSizer3->Add( saveBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );
	
	cancelBtn = new wxButton( m_panel1, wxID_ANY, _("Cancel changes"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	cancelBtn->Enable( false );
	
	sbSizer3->Add( cancelBtn, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxEXPAND, 5 );
	
	
	gSizer2->Add( sbSizer3, 1, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	
	fgSizer1->Add( gSizer2, 1, wxEXPAND, 5 );
	
	outSizer = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, _("Out:") ), wxVERTICAL );
	
	
	fgSizer1->Add( outSizer, 1, wxEXPAND|wxALL, 5 );
	
	
	m_panel1->SetSizer( fgSizer1 );
	m_panel1->Layout();
	fgSizer1->Fit( m_panel1 );
	gSizer1->Add( m_panel1, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	this->SetSizer( gSizer1 );
	this->Layout();
	mainToolBar = this->CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, wxID_ANY );
	mainToolBar->SetToolBitmapSize( wxSize( 32,32 ) );
	mainToolBar->AddTool( idMenuLoad, _("Load file"), wxBitmap( loadfile0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Loads file to explore"), NULL ); 
	
	mainToolBar->AddSeparator(); 
	
	mainToolBar->AddTool( idMenuLoadState, _("Load project"), wxBitmap( loadprj0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Load stored program state"), NULL ); 
	
	mainToolBar->AddTool( idMenuSaveState, _("Save project"), wxBitmap( saveprj0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Strore program state"), NULL ); 
	
	mainToolBar->AddSeparator(); 
	
	mainToolBar->AddTool( idImportBMP, _("Import BMP"), wxBitmap( bmpin0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Replace current image with loaded from BMP file"), NULL ); 
	
	mainToolBar->AddTool( idExportBMP, _("Export BMP"), wxBitmap( bmpout0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Creates BMP file from current image"), NULL ); 
	
	mainToolBar->AddSeparator(); 
	
	mainToolBar->AddTool( idLoadPlatte, _("Load palette"), wxBitmap( custompal0_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Load palette from any file from any offset"), NULL ); 
	
	mainToolBar->AddSeparator(); 
	
	mainToolBar->AddTool( idFlipImage, _("Flip"), wxBitmap( FLIP_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Flip up and down"), NULL ); 
	
	mainToolBar->AddTool( idRotateLeft, _("Rotate counterclockwise"), wxBitmap( aclockwise1_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Rotate counterclockwise"), NULL ); 
	
	mainToolBar->AddTool( idRotateRight, _("Rotate clockwise"), wxBitmap( clockwise1_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Rotate clockwise"), NULL ); 
	
	mainToolBar->Realize(); 
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ) );
	this->Connect( menuFileLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::onMenuFileLoad ) );
	this->Connect( menuLoadState->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnLoadState ) );
	this->Connect( menuSaveState->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSaveState ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuImportBMP->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnImportBMP ) );
	this->Connect( menuExportBMP->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportBMP ) );
	this->Connect( menuExportRAW->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportRAW ) );
	this->Connect( menuSettings->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSettingsMenu ) );
	this->Connect( menuPaletteLoad->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnMenuPalLoad ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_panel1->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	mDataModeChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::DataModeChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitsCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	bitsCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	startCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	pageLeftBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnPrevFrame ), NULL, this );
	lineLeftBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnPrevLine ), NULL, this );
	lineRightBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNextLine ), NULL, this );
	pageRigthBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNextFrame ), NULL, this );
	jumpBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnJumpBtn ), NULL, this );
	mWidthChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnSizeChoice ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	widthCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	mHeightChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnSizeChoice ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	heightCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomCtrl->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	zoomCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	gridCheck->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::OnGridCheck ), NULL, this );
	gridInvert->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::OnInvertChange ), NULL, this );
	palChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnPalChanged ), NULL, this );
	CGACheck->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::PalChanged ), NULL, this );
	palBitmap->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnPaletteClick ), NULL, this );
	saveBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::SaveChanges ), NULL, this );
	cancelBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::CancelChanges ), NULL, this );
	this->Connect( idMenuLoad, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::onMenuFileLoad ));
	this->Connect( idMenuLoadState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnLoadState ));
	this->Connect( idMenuSaveState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSaveState ));
	this->Connect( idImportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnImportBMP ));
	this->Connect( idExportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportBMP ));
	this->Connect( idLoadPlatte, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnMenuPalLoad ));
	this->Connect( idFlipImage, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnFlipImage ));
	this->Connect( idRotateLeft, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnRotateLeft ));
	this->Connect( idRotateRight, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnRotateRight ));
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ) );
	this->Disconnect( idMenuLoad, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::onMenuFileLoad ) );
	this->Disconnect( idMenuLoadState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnLoadState ) );
	this->Disconnect( idMenuSaveState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSaveState ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( idImportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnImportBMP ) );
	this->Disconnect( idExportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportBMP ) );
	this->Disconnect( idExportRAW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportRAW ) );
	this->Disconnect( idSettingsMenu, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSettingsMenu ) );
	this->Disconnect( idLoadPlatte, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnMenuPalLoad ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	m_panel1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ), NULL, this );
	mDataModeChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::DataModeChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	bitsCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	bitsCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	startCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	startCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	pageLeftBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnPrevFrame ), NULL, this );
	lineLeftBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnPrevLine ), NULL, this );
	lineRightBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNextLine ), NULL, this );
	pageRigthBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnNextFrame ), NULL, this );
	jumpBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnJumpBtn ), NULL, this );
	mWidthChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnSizeChoice ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	widthCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	widthCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	mHeightChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnSizeChoice ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	heightCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	heightCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::OnScrollChanged ), NULL, this );
	zoomCtrl->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::OnKeyUp ), NULL, this );
	zoomCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( GUIFrame::OnSpinStrl ), NULL, this );
	gridCheck->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::OnGridCheck ), NULL, this );
	gridInvert->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::OnInvertChange ), NULL, this );
	palChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::OnPalChanged ), NULL, this );
	CGACheck->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::PalChanged ), NULL, this );
	palBitmap->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( GUIFrame::OnPaletteClick ), NULL, this );
	saveBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::SaveChanges ), NULL, this );
	cancelBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::CancelChanges ), NULL, this );
	this->Disconnect( idMenuLoad, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::onMenuFileLoad ));
	this->Disconnect( idMenuLoadState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnLoadState ));
	this->Disconnect( idMenuSaveState, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSaveState ));
	this->Disconnect( idImportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnImportBMP ));
	this->Disconnect( idExportBMP, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnExportBMP ));
	this->Disconnect( idLoadPlatte, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnMenuPalLoad ));
	this->Disconnect( idFlipImage, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnFlipImage ));
	this->Disconnect( idRotateLeft, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnRotateLeft ));
	this->Disconnect( idRotateRight, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnRotateRight ));
	
}
