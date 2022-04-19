#pragma once
#include <iostream>
using namespace std;
class Producto{
	//atrubutos
protected: string producto, descripcion, precio_costo, precio_venta, fecha_ingreso;
		 int existencia=0;
		 //constructor
protected:
	Producto() {
	}
	Producto(string pro, string des, string cost, string vent, int ex, string fn) {
		producto = pro;
		descripcion = des;
		precio_costo = cost;
		precio_venta = vent;
		existencia = ex;
		fecha_ingreso = fn;
	}
};