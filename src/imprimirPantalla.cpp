#include <iostream>
#include "procesarAccionUsuario.h"

using namespace std;



void imprimirTerreno(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]) {


	for (int unsigned fil=0; fil < FIL_TERRENO; fil++){
		for (int unsigned col=0; col < COL_TERRENO; col++) {

			//Comienzo impresion coordenadas
			if(fil==0 && col== 0) {
				cout<< "  ";
				for(int unsigned i = 0; i < COL_TERRENO; i++){
					cout<< i+1;
				}
			cout<< endl;
			}

			if(col==0){
				cout<<fil+1<<" ";
			}
			//Fin impresion coordenadas


			if (matrizParcelas[fil][col].estado == vacia) {
				cout<<'#';
			}

			else if (matrizParcelas[fil][col].estado == creciendo){
				cout<< matrizParcelas[fil][col].cultivo.nombreCreciendo;
			}

			else if (matrizParcelas[fil][col].estado == listaParaCosechar){
				cout<< matrizParcelas[fil][col].cultivo.nombreLista;
			}

			else if (matrizParcelas[fil][col].estado == recuperando){
				cout<< 'R';
			}


		}
		cout<< endl;
	}

}




void mensajeInicioTurno(int creditos, int dado, int tanqueDeAgua, int turno) {
	cout<< "------------TURNO nº"<<turno<<"------------"<<endl;
	cout<< "Creditos actuales: "<< creditos<<endl;
	cout<< "Tu potenciador de agua es "<< dado<<
		 "! Tenes "<< tanqueDeAgua<< " de agua disponible."<< endl;

	if (turno < 3) {
		cout<< "***Para terminar tu turno, ingresa una coordenada negativa o elige como accion 'siguiente'.***"<<endl<<
				"***Para cancelar la siembra de una semilla, ingresa 'cancelar'.***"<<endl<<endl;
	}
}





void mensajeFinDeJuego(int creditosFinales) {
	cout<< "---------------------------------"<<endl;
	cout<< "| Fin del juego. Puntuacion: "<<creditosFinales<<" |"<<endl;
	cout<< "---------------------------------"<<endl;
}

