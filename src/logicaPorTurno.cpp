#include <limits> //necesario en obtenerCoordenada, para asi usar cin dentro de un loop
#include <iostream>

#include "procesarAccionUsuario.h"

using namespace std;


int obtenerCoordenada(string eje) {

	int inputUsuario = 0;
	int maximoTerreno = 5;

	if (eje == "columna") {
		maximoTerreno = COL_TERRENO;
	}
	else if (eje == "fila") {
		maximoTerreno = FIL_TERRENO;
	}


	cout<<endl<< "Ingrese su "<< eje << ": ";
	cin>> inputUsuario;

	while(inputUsuario > maximoTerreno || inputUsuario == 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<< "Rango de "<< eje<< " incorrecto, reintente: ";
		cin>> inputUsuario;
		};

	inputUsuario--;
	return inputUsuario;
}


bool menuUsuario(Parcela& parcelaElegida, int &creditos, Cultivo cultivos[], int cantidadSemillas, int tanqueDeAgua, int col, int fil) {

		bool cancelarTurno = false;
		cout << "Determine la accion a realizar en la parcela "<< fil+1 << "-" << col+1<<": ";
		string accionUsuario;
		cin >> accionUsuario;


		if (accionUsuario == "siguiente") {
			cancelarTurno = true;
		}

		else if (accionUsuario == "sembrar") {
			if (parcelaElegida.estado != vacia){
				cout<< "La parcela seleccionada no esta vacia!"<<endl;
			}
			else {
				procesarSiembra(parcelaElegida, creditos, cultivos, cantidadSemillas);
			}
		}

		else if (accionUsuario == "cosechar")
			procesarCosecha(parcelaElegida, creditos);

		else if (accionUsuario == "regar"){
			procesarRiego(parcelaElegida, tanqueDeAgua);
		}

		else {
			cout<< "Comando no reconocido. Disponibles: sembrar, cosechar, regar, siguiente";
		}

		return cancelarTurno;

}




void pudrirYsecarParcelas(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]) {
	for (int unsigned fil = 0; fil < FIL_TERRENO; fil++){
		for (int unsigned col = 0; col < COL_TERRENO; col++) {

			if (matrizParcelas[fil][col].estado == listaParaCosechar) {
				matrizParcelas[fil][col].estado = recuperando;
				matrizParcelas[fil][col].turnosRestantes = (matrizParcelas[fil][col].cultivo.tiempoDeRecuperacion / 2) + 1;
				cout<< "Parcela "<< fil+1<<"-"<<col+1 << " se pudrio!"<<endl;
			}

			else if (matrizParcelas[fil][col].estado == creciendo && matrizParcelas[fil][col].regadaEsteTurno == false) {
				matrizParcelas[fil][col].estado = vacia;
				cout<< "Parcela "<< fil+1<<"-"<<col+1 << " se seco!"<<endl;
			}
		}
	}
}



void actualizarEstadoParcelas(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]) {

	//no hay que chequear si se debe pudrir o secar

	for (int unsigned fil = 0; fil < FIL_TERRENO; fil++){
		for (int unsigned col = 0; col < COL_TERRENO; col++) {


			if (matrizParcelas[fil][col].estado == creciendo) {
				if (matrizParcelas[fil][col].turnosRestantes > 1) {
					matrizParcelas[fil][col].turnosRestantes--;
				}

				else if (matrizParcelas[fil][col].turnosRestantes == 1) {
					matrizParcelas[fil][col].turnosRestantes = 0;
					matrizParcelas[fil][col].estado = listaParaCosechar;
					cout<< "Parcela "<< fil+1<<"-"<<col+1 << " esta lista para cosechar"<<endl;
				}
			}

			else if (matrizParcelas[fil][col].estado == recuperando) {

				if (matrizParcelas[fil][col].turnosRestantes > 1) {
					matrizParcelas[fil][col].turnosRestantes--;
				}

				else if (matrizParcelas[fil][col].turnosRestantes == 1) {
					matrizParcelas[fil][col].turnosRestantes = 0;
					matrizParcelas[fil][col].estado = vacia;
				}

			}

			matrizParcelas[fil][col].regadaEsteTurno = false;
		}
	}
}

