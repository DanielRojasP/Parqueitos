#ifndef CONTROL_H
#define CONTROL_H

#include "Parqueo.h"
#include <vector>
#include "windows.h"

class Control
{
public:
	Control();
	void controlPrincipal();

	void ingresar(Parqueo*);
	void reservar(Parqueo*);
	void salir();


	void registrarAutos(Automovil*);
	void mostrarAutos();


private:

	vector<Automovil> lista;
};

#endif