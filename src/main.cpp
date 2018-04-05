#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "imprimirPantalla.h"
#include "inicializacionJuego.h"
#include "logicaPorTurno.h"


using namespace std;



int main() {


	Cultivo A;
	crearCultivo(A,'A');

	Cultivo B;
	crearCultivo(B,'B');

	Cultivo C;
	crearCultivo(C,'C');

	Cultivo cultivosDisponibles[] = {A, B, C};
	int cantidadSemillas = 3; //equivalente a longitud de cultivosDisponibles[]



	cout<< "Bienvenido a Granjeros 1.0"<<endl<<endl;


	Parcela Terreno[FIL_TERRENO][COL_TERRENO];
	vaciarTerreno(Terreno);

	int tanqueDeAgua = 0;

	int creditos = CREDITOS_INICIO;

	int valorDado;
	srand(time(NULL)); //inicializar semilla para generar numero aleatorio mas adelante

	for (int unsigned turno = 1; turno <= TURNOS_TOTALES; turno++) {

		valorDado = rand()%6 +1;

		tanqueDeAgua += valorDado * MULTIPLICADOR_AGUA;


		mensajeInicioTurno(creditos, valorDado, tanqueDeAgua, turno);

		actualizarEstadoParcelas(Terreno);

		imprimirTerreno(Terreno);

		int filaElegida  = obtenerCoordenada("fila");
		int columnaElegida = obtenerCoordenada("columna");
		bool cancelarTurno = false;

		while ((columnaElegida >= 0 && filaElegida >= 0) && (!cancelarTurno)) {

			cancelarTurno = menuUsuario(Terreno[filaElegida][columnaElegida], creditos, cultivosDisponibles, cantidadSemillas, tanqueDeAgua, columnaElegida, filaElegida);

			if (!cancelarTurno) {
				filaElegida  = obtenerCoordenada("fila");
				columnaElegida = obtenerCoordenada("columna");
			}


		}


		if (tanqueDeAgua > CAPACIDAD_TANQUE) {
			tanqueDeAgua = CAPACIDAD_TANQUE;
		}

		cout<<"Terminando turno..."<<endl<<endl<<endl;
		pudrirYsecarParcelas(Terreno);
	}


	mensajeFinDeJuego(creditos);
	return 0;
}






















