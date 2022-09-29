#include "Sistema.h"
#include <vector>
#include <iostream>

Sistema::Sistema(std::string nombre_s,std::string nombre_v):s(nombre_s),v(nombre_v){}

bool Sistema::Vender(Stock productos_avender, std::vector<int> cantidad, std::vector<int> desc){ /* Realiza una venta y devuelve true si se realizo correctamente */
	std::vector<std::string> ids;
	for(size_t i=0;i<productos_avender.VerTamStock();i++){
		ids.push_back(productos_avender.VerProductoStock(i).VerID());
	}
	if(s.ValidarCantidad(ids,cantidad)){ /* Si la cantidad es valida, realiza la venta */
		if(v.RealizarVenta(productos_avender,cantidad,desc)){
			std::vector<int> posiciones;
		    for(size_t i=0;i<ids.size();i++){
				int x = s.BuscarID(ids[i]);
				posiciones.push_back(x);
		    }
		    s.DescontarVenta(posiciones,cantidad); /* Si se realizo correctamente la venta, se descuenta la cantidad de un producto del Stock */
		    return true;
	    }
	}
	return false;
}

Stock &Sistema::VerStock(){return s;} /* Devuelve stock */

Ventas &Sistema::VerVentas(){return v;} /* Devuelve ventas */

