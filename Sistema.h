#ifndef SISTEMA_H
#define SISTEMA_H
#include "Stock.h"
#include "Ventas.h"
#include "Producto.h"
#include <vector>
class Sistema {
	Stock s;
	Ventas v;
public:
	Sistema(std::string nombre_s, std::string nombre_v); /** Construye el objeto con los nombres de los binarios Stock y Ventas **/
	
	bool Vender(Stock productos_avender, std::vector<int> cantidad, std::vector<int> desc); /** Realiza una venta y devuelve true si se realizo correctamente **/
	
	Stock &VerStock(); /** Metodo para ver el stock **/
	
	Ventas &VerVentas(); /** Metodo para ver las ventas **/
	
	
};
#endif

