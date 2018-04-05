#include "procesarAccionUsuario.h"

#include <iostream>





using namespace std;




void procesarSiembra(Parcela& parcelaElegida, int &creditos, Cultivo cultivos[], int cantidadSemillas) {

	string inputCultivo;
	bool semillaCorrecta = false;
	bool cancelarSiembra = false;
	Cultivo cultivoElegido;

	do {
		cout<< "Escoja un cultivo valido para sembrar: ";
		cin >> inputCultivo;

		if (inputCultivo == "cancelar") {
			cancelarSiembra = true;
		}

		else {
			for (int i = 0; i < cantidadSemillas; i++) {

				bool nombreDeCultivoValido = (cultivos[i].nombreLista == inputCultivo || cultivos[i].nombreCreciendo == inputCultivo);

				if (nombreDeCultivoValido && (creditos >= cultivos[i].costoSemilla) ) {
					semillaCorrecta = true;
					cultivoElegido = cultivos[i];
				}
			}
		}
	}
	while (!semillaCorrecta && !cancelarSiembra);

	if (!cancelarSiembra) {
		parcelaElegida.estado = creciendo;
		parcelaElegida.cultivo = cultivoElegido;
		parcelaElegida.turnosRestantes = cultivoElegido.turnosHastaCosecha + 1;
		parcelaElegida.regadaEsteTurno = true;

		creditos -= cultivoElegido.costoSemilla;
		cout<< "Parcela correctamente sembrada. Creditos disponibles: "<< creditos<<endl;
	}
}

void procesarCosecha(Parcela& parcelaElegida, int &creditos) {


	if (parcelaElegida.estado != listaParaCosechar) {
		cout<< "La parcela seleccionada no esta lista!" << endl;
	}

	else {
		parcelaElegida.estado = recuperando;
		parcelaElegida.turnosRestantes = parcelaElegida.cultivo.tiempoDeRecuperacion + 1;
		creditos += parcelaElegida.cultivo.rentabilidad;
		cout<<"Parcela cosechada. Creditos: "<<creditos<<endl;
	}

}

void procesarRiego(Parcela& parcelaElegida, int& tanqueDeAgua) {

	if (parcelaElegida.regadaEsteTurno == true || parcelaElegida.estado != creciendo || tanqueDeAgua == 0) {
		cout<< "La parcela seleccionada no necesita ser regada o no se dispone de agua suficiente."<<endl;
	}

	else if (parcelaElegida.regadaEsteTurno == false && tanqueDeAgua > 0) {
		parcelaElegida.regadaEsteTurno = true;
		tanqueDeAgua -= 1;
		cout<<"Riego exitoso. Agua disponible: "<<tanqueDeAgua<<endl;
	}

}






