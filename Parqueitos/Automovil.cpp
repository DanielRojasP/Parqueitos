#include "Automovil.h"

Automovil::Automovil()
{
    placa = 0;
    hEntrada = "";
    hSalida = "";
    lugar = new int();
    tiempo = 0.0;
    start = 0.0;
    end = 0.0;
}

Automovil::Automovil(int p, string hE, string hS, int* l, time_t s, time_t e)
{
    this->placa = p;
    this->hEntrada = hE;
    this->hSalida = hS;
    this->lugar = l;
    this->start = s;
    this->end = e;
}


void Automovil::setPlaca(int p)
{
    this->placa = p;
}

void Automovil::sethEntrada(string hE)
{
    this->hEntrada = hE;
}

void Automovil::setLugar(int* l)
{
    this->lugar = l;

}

void Automovil::setTiempo(double t)
{
    this->tiempo = t;
}

void Automovil::setSalida(time_t e)
{
    this->end = e;
}
void Automovil::sethSalida(string hS) {
    this->hSalida = hS;
}
void Automovil::setInicio(time_t s) {
    this->start = s;

}
int Automovil::getPlaca()
{
    return placa;
}

int Automovil::getLugar()
{
    return *lugar;
}

double Automovil::getTiempo()
{
    return tiempo;
}

string Automovil::gethEntrada()
{
    return hEntrada;
}

string Automovil::gethSalida()
{
    return hSalida;
}

time_t Automovil::getEntrada()
{
    return start;
}

time_t Automovil::getSalida()
{
    return end;
}

string Automovil::toString()
{
    stringstream s;

    s << "Placa: " << getPlaca() << endl;
    s << "Hora de Entrada: " << gethEntrada() << endl;
    s << "Hora de Salida: " << gethSalida() << endl;
    s << "Numero de parqueo: " << setprecision(2) << getLugar() << endl;
    s << "Tiempo: " << setprecision(3) << fixed << getTiempo() << " hrs" << endl;
    return s.str();
}
