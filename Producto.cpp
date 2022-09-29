#include "Producto.h"
#include <cstring>

Producto::Producto (std::string nombre_producto, std::string marca, std::string categoria, std::string id, int cantidad, int precio){ /* Se carga el Producto con cada uno de sus datos */
	p_nombre = nombre_producto;
	p_marca = marca;
	p_categoria = categoria;
	p_id = id;
	p_cantidad = cantidad;
	p_precio = precio;
	p_eliminado = false;
}

std::string Producto::VerNombre () const { /* Devuelve el nombre del Producto */
	return p_nombre;
}

std::string Producto::VerMarca () const { /* Devuelve la marca del Producto */
	return p_marca;
}

std::string Producto::VerCategoria () const { /* Devuelve la categoria del Producto */
	return p_categoria;
}

std::string Producto::VerID () const { /* Devuelve el codigo de identificacion del Producto */
	return p_id;
}

int Producto::VerCantidad () const { /* Devuelve la cantidad de unidades que posee el Producto */
	return p_cantidad;
}

int Producto::VerPrecio () const { /* Devuelve el precio del Producto */
	return p_precio;
}

bool Producto::VerEliminado() const{
	return p_eliminado;
}

void Producto::ModificarNombre (std::string nuevo_nomb_producto) { /* Modifica el nombre del Producto por uno nuevo */
	p_nombre = nuevo_nomb_producto;
}

void Producto::ModificarMarca (std::string nueva_marca) { /* Modifica la marca del Producto por una nueva */
	p_marca = nueva_marca;
}

void Producto::ModificarCategoria (std::string nueva_categoria) { /* Modifica la categoria del Producto por una nueva */
	p_categoria = nueva_categoria;
}

void Producto::ModificarID (std::string nueva_id) { /* Modifica el codigo de identificacion de un Producto por uno nuevo */ 
	p_id = nueva_id;
}

void Producto::ModificarCantidad (int nueva_cantidad) { /* Modifica la cantidad de unidades de un Producto por una nueva */
	p_cantidad = nueva_cantidad;
}

void Producto::ModificarPrecio (int nuevo_precio) { /* Modifica el precio de un Producto por uno nuevo */
	p_precio = nuevo_precio;
}

void Producto::EliminarProducto(){
	p_eliminado = true;
}

Producto Producto::operator++(int) { /* Sobrecarga del operador ++ para aumentar la cantidad de un Producto en uno */
	Producto P = *this;
	this -> p_cantidad++;
	return P;
}

Producto Producto::operator--(int) { /* Sobrecarga del operador -- para restar la cantidad de un Producto en uno */
	Producto P = *this;
	if (P.VerCantidad() > 0) {
		this -> p_cantidad--;
	}
	return P;
}

void Producto::GuardarBinario (std::ofstream &EscArchivo) { /* Guarda los datos de un Producto hacia un archivo binario usando un struct como intermediario */
	SProducto Sp;
	strcpy (Sp.nombre_producto, p_nombre.c_str());
	strcpy (Sp.marca, p_marca.c_str());
	strcpy (Sp.categoria, p_categoria.c_str());
	strcpy (Sp.id, p_id.c_str());
	Sp.cantidad = p_cantidad;
	Sp.precio = p_precio;
	if(p_eliminado){
		Sp.eliminado=1;
	}else{
		Sp.eliminado=0;
	}
	EscArchivo.write (reinterpret_cast <char*> (&Sp), sizeof (Sp));
}

void Producto::AbrirBinario (std::ifstream &LectArchivo) { /* Lee los datos de un Producto desde un archivo binario usando un struct como intermediario */
	SProducto Sp;
	LectArchivo.read (reinterpret_cast <char*> (&Sp), sizeof (Sp));
	p_nombre = Sp.nombre_producto;
	p_marca = Sp.marca;
	p_categoria = Sp.categoria;
	p_id = Sp.id;
	p_cantidad = Sp.cantidad;
	p_precio = Sp.precio;
	if(Sp.eliminado==1){
		p_eliminado=true;
	}else{
		p_eliminado=false;
	}
}

std::string Producto::VerificarProducto () { /* Devuelve un mensaje de error si un dato de un Producto es incorrecto */
	std::string error;
	
	if (p_nombre.size()==0) {
		error = error + "¡Debe ingresar el nombre de un producto!\n";
	}
	if (p_marca.size()==0) {
		error = error + "¡Debe ingresar la marca de un producto!\n";
	}
	if (p_categoria.size()==0) {
		error = error + "¡Debe ingresar la categoria de un producto!\n";
	}
	if (p_id.size()==0) {
		error = error + "¡Debe ingresar la ID de un producto!\n";
	}
	if (p_nombre.size()>256) {
		error = error + "¡Se supera el limite de caracteres!\n";
	}
	if (p_marca.size()>256) {
		error = error + "¡Se supera el limite de caracteres!\n";
	}
	if (p_categoria.size()>256) {
		error = error + "¡Se supera el limite de caracteres!\n";
	}
	if (p_id.size()>256) {
		error = error + "¡Se supera el limite de caracteres!\n";
	}
	if (p_precio < 0) {
		error = error + "¡Debe ingresar un precio real!\n";
	}
	if (p_cantidad < 0) {
		error = error + "¡Debe ingresar una cantidad real!\n";
	}
	return error;
}

bool SegunNombre (const Producto &P1, const Producto &P2) { /* Criterio para usarlo segun su nombre */
	std::string pr1 = P1.VerNombre() + ", " + P1.VerMarca() + ", " + P1.VerCategoria();
	std::string pr2 = P2.VerNombre() + ", " + P2.VerMarca() + ", " + P2.VerCategoria();
	Minuscula (pr1);
	Minuscula (pr2);
	return pr1<pr2;
}

bool SegunMarca (const Producto &P1, const Producto &P2) { /* Criterio para para usarlo segun su marca */
	std::string pr1 = P1.VerMarca() + ", " + P1.VerNombre() + ", " + P1.VerCategoria();
	std::string pr2 = P2.VerMarca() + ", " + P2.VerNombre() + ", " + P2.VerCategoria();
	Minuscula (pr1);
	Minuscula (pr2);
	return pr1<pr2;
}

bool SegunCategoria (const Producto &P1, const Producto &P2) { /* Criterio para para usarlo segun su categoria */
	std::string pr1 = P1.VerCategoria() + ", " + P1.VerNombre() + ", " + P1.VerMarca();
	std::string pr2 = P2.VerCategoria() + ", " + P2.VerNombre() + ", " + P2.VerMarca();
	Minuscula (pr1);
	Minuscula (pr2);
	return pr1<pr2;
}

bool SegunCantidad (const Producto &P1, const Producto &P2) { /* Criterio para para usarlo segun su cantidad */
	int pr1 = P1.VerCantidad();
	int pr2 = P2.VerCantidad();
	return pr1<pr2;
}

bool SegunPrecio (const Producto &P1, const Producto &P2) { /* Criterio para para usarlo segun su precio */
	int pr1 = P1.VerPrecio();
	int pr2 = P2.VerPrecio();
	return pr1<pr2;
}

void Minuscula (std::string &cadena) { /* Funcion que transforma los valores de una cadena en minuscula */ 
	int tam = cadena.size();
	
	for(int i=0;i<tam;i++) { 
		cadena[i] = std::tolower(cadena[i]);
	}
}

void Corregir (std::string &cadena) { /* Funcion que transforma cada valor inicial de una cadena en mayuscula y al resto lo deja en minuscula */
	int pos, tam = cadena.size();
	cadena[0] = std::toupper(cadena[0]);
	
	for(int i=1;i<tam;i++) { 
		cadena[i] = std::tolower(cadena[i]);
	}
	for(int i=0;i<tam;i++) { 
		pos = cadena.find(" ", i);
		cadena[pos+1] = std::toupper(cadena[pos+1]);
	}
}

