// mysql_em.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "USR_EMPRESA", "*54168217Ny", "empresa", 3306, NULL, 0);
	if (conectar) {
		//cout << "Conectado a la Matrix..." << endl;
		string producto, Descripcion;
		cout << "Ingrese product: ";
		cin >> producto;
		cout << "Ingrese Descripcion: ";
		cin >> Descripcion;
		string insert = "insert into productos(Producto, Descripcion) values('" + producto+"', '"+Descripcion + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso..." << endl;
		}
		else {
			cout << "**** Error al ingresar ****" << endl;
		}
	}
	else {
		cout << "Error en la Matrix..." << endl;
	}
		system("pause");
	return 0;
}

