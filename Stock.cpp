#include "Producto.h"
#include "Stock.h"
#include <fstream>
#include <algorithm>
#include <iostream>
Stock::Stock(std::string nombre_archivo_bin) {
	s_archivo_bin = nombre_archivo_bin;
	std::ifstream LectArchivoS (s_archivo_bin, std::ios::binary | std::ios::ate);
	if (LectArchivoS.is_open()) {
		int tam = LectArchivoS.tellg()/sizeof(SProducto);
		LectArchivoS.seekg(0);
		
		v_prod.resize(tam);
		for(int i=0;i<tam;i++) { 
			v_prod[i].AbrirBinario(LectArchivoS);
		}
	}
	LectArchivoS.close();
}

Stock::Stock(){}

int Stock::VerPosicion (int fila) { /* Segun la fila pasada desde la grilla, devuelve la posicion original de un producto */ 
	int cont = 0;
	for(int i=0;i<VerTamStock();i++) {
		if (!VerProductoStock(i).VerEliminado()) {
			if (fila == cont) {
				return i;
			} else {
				cont++;
			}
		}
	}
	return -1;
}

void Stock::AgregarProducto (Producto P) { /* Se agrega un nuevo producto en la ultima posicion del vector */
	v_prod.push_back(P);
}

void Stock::GuardarStock () { /* Se borran los antiguos datos del binario y se actualiza con los nuevos provenientes del vector */
	int tam = v_prod.size();
	
	std::ofstream EscArchivoS (s_archivo_bin, std::ios::binary | std::ios::trunc);
	if (EscArchivoS.is_open()) {
		for(int i=0;i<tam;i++) { 
			v_prod[i].GuardarBinario(EscArchivoS);
		}
	}
	EscArchivoS.close();
}

void Stock::OrdenarStock (int segun) { /* Se ordenan los productos del vector segun cierto criterio */ 
	switch (segun) {
	case 1:
		sort(v_prod.begin(), v_prod.end(), SegunNombre); /* Ordena segun el nombre (A-Z) */
		break;
	case 2:
		sort (v_prod.begin(), v_prod.end(), SegunNombre); /* Ordena segun el nombre (Z-A) */
		reverse(v_prod.begin(), v_prod.end());
		break;
	case 3:
		sort(v_prod.begin(), v_prod.end(), SegunMarca); /* Ordena segun la marca (A-Z) */
		break;
	case 4:
		sort(v_prod.begin(), v_prod.end(), SegunMarca); /* Ordena segun la marca (Z-A) */
		reverse(v_prod.begin(), v_prod.end());
		break;
	case 5:
		sort(v_prod.begin(), v_prod.end(), SegunCategoria); /* Ordena segun la categoria (A-Z) */
		break;
	case 6:
		sort(v_prod.begin(), v_prod.end(), SegunCategoria); /* Ordena segun la categoria (Z-A) */
		reverse(v_prod.begin(), v_prod.end());
		break;
	case 7:
		sort(v_prod.begin(), v_prod.end(), SegunPrecio); /* Ordena segun el precio (0-n) */
		break;
	case 8:
		sort(v_prod.begin(), v_prod.end(), SegunPrecio); /* Ordena segun el precio (n-0) */
		reverse(v_prod.begin(), v_prod.end());
		break;
    case 9:
	    sort(v_prod.begin(), v_prod.end(), SegunCantidad); /* Ordena segun la cantidad (0-n) */
		break;
    case 10:
		sort(v_prod.begin(), v_prod.end(), SegunCantidad); /* Ordena segun la cantidad (n-0) */
		reverse(v_prod.begin(), v_prod.end());
		break;
	}
}

int Stock::BuscarProducto (std::string busq_prod, int pos) { /* Busca un producto segun su nombre */
	Minuscula (busq_prod);
	int no = -1;
	int tam = v_prod.size(); 
	std::string nomb_prod;
	
	for(int i=pos; i<tam; i++) {
		Producto P = v_prod[i];
		nomb_prod = P.VerNombre();
		Minuscula (nomb_prod);
		if (nomb_prod.find(busq_prod,0) != std::string::npos) {
			return i;
		}
	}
	return no;
}

int Stock::BuscarMarca (std::string busq_marca, int pos) { /* Busca un producto segun su marca */
	Minuscula (busq_marca);
	int no = -1;
	int tam = v_prod.size();
	std::string marca_prod;
	for(int i=pos;i<tam;i++) { 
		Producto P = v_prod[i];
		marca_prod = P.VerMarca();
		Minuscula (marca_prod);
		if (marca_prod.find(busq_marca, 0) != std::string::npos) {
			return i;
		}
	}
	return no;
}

int Stock::BuscarCategoria (std::string busq_cat, int pos) { /* Busca un producto segun su categoria */
	Minuscula (busq_cat);
	int no = -1;
	int tam = v_prod.size();
	std::string cat_prod;
	
	for(int i=pos; i<tam; i++) {
		Producto P = v_prod[i];
		cat_prod = P.VerCategoria();
		Minuscula (cat_prod);
		if (cat_prod.find(busq_cat, 0) != std::string::npos) {
			return i;
		}
	}
	return no;
}

int Stock::BuscarID (std::string busq_id) { /* Busca un producto segun su codigo de identificacion */
	int no = -1;
	int tam = v_prod.size();
	std::string s_id; 
	
	for(int i=0; i<tam; i++) {
		Producto P = v_prod[i];
		s_id = P.VerID();
		if (s_id == busq_id) {
			return i;
		}
	}
	return no;
}

std::string Stock::VerificarID (std::string id) { /* Verifica si el codigo de identificacion de un producto ya existe en el stock */
	std::string error;
	int tam = VerTamStock();
	
	for(int i=0;i<tam;i++) { 
		Producto P = v_prod[i];
		if (id==P.VerID()) {
			error = error + "¡La ID ingresada ya existe! Verifique el stock o ingrese una nueva ID\n";
		}
	}
	return error;
}

std::string Stock::VerNombArchiBin () { /* Devuelve el nombre del archivo binario */
	return s_archivo_bin;
}

size_t Stock::VerTamStock() { /* Devuelve la cantidad disponible del stock */
	return v_prod.size();
}

Producto &Stock::VerProductoStock(int i) { /* Devuelve los valores de un Producto */
	return v_prod[i];
}

bool Stock::ValidarCantidad (std::vector<std::string>ids, std::vector<int>cantidad) { /* Devuelve true si la cantidad a vender es mayor a la disponible en stock */
	for(size_t i=0;i<ids.size();i++) { 
		int posi = BuscarID(ids[i]);
		if(v_prod[posi].VerCantidad() < cantidad[i]){
			return false;
		}
	}
	return true;
}

void Stock::DescontarVenta (std::vector<int> posiciones, std::vector<int> cantidad) { /* Descuenta la cantidad vendida a un Producto luego de realizar correctamente una venta */
	for(size_t i=0;i<posiciones.size();i++){
		int x = posiciones[i];
		v_prod[x].ModificarCantidad(v_prod[x].VerCantidad() - cantidad[i]);
	}
	GuardarStock();
}

void Stock::EliminarDelCarrito (int pos) { /* Elimina un producto del carrito de compras */
	auto iterador = v_prod.begin()+pos;  /* Utilizar esta función unicamente en el carrito de compras */
	v_prod.erase(iterador);
}
