// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include "Marca.h"

using namespace std;

int q_estado; 

void crear_marcas();
void crear_productos();
void leer_marcas();
void leer_productos();
void actualizar_marcas();
void actualizar_productos();
void borrar_marcas();
void borrar_productos();

int main(){
    string producto, id_marca, descripcion, precio_costo, precio_venta, fecha_ingreso;
    int existencia = 0, op = 0, op1 = 0, op2 = 0;

	cout << "*****************MENU******************" << endl << endl;
	cout << "SELECCIONE LA TABLA QUE DESEA EDITAR:" << endl << endl;
	cout << "Marcas...............................1" << endl;
	cout << "Productos............................2" << endl;
	cout << "Salir................................3" << endl << endl;
	cin >> op;

	switch (op) {

	case 1: system("cls");

		cout << "*************Editar_Tabla_Marcas**************" << endl << endl;
		cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
		cout << "Crear registro.......................1" << endl;
		cout << "Leer registro........................2" << endl;
		cout << "Actualizar registro..................3" << endl;
		cout << "Borrar registro......................4" << endl;
		cout << "Regresar.............................5" << endl << endl;
		cin >> op1;

		switch (op1) {
		case 1: crear_marcas();
			break;
		case 2: leer_marcas();
			break;
		case 3: actualizar_marcas();
			break;
		case 4:  borrar_marcas();
			break;
		case 5: system("cls"); main();
			break;
		default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
		}

		break;

	case 2:  system("cls");

		cout << "************Editar_Tabla_Productos************" << endl << endl;
		cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
		cout << "Crear registro.......................1" << endl;
		cout << "Leer registro........................2" << endl;
		cout << "Actualizar registro..................3" << endl;
		cout << "Borrar registro......................4" << endl;
		cout << "Regresar.............................5" << endl << endl;
		cin >> op2;

		switch (op2) {
		case 1: crear_productos();
			break;
		case 2: leer_productos();
			break;
		case 3: actualizar_productos();
			break;
		case 4:  borrar_productos();
			break;
		case 5: system("cls"); main();
			break;
		default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
		}

		break;

	case 3: system("exit");
		break;
	default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
	}

		system("pause");
		return 0;
};

void crear_marcas()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string marca;
		cout << "Ingrese la marca:" << endl;
		cin >> marca;
		string insert = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Ingreso exitoso..." << endl;
		}
		else {
			cout << "error al ingresar..." << endl;
		}
	}
	else {
		cout << "error en la conexion..." << endl;
	}
	system("pause");	system("cls"); main();
}

void crear_productos()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso;
		cout << "Ingrese el nombre del producto:" << endl;
		cin >> producto;
		cout << "Ingrese el ID de la marca:" << endl;
		cin >> id_marca;
		cout << "Ingrese la descripcion del producto:" << endl;
		cin >> descripcion;
		cout << "Ingrese el precio costo del producto:" << endl;
		cin >> precio_costo;
		cout << "Ingrese el precio de venta del producto:" << endl;
		cin >> precio_venta;
		cout << "Ingrese la existencia del producto:" << endl;
		cin >> existencia;
		cout << "Ingrese la fecha de ingreso del producto en formato AA-MM-DD:" << endl;
		cin >> fecha_ingreso;


		string insert = "insert into productos(productos,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values('" + producto + "','" + id_marca + "','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Ingreso exitoso..." << endl;
		}
		else {
			cout << "error al ingresar..." << endl;
		}
	}
	else {
		cout << "error en la conexion..." << endl;
	}
	system("pause");	system("cls"); main();
}

void leer_marcas()
{
	system("cls");

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << ", " << fila[1] << endl;


			}

		}
		else {
			cout << "error al consultar..." << endl;
		}
	}
	else {
		cout << "error en la conexion..." << endl;
	}
	system("pause");	system("cls"); main();
}

void leer_productos()
{
	system("cls");

	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << endl;


			}

		}
		else {
			cout << "error al consultar..." << endl;
		}
	}
	else {
		cout << "error en la conexion..." << endl;
	}
	system("pause");	system("cls"); main();
}

void actualizar_marcas()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string marca;
		string id_marca;
		cout << "Ingrese la ID de la marca que desa actualizar:" << endl;
		cin >> id_marca;
		cout << "Ingrese la el nuevo registro:" << endl;
		cin >> marca;

		string update = "update db_tienda.marcas set marca=('" + marca + "') where('" + id_marca + "')=id_marca";
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Actualizacion exitosa..." << endl;
		}
		else {
			cout << "Error al Actualizar..." << endl;
		}
	}
	else {
		cout << "Error en la conexion..." << endl;
	}

	system("pause");	system("cls"); main();
}

void actualizar_productos()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso, id_producto;

		cout << "Ingrese la ID del producto que desa actualizar:" << endl;
		cin >> id_producto;
		cout << "Ingrese el nombre del producto:" << endl;
		cin >> producto;
		cout << "Ingrese el ID de la marca:" << endl;
		cin >> id_marca;
		cout << "Ingrese la descripcion del producto:" << endl;
		cin >> descripcion;
		cout << "Ingrese el precio costo del producto:" << endl;
		cin >> precio_costo;
		cout << "Ingrese el precio de venta del producto:" << endl;
		cin >> precio_venta;
		cout << "Ingrese la existencia del producto:" << endl;
		cin >> existencia;
		cout << "Ingrese la fecha de ingreso del producto en formato AA-MM-DD:" << endl;
		cin >> fecha_ingreso;


		string insert = "update db_tienda.productos set  productos =('" + producto + "'),idmarca =('" + id_marca + "'),descripcion =('" + descripcion + "' ), precio_costo = ('" + precio_costo + "'), precio_venta =('" + precio_venta + "'), existencia =('" + existencia + "'), fecha_ingreso =('" + fecha_ingreso + "')  where('" + id_producto + "') = id_producto";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Ingreso exitoso..." << endl;
		}
		else {
			cout << "error al ingresar..." << endl;
		}
	}
	else {
		cout << "error en la conexion..." << endl;
	}

	system("pause");	system("cls"); main();
}

void borrar_marcas()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string marca;
		string id_marca;
		cout << "Ingrese la ID de la marca	que desea eliminar:" << endl;
		cin >> id_marca;

		string update = "delete from db_tienda.marcas  where('" + id_marca + "')=id_marca"; 
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Eliminacion exitosa..." << endl;
		}
		else {
			cout << "Error al eliminar..." << endl;
		}
	}
	else {
		cout << "Error en la conexion..." << endl;
	}
	system("pause");	system("cls"); main();
}

void borrar_productos()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_tienda", "Tiend@123", "db_tienda", 3306, NULL, 0);


	if (conectar) {

		string producto;
		string id_producto;
		cout << "Ingrese la ID del producto que desea eliminar:" << endl;
		cin >> id_producto;

		string update = "delete from db_tienda.productos  where('" + id_producto + "')=id_producto";
		const char* i = update.c_str();
		q_estado = mysql_query(conectar, i);

		if (!q_estado) {
			cout << "Eliminacion exitosa..." << endl;
		}
		else {
			cout << "Error al eliminar..." << endl;
		}
	}
	else {
		cout << "Error en la conexiÃ³n..." << endl;
	}

	system("pause");	system("cls"); main();
}
