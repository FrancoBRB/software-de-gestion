///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

ventana_principal::ventana_principal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline22 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer1->Add( m_staticline22, 0, wxEXPAND | wxALL, 5 );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("boxmain.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_bitmap1, 0, wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );

	m_staticText45 = new wxStaticText( this, wxID_ANY, wxT("Software"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	m_staticText45->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer56->Add( m_staticText45, 0, wxALL, 5 );

	m_staticText46 = new wxStaticText( this, wxID_ANY, wxT("              De"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	m_staticText46->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer56->Add( m_staticText46, 0, wxALL, 5 );

	m_staticText47 = new wxStaticText( this, wxID_ANY, wxT("                  Gestión"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText47->Wrap( -1 );
	m_staticText47->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer56->Add( m_staticText47, 0, wxALL, 5 );


	bSizer1->Add( bSizer56, 0, wxALIGN_CENTER_VERTICAL, 5 );

	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer1->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );

	btn_principal_stock = new wxButton( this, wxID_ANY, wxT("Stock"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_principal_stock->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	btn_principal_stock->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	btn_principal_stock->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	bSizer57->Add( btn_principal_stock, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText48 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer57->Add( m_staticText48, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	btn_principal_ventas = new wxButton( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	btn_principal_ventas->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	btn_principal_ventas->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	btn_principal_ventas->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	bSizer57->Add( btn_principal_ventas, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer57, 0, wxALIGN_CENTER_VERTICAL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer1->Add( m_staticline2, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	btn_principal_stock->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_principal::clickAbrirStock ), NULL, this );
	btn_principal_ventas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_principal::clickAbrirVentas ), NULL, this );
}

ventana_principal::~ventana_principal()
{
	// Disconnect Events
	btn_principal_stock->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_principal::clickAbrirStock ), NULL, this );
	btn_principal_ventas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_principal::clickAbrirVentas ), NULL, this );

}

ventana_stock::ventana_stock( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Inserte Busqueda:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	busqueda_stock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,-1 ), 0 );
	bSizer3->Add( busqueda_stock, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_buscarstock = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_buscarstock, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Recargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button26, 0, wxALL, 5 );

	m_button27 = new wxButton( this, wxID_ANY, wxT("Productos Discontinuados"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button27, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	grilla_stock = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 800,600 ), 0 );

	// Grid
	grilla_stock->CreateGrid( 0, 6 );
	grilla_stock->EnableEditing( false );
	grilla_stock->EnableGridLines( true );
	grilla_stock->EnableDragGridSize( false );
	grilla_stock->SetMargins( 0, 0 );

	// Columns
	grilla_stock->SetColSize( 0, 41 );
	grilla_stock->SetColSize( 1, 260 );
	grilla_stock->SetColSize( 2, 152 );
	grilla_stock->SetColSize( 3, 157 );
	grilla_stock->SetColSize( 4, 132 );
	grilla_stock->SetColSize( 5, 58 );
	grilla_stock->EnableDragColMove( false );
	grilla_stock->EnableDragColSize( true );
	grilla_stock->SetColLabelValue( 0, wxT("ID") );
	grilla_stock->SetColLabelValue( 1, wxT("Nombre") );
	grilla_stock->SetColLabelValue( 2, wxT("Marca") );
	grilla_stock->SetColLabelValue( 3, wxT("Categoria") );
	grilla_stock->SetColLabelValue( 4, wxT("Precio") );
	grilla_stock->SetColLabelValue( 5, wxT("Cantidad") );
	grilla_stock->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grilla_stock->EnableDragRowSize( true );
	grilla_stock->SetRowLabelSize( 0 );
	grilla_stock->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_stock->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer2->Add( grilla_stock, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Stock total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer7->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	t_stock = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0|wxBORDER_SUNKEN );
	t_stock->Wrap( -1 );
	bSizer7->Add( t_stock, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT(" | "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	bSizer7->Add( m_staticText38, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button_sumar = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button_sumar, 0, wxALL, 5 );

	m_button_restar = new wxButton( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button_restar, 0, wxALL, 5 );

	m_button_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button_agregar, 0, wxALL, 5 );

	m_button_editar = new wxButton( this, wxID_ANY, wxT("Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button_editar, 0, wxALL, 5 );

	m_button_eliminar = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button_eliminar, 0, wxALL, 5 );


	bSizer2->Add( bSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button_buscarstock->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_busqueda ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_recargar_stock ), NULL, this );
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_VerEliminados ), NULL, this );
	grilla_stock->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_stock::SelectGrillaStockCizq ), NULL, this );
	grilla_stock->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_stock::ClickGrillaStockI ), NULL, this );
	grilla_stock->Connect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( ventana_stock::ClickGrillaStockD ), NULL, this );
	m_button_sumar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_sumar ), NULL, this );
	m_button_restar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_restar ), NULL, this );
	m_button_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_agregar ), NULL, this );
	m_button_editar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_editar_producto ), NULL, this );
	m_button_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_eliminar ), NULL, this );
}

ventana_stock::~ventana_stock()
{
	// Disconnect Events
	m_button_buscarstock->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_busqueda ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_recargar_stock ), NULL, this );
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_VerEliminados ), NULL, this );
	grilla_stock->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_stock::SelectGrillaStockCizq ), NULL, this );
	grilla_stock->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_stock::ClickGrillaStockI ), NULL, this );
	grilla_stock->Disconnect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( ventana_stock::ClickGrillaStockD ), NULL, this );
	m_button_sumar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_sumar ), NULL, this );
	m_button_restar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_restar ), NULL, this );
	m_button_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_agregar ), NULL, this );
	m_button_editar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_editar_producto ), NULL, this );
	m_button_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_stock::btn_eliminar ), NULL, this );

}

ventana_agregar::ventana_agregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("ID:             "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer9->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_id = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( lblagregar_id, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Nombre:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer10->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( lblagregar_nombre, 1, wxALL, 5 );


	bSizer5->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Marca:      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer11->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_marca = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( lblagregar_marca, 1, wxALL, 5 );


	bSizer5->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Categoria:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer12->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_categoria = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( lblagregar_categoria, 1, wxALL, 5 );


	bSizer5->Add( bSizer12, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Precio:      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer13->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( lblagregar_precio, 1, wxALL, 5 );


	bSizer5->Add( bSizer13, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText241 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText241->Wrap( -1 );
	bSizer16->Add( m_staticText241, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lblagregar_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( lblagregar_cantidad, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_button9 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button9, 1, wxALL, 5 );

	m_button10 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button10, 1, wxALL, 5 );


	bSizer5->Add( bSizer18, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_agregar::btn_agregar_producto ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_agregar::btn_producto_cancelar ), NULL, this );
}

ventana_agregar::~ventana_agregar()
{
	// Disconnect Events
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_agregar::btn_agregar_producto ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_agregar::btn_producto_cancelar ), NULL, this );

}

ventana_modificar::ventana_modificar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("ID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer9->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	id_editar = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	id_editar->Wrap( -1 );
	bSizer9->Add( id_editar, 0, wxALL, 5 );


	bSizer5->Add( bSizer9, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Nombre:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer10->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbleditar_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( lbleditar_nombre, 1, wxALL, 5 );


	bSizer5->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Marca:      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer11->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbleditar_marca = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( lbleditar_marca, 1, wxALL, 5 );


	bSizer5->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Categoria:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer12->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbleditar_categoria = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( lbleditar_categoria, 1, wxALL, 5 );


	bSizer5->Add( bSizer12, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Precio:      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer13->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbleditar_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( lbleditar_precio, 1, wxALL, 5 );


	bSizer5->Add( bSizer13, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText241 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText241->Wrap( -1 );
	bSizer16->Add( m_staticText241, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbleditar_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( lbleditar_cantidad, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_button9 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button9, 1, wxALL, 5 );

	m_button10 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_button10, 1, wxALL, 5 );


	bSizer5->Add( bSizer18, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_modificar::btn_editar_guardar ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_modificar::btn_editar_cancelar ), NULL, this );
}

ventana_modificar::~ventana_modificar()
{
	// Disconnect Events
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_modificar::btn_editar_guardar ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_modificar::btn_editar_cancelar ), NULL, this );

}

ventana_opciones_ventas::ventana_opciones_ventas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxVERTICAL );

	m_staticline41 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer50->Add( m_staticline41, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Vender"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button28->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer52->Add( m_button28, 0, wxALL, 5 );


	bSizer50->Add( bSizer52, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	m_button27 = new wxButton( this, wxID_ANY, wxT("Ver Facturas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button27->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer51->Add( m_button27, 0, wxALL, 5 );


	bSizer50->Add( bSizer51, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );

	m_button30 = new wxButton( this, wxID_ANY, wxT("Ranking"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button30->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer55->Add( m_button30, 0, wxALL, 5 );


	bSizer50->Add( bSizer55, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer50->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer50 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_vender ), NULL, this );
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_ver_ventas ), NULL, this );
	m_button30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_ranking ), NULL, this );
}

ventana_opciones_ventas::~ventana_opciones_ventas()
{
	// Disconnect Events
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_vender ), NULL, this );
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_ver_ventas ), NULL, this );
	m_button30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_opciones_ventas::btn_ranking ), NULL, this );

}

ventana_ventas::ventana_ventas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	grilla_historial_ventas = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 800,600 ), 0 );

	// Grid
	grilla_historial_ventas->CreateGrid( 0, 4 );
	grilla_historial_ventas->EnableEditing( false );
	grilla_historial_ventas->EnableGridLines( true );
	grilla_historial_ventas->EnableDragGridSize( true );
	grilla_historial_ventas->SetMargins( 0, 0 );

	// Columns
	grilla_historial_ventas->SetColSize( 0, 90 );
	grilla_historial_ventas->SetColSize( 1, 450 );
	grilla_historial_ventas->SetColSize( 2, 150 );
	grilla_historial_ventas->SetColSize( 3, 91 );
	grilla_historial_ventas->EnableDragColMove( false );
	grilla_historial_ventas->EnableDragColSize( true );
	grilla_historial_ventas->SetColLabelValue( 0, wxT("Factura") );
	grilla_historial_ventas->SetColLabelValue( 1, wxT("Descripción") );
	grilla_historial_ventas->SetColLabelValue( 2, wxT("Precio total") );
	grilla_historial_ventas->SetColLabelValue( 3, wxT("Fecha") );
	grilla_historial_ventas->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grilla_historial_ventas->EnableDragRowSize( true );
	grilla_historial_ventas->SetRowLabelSize( 0 );
	grilla_historial_ventas->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_historial_ventas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_CENTER );
	bSizer21->Add( grilla_historial_ventas, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Ventas Realizadas:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer22->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	t_ventas_realizadas = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_SUNKEN );
	t_ventas_realizadas->Wrap( -1 );
	bSizer22->Add( t_ventas_realizadas, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText44 = new wxStaticText( this, wxID_ANY, wxT(" | "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	bSizer22->Add( m_staticText44, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Fecha Actual:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer22->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	t_fecha_actual = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_STATIC );
	t_fecha_actual->Wrap( -1 );
	bSizer22->Add( t_fecha_actual, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT(" | "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer22->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Ver Factura"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button26, 0, wxALL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Busqueda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer21->Add( bSizer22, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer21 );
	this->Layout();
	bSizer21->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	grilla_historial_ventas->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_ventas::SelectGrillaVentCizq ), NULL, this );
	grilla_historial_ventas->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_ventas::AbrirFacturaDCizq ), NULL, this );
	grilla_historial_ventas->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_ventas::ClickGrillaVentasIzq ), NULL, this );
	grilla_historial_ventas->Connect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( ventana_ventas::ClickGrillaVentasDer ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ventas::btn_ver_factura ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ventas::btn_busqueda_avanzada_ventas ), NULL, this );
}

ventana_ventas::~ventana_ventas()
{
	// Disconnect Events
	grilla_historial_ventas->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_ventas::SelectGrillaVentCizq ), NULL, this );
	grilla_historial_ventas->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_ventas::AbrirFacturaDCizq ), NULL, this );
	grilla_historial_ventas->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_ventas::ClickGrillaVentasIzq ), NULL, this );
	grilla_historial_ventas->Disconnect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( ventana_ventas::ClickGrillaVentasDer ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ventas::btn_ver_factura ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ventas::btn_busqueda_avanzada_ventas ), NULL, this );

}

ventana_vender::ventana_vender( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	busqueda_producto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( busqueda_producto, 1, wxALL, 5 );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button24, 0, wxALL, 5 );


	bSizer26->Add( bSizer43, 0, wxALL|wxEXPAND, 5 );

	grilla_productos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grilla_productos->CreateGrid( 0, 3 );
	grilla_productos->EnableEditing( false );
	grilla_productos->EnableGridLines( true );
	grilla_productos->EnableDragGridSize( false );
	grilla_productos->SetMargins( 0, 0 );

	// Columns
	grilla_productos->SetColSize( 0, 188 );
	grilla_productos->SetColSize( 1, 111 );
	grilla_productos->SetColSize( 2, 79 );
	grilla_productos->EnableDragColMove( false );
	grilla_productos->EnableDragColSize( true );
	grilla_productos->SetColLabelValue( 0, wxT("Descripción") );
	grilla_productos->SetColLabelValue( 1, wxT("Precio U") );
	grilla_productos->SetColLabelValue( 2, wxT("Cantidad") );
	grilla_productos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grilla_productos->EnableDragRowSize( true );
	grilla_productos->SetRowLabelSize( 0 );
	grilla_productos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_productos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer26->Add( grilla_productos, 1, wxALL|wxEXPAND, 5 );


	bSizer23->Add( bSizer26, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer27->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	cantidad_a_vender = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 35,-1 ), wxTE_CENTER );
	bSizer27->Add( cantidad_a_vender, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button281 = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_button281->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button281->SetMaxSize( wxSize( 27,27 ) );

	bSizer27->Add( m_button281, 1, wxALL, 5 );

	m_button29 = new wxButton( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button29->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button29->SetMaxSize( wxSize( 27,27 ) );

	bSizer27->Add( m_button29, 1, wxALL, 5 );


	bSizer24->Add( bSizer27, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Descuento:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer28->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	descuento_a_vender = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 35,-1 ), wxTE_CENTER );
	bSizer28->Add( descuento_a_vender, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer28->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer24->Add( bSizer28, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_button20, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer24->Add( bSizer29, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	grilla_factura = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grilla_factura->CreateGrid( 0, 1 );
	grilla_factura->EnableEditing( false );
	grilla_factura->EnableGridLines( true );
	grilla_factura->EnableDragGridSize( false );
	grilla_factura->SetMargins( 0, 0 );

	// Columns
	grilla_factura->SetColSize( 0, 303 );
	grilla_factura->EnableDragColMove( false );
	grilla_factura->EnableDragColSize( true );
	grilla_factura->SetColLabelValue( 0, wxT("Factura") );
	grilla_factura->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTER );

	// Rows
	grilla_factura->EnableDragRowSize( true );
	grilla_factura->SetRowLabelSize( 0 );
	grilla_factura->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_factura->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_CENTER );
	bSizer24->Add( grilla_factura, 1, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer301;
	bSizer301 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText241 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxSize( 27,-1 ), 0 );
	m_staticText241->Wrap( -1 );
	bSizer301->Add( m_staticText241, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	lbl_total = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_RAISED );
	lbl_total->Wrap( -1 );
	bSizer301->Add( lbl_total, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer24->Add( bSizer301, 0, 0, 5 );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Realizar Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Quitar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( m_button28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer24->Add( bSizer30, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer23->Add( bSizer24, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_busqueda_productos ), NULL, this );
	grilla_productos->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_vender::SelectGrillaProdCizq ), NULL, this );
	grilla_productos->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_vender::RecargarGrillaProdCizq ), NULL, this );
	m_button281->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_sumar_cant ), NULL, this );
	m_button29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_restar_cant ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_agregar ), NULL, this );
	grilla_factura->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_vender::SelectGrillaFactCizq ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_realizar_venta ), NULL, this );
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_quitar_producto ), NULL, this );
}

ventana_vender::~ventana_vender()
{
	// Disconnect Events
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_busqueda_productos ), NULL, this );
	grilla_productos->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_vender::SelectGrillaProdCizq ), NULL, this );
	grilla_productos->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( ventana_vender::RecargarGrillaProdCizq ), NULL, this );
	m_button281->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_sumar_cant ), NULL, this );
	m_button29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_restar_cant ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_agregar ), NULL, this );
	grilla_factura->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( ventana_vender::SelectGrillaFactCizq ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_realizar_venta ), NULL, this );
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_vender::btn_quitar_producto ), NULL, this );

}

ventana_factura::ventana_factura( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("Factura Nro:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	bSizer46->Add( m_staticText39, 0, wxALL, 5 );

	lbl_factura_factura = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	lbl_factura_factura->Wrap( -1 );
	bSizer46->Add( lbl_factura_factura, 0, wxALL, 5 );


	bSizer44->Add( bSizer46, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Fecha: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer45->Add( m_staticText41, 0, wxALL, 5 );

	lbl_fecha_factura = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	lbl_fecha_factura->Wrap( -1 );
	bSizer45->Add( lbl_fecha_factura, 0, wxALL, 5 );


	bSizer44->Add( bSizer45, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	grilla_factura_factura = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grilla_factura_factura->CreateGrid( 0, 5 );
	grilla_factura_factura->EnableEditing( false );
	grilla_factura_factura->EnableGridLines( true );
	grilla_factura_factura->EnableDragGridSize( false );
	grilla_factura_factura->SetMargins( 0, 0 );

	// Columns
	grilla_factura_factura->SetColSize( 0, 50 );
	grilla_factura_factura->SetColSize( 1, 150 );
	grilla_factura_factura->SetColSize( 2, 100 );
	grilla_factura_factura->SetColSize( 3, 70 );
	grilla_factura_factura->SetColSize( 4, 110 );
	grilla_factura_factura->EnableDragColMove( false );
	grilla_factura_factura->EnableDragColSize( true );
	grilla_factura_factura->SetColLabelValue( 0, wxT("Cant") );
	grilla_factura_factura->SetColLabelValue( 1, wxT("Descripcion") );
	grilla_factura_factura->SetColLabelValue( 2, wxT("Precio Unitario") );
	grilla_factura_factura->SetColLabelValue( 3, wxT("Descuento") );
	grilla_factura_factura->SetColLabelValue( 4, wxT("Precio Total") );
	grilla_factura_factura->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grilla_factura_factura->EnableDragRowSize( true );
	grilla_factura_factura->SetRowLabelSize( 0 );
	grilla_factura_factura->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_factura_factura->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	bSizer44->Add( grilla_factura_factura, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer47->Add( m_staticText43, 0, wxALL, 5 );


	bSizer51->Add( bSizer47, 0, 0, 5 );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxVERTICAL );

	lbl_total_factura = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxBORDER_RAISED );
	lbl_total_factura->Wrap( -1 );
	bSizer50->Add( lbl_total_factura, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer51->Add( bSizer50, 1, 0, 5 );


	bSizer44->Add( bSizer51, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( ventana_factura::cerrar_ventana_factura ) );
}

ventana_factura::~ventana_factura()
{
	// Disconnect Events
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( ventana_factura::cerrar_ventana_factura ) );

}

ventana_busqueda::ventana_busqueda( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Buscar una Factura:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer59->Add( m_staticText52, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer31->Add( bSizer59, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Nro. Factura:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer57->Add( m_staticText50, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	nro_factura_unica = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( nro_factura_unica, 0, wxALL, 5 );


	bSizer31->Add( bSizer57, 0, 0, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Buscar segun rango:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer60->Add( m_staticText53, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer31->Add( bSizer60, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Fecha Inicial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer32->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Dia:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer37->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	dia_inicial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer37->Add( dia_inicial, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Mes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer37->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	mes_inicial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer37->Add( mes_inicial, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Año:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer37->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	anio_inicial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), 0 );
	bSizer37->Add( anio_inicial, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer32->Add( bSizer37, 1, wxEXPAND, 5 );


	bSizer31->Add( bSizer32, 0, 0, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Fecha Final"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer34->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer371;
	bSizer371 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText321 = new wxStaticText( this, wxID_ANY, wxT("Dia:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	bSizer371->Add( m_staticText321, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	dia_final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer371->Add( dia_final, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText331 = new wxStaticText( this, wxID_ANY, wxT("Mes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText331->Wrap( -1 );
	bSizer371->Add( m_staticText331, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	mes_final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer371->Add( mes_final, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText341 = new wxStaticText( this, wxID_ANY, wxT("Año:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText341->Wrap( -1 );
	bSizer371->Add( m_staticText341, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	anio_final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 202,-1 ), 0 );
	bSizer371->Add( anio_final, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer34->Add( bSizer371, 1, wxEXPAND, 5 );


	bSizer31->Add( bSizer34, 0, 0, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Nro. Factura Inicial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer35->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	nro_factura_inicial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer35->Add( nro_factura_inicial, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer31->Add( bSizer35, 0, 0, 5 );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Nro. Factura Final: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer36->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	nro_factura_final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	bSizer36->Add( nro_factura_final, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer31->Add( bSizer36, 0, 0, 5 );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer31->Add( bSizer38, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer31 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_busqueda::btn_aceptar_busqueda ), NULL, this );
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_busqueda::btn_cancelar_busqueda ), NULL, this );
}

ventana_busqueda::~ventana_busqueda()
{
	// Disconnect Events
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_busqueda::btn_aceptar_busqueda ), NULL, this );
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_busqueda::btn_cancelar_busqueda ), NULL, this );

}

ventana_ranking::ventana_ranking( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_comboBoxVR = new wxComboBox( this, wxID_ANY, wxT("Categoria"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer40->Add( m_comboBoxVR, 0, wxALL, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button22, 0, wxALL, 5 );


	bSizer39->Add( bSizer40, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	grilla_ranking = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grilla_ranking->CreateGrid( 0, 1 );
	grilla_ranking->EnableEditing( true );
	grilla_ranking->EnableGridLines( true );
	grilla_ranking->EnableDragGridSize( false );
	grilla_ranking->SetMargins( 0, 0 );

	// Columns
	grilla_ranking->SetColSize( 0, 133 );
	grilla_ranking->EnableDragColMove( false );
	grilla_ranking->EnableDragColSize( true );
	grilla_ranking->SetColLabelValue( 0, wxT("Producto más vendido") );
	grilla_ranking->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTER );

	// Rows
	grilla_ranking->EnableDragRowSize( true );
	grilla_ranking->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grilla_ranking->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer41->Add( grilla_ranking, 1, wxALL|wxEXPAND, 5 );


	bSizer39->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_button23, 0, wxALL, 5 );


	bSizer39->Add( bSizer42, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer39 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ranking::btn_buscar_ranking ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ranking::btn_cerrar_ranking ), NULL, this );
}

ventana_ranking::~ventana_ranking()
{
	// Disconnect Events
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ranking::btn_buscar_ranking ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_ranking::btn_cerrar_ranking ), NULL, this );

}
