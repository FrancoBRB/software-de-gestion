#ifndef STOCK_H
#define STOCK_H
#include "Producto.h"
#include <vector>
#include <string>

class Stock {
	
	std::vector<Producto> v_prod; /** Vector donde se cargan los productos del binario **/
	std::string s_archivo_bin = " "; /** Variable donde se guarda el nombre del archivo binario **/
	
public:
	Stock (std::string nombre_archivo_bin); /** Construye el objeto y carga los datos de los productos desde un archivo binario **/
	
	Stock (); /** Constructor para los productos del carrito de compras **/
	
	int VerPosicion (int fila); /** Metodo que devuelve la posicion original de un Producto **/
	
	void AgregarProducto (Producto P); /** Metodo para agregar un Producto al registro **/
	
	void OrdenarStock (int segun); /** Metodo para ordenar el stock segun un criterio **/
	
	void GuardarStock (); /** Metodo para guardar un archivo binario **/
	
	/** Metodos de busqueda **/
	
	int BuscarProducto (std::string busq_prod, int pos); /** Metodo para buscar un Producto por su nombre **/
	
	int BuscarMarca (std::string busq_marca, int pos); /** Metodo para buscar un Producto por su marca **/
	
	int BuscarCategoria (std::string busq_cat, int pos); /** Metodo para buscar un Producto por su categoria **/
	
	int BuscarID (std::string busq_id); /** Metodo para buscar un Producto por su codigo de identificacion **/
	
	/** Otros metodos **/ 
	std::string VerificarID (std::string id); /** Metodo para verificar el codigo de identificacion de un Producto **/
	
	std::string VerNombArchiBin (); /** Metodo para ver el nombre del archivo binario del stock **/
	
	size_t VerTamStock (); /** Metodo para ver el stock disponible cargado en un vector **/
	
	Producto &VerProductoStock(int i); /** Metodo para ver o modificar un Producto **/
	
	bool ValidarCantidad(std::vector<std::string>ids,std::vector<int>cantidad); /** Verifica que la cantidad a vender sea menor a la cantidad disponible en el stock **/
	
	void DescontarVenta(std::vector<int> posiciones, std::vector<int> cantidad); /** Descuenta la cantidad vendida a un Producto luego de realizar correctamente una venta **/
	
	void EliminarDelCarrito(int pos); /** Elimina un producto del carrito de compras **/
};

#endif

