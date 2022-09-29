#include "hija_vender.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <wx/valtext.h>
#include <vector>
#include <wx/grid.h>
#include <wx/icon.h>
#include "iconovender.xpm"

hija_vender::hija_vender(wxWindow *parent,Sistema *sistema) : ventana_vender(parent),m_sistema(sistema) {
	SetIcon(wxIcon(iconovender_xpm));
	/* Validadores para cada barra de texto */
	wxTextValidator numerico(wxFILTER_NUMERIC);
	cantidad_a_vender -> SetValidator (numerico);
	descuento_a_vender -> SetValidator (numerico);
	
	int fila = 0;
	
	for(int i=0;i<m_sistema -> VerStock().VerTamStock();i++) { /* Carga los productos disponibles en la grilla de productos */
		Producto &p = m_sistema -> VerStock().VerProductoStock(i);
		if (!p.VerEliminado()) {
			grilla_productos -> AppendRows();
			grilla_productos -> SetCellValue(fila, 0, p.VerNombre() + " " + p.VerMarca());
			grilla_productos -> SetCellValue(fila, 1, "$" + std::to_string(p.VerPrecio()));
			grilla_productos -> SetCellValue(fila, 2, std::to_string(p.VerCantidad()));
			cont_disponibles++;
			fila++;
		}
	}
	grilla_productos -> AutoSizeColumns();
	grilla_productos -> AutoSizeRows();
	
	lbl_total -> SetLabel("$0"); /* Muestra el costo total del carrito inicializado en 0 */
	descuento_a_vender -> SetValue(std::to_string(0)); /* Muestra la barra de texto del descuento inicializado en 0 */
	cantidad_a_vender -> SetValue(std::to_string(1)); /* Muestra la barra de texto de la cantidad inicializada en 1 */
}

void hija_vender::btn_agregar( wxCommandEvent& event )  { /* Boton para agregar un producto al carrito de compras */
	if (cont_disponibles == 0) {
		wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
	} else {
		std::string descripcion;
		int pos, total, fila = grilla_productos -> GetGridCursorRow();
		long cantidad, cantidad_s, descuento;
		bool repetido = false;
		
		Producto p, p1;
		
		grilla_productos -> GetCellValue(fila, 2).ToLong(&cantidad_s);
		cantidad_a_vender -> GetValue().ToLong(&cantidad);
		descuento_a_vender -> GetValue().ToLong(&descuento);
		
		if (pos_b.empty()) { /* Si no se realizo ninguna busqueda, uso la fila seleccionada de la grilla principal */
			pos = m_sistema -> VerStock().VerPosicion(fila);
			p = m_sistema -> VerStock().VerProductoStock(pos);
		} else { /* Si se realizo alguna busqueda, utilizo la fila de los resultados de busqueda */
			pos = pos_b[fila];
			p = m_sistema -> VerStock().VerProductoStock(pos);
		}
		for(size_t i=0;i<pos_f.size();i++) { /* Reviso si el producto a agregar ya se encuentra en el carrito */
			p1 = m_sistema -> VerStock().VerProductoStock(m_sistema -> VerStock().VerPosicion(pos_f[i]));
			if (p1.VerID() == p.VerID()) { /* Al ser unicas, comparo las ID y si ninguna se repite, procede */
				repetido = true;
			}
		}
		
		if (repetido) {
			wxMessageBox("El producto ya se encuentra en el carrito" ,"¡Error en factura!", wxOK | wxICON_ERROR);
		} else {
			if (cantidad <= 0 || cantidad_a_vender -> IsEmpty()) { /* Verifica que se ingrese una cantidad valida */
				wxMessageBox("Debe ingresar una cantidad real", "¡Error en cantidad!", wxOK | wxICON_ERROR);
			}else{
				if (cantidad > cantidad_s) { /* Verifica que la cantidad ingresada no supere al stock disponible */
					wxMessageBox("Cantidad insuficiente. Solo hay " + std::to_string(cantidad_s) + " unidades", "¡Error en cantidad!", wxOK | wxICON_ERROR);
				}else{
					if ((descuento < 0 && descuento > 100) || descuento_a_vender -> IsEmpty()) { /* Verifica que se ingrese un valor de descuento valido */
						wxMessageBox("Debe ingresar un valor entre 0 y 100","¡Error en descuento!", wxOK | wxICON_ERROR);
					} else {
						if (pos_b.empty()) { /* Si no se realizo ninguna busqueda, se guarda la fila del producto seleccionado */
							pos_f.push_back(fila);
						} else { /* Si se realizo alguna busqueda, se guarda la fila original del producto seleccionado */
							for(int i=0;i<m_sistema -> VerStock().VerTamStock();i++) { 
								if (pos == m_sistema -> VerStock().VerPosicion(i)) {
									pos_f.push_back(i);
									fila = i;
								}
							}
						}
						fac.cant.push_back(cantidad);
						fac.desc.push_back(descuento);
						fac.carrito_de_compra.AgregarProducto(p);
						
						total = p.VerPrecio() * cantidad - (p.VerPrecio() * cantidad * descuento / 100); /* Se calcula el costo total del producto seleccionado */
						fac.p_total.push_back(total);
						cont_total += (total);
						
						if (descuento > 0) {
							descripcion = wx_to_std(std::to_string(cantidad) + "       " + p.VerNombre() + " " + p.VerMarca() +
							"       $" + std::to_string(total) + "    % " + std::to_string(descuento));
						}else {
							descripcion = wx_to_std(std::to_string(cantidad) + "       " + p.VerNombre() + " " + p.VerMarca() +
							"       $" + std::to_string(total));
						}
						
						grilla_factura -> AppendRows(); /* Se agrega una fila con el producto agregado al carrito */
						grilla_factura -> SetCellValue(cont_filas, 0, descripcion);
						grilla_factura -> AutoSizeColumns();
						grilla_factura -> AutoSizeRows();
						cont_filas++;
						lbl_total -> SetLabel("$" + std::to_string(cont_total));  /* Se muestra el costo total que lleva el carrito */
						
						refrescar_grilla_productos();
						busqueda_producto -> Clear();
						
						grilla_productos -> SelectRow(fila);
						grilla_productos -> SetGridCursor(fila, 0);
					}
				}
			}
		}
	}
}

void hija_vender::btn_realizar_venta( wxCommandEvent& event )  { /* Boton para realizar una venta */
	std::string alerta;
	if(fac.cant.empty()){
		wxMessageBox("El carrito está vacio","¡Error!",wxOK|wxICON_ERROR);
	}else{
		if(m_sistema->Vender(fac.carrito_de_compra,fac.cant,fac.desc) && fac.carrito_de_compra.VerTamStock()>0){
			for(size_t i=0;i<pos_f.size();i++) { 
				int posi = m_sistema -> VerStock().VerPosicion(pos_f[i]);
				Producto &p = m_sistema -> VerStock().VerProductoStock(posi);
				if (p.VerCantidad() <= 5) {
					alerta += p.VerID() + " - " + p.VerNombre() + ", " + p.VerMarca() + "\n";
				}
			}
			if (alerta.empty()) {
				wxMessageBox("Venta realizada", "¡Operación exitosa!" , wxOK | wxICON_INFORMATION);
			} else {
				wxMessageBox("Venta realizada\n\nQuedan pocas unidades de:\n" + alerta, "¡Operación exitosa! | ¡Revise su stock!" , wxOK | wxICON_INFORMATION);
			}
			EndModal(1);
		}else{
			EndModal(0);
		}
	}
}

void hija_vender::btn_quitar_producto( wxCommandEvent& event )  { /* Boton para eliminar el producto seleccionado del carrito */
	int pos, fila = grilla_factura -> GetGridCursorRow();
	long cantidad, cantidad_s;
	if (fila > -1) {
		if (pos_b.empty()) { /* Si se realizo una busqueda, devuelve la cantidad y la muestra en la grilla correspondiente */
			grilla_productos -> SelectRow(pos_f[fila]);
			grilla_productos -> SetGridCursor(pos_f[fila], 0);
			grilla_productos -> GetCellValue(pos_f[fila], 2).ToLong(&cantidad_s);
			cantidad = fac.cant[fila];
			grilla_productos -> SetCellValue (pos_f[fila], 2, std::to_string(cantidad + cantidad_s)); 
		} else { /* Si no se realizo una busqueda, devuelve la cantidad y la muestra en la grilla principal de productos */
			pos = m_sistema -> VerStock().VerPosicion(pos_f[fila]);
			for(size_t i=0;i<pos_b.size();i++) { 
				if (pos == pos_b[i]) {
					grilla_productos -> SelectRow(i);
					grilla_productos -> SetGridCursor(i, 0);
					grilla_productos -> GetCellValue(i, 2).ToLong(&cantidad_s);
					cantidad = fac.cant[fila];
					grilla_productos -> SetCellValue (i, 2, std::to_string(cantidad + cantidad_s));
				}
			}
		}
		auto it = pos_f.begin() + fila; /* Elimina la fila seleccionada del carrito */
		pos_f.erase(it);
		
		cont_total -= fac.p_total[fila]; /* Descuenta del monto total, el costo total del producto eliminado del carrito */
		it = fac.p_total.begin() + fila;
		fac.p_total.erase(it);
		
		it = fac.desc.begin() + fila; /* Elimina el porcentaje de descuento del producto seleccionado en el carrito */
		fac.desc.erase(it);
		
		it = fac.cant.begin() + fila; /* Elimina la cantidad del producto seleccionado en el carrito */
		fac.cant.erase(it);
		
		fac.carrito_de_compra.EliminarDelCarrito(fila);
		grilla_factura -> DeleteRows(fila);
		cont_filas--;
		
		lbl_total -> SetLabel("$" + std::to_string(cont_total)); /* Muestra el costo total actualizado */
	} else {
		wxMessageBox("No hay productos en el carrito","¡Error!",wxOK|wxICON_ERROR);
	}
}

void hija_vender::btn_busqueda_productos( wxCommandEvent& event )  { /* Boton para realizar una busqueda segun el criterio ingresado en la barra */ 
	pos_b.clear();
	
	refrescar_grilla_productos ();
	if (busqueda_producto -> IsEmpty()) { /* Verifica que se haya ingresado un criterio de busqueda */
		wxMessageBox("Debe ingresar una busqueda", "¡Error!", wxOK | wxICON_ERROR);
	}else{
		if (cont_disponibles == 0) {
			wxMessageBox("No es posible realizar esta accion. No hay registros disponibles", "¡Aviso!", wxOK | wxICON_INFORMATION);
		} else {
			
			/* Busqueda por NOMBRE */
			int col_desc_nombre = m_sistema -> VerStock().BuscarProducto(wx_to_std(busqueda_producto -> GetValue()), 0);
			while (col_desc_nombre != -1) {
				if (!m_sistema -> VerStock().VerProductoStock(col_desc_nombre).VerEliminado()) {
					pos_b.push_back(col_desc_nombre);
				}
				col_desc_nombre = m_sistema -> VerStock().BuscarProducto(wx_to_std(busqueda_producto -> GetValue()), col_desc_nombre + 1);
			}
			
			int col_desc_marca = m_sistema -> VerStock().BuscarMarca(wx_to_std(busqueda_producto ->  GetValue()), 0);
			while (col_desc_marca != -1) {
				int cont = 0;
				for(size_t i=0;i<pos_b.size();i++) { /* Si el resultado obtenido ya fue encontrado anteriormente, se lo saltea */
					if (col_desc_marca == pos_b[i]) { cont++; }
				}
				if (!m_sistema -> VerStock().VerProductoStock(col_desc_marca).VerEliminado() && cont == 0) {
					pos_b.push_back(col_desc_marca);
				}
				col_desc_marca = m_sistema -> VerStock().BuscarMarca(wx_to_std(busqueda_producto -> GetValue()), col_desc_marca + 1);
			}
			
			/* Si se encontraron resultados, los muestra en la grilla */
			if (pos_b.empty()) {
				wxMessageBox("No se encontraron coincidencias");
			}else{
				if (grilla_productos -> GetNumberRows() != 0) {
					grilla_productos -> DeleteRows(0, grilla_productos -> GetNumberRows());
				}
				for(size_t i=0;i<pos_b.size();i++) { 
					Producto &p = m_sistema -> VerStock().VerProductoStock(pos_b[i]);
					grilla_productos -> AppendRows();
					grilla_productos -> SetCellValue(i, 0, p.VerNombre() + " " + p.VerMarca());
					grilla_productos -> SetCellValue(i, 1, "$" + std::to_string(p.VerPrecio()));
					grilla_productos -> SetCellValue(i, 2, std::to_string(p.VerCantidad()));
				}
				if (!pos_f.empty()) { /* Si se realizo una busqueda y se agrego o elimino un producto del carrito, devuelve la cantidad y la muestra en la grilla correspondiente */
					for(size_t i=0;i<pos_f.size();i++) { 
						int pos = m_sistema -> VerStock().VerPosicion(pos_f[i]);
						for(size_t j=0;j<pos_b.size();j++) { 
							if (pos == pos_b[j]) {
								long cantidad_s, cantidad = fac.cant[i];
								grilla_productos -> GetCellValue(j, 2).ToLong(&cantidad_s);
								grilla_productos -> SetCellValue(j, 2, std::to_string(cantidad_s - cantidad));
							}
						}
					}
				}
			}
		}
		
	}
}

void hija_vender::refrescar_grilla_productos() { /* Metodo para recargar la grilla de productos */
	pos_b.clear();
	
	cont_disponibles = 0;
	int fila = 0;
	if (grilla_productos -> GetNumberRows() != 0) { /* Si la grilla no esta vacia */
		grilla_productos -> DeleteRows(0, grilla_productos -> GetNumberRows()); /* Borra la grilla */
	}
	for(int i=0;i<m_sistema -> VerStock().VerTamStock();i++) { 
		Producto &p = m_sistema -> VerStock().VerProductoStock(i);
		if (!p.VerEliminado()) {
			grilla_productos -> AppendRows();
			grilla_productos -> SetCellValue(fila, 0, p.VerNombre() + " " + p.VerMarca());
			grilla_productos -> SetCellValue(fila, 1, "$" + std::to_string(p.VerPrecio()));
			grilla_productos -> SetCellValue(fila, 2, std::to_string(p.VerCantidad()));
			cont_disponibles++;
			fila++;
		}
	}
	if (!pos_f.empty()) { 
		for(size_t i=0;i<pos_f.size();i++) { /* Si se agregaron productos al carrito, se descuenta su cantidad en la grilla*/ 
			long cantidad_s, cantidad = fac.cant[i];
			grilla_productos -> GetCellValue(pos_f[i], 2).ToLong(&cantidad_s);
			grilla_productos -> SetCellValue(pos_f[i], 2, std::to_string(cantidad_s - cantidad));
		}
	}
	grilla_productos -> AutoSizeColumns();
	grilla_productos -> AutoSizeRows();
	
	descuento_a_vender -> SetValue(std::to_string(0)); /* Muestra la barra de texto del descuento inicializado en 0 */
	cantidad_a_vender -> SetValue(std::to_string(1)); /* Muestra la barra de texto de la cantidad inicializada en 1 */
}


void hija_vender::SelectGrillaFactCizq( wxGridEvent& event )  { /* Metodo para seleccionar el producto clickeado en el carrito (click izquierdo) */
	grilla_factura -> SelectRow(event.GetRow());
	grilla_factura -> SetGridCursor(event.GetRow(),event.GetCol());
}

void hija_vender::SelectGrillaProdCizq( wxGridEvent& event )  { /* Metodo para seleccionar el producto clickeado en la grilla de productos (click izquierdo) */
	grilla_productos -> SelectRow(event.GetRow());
	grilla_productos -> SetGridCursor(event.GetRow(),event.GetCol()); 
}

void hija_vender::btn_sumar_cant( wxCommandEvent& event )  {
	long aux; 
	cantidad_a_vender -> GetValue().ToLong(&aux);
	aux++;
	cantidad_a_vender -> SetValue (std::to_string(aux));
}

void hija_vender::btn_restar_cant( wxCommandEvent& event )  {
	long aux; 
	cantidad_a_vender -> GetValue().ToLong(&aux);
	if (aux > 1) {
		aux--;
		cantidad_a_vender -> SetValue (std::to_string(aux));
	}
}

void hija_vender::RecargarGrillaProdCizq( wxGridEvent& event )  {
	refrescar_grilla_productos();
	busqueda_producto -> Clear();
}

