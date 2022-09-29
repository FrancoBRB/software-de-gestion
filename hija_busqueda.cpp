#include "hija_busqueda.h"
#include "Sistema.h"
#include <wx/msgdlg.h>
#include <vector>
#include <string>
#include <wx/valtext.h>
#include <wx/icon.h>
#include "iconobusqueda.xpm"

hija_busqueda::hija_busqueda(wxWindow *parent,Sistema *sistema, wxGrid* grilla_historial_ventas) : ventana_busqueda(parent),m_sistema(sistema),m_grilla_historial_ventas(grilla_historial_ventas) {
	SetIcon(wxIcon(iconobusqueda_xpm));
	/* Validadores para cada barra de texto */
	wxTextValidator numerico(wxFILTER_NUMERIC);
	dia_inicial -> SetValidator(numerico);
	mes_inicial -> SetValidator(numerico);
	anio_inicial -> SetValidator(numerico);
	dia_final -> SetValidator(numerico);
	mes_final -> SetValidator(numerico);
	anio_final -> SetValidator(numerico);
	nro_factura_inicial -> SetValidator(numerico);
	nro_factura_final -> SetValidator(numerico);
	nro_factura_unica -> SetValidator(numerico);
}

void hija_busqueda::btn_aceptar_busqueda( wxCommandEvent& event )  { /* Boton para realizar una busqueda */
	long dia_i, mes_i, anio_i, dia_f, mes_f, anio_f, nro_factura_i, nro_factura_f, nro_factura;
	int di, mi, ai, df, mf, af;
	std::string error, descripcion;
	
	if(!nro_factura_unica -> IsEmpty()){
		if(dia_inicial -> IsEmpty() and mes_inicial -> IsEmpty() and anio_inicial -> IsEmpty() and
		   dia_final -> IsEmpty() and mes_final -> IsEmpty() and anio_final -> IsEmpty() and nro_factura_inicial -> IsEmpty() and nro_factura_final -> IsEmpty()){
			nro_factura_unica -> GetValue().ToLong(&nro_factura);
			error = m_sistema -> VerVentas().VerificacionBusqueda(-1, -1, -1, -1, nro_factura);
			if (error.empty()) {
				if (m_grilla_historial_ventas -> GetNumberRows() != 0){	
					m_grilla_historial_ventas -> DeleteRows(0, m_grilla_historial_ventas -> GetNumberRows()); 
				} 
				int pos, precio_t_aux = 0,fecha_aux;
				for(size_t i=0;i< m_sistema -> VerVentas().VentaTam();i++) {
					if(nro_factura==m_sistema->VerVentas().VerFactura(i)){
						precio_t_aux += m_sistema -> VerVentas().VerPTotal(i);
						pos = m_sistema -> VerStock().BuscarID(m_sistema -> VerVentas().VerID(i));
						Producto p = m_sistema -> VerStock().VerProductoStock(pos);
						descripcion += p.VerNombre() + " " + p.VerMarca() + ", ";
						fecha_aux=m_sistema -> VerVentas().VerFecha(i-1);
					}
				}
				if (descripcion.size() > 74) {
					descripcion = descripcion.substr(0, 70);
					descripcion += "...  ";
				}
				m_grilla_historial_ventas -> AppendRows();
				m_grilla_historial_ventas -> SetCellValue(0, 0, std::to_string(nro_factura));
				m_grilla_historial_ventas -> SetCellValue(0, 1, descripcion.substr(0, descripcion.size()-2));
				m_grilla_historial_ventas -> SetCellValue(0, 2, "$" + std::to_string(precio_t_aux));
				m_grilla_historial_ventas -> SetCellValue(0, 3, FechaString(fecha_aux));
			}else{
				wxMessageBox(error, "Error", wxOK | wxICON_ERROR);
			}
		}else{
			wxMessageBox("No es posible realizar ambos tipos de busquedas, solo por factura unica o segun un rango", "Error", wxOK | wxICON_ERROR);
			EndModal(1);
		}
	}else{
		std::vector <SVentas> aux = m_sistema -> VerVentas().VerVentas();
		SVentas sv1, sv2;
		
		auto it1 = max_element(aux.begin(), aux.end(), SegunFecha);
		sv1 = *it1;
		auto it2 = min_element(aux.begin(), aux.end(), SegunFecha);
		sv2 = *it2;
		
		std::tie(di, mi, ai) = FechaSeparada(sv2.fecha);
		std::tie(df, mf, af) = FechaSeparada(sv1.fecha);
		
		dia_inicial -> GetValue().ToLong(&dia_i);
		mes_inicial -> GetValue().ToLong(&mes_i);
		anio_inicial -> GetValue().ToLong(&anio_i);
		dia_final -> GetValue().ToLong(&dia_f);
		mes_final -> GetValue().ToLong(&mes_f);
		anio_final -> GetValue().ToLong(&anio_f);
		nro_factura_inicial -> GetValue().ToLong(&nro_factura_i);
		nro_factura_final -> GetValue().ToLong(&nro_factura_f);
		
		if(dia_inicial -> IsEmpty() and mes_inicial -> IsEmpty() and anio_inicial -> IsEmpty()){
			dia_i=di; mes_i=mi; anio_i=ai;
		}
		if(dia_final -> IsEmpty() and mes_final -> IsEmpty() and anio_final -> IsEmpty()){
			dia_f = df; mes_f = mf; anio_f = af;
		}
		
		it1 = max_element(aux.begin(), aux.end(), SegunFactura);
		sv1 = *it1;
		it2 = min_element(aux.begin(), aux.end(), SegunFactura);
		sv2 = *it2;
		
		if(nro_factura_inicial -> IsEmpty()){
			nro_factura_i = sv2.nro_factura;
		}	
		if(nro_factura_final -> IsEmpty()){
			nro_factura_f = sv1.nro_factura;
		}
		
		int fecha_i = aaaammdd(anio_i, mes_i, dia_i);
		int fecha_f = aaaammdd(anio_f, mes_f, dia_f);
		
		error = m_sistema -> VerVentas().VerificacionBusqueda(fecha_i, fecha_f, nro_factura_i, nro_factura_f, -1);
		if (error.empty()) {
			aux.clear();
			aux = m_sistema -> VerVentas().ListaBusquedaAvanzada(fecha_i, fecha_f, nro_factura_i, nro_factura_f);
			int pos, precio_t_aux = 0, cont = 0, i = 0, fac_aux;
			if(!aux.empty()){
				if (m_grilla_historial_ventas -> GetNumberRows() != 0){	
					m_grilla_historial_ventas -> DeleteRows(0, m_grilla_historial_ventas -> GetNumberRows()); 
				} 
				
				fac_aux = aux[0].nro_factura;
				while (cont < aux.size()) {
					while(fac_aux == aux[cont].nro_factura and cont < aux.size()){
						precio_t_aux += aux[cont].precio_total_v;
						pos = m_sistema -> VerStock().BuscarID(aux[cont].id_v);
						Producto p = m_sistema -> VerStock().VerProductoStock(pos);
						descripcion += p.VerNombre() + " " + p.VerMarca() + ", ";
						cont++;
					}
					if (descripcion.size() > 74) {
						descripcion = descripcion.substr(0, 74);
						descripcion += "...  ";
					}
					m_grilla_historial_ventas -> AppendRows();
					m_grilla_historial_ventas -> SetCellValue(i, 0,std::to_string(aux[cont-1].nro_factura));
					m_grilla_historial_ventas -> SetCellValue(i, 1, descripcion.substr(0, descripcion.size()-2));
					m_grilla_historial_ventas -> SetCellValue(i, 2, "$" + std::to_string(precio_t_aux));
					m_grilla_historial_ventas -> SetCellValue(i, 3, FechaString(aux[cont-1].fecha));
					precio_t_aux = 0;
					descripcion.clear();
					i++;
					fac_aux = aux[cont].nro_factura;
				}
			}else{
				wxMessageBox("No se encontro ninguna coincidencia", "Aviso", wxOK | wxICON_EXCLAMATION);
			}
		}else{
			wxMessageBox(error, "Error", wxOK | wxICON_ERROR);
		}
	}
	EndModal(1);
}

void hija_busqueda::btn_cancelar_busqueda( wxCommandEvent& event )  { /* Boton para cerrar la ventana de busqueda */
	EndModal(0);
}
