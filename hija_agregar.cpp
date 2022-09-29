#include "hija_agregar.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <wx/wx.h>
#include <wx/valtext.h>
#include "iconoagregar.xpm"
#include <wx/icon.h>

hija_agregar::hija_agregar(wxWindow *parent,Sistema *sistema) : ventana_agregar(parent), m_sistema(sistema) {
	SetIcon(wxIcon(iconoagregar_xpm));
	/* Validadores para cada barra de texto */
	wxTextValidator numerico(wxFILTER_NUMERIC);
	wxTextValidator alfabetico(wxFILTER_ALPHA);
	lblagregar_id -> SetValidator(numerico);
	lblagregar_marca -> SetValidator(alfabetico);
	lblagregar_categoria -> SetValidator(alfabetico);
	lblagregar_precio -> SetValidator(numerico);
	lblagregar_cantidad -> SetValidator(numerico);
	
	lblagregar_cantidad -> SetValue(std::to_string(0)); /* Cantidad inicializada en 0 */
	lblagregar_precio -> SetValue(std::to_string(0)); /* Precio inicializado en 0 */
}

void hija_agregar::btn_agregar_producto( wxCommandEvent& event )  { /* Boton para agregar un nuevo producto si se ingresaron correctamente los datos */
	long precio, cantidad;
	std::string id = wx_to_std(lblagregar_id -> GetValue());
	std::string nombre = wx_to_std(lblagregar_nombre -> GetValue());
	std::string marca = wx_to_std(lblagregar_marca -> GetValue());
	std::string categoria = wx_to_std(lblagregar_categoria -> GetValue());
	lblagregar_precio -> GetValue().ToLong(&precio);
	lblagregar_cantidad -> GetValue().ToLong(&cantidad);
	
	
	Corregir(nombre); Corregir (marca); Corregir (categoria); /* Corrige los datos ingresados, la letra inicial en mayus, el resto en minus */
	Producto p(nombre, marca, categoria, id, cantidad, precio);
	
	std::string error = m_sistema -> VerStock().VerificarID(id) + p.VerificarProducto(); /* Verifica los datos ingresados antes de agregarlos al archivo */
	if (error.empty()) {		
		m_sistema -> VerStock().AgregarProducto(p);	
		m_sistema -> VerStock().GuardarStock();
		EndModal(1);
	}
	else {
		wxMessageBox(error, "Error", wxOK | wxICON_ERROR);
	}
}

void hija_agregar::btn_producto_cancelar( wxCommandEvent& event )  { /* Boton para cerrar la ventana anulando cualquier dato ingresado */
	EndModal(0);
}
