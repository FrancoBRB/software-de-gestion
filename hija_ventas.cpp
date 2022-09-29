#include "hija_ventas.h"
#include <wx/grid.h>
#include "Producto.h"
#include <wx/msgdlg.h>
#include "hija_busqueda.h"
#include "hija_factura.h"
#include <wx/icon.h>
#include "iconofacturas.xpm"

hija_ventas::hija_ventas(wxWindow *parent, Sistema *sistema) : ventana_ventas(parent), m_sistema(sistema){
	SetIcon(wxIcon(iconofacturas_xpm));
	int pos, precio_t_aux = 0, cont = 0, i = 0, caracteres = 74, fac_aux;
	std::string descripcion;
	
	if(m_sistema -> VerVentas().VentaTam()==0){
		fac_aux = 0;
	}else{		
		fac_aux = m_sistema -> VerVentas().VerFactura(0);
	}
	
	while (cont < m_sistema -> VerVentas().VentaTam()) { /* Carga la lista de facturas en la grilla */
		while(fac_aux == m_sistema -> VerVentas().VerFactura(cont) && cont < m_sistema -> VerVentas().VentaTam()) {
			precio_t_aux += m_sistema -> VerVentas().VerPTotal(cont);
			pos = m_sistema -> VerStock().BuscarID(m_sistema -> VerVentas().VerID(cont));
			Producto p = m_sistema -> VerStock().VerProductoStock(pos);
			descripcion += p.VerNombre() + " " + p.VerMarca() + ", ";
			cont++;
		}
		if (descripcion.size() > 74) {
			descripcion = descripcion.substr(0, 70);
			descripcion += "...  ";
		}
		grilla_historial_ventas -> AppendRows();
		grilla_historial_ventas -> SetCellValue(i, 0, std::to_string(m_sistema -> VerVentas().VerFactura(cont-1)));
		grilla_historial_ventas -> SetCellValue(i, 1, descripcion.substr(0, descripcion.size()-2));
		grilla_historial_ventas -> SetCellValue(i, 2, "$" + std::to_string(precio_t_aux));
		grilla_historial_ventas -> SetCellValue(i, 3, FechaString(m_sistema -> VerVentas().VerFecha(cont-1)));
		precio_t_aux = 0;
		descripcion.clear();
		i++;
		fac_aux = m_sistema -> VerVentas().VerFactura(cont);
	}
	
	t_ventas_realizadas -> SetLabel (std::to_string(i));
	t_fecha_actual -> SetLabel (FechaString(VerFechaActual()));
}

void hija_ventas::refrescar_grilla_ventas() { /* Metodo para recargar la grilla de productos */
	if (grilla_historial_ventas -> GetNumberRows() != 0){	/* Si la grilla no esta vacia */
		grilla_historial_ventas -> DeleteRows(0, grilla_historial_ventas -> GetNumberRows()); /* Borra la grilla */
	}
	
	int pos, precio_t_aux = 0, cont = 0, i = 0, fac_aux;
	std::string descripcion;
	fac_aux = m_sistema -> VerVentas().VerFactura(0);
	
	while(cont < m_sistema -> VerVentas().VentaTam()){
		while(fac_aux == m_sistema -> VerVentas().VerFactura(cont) and cont < m_sistema -> VerVentas().VentaTam()){
			precio_t_aux += m_sistema -> VerVentas().VerPTotal(cont);
			pos = m_sistema -> VerStock().BuscarID(m_sistema -> VerVentas().VerID(cont));
			Producto p = m_sistema -> VerStock().VerProductoStock(pos);
		    descripcion += p.VerNombre() + " " + p.VerMarca() + ", ";
			cont++;
		}
		if (descripcion.size() > 74) {
			descripcion = descripcion.substr(0, 70);
			descripcion += "...  ";
		}
		grilla_historial_ventas -> AppendRows();
		grilla_historial_ventas -> SetCellValue(i, 0, std::to_string(m_sistema -> VerVentas().VerFactura(cont-1)));
		grilla_historial_ventas -> SetCellValue(i, 1, descripcion.substr(0, descripcion.size()-2));
		grilla_historial_ventas -> SetCellValue(i, 2, "$" + std::to_string(precio_t_aux));
		grilla_historial_ventas -> SetCellValue(i, 3, FechaString(m_sistema -> VerVentas().VerFecha(cont-1)));
		precio_t_aux = 0;
		descripcion.clear();
		i++;
		fac_aux = m_sistema -> VerVentas().VerFactura(cont);
	}
	
	t_ventas_realizadas -> SetLabel (std::to_string(i));
	t_fecha_actual -> SetLabel (FechaString(VerFechaActual()));
}

void hija_ventas::btn_busqueda_avanzada_ventas( wxCommandEvent& event )  { /* Boton para ingresar a la ventana de busquedas */
	if (m_sistema -> VerVentas().VentaTam() == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		hija_busqueda win_busqueda(this, m_sistema, grilla_historial_ventas);
		win_busqueda.ShowModal();
	}
}

void hija_ventas::btn_ver_factura( wxCommandEvent& event )  { /* Boton para ver los detalles de una factura seleccionada */
	if (m_sistema -> VerVentas().VentaTam() == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		int fila = grilla_historial_ventas -> GetGridCursorRow();
		long nro_factura;
		grilla_historial_ventas -> GetCellValue(fila, 0).ToLong(&nro_factura);
		hija_factura win_factura(this, m_sistema, nro_factura);
		win_factura.ShowModal();
	}
}

void hija_ventas::ClickGrillaVentasIzq( wxGridEvent& event )  { /* Ordena la grilla (0 - n) segun un criterio (click izquierdo) */
	int columna = event.GetCol();
	if (m_sistema -> VerVentas().VentaTam() > 0) {
		switch (columna) {
		case 0:
			m_sistema -> VerVentas().OrdenarVentas(1); /* Por factura */
			break;
		case 3:
			m_sistema -> VerVentas().OrdenarVentas(3); /* Por fecha */
			break;
		}	
		refrescar_grilla_ventas();
	}
}

void hija_ventas::ClickGrillaVentasDer( wxGridEvent& event )  {  /* Ordena la grilla (n - 0) segun un criterio (click derecho) */
	int columna = event.GetCol();
	if (m_sistema -> VerVentas().VentaTam() > 0) {
		switch (columna) {
		case 0:
			m_sistema -> VerVentas().OrdenarVentas(2); /* Por factura */
			break;
		case 3:
			m_sistema -> VerVentas().OrdenarVentas(4); /* Por fecha */
			break;
		}	
		refrescar_grilla_ventas();
	}
}

void hija_ventas::SelectGrillaVentCizq( wxGridEvent& event )  { /* Metodo para seleccionar el producto clickeado (click izquierdo) */
	grilla_historial_ventas -> SelectRow(event.GetRow());
	grilla_historial_ventas -> SetGridCursor(event.GetRow(),event.GetCol());
}

void hija_ventas::AbrirFacturaDCizq( wxGridEvent& event )  {
	int fila = grilla_historial_ventas -> GetGridCursorRow();
	long nro_factura;
	grilla_historial_ventas -> GetCellValue(fila, 0).ToLong(&nro_factura);
	hija_factura win_factura(this, m_sistema, nro_factura);
	win_factura.ShowModal();
}

hija_ventas::~hija_ventas() {
	m_sistema -> VerVentas().OrdenarVentas(1);
}

