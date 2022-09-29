#include "hija_factura.h"
#include <wx/icon.h>
#include "iconounafactura.xpm"

hija_factura::hija_factura(wxWindow *parent, Sistema *sistema, long nro_factura) : ventana_factura(parent), m_sistema(sistema), m_nro_factura(nro_factura){
	SetIcon(wxIcon(iconounafactura_xpm));
	std::vector <int> pos_prod_fact;
	std::string fecha; int pos, total=0;
	
	lbl_factura_factura -> SetLabel(std::to_string(nro_factura));
	
	for(size_t i=0;i<m_sistema -> VerVentas().VentaTam();i++) {  
		if (m_nro_factura == m_sistema -> VerVentas().VerFactura(i)) {
			pos_prod_fact.push_back(i);
		}
	}
	for(size_t i=0;i<pos_prod_fact.size();i++) { 
		pos = m_sistema -> VerStock().BuscarID(m_sistema -> VerVentas().VerID(pos_prod_fact[i]));
		Producto p = m_sistema -> VerStock().VerProductoStock(pos);
		grilla_factura_factura -> AppendRows();
		grilla_factura_factura -> SetCellValue(i, 0, std::to_string(m_sistema -> VerVentas().VerCantidad(pos_prod_fact[i])));
		grilla_factura_factura -> SetCellValue(i, 1, p.VerNombre() + " " + p.VerMarca());
		grilla_factura_factura -> SetCellValue(i, 2, "$" + std::to_string(m_sistema -> VerVentas().VerPUnitario(pos_prod_fact[i])));
		grilla_factura_factura -> SetCellValue(i, 3, std::to_string(m_sistema -> VerVentas().VerPorcentaje(pos_prod_fact[i])) + "%");
		grilla_factura_factura -> SetCellValue(i, 4, "$" + std::to_string(m_sistema -> VerVentas().VerPTotal(pos_prod_fact[i])));
		total += m_sistema -> VerVentas().VerPTotal(pos_prod_fact[i]);
	}
	grilla_factura_factura -> AutoSizeColumn(1);
	fecha = FechaString(m_sistema -> VerVentas().VerFecha(pos_prod_fact[0]));
	lbl_fecha_factura -> SetLabel(fecha);
	lbl_total_factura -> SetLabel("$" + std::to_string(total));
}

void hija_factura::cerrar_ventana_factura( wxMouseEvent& event )  {
	event.Skip();
}

