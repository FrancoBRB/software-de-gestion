///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statline.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ventana_principal
///////////////////////////////////////////////////////////////////////////////
class ventana_principal : public wxFrame
{
	private:

	protected:
		wxStaticLine* m_staticline22;
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText45;
		wxStaticText* m_staticText46;
		wxStaticText* m_staticText47;
		wxStaticLine* m_staticline21;
		wxButton* btn_principal_stock;
		wxStaticText* m_staticText48;
		wxButton* btn_principal_ventas;
		wxStaticLine* m_staticline2;

		// Virtual event handlers, override them in your derived class
		virtual void clickAbrirStock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickAbrirVentas( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Software de Gestion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 539,331 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~ventana_principal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_stock
///////////////////////////////////////////////////////////////////////////////
class ventana_stock : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* busqueda_stock;
		wxButton* m_button_buscarstock;
		wxButton* m_button26;
		wxButton* m_button27;
		wxGrid* grilla_stock;
		wxStaticText* m_staticText21;
		wxStaticText* t_stock;
		wxStaticText* m_staticText38;
		wxButton* m_button_sumar;
		wxButton* m_button_restar;
		wxButton* m_button_agregar;
		wxButton* m_button_editar;
		wxButton* m_button_eliminar;

		// Virtual event handlers, override them in your derived class
		virtual void btn_busqueda( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_recargar_stock( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_VerEliminados( wxCommandEvent& event ) { event.Skip(); }
		virtual void SelectGrillaStockCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaStockI( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaStockD( wxGridEvent& event ) { event.Skip(); }
		virtual void btn_sumar( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_restar( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_agregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_editar_producto( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_eliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_stock( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Stock"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~ventana_stock();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_agregar
///////////////////////////////////////////////////////////////////////////////
class ventana_agregar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* lblagregar_id;
		wxStaticText* m_staticText21;
		wxTextCtrl* lblagregar_nombre;
		wxStaticText* m_staticText22;
		wxTextCtrl* lblagregar_marca;
		wxStaticText* m_staticText23;
		wxTextCtrl* lblagregar_categoria;
		wxStaticText* m_staticText24;
		wxTextCtrl* lblagregar_precio;
		wxStaticText* m_staticText241;
		wxTextCtrl* lblagregar_cantidad;
		wxButton* m_button9;
		wxButton* m_button10;

		// Virtual event handlers, override them in your derived class
		virtual void btn_agregar_producto( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_producto_cancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_agregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,300 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );

		~ventana_agregar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_modificar
///////////////////////////////////////////////////////////////////////////////
class ventana_modificar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxStaticText* id_editar;
		wxStaticText* m_staticText21;
		wxTextCtrl* lbleditar_nombre;
		wxStaticText* m_staticText22;
		wxTextCtrl* lbleditar_marca;
		wxStaticText* m_staticText23;
		wxTextCtrl* lbleditar_categoria;
		wxStaticText* m_staticText24;
		wxTextCtrl* lbleditar_precio;
		wxStaticText* m_staticText241;
		wxTextCtrl* lbleditar_cantidad;
		wxButton* m_button9;
		wxButton* m_button10;

		// Virtual event handlers, override them in your derived class
		virtual void btn_editar_guardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_editar_cancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_modificar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editar Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,300 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX );

		~ventana_modificar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_opciones_ventas
///////////////////////////////////////////////////////////////////////////////
class ventana_opciones_ventas : public wxFrame
{
	private:

	protected:
		wxStaticLine* m_staticline41;
		wxButton* m_button28;
		wxButton* m_button27;
		wxButton* m_button30;
		wxStaticLine* m_staticline4;

		// Virtual event handlers, override them in your derived class
		virtual void btn_vender( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_ver_ventas( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_ranking( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_opciones_ventas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,250 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~ventana_opciones_ventas();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_ventas
///////////////////////////////////////////////////////////////////////////////
class ventana_ventas : public wxDialog
{
	private:

	protected:
		wxGrid* grilla_historial_ventas;
		wxStaticText* m_staticText42;
		wxStaticText* t_ventas_realizadas;
		wxStaticText* m_staticText44;
		wxStaticText* m_staticText17;
		wxStaticText* t_fecha_actual;
		wxStaticText* m_staticText19;
		wxButton* m_button26;
		wxButton* m_button21;

		// Virtual event handlers, override them in your derived class
		virtual void SelectGrillaVentCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void AbrirFacturaDCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaVentasIzq( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaVentasDer( wxGridEvent& event ) { event.Skip(); }
		virtual void btn_ver_factura( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_busqueda_avanzada_ventas( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_ventas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~ventana_ventas();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_vender
///////////////////////////////////////////////////////////////////////////////
class ventana_vender : public wxDialog
{
	private:

	protected:
		wxTextCtrl* busqueda_producto;
		wxButton* m_button24;
		wxGrid* grilla_productos;
		wxStaticText* m_staticText17;
		wxTextCtrl* cantidad_a_vender;
		wxButton* m_button281;
		wxButton* m_button29;
		wxStaticText* m_staticText18;
		wxTextCtrl* descuento_a_vender;
		wxStaticText* m_staticText24;
		wxButton* m_button20;
		wxGrid* grilla_factura;
		wxStaticText* m_staticText241;
		wxStaticText* lbl_total;
		wxButton* m_button23;
		wxButton* m_button28;

		// Virtual event handlers, override them in your derived class
		virtual void btn_busqueda_productos( wxCommandEvent& event ) { event.Skip(); }
		virtual void SelectGrillaProdCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void RecargarGrillaProdCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void btn_sumar_cant( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_restar_cant( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_agregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void SelectGrillaFactCizq( wxGridEvent& event ) { event.Skip(); }
		virtual void btn_realizar_venta( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_quitar_producto( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_vender( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Vender"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 711,600 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~ventana_vender();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_factura
///////////////////////////////////////////////////////////////////////////////
class ventana_factura : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText39;
		wxStaticText* lbl_factura_factura;
		wxStaticText* m_staticText41;
		wxStaticText* lbl_fecha_factura;
		wxGrid* grilla_factura_factura;
		wxStaticText* m_staticText43;
		wxStaticText* lbl_total_factura;

		// Virtual event handlers, override them in your derived class
		virtual void cerrar_ventana_factura( wxMouseEvent& event ) { event.Skip(); }


	public:

		ventana_factura( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Factura"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,500 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~ventana_factura();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_busqueda
///////////////////////////////////////////////////////////////////////////////
class ventana_busqueda : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText52;
		wxStaticText* m_staticText50;
		wxTextCtrl* nro_factura_unica;
		wxStaticText* m_staticText53;
		wxStaticText* m_staticText27;
		wxStaticText* m_staticText32;
		wxTextCtrl* dia_inicial;
		wxStaticText* m_staticText33;
		wxTextCtrl* mes_inicial;
		wxStaticText* m_staticText34;
		wxTextCtrl* anio_inicial;
		wxStaticText* m_staticText28;
		wxStaticText* m_staticText321;
		wxTextCtrl* dia_final;
		wxStaticText* m_staticText331;
		wxTextCtrl* mes_final;
		wxStaticText* m_staticText341;
		wxTextCtrl* anio_final;
		wxStaticText* m_staticText29;
		wxTextCtrl* nro_factura_inicial;
		wxStaticText* m_staticText31;
		wxTextCtrl* nro_factura_final;
		wxButton* m_button23;
		wxButton* m_button24;

		// Virtual event handlers, override them in your derived class
		virtual void btn_aceptar_busqueda( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_cancelar_busqueda( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_busqueda( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Busqueda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,339 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_busqueda();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_ranking
///////////////////////////////////////////////////////////////////////////////
class ventana_ranking : public wxDialog
{
	private:

	protected:
		wxComboBox* m_comboBoxVR;
		wxButton* m_button22;
		wxGrid* grilla_ranking;
		wxButton* m_button23;

		// Virtual event handlers, override them in your derived class
		virtual void btn_buscar_ranking( wxCommandEvent& event ) { event.Skip(); }
		virtual void btn_cerrar_ranking( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_ranking( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ranking"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 428,372 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_ranking();

};

