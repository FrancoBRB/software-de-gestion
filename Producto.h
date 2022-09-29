#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <fstream>
#include <vector>

struct SProducto { /** Al no poder usar strings, se usa un struct como intermediario para leer o escribir en un archivo binario **/
	char nombre_producto[256];
	char marca[256];
	char categoria[256];
	char id[256];
	int cantidad;
	int precio;
	int eliminado;
};

class Producto {
	
	std::string p_nombre; /** Nombre del Producto **/
	std::string p_marca; /** Nombre de la marca que fabrica el Producto **/
	std::string p_categoria; /** Categoria del Producto **/
	std::string p_id; /** Codigo de identificacion de un Producto **/
	int p_cantidad; /** Cantidad de unidades de un Producto **/
	int p_precio; /** Precio de cada unidad de un Producto **/
	bool p_eliminado; /** Booleano para un producto eliminado **/
	
public:
	
	/** Construye e inicializa un objeto con los datos de un Producto **/
	Producto (std::string nombre_producto = "", std::string marca="", std::string categoria = "", std::string id = "", int cantidad = 0, int precio = 0);
	
	/** Metodos para ver los datos de un Producto **/
	std::string VerNombre () const; /** Metodo para ver el nombre de un Producto **/
	
	std::string VerMarca () const; /** Metodo para ver la marca del fabricante de un Producto **/
	
	std::string VerCategoria () const; /** Metodo para ver la categoria de un Producto **/
	
	std::string VerID () const; /** Metodo para ver el codigo de identificacion de un Producto **/
	
	int VerCantidad () const; /** Metodo para ver la cantidad de unidades de un Producto **/
	
	int VerPrecio () const; /** Metodo para ver el precio de un Producto **/
	
	bool VerEliminado() const; /** Metodo para ver si un Producto esta discontinuado **/
	
	/** Metodos para modificar los datos de un Producto **/
	void ModificarNombre (std::string nuevo_nomb_producto); /** Metodo para modificar el nombre de un Producto **/
	
	void ModificarMarca (std::string nueva_marca); /** Metodo para modificar la marca del fabricante de un Producto **/
	
	void ModificarCategoria (std::string nueva_categoria); /** Metodo para modificar la categoria de un Producto **/
	
	void ModificarID (std::string nueva_id); /** Metodo para modificar el codigo de identificacion de un Producto **/
	
	void ModificarCantidad (int nueva_cantidad); /** Metodo para modificar la cantidad de unidades de un Producto **/
	
	void ModificarPrecio (int nuevo_precio); /** Metodo para modificar el precio de un Producto **/
	
	void EliminarProducto (); /** Metodo para discontinuar un Producto **/
	
	Producto operator++(int); /** Metodo para aumentar en uno la cantidad de un Producto **/
	
	Producto operator--(int); /** Metodo para restar en uno la cantidad de un Producto **/
	
	/** Metodos para manejo de archivos **/
	void GuardarBinario (std::ofstream &EscArchivo); /** Metodo para guardar desde un archivo binario **/
	
	void AbrirBinario (std::ifstream &LectArchivo); /** Metodo para leer desde un archivo binario **/ 
	
	/** Metodos para verificar datos de un producto **/
	std::string VerificarProducto (); /** Metodo para verificar si los datos de un Producto es correcto **/
	
	std::string VerificarPrecio (); /** Metodo para verificar si el precio ingresado es correcto **/
	
};

/** Metodos para comparar datos **/
bool SegunNombre (const Producto &P1, const Producto &P2); /** Metodo para comparar dos productos segun el nombre **/

bool SegunMarca (const Producto &P1, const Producto &P2); /** Metodo para comparar dos productos segun la marca **/

bool SegunCategoria (const Producto &P1, const Producto &P2); /** Metodo para comparar dos productos segun la categoria **/

bool SegunCantidad (const Producto &P1, const Producto &P2); /** Metodo para comparar dos productos segun su cantidad **/

bool SegunPrecio (const Producto &P1, const Producto &P2); /** Metodo para comparar dos productos segun su precio **/

/** Otros metodos **/
void Minuscula (std::string &cadena); /** Funcion para pasar todo a minuscula **/

void Corregir (std::string &cadena); /** Funcion para corregir cada letra inicial por una mayuscula y el resto minuscula **/

#endif

