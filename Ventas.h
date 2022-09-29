#ifndef VENTAS_H
#define VENTAS_H
#include <vector>
#include <string>
#include <algorithm>
#include "Producto.h"
#include "Fecha.h"
#include "Stock.h"

struct SVentas{ /** Al no poder usar strings, se usa un struct como intermediario para leer o escribir en un archivo binario **/
	int nro_factura;
	char id_v[256];
	int precio_unitario_v;
	int precio_total_v;
	int cantidad_v;
	int porcentaje_v;
	int fecha;
};

struct SRanking{
	std::string id;
	int cant=0;
};

class Ventas {
	
	std::vector <SVentas> v_ventas; /** Vector donde se cargan las ventas del binario **/
	int cont_factura= -1;
	std::string v_archivo_bin; /** Nombre del archivo binario donde se guardan el historial de mas vendidos **/
	
public:
	/** Construye el objeto y carga los datos de los Productos desde archivos binarios **/
	Ventas(std::string nombre_bin);
	
	Ventas();
	
	std::string VerID (int i);
	
	int VerPUnitario (int i);
	
	int VerPTotal (int i);
	
	int VerCantidad (int i);
	
	int VerPorcentaje (int i);
	
	int VerFecha(int i);
	
	int VerFactura(int i);
	
	std::vector<SVentas>VerVentas(); /** Metodo para ver ventas **/
	
	int CalcularDescuento (int precio, int porcentaje); /** Metodo para calcular el costo con descuento de un Producto **/ 
	
	void GuardarVentas(); /** Metodo para guardar un archivo binario **/
	
	bool RealizarVenta(Stock s, std::vector<int> cantidad, std::vector<int>desc); /** Metodo para realizar una venta **/
	
	void OrdenarVentas(int segun); /** Metodo para ordenar las ventas segun un criterio **/
	
	std::string VerificacionBusqueda(int fecha_i,int fecha_f,int nro_factura_i,int nro_factura_f,int nro_factura); /** Metodo para verificar una busqueda **/
	
	std::vector<SVentas> ListaBusquedaAvanzada(int fecha_i,int fecha_f,int nro_factura_i,int nro_factura_f);
	
	std::vector<SVentas> FiltrarPorFecha(int fecha_i=-1,int fecha_f=-1);
	
	std::vector<SVentas> FiltrarPorFactura(int nro_factura_i,int nro_factura_f,std::vector<SVentas>v_fil);
	
	std::vector<std::string> VerCategoriasVentas(Stock s);
	
	std::vector<SRanking> Ranking(std::string categoria,Stock s);
	
	size_t VentaTam(); /** Metodo para ver el tamaño del vector de ventas **/
};

bool SegunFactura (const SVentas &sv1, const SVentas &sv2); /** Criterio para ordenar las ventas segun la factura **/

bool SegunFecha (const SVentas &sv1, const SVentas &sv2); /** Criterio para ordenar las ventas segun la fecha **/

#endif

