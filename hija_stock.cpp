#include "hija_stock.h"
#include "Sistema.h"
#include <wx/msgdlg.h>
#include "hija_agregar.h"
#include "hija_modificar.h"
#include <vector>
#include <wx/icon.h>
#include "iconoStock.xpm"

hija_stock::hija_stock(wxWindow *parent, Sistema *sistema) : ventana_stock(parent), m_sistema(sistema){
	SetIcon(wxIcon(iconoStock_xpm));
	int fila = 0;
	
	for(int i=0; i<m_sistema -> VerStock().VerTamStock(); i++) { /* Carga los productos disponibles en la grilla */
		p = m_sistema -> VerStock().VerProductoStock(i);
		if (!p.VerEliminado()) {
			grilla_stock -> AppendRows();
			grilla_stock -> SetCellValue(fila, 0, p.VerID());
			grilla_stock -> SetCellValue(fila, 1, p.VerNombre());
			grilla_stock -> SetCellValue(fila, 2, p.VerMarca());
			grilla_stock -> SetCellValue(fila, 3, p.VerCategoria());
			grilla_stock -> SetCellValue(fila, 4, "$" + std::to_string(p.VerPrecio()));
			grilla_stock -> SetCellValue(fila, 5, std::to_string(p.VerCantidad()));
			cont_disponibles++;
			fila++;
		}
	}
//	grilla_stock -> AutoSizeRows();
//	grilla_stock -> AutoSizeColumns();
	
	t_stock -> SetLabel (std::to_string(cont_disponibles)); /* Muestra el stock total disponible */
}

void hija_stock::btn_sumar( wxCommandEvent& event )  { /* Boton para agregar en 1 la cantidad de un producto */
	if (cont_disponibles == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		int pos, fila = grilla_stock -> GetGridCursorRow();
		
		if (pos_b.empty()) { /* Si el vector de busqueda tiene resultados, se obtiene la posicion de ahi, de lo contrario, se usa la posicion original */
			pos = m_sistema -> VerStock().VerPosicion(fila);
		} else {
			pos = pos_b[fila];
		}
		
		m_sistema -> VerStock().VerProductoStock(pos)++;
		m_sistema -> VerStock().GuardarStock();
		
		grilla_stock -> SetCellValue(fila, 5, std::to_string(m_sistema -> VerStock().VerProductoStock(pos).VerCantidad()));
	}
}

void hija_stock::btn_restar( wxCommandEvent& event )  { /* Boton para restar en 1 la cantidad de un producto */
	if (cont_disponibles == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		std::string alerta;
		int pos, fila = grilla_stock -> GetGridCursorRow();
		
		if (pos_b.empty()) {
			pos = m_sistema -> VerStock().VerPosicion(fila);
		} else {
			pos = pos_b[fila];
		}
		p = m_sistema -> VerStock().VerProductoStock(pos);
		
		m_sistema -> VerStock().VerProductoStock(pos)--;
		m_sistema -> VerStock().GuardarStock();
		
		grilla_stock -> SetCellValue(fila, 5, std::to_string(m_sistema -> VerStock().VerProductoStock(pos).VerCantidad()));
		
		if ((p.VerCantidad() <= 5) && (p.VerCantidad() > 0)) {
			alerta = "Quedan pocas unidades de ''" + p.VerID() + " - " + p.VerNombre() + ", " + p.VerMarca() + "''";
		}
		if (!alerta.empty()) {
			wxMessageBox(alerta, "¡Revise su stock!", wxOK | wxICON_EXCLAMATION);
		}
	}
}

void hija_stock::btn_agregar( wxCommandEvent& event )  { /* Boton para agregar un nuevo producto */
	hija_agregar win_agregar(this, m_sistema); 
	
	if(win_agregar.ShowModal() == 1){
		refrescar_grilla_stock();
	}
}

void hija_stock::btn_editar_producto( wxCommandEvent& event )  { /* Boton para editar un producto seleccionado */
	if (cont_disponibles == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		hija_modificar win_editar(this, m_sistema, grilla_stock, pos_b); 
		
		if(win_editar.ShowModal() == 1){
			refrescar_grilla_stock();
		}
	}
}

void hija_stock::btn_eliminar( wxCommandEvent& event )  { /* Boton para eliminar un producto seleccionado (No se elimina del archivo, solo de la grilla) */
	if (cont_disponibles == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		int pos, fila = grilla_stock -> GetGridCursorRow();
		
		if (pos_b.empty()) { 
			pos = m_sistema -> VerStock().VerPosicion(fila);
		} else {
			pos = pos_b[fila];
		}
		p = m_sistema -> VerStock().VerProductoStock(pos);
		
		int opcion = wxMessageBox("Borrar ''" + p.VerID() + " - " + p.VerNombre() + ", " + p.VerMarca() + "'' ?", "¡Advertencia!", wxYES_NO);
		
		if (opcion == wxYES) {
			m_sistema -> VerStock().VerProductoStock(pos).EliminarProducto();
			m_sistema -> VerStock().GuardarStock();
			refrescar_grilla_stock();
		}
	}
}

void hija_stock::btn_busqueda( wxCommandEvent& event )  { /* Boton para realizar una busqueda segun el criterio ingresado en la barra */
	pos_b.clear();
	int cont = 0;
	
	if (busqueda_stock -> IsEmpty()) { /* Verifica que se haya ingresado un criterio de busqueda */
		//refrescar_grilla_stock ();
		wxMessageBox("¡Debe ingresar una busqueda!", "¡Error!", wxOK | wxICON_ERROR);
	} else {
		if (cont_disponibles == 0) {
			wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
		} else {
			
			/* Busqueda por ID */
			int columna_ID = m_sistema -> VerStock().BuscarID(wx_to_std(busqueda_stock -> GetValue()));
			if ((!m_sistema -> VerStock().VerProductoStock(columna_ID).VerEliminado()) && (columna_ID != -1)) {
				pos_b.push_back(columna_ID);
			}
			
			/* Busqueda por NOMBRE */
			int columna_nombre = m_sistema -> VerStock().BuscarProducto(wx_to_std(busqueda_stock -> GetValue()), 0);
			while (columna_nombre != -1) {
				for(size_t i=0;i<pos_b.size();i++) { /* Si el resultado obtenido ya fue encontrado anteriormente, se lo saltea */
					if (columna_nombre == pos_b[i]) {
						cont++;
					}
				}
				if ((!m_sistema -> VerStock().VerProductoStock(columna_nombre).VerEliminado()) && (cont == 0)) {
					pos_b.push_back(columna_nombre);
				}
				cont = 0;
				columna_nombre = m_sistema -> VerStock().BuscarProducto(wx_to_std(busqueda_stock -> GetValue()), columna_nombre + 1);
			}
			
			/* Busqueda por MARCA */
			int columna_marca = m_sistema -> VerStock().BuscarMarca(wx_to_std(busqueda_stock -> GetValue()), 0);
			while (columna_marca != -1) {
				for(size_t i=0;i<pos_b.size();i++) { 
					if (columna_marca == pos_b[i]) {
						cont++;
					}
				}
				if ((!m_sistema -> VerStock().VerProductoStock(columna_marca).VerEliminado()) && (cont == 0)) {
					pos_b.push_back(columna_marca);
				}
				cont = 0;
				columna_marca = m_sistema -> VerStock().BuscarMarca(wx_to_std(busqueda_stock -> GetValue()), columna_marca + 1);
			}
			
			/* Busqueda por CATEGORIA */
			int columna_categoria = m_sistema -> VerStock().BuscarCategoria(wx_to_std(busqueda_stock -> GetValue()), 0);
			while (columna_categoria != -1) {
				for(size_t i=0;i<pos_b.size();i++) { 
					if (columna_categoria == pos_b[i]) {
						cont++;
					}
				}
				if ((!m_sistema -> VerStock().VerProductoStock(columna_categoria).VerEliminado()) && (cont == 0)) {
					pos_b.push_back(columna_categoria);
				}
				cont = 0;
				columna_categoria = m_sistema -> VerStock().BuscarCategoria(wx_to_std(busqueda_stock -> GetValue()), columna_categoria + 1);
			}
			
			/* Si se encontraron resultados, los muestra en la grilla */
			if (pos_b.empty()) {
				wxMessageBox("No se encontraron coincidencias", "¡Aviso!", wxOK | wxICON_INFORMATION);
			} else {
				if (grilla_stock -> GetNumberRows() != 0) {
					grilla_stock -> DeleteRows(0, grilla_stock -> GetNumberRows());
				}
				for(size_t i=0;i<pos_b.size();i++) { 
					p = m_sistema -> VerStock().VerProductoStock(pos_b[i]);
					grilla_stock -> AppendRows();
					grilla_stock -> SetCellValue(i, 0, p.VerID());
					grilla_stock -> SetCellValue(i, 1, p.VerNombre());
					grilla_stock -> SetCellValue(i, 2, p.VerMarca());
					grilla_stock -> SetCellValue(i, 3, p.VerCategoria());
					grilla_stock -> SetCellValue(i, 4, "$" + std::to_string(p.VerPrecio()));
					grilla_stock -> SetCellValue(i, 5, std::to_string(p.VerCantidad()));
				}
			}
		}
	}
}

void hija_stock::btn_recargar_stock( wxCommandEvent& event )  { /*Boton para recargar la grilla de productos */
	refrescar_grilla_stock();
}

void hija_stock::btn_VerEliminados( wxCommandEvent& event )  { /* Boton para ver los productos discontinuados */
	if (cont_disponibles != m_sistema -> VerStock().VerTamStock()) {
		OnOff (false);
		
		if (grilla_stock -> GetNumberRows()!=0) {
			grilla_stock -> DeleteRows(0,grilla_stock -> GetNumberRows());
		}
		for(int i=0, j=0;i<m_sistema -> VerStock().VerTamStock();i++) { 
			p = m_sistema -> VerStock().VerProductoStock(i);
			if (p.VerEliminado()) {
				grilla_stock -> AppendRows();
				grilla_stock -> SetCellValue(j, 0, p.VerID());
				grilla_stock -> SetCellValue(j, 1, p.VerNombre());
				grilla_stock -> SetCellValue(j, 2, p.VerMarca());
				grilla_stock -> SetCellValue(j, 3, p.VerCategoria());
				grilla_stock -> SetCellValue(j, 4, "$" + std::to_string(p.VerPrecio()));
				grilla_stock -> SetCellValue(j, 5, std::to_string(p.VerCantidad()));
				j++;
			}
		}
	} else {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	}
}

void hija_stock::ClickGrillaStockI( wxGridEvent& event )  { /* Ordena la grilla (A - Z o 0 - n) segun la columna clickeada (excepto ID) con el click izquierdo */
	int columna = event.GetCol();
	
	if (cont_disponibles > 0) {
		switch (columna) {
		case 1:
			m_sistema->VerStock().OrdenarStock(1);
			break;
		case 2:
			m_sistema->VerStock().OrdenarStock(3);
			break;
		case 3:
			m_sistema->VerStock().OrdenarStock(5);
			break;
		case 4:
			m_sistema->VerStock().OrdenarStock(7);
			break;
		case 5:
			m_sistema->VerStock().OrdenarStock(9);
			break;
		}
		
		refrescar_grilla_stock();
	}
}

void hija_stock::ClickGrillaStockD( wxGridEvent& event )  { /* Ordena la grilla (Z - A o n - 0) segun la columna clickeada (excepto ID) con el click derecho */
	int columna = event.GetCol();
	
	if (cont_disponibles  > 0) {
		switch (columna) {
		case 1:
			m_sistema -> VerStock().OrdenarStock(2);
			break;
		case 2:
			m_sistema -> VerStock().OrdenarStock(4);
			break;
		case 3:
			m_sistema -> VerStock().OrdenarStock(6);
			break;
		case 4:
			m_sistema -> VerStock().OrdenarStock(8);
			break;
		case 5:
			m_sistema -> VerStock().OrdenarStock(10);
			break;
		}
		
		refrescar_grilla_stock();
	}
}

void hija_stock::refrescar_grilla_stock () { /* Metodo para recargar la grilla de productos */
	OnOff (true);
	pos_b.clear();
	
	cont_disponibles = 0;
	int fila = 0;
	
	if (grilla_stock -> GetNumberRows() != 0){	/* Si la grilla no esta vacia */
		grilla_stock -> DeleteRows(0, grilla_stock -> GetNumberRows()); /* Borra la grilla */
	}
	for(int i=0; i<m_sistema -> VerStock().VerTamStock(); i++) { 
		p = m_sistema -> VerStock().VerProductoStock(i);
		if (!p.VerEliminado()) {
			grilla_stock -> AppendRows();
			grilla_stock -> SetCellValue(fila, 0, p.VerID());
			grilla_stock -> SetCellValue(fila, 1, p.VerNombre());
			grilla_stock -> SetCellValue(fila, 2, p.VerMarca());
			grilla_stock -> SetCellValue(fila, 3, p.VerCategoria());
			grilla_stock -> SetCellValue(fila, 4, "$" + std::to_string(p.VerPrecio()));
			grilla_stock -> SetCellValue(fila, 5, std::to_string(p.VerCantidad()));
			cont_disponibles++;
			fila++;
		}
	}
//	grilla_stock -> AutoSizeRows();
//	grilla_stock -> AutoSizeColumns();
	
	t_stock -> SetLabel (std::to_string(cont_disponibles));
	busqueda_stock -> Clear();
}

void hija_stock::SelectGrillaStockCizq( wxGridEvent& event )  { /* Metodo para seleccionar el producto clickeado (click izquierdo) */
	grilla_stock -> SelectRow(event.GetRow());
	grilla_stock -> SetGridCursor(event.GetRow(),event.GetCol());
}

void hija_stock::OnOff (bool opcion) { /* Metodo para activar o desactivar la grilla y algunos botones */
	//grilla_stock -> Enable(opcion);
	m_button_sumar -> Enable(opcion);
	m_button_restar -> Enable(opcion);
	m_button_agregar -> Enable(opcion);
	m_button_editar -> Enable(opcion);
	m_button_eliminar -> Enable(opcion);
	m_button_buscarstock -> Enable(opcion);
}

hija_stock::~hija_stock() {
	m_sistema -> VerStock().OrdenarStock(1);
	m_sistema -> VerStock().GuardarStock(); 
}
