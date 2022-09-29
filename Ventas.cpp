#include "Ventas.h"
#include "Producto.h"
#include "Fecha.h"
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "Stock.h"
#include <iostream>

Ventas::Ventas(std::string nombre_bin){
	v_archivo_bin=nombre_bin;
	std::ifstream LectArchivoV (v_archivo_bin, std::ios::binary | std::ios::ate);
	SVentas aux;
	if (LectArchivoV.is_open()) {
		int tam = LectArchivoV.tellg()/sizeof(SVentas);
		LectArchivoV.seekg(0);
		for(int i=0;i<tam;i++) { 
			LectArchivoV.read(reinterpret_cast <char*>(&aux), sizeof (aux));
			v_ventas.push_back(aux);
		}		
	}
	LectArchivoV.close();
}

Ventas::Ventas(){}

std::string Ventas::VerID (int i) { /* Devuelve la id de un producto vendido */
	return v_ventas[i].id_v;
}

int Ventas::VerPUnitario (int i) { /* Devuelve el precio unitario del producto vendido */
	return v_ventas[i].precio_unitario_v;
}

int Ventas::VerPTotal (int i) { /* Devuelve el precio total del producto vendido */
	return v_ventas[i].precio_total_v;
}

int Ventas::VerCantidad (int i) { /* Devuelve la cantidad vendida del producto */
	return v_ventas[i].cantidad_v;
}

int Ventas::VerPorcentaje (int i) { /* Devuelve si se aplico, el valor de descuento de un producto */
	return v_ventas[i].porcentaje_v;
}

int Ventas::VerFecha(int i){ /* Devuelve la fecha de cuando se vendio un producto */
	return v_ventas[i].fecha;
}

int Ventas::VerFactura(int i){ /* Devuelve el nro de factura */
	return v_ventas[i].nro_factura;
}

std::vector<SVentas>Ventas::VerVentas(){ /* Devuelve ventas */
	return v_ventas;
}

size_t Ventas::VentaTam(){ /* Devuelve el tamaño del vector de ventas */
	return v_ventas.size();
}

void Ventas::GuardarVentas () { /* Guarda el vector de ventas en el binario */
	std::ofstream EscArchivoV(v_archivo_bin, std::ios::binary | std::ios::trunc);
	for(size_t i=0;i<v_ventas.size();i++) { 
		EscArchivoV.write(reinterpret_cast <char*> (&v_ventas[i]), sizeof (SVentas));
	}
	EscArchivoV.close();
}

bool Ventas::RealizarVenta(Stock s, std::vector<int> cantidad,std::vector<int>desc) { /* Devuelve true si la venta se realizo correctamente */
	std::string nombremarca; 
	if(v_ventas.size()==0){
		cont_factura = 1000;
	}else{
		SVentas aux;
		auto it = max_element(v_ventas.begin(), v_ventas.end(), SegunFactura);
		aux = *it;
		cont_factura = (aux.nro_factura)+1;
	}
	for(size_t i=0;i<s.VerTamStock();i++){
		SVentas sv;
		Producto aux = s.VerProductoStock(i);
		strcpy (sv.id_v,aux.VerID().c_str());
		sv.nro_factura=cont_factura;
		sv.precio_unitario_v=aux.VerPrecio();
		sv.cantidad_v=cantidad[i];
		sv.porcentaje_v=desc[i];
		sv.precio_total_v=sv.cantidad_v*CalcularDescuento(aux.VerPrecio(),sv.porcentaje_v);
		sv.fecha=VerFechaActual();
		v_ventas.push_back(sv);
	}
	GuardarVentas();
	return true;
}

void Ventas::OrdenarVentas (int segun) {
	switch (segun) {
	case 1:
		sort(v_ventas.begin(), v_ventas.end(), SegunFactura); /* Ordena segun la factura (0 - n) */
		break;
	case 2:
		sort(v_ventas.begin(), v_ventas.end(), SegunFactura); /* Ordena segun la factura (n - 0) */
		reverse(v_ventas.begin(), v_ventas.end());
		break;
	case 3:
		sort(v_ventas.begin(), v_ventas.end(), SegunFecha); /* Ordena segun la fecha (0 - n) */
		break;
	case 4:
		sort(v_ventas.begin(), v_ventas.end(), SegunFecha); /* Ordena segun la fecha (n - 0) */
		reverse(v_ventas.begin(), v_ventas.end());
		break;
	}
}

int Ventas::CalcularDescuento(int precio, int porcentaje) { /* Calcula el costo con descuento para realizar una venta */
	if (porcentaje==0)
		return precio; 
	else
		return (precio - (precio * porcentaje/100));
}

std::string Ventas::VerificacionBusqueda(int fecha_i,int fecha_f,int nro_factura_i,int nro_factura_f,int nro_factura_unica){ /* Verifica los valores ingresados para una busqueda y devuelve un mensaje de error si encuentra alguno */
	SVentas sv1, sv2, sv3, sv4;
	std::string error;
	int di,da,mi,ma,ai,aa;
	
	auto it1 = max_element(v_ventas.begin(), v_ventas.end(), SegunFactura); /* Se busca el mayor nro de factura registrado */
	sv1 = *it1;
	auto it2 = min_element(v_ventas.begin(), v_ventas.end(), SegunFactura); /* Se busca el menor nro de factura registrado */
	sv2 = *it2;
	auto it3 = max_element(v_ventas.begin(), v_ventas.end(), SegunFecha); /* Se busca la mayor fecha registrada */
	sv3 = *it3;
	auto it4 = min_element(v_ventas.begin(), v_ventas.end(), SegunFecha); /* Se busca la menor fecha registrada */
	sv4 = *it4;
	
	std::tie(da,ma,aa) = FechaSeparada(sv3.fecha);
	std::tie(di,mi,ai) = FechaSeparada(sv4.fecha);
	
	if((nro_factura_unica < sv2.nro_factura or nro_factura_unica > sv1.nro_factura) and nro_factura_unica != -1){
		error += "¡No existen coincidencias con la factura a buscar!\n";
	}
	if(nro_factura_i > nro_factura_f and nro_factura_i != -1){
		error += "¡La factura inicial no puede ser mayor a la factura final! (" + std::to_string(nro_factura_f) + ")\n";
	}
	if(nro_factura_i < sv2.nro_factura and nro_factura_i != -1){
		error += "¡La factura inicial no puede ser menor a la primer factura! (" + std::to_string(sv2.nro_factura) + ")\n";
	}
	if(nro_factura_f > sv1.nro_factura && nro_factura_f != -1){
		error += "¡La factura final es mayor a la ultima factura! (" + std::to_string(sv1.nro_factura) + ")\n";
	}
	if (nro_factura_f < sv2.nro_factura && nro_factura_f != -1) {
		error += "¡La factura final no puede ser menor a la primer factura! (" + std::to_string(sv2.nro_factura) +")\n";
	}
	if (fecha_f < sv4.fecha && fecha_f != -1) {
		error += "¡La fecha final no puede ser menor a la fecha de la primer factura! (" + std::to_string(di) + "/" + std::to_string(mi) + "/" + std::to_string(ai) + ")\n";
	}
	if(fecha_i > fecha_f && fecha_i != -1){
		error += "¡La fecha inicial no puede ser mayor a la fecha final! (" + std::to_string(da) + "/" + std::to_string(ma) + "/" + std::to_string(aa) + ")";
	}
	if(fecha_f > sv3.fecha && fecha_f != -1){
		error += "¡La fecha final no puede ser mayor a la fecha de la ultima factura! (" + std::to_string(da) + "/" + std::to_string(ma) + "/" + std::to_string(aa) + ")\n";
	}
	if(fecha_i > sv3.fecha and fecha_i != -1){
		error += "¡La fecha inicial no puede ser mayor a la fecha de la ultima factura! (" + std::to_string(da) + "/" + std::to_string(ma) + "/" + std::to_string(aa) + ")\n";
	}
	if(fecha_i < sv4.fecha and fecha_i != -1){
		error += "¡La fecha inicial no puede ser menor a la fecha de la primer factura! (" + std::to_string(di) + "/" + std::to_string(mi) + "/" + std::to_string(ai) + ")\n";
	}
	
	return error;
}

std::vector<SVentas>Ventas::ListaBusquedaAvanzada(int fecha_i,int fecha_f,int nro_factura_i,int nro_factura_f){ /* Devuelve un vector con las busquedas segun una factura / fecha inicial y una final */
	std::vector<SVentas>aux=FiltrarPorFecha(fecha_i,fecha_f);
	return FiltrarPorFactura(nro_factura_i,nro_factura_f,aux);
}

std::vector<SVentas>Ventas::FiltrarPorFecha(int fecha_i,int fecha_f){ /* Devuelve un vector con las busquedas segun una fecha inicial y una final */
	std::vector<SVentas>aux;
	for(size_t i=0;i<v_ventas.size();i++) { 
		if(v_ventas[i].fecha>=fecha_i and v_ventas[i].fecha<=fecha_f){
			aux.push_back(v_ventas[i]);
		}
	}
	return aux;
}

std::vector<SVentas>Ventas::FiltrarPorFactura(int nro_factura_i,int nro_factura_f,std::vector<SVentas>v_fil){ /* Devuelve un vector con las busquedas segun una factura inicial y una final */
	std::vector<SVentas>aux;
	for(size_t i=0;i<v_fil.size();i++) { 
		if(v_fil[i].nro_factura>=nro_factura_i and v_fil[i].nro_factura<=nro_factura_f){
			aux.push_back(v_fil[i]);
		}
	}
	return aux;
}

std::vector<std::string>Ventas::VerCategoriasVentas(Stock s){
	std::vector<std::string>str_cat;
	int pos;
	for(size_t i=0;i<v_ventas.size();i++) {
		pos = s.BuscarID(v_ventas[i].id_v);
		Producto aux = s.VerProductoStock(pos);
		str_cat.push_back(aux.VerCategoria());
	}
	std::sort(str_cat.begin(),str_cat.end());
	auto ultimo=std::unique(str_cat.begin(),str_cat.end());
	str_cat.erase(ultimo,str_cat.end());
	return str_cat;
}

std::vector<SRanking>Ventas::Ranking(std::string categoria,Stock s){ /* Devuelve un vector con el ranking por categoria segun los mas vendidos */
	std::vector<SRanking> SR;
	int pos;
	for(size_t i=0;i<v_ventas.size();i++) { /* Se carga el vector segun una categoria */
		pos = s.BuscarID(v_ventas[i].id_v);
		Producto p = s.VerProductoStock(pos);
		if(p.VerCategoria()==categoria){
			SRanking aux;
			aux.id = p.VerID();
			SR.push_back(aux);
		}
	}
	for(size_t i=0;i<SR.size();i++) { /* Acumula la cantidad vendida de un producto */
		for(size_t j=0;j<v_ventas.size();j++) { 
				if(SR[i].id==v_ventas[j].id_v){
					SR[i].cant+=v_ventas[j].cantidad_v;
				}
		}
	}
	std::sort(SR.begin(), SR.end(), [](SRanking a, SRanking b) { /* Ordena segun la id */
		return a.id > b.id;
	});
	
	SR.erase(std::unique(SR.begin(),SR.end(), [](SRanking a, SRanking b) { /* Elimina las id repetidas */
		return a.id == b.id;
	}),SR.end()); 
	
	std::sort(SR.begin(), SR.end(), [](SRanking a, SRanking b) { /* Ordena segun la cantidad */
		return a.cant > b.cant;
	});
	
	return SR;
}

bool SegunFactura (const SVentas &sv1, const SVentas &sv2) { /* Critero para usarlo segun su nro de factura */
	std::string fact1 = std::to_string(sv1.nro_factura) + ", " + sv1.id_v;
	std::string fact2 = std::to_string(sv2.nro_factura) + ", " + sv2.id_v;
	return fact1 < fact2;
}

bool SegunFecha (const SVentas &sv1, const SVentas &sv2) { /* Criterio para usarlo segun su fecha */
	std::string fact1 = std::to_string(sv1.fecha) + ", " + std::to_string(sv1.nro_factura) + ", " + sv1.id_v;
	std::string fact2 = std::to_string(sv2.fecha) + ", " + std::to_string(sv2.nro_factura) + ", " + sv2.id_v;
	return fact1 < fact2;
}
