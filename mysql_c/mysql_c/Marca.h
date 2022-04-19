#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Producto.h"

using namespace std; 

class Marca : public Producto {
	// atributos
private: string id_marca;

	   //contructor
public:
	Marca() {
	}

	Marca(string pro, string des, string cost, string vent, int ex, string fn, string ma) : Producto(pro, des, cost, vent, ex, fn) { 

	}
	// metodos
	// set (modificar)
	void setMarca(string ma) { id_marca = ma; }
	void setProducto(string pro) { producto = pro; }
	void setDescripcion(string des) { descripcion = des; }
	void setPrecio_costo(string cost) { precio_costo = cost; }
	void setPrecio_venta(string vent) { precio_venta = vent; }
	void setFecha_ingreso(string fn) { fecha_ingreso = fn; }
	void setExistencia(int ex) { existencia = ex; }
	//get (mostrar)
	string getMarca() { return id_marca; }
	string getProducto() { return producto; }
	string getDescripcion() { return descripcion; }
	string getPrecio_costo() { return precio_costo; }
	string getPrecio_venta() { return precio_venta; }
	string getFecha_ingreso() { return fecha_ingreso; }
	int getExistencia() { return existencia; }

};
