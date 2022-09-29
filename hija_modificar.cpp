#include "hija_modificar.h"
#include <wx/valtext.h>
#include <vector>
#include "iconomodificar.xpm"
#include <wx/icon.h>

hija_modificar::hija_modificar(wxWindow *parent, Sistema *sistema, wxGrid* grilla_stock, const std::vector <int> &pos_b) : ventana_modificar(parent), m_sistema(sistema), m_grilla_stock(grilla_stock), m_pos_b(pos_b){
	SetIcon(wxIcon(iconomodificar_xpm));
	/* Validadores para cada barra de texto */
	wxTextValidator numerico(wxFILTER_NUMERIC);
	wxTextValidator alfabetico(wxFILTER_ALPHA);
	lbleditar_marca -> SetValidator (alfabetico);
	lbleditar_categoria -> SetValidator (alfabetico);
	lbleditar_precio -> SetValidator (numerico);
	lbleditar_cantidad -> SetValidator (numerico);
	
	int pos, fila = m_grilla_stock -> GetGridCursorRow();
	Producto p;
	
	if (m_pos_b.empty()) { /* Si el vector de busqueda tiene resultados, se obtiene la posicion de ahi, de lo contrario, se usa la posicion original */ 
		pos = m_sistema -> VerStock().VerPosicion(fila);
		p = m_sistema -> VerStock().VerProductoStock(pos);
	} else {
		pos = pos_b[fila];
		p = m_sistema -> VerStock().VerProductoStock(pos);
	}
	
	id_editar -> SetLabel (p.VerID());
	lbleditar_nombre -> SetValue(p.VerNombre());
	lbleditar_marca -> SetValue(p.VerMarca());
	lbleditar_categoria -> SetValue(p.VerCategoria());
	lbleditar_precio -> SetValue(std::to_string(p.VerPrecio()));
	lbleditar_cantidad -> SetValue(std::to_string(p.VerCantidad()));
}

void hija_modificar::btn_editar_guardar( wxCommandEvent& event )  { /* Boton para guardar los datos de un producto */
	int pos, fila = m_grilla_stock -> GetGridCursorRow(); 
	
	if (m_pos_b.empty()) {
		pos = m_sistema -> VerStock().VerPosicion(fila);
	} else {
		pos = m_pos_b[fila];
	}
	
	long precio, cantidad;
	std::string nombre = wx_to_std(lbleditar_nombre -> GetValue());
	std::string marca = wx_to_std(lbleditar_marca -> GetValue());
	std::string categoria = wx_to_std(lbleditar_categoria -> GetValue());	
	lbleditar_precio -> GetValue().ToLong(&precio);
	lbleditar_cantidad -> GetValue().ToLong(&cantidad);
	
	Corregir(nombre); Corregir (marca); Corregir (categoria); /* Corrige los datos ingresados, la letra inicial en mayus, el resto en minus */
	
	Producto p = m_sistema -> VerStock().VerProductoStock(pos);
	p.ModificarNombre(nombre);
	p.ModificarMarca(marca);
	p.ModificarCategoria(categoria);
	p.ModificarPrecio(precio);
	p.ModificarCantidad(cantidad);
	
	std::string error = p.VerificarProducto(); /* Verifica los datos ingresados antes de agregarlos al archivo */
	if (error.empty()) {
		m_sistema -> VerStock().VerProductoStock(pos) = p;
		m_sistema -> VerStock().GuardarStock();
		EndModal(1);
	}
	else {
		wxMessageBox(error, "Error", wxOK | wxICON_ERROR);
	}	
}

void hija_modificar::btn_editar_cancelar( wxCommandEvent& event )  { /* Boton para cerrar la ventana anulando cualquier dato ingresado */
	EndModal(0);
}

