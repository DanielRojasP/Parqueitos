#include "Control.h"


Control::Control()
{

}

void Control::controlPrincipal()
{
	char opc;
	bool finalizar = false;
	int n;
	cout << "\tBienvenido al sistema de Parqueitos\n\n";
	cout << "Que extension de Parqueo tenemos para este mes?\n";
	cin >> n;
	system("cls");

	Parqueo* p1 = new Parqueo();
	p1->llenadoParqueo(n);
	do {
		cout << "1- Ingresar Vehiculo al parqueo\n";
		cout << "2- Reservar espacio por un mes\n";
		cout << "3- Registrar Salida y Facturar Cobro\n";
		cout << "4- Mostrar Estado del Parqueo\n";
		cout << "5- Mostrar historial de Vehiculos en el Parqueo\n";
		cout << "6- Salir\n";
		cin >> opc;

		switch (opc)
		{
		case '1': {
			system("cls");
			ingresar(p1);
			system("pause");
			system("cls");
			break;
		}
		case '2': {
			system("cls");
			reservar(p1);
			system("pause");
			system("cls");
			break;
		}
		case '3': {
			system("cls");
			salir();
			system("pause");
			system("cls");
			break;
		}
		case '4': {
			system("cls");
			p1->imprimeParqueo();
			system("pause");
			system("cls");
			break;
		}
		case '5': {
			system("cls");
			mostrarAutos();
			system("pause");
			system("cls");
			break;
		}
		case '6': {
			system("cls");
			system("pause");
			exit(0);
			break;
		}
		default:
			cout << "Ingrese una opcion correcta...\n";
			system("pause");
			system("cls");
			break;
		}

	} while (!finalizar);
}

void Control::ingresar(Parqueo* p)
{
	char* campo = new char('O');
	int placa;
	string hEntrada; // hora de entrada
	string hSalida = ""; // hora de salida
	int* lugar = new int();
	*lugar = p->getCantidad(); // lugar de parqueo 
	double tiempo = 0.0; //tiempo transcurrido en el parqueo
	time_t start;
	time_t end = 0.0;

	cout << "Numero de Placa\n";
	cin >> placa;
	cout << "Introdusca la hora de entrada en el siguiente formato hh:mm\n";
	cin >> hEntrada;

	time(&start);
	if (p->agregarCampo(campo)) {
		cout << "Ocupando...\n";
	}
	else {
		cout << "No hay mas campos\n";
	}

	Automovil* a = new Automovil(placa, hEntrada, hSalida, lugar, start, end);
	registrarAutos(a);

}

void Control::reservar(Parqueo* p)
{
	char* campo = new char('R');
	int placa;
	string hEntrada; // hora de entrada
	string hSalida = ""; // hora de salida
	int* lugar = new int();
	*lugar = p->getCantidad(); // lugar de parqueo 
	double tiempo = 0.0; //tiempo transcurrido en el parqueo
	time_t start;
	time_t end = 0.0;

	cout << "Numero de Placa\n";
	cin >> placa;
	cout << "Introduzca la hora de entrada en el siguiente formato hh:mm\n";
	cin >> hEntrada;

	time(&start);
	if (p->agregarCampo(campo)) {
		cout << "Ocupando...\n";

	}
	else {
		cout << "No hay mas campos\n";
	}

	Automovil* a = new Automovil(placa, hEntrada, hSalida, lugar, start, end);
	registrarAutos(a);
}

void Control::salir()
{
	Automovil* a = new Automovil;
	Parqueo p;
	char* c = new char('D');
	time_t end;
	string hSalida = "";
	double tiempo; //variable para guardar el tiempo de estadia en el parqueo  en segundos 
	bool encontrado = false;
	int placa = 0;
	cout << "Ingrese el numero de placa del vehiculo\n";
	cin >> placa;


	for (unsigned int i = 0; i < lista.size(); i++) {
		if (lista[i].getPlaca() == placa) {
			encontrado = true;

			cout << "Introduzca la hora de salida en el siguiente formato hh:mm\n";
			cin >> hSalida;

			//calculamos el tiempo transcurrido en el parqueo por un automovil
			time(&end);
			a->setSalida(end);
			tiempo = difftime(end, a->getEntrada());

			tiempo = tiempo / 3600; //determinamos el tiempo de estadia en horas 
			a->setTiempo(tiempo);

			//calculamos el monto que debe pagar el usuario		
			if (p.reservado(i) == true) {
				cout << "Monto\n\t30 000 colones\n";
			}
			else {
				cout << "Monto\n\t" << setprecision(2) << fixed << (a->getTiempo() / 3600) * 800 << " colonones" << endl;
			}

			p.actualizar(i);

		}

	}
	if (!encontrado) {
		cout << "No se encontro el vehiculo en el Parqueo\n";
	}

}

void Control::registrarAutos(Automovil* a)
{
	lista.push_back(*a);
}

void Control::mostrarAutos()
{
	for (unsigned int i = 0; i < lista.size(); i++) {
		cout << lista[i].toString() << endl;
	}
}
