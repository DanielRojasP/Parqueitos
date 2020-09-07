#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <iostream>
#include <sstream>
#include <iomanip> 
#include <time.h>
using namespace std;
class Automovil
{
public:
	Automovil();
	Automovil(int, string, string, int*, time_t, time_t);

	void setPlaca(int);
	void sethEntrada(string);
	void sethSalida(string);
	void setLugar(int*);
	void setTiempo(double);
	void setInicio(time_t);
	void setSalida(time_t);

	int getPlaca();
	int getLugar();
	double getTiempo();
	string gethEntrada();
	string gethSalida();

	time_t getEntrada();
	time_t getSalida();

	string toString();

private:
	int placa;
	string hEntrada; // hora de entrada
	string hSalida; // hora de salida
	int* lugar; // lugar de parqueo 
	double tiempo; //tiempo transcurrido en el parqueo
	time_t start;
	time_t end;


};
#endif
