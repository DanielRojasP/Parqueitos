#include "Parqueo.h"

Parqueo::Parqueo()
{
	cantidad = 0;
	tamano = 0;
	//Se define el tamaño del vector
	//en tiempo de ejecución.
	parqueo = new char* [tamano];

	for (int i = 0; i < tamano; i++)
		parqueo[i] = new char();
}

void Parqueo::llenadoParqueo(int n)
{

	tamano = n;
	//Se define el tamaño del vector
	//en tiempo de ejecución.
	parqueo = new char* [n];

	for (int i = 0; i < n; i++)
		parqueo[i] = new char('D');
}

Parqueo::~Parqueo()
{
	cantidad = 0;
	for (int i = 0; i < cantidad; i++)
		delete parqueo[i];
}

bool Parqueo::agregarCampo(char* campo)
{
	//campo = new char('O');
	if (cantidad < tamano) {
		parqueo[cantidad] = campo;
		cantidad++;
		return true;
	}
	return false;
}

void Parqueo::actualizar(int pos)
{
	char* campo = new char('D');
	parqueo[pos] = campo;
}

void Parqueo::imprimeParqueo() {
	int cont = 0;
	for (int i = 0; i < tamano; i++) {
		cout << "\t" << i << "[" << *parqueo[i] << "]\t";
		cont++;
		if (cont == 5) {
			cout << "\n";
			cont = 0;
		}

	}
	cout << "\n";
}

bool Parqueo::reservado(int pos)
{
	char* campo = new char('R');
	if (parqueo[pos] == campo) return true;
	return false;
}
