#ifndef PARQUEO_H
#define PARQUEO_H

#include "Automovil.h"


class Parqueo
{
public:

	Parqueo();

	~Parqueo();
	void llenadoParqueo(int);
	bool agregarCampo(char*);
	void actualizar(int);
	void imprimeParqueo();
	bool reservado(int pos); //determina si un campo del parqueo se encuentra reservado

	int getCantidad() { return cantidad; };

private:
	char** parqueo;
	int cantidad;
	int tamano;
	//

};

#endif