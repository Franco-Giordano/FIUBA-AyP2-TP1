#include "tipos.h"
#include "constantes.h"



void vaciarTerreno(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]) {

	for (int unsigned fil = 0; fil < FIL_TERRENO; fil++){
		for (int unsigned col = 0; col < COL_TERRENO; col++) {
			matrizParcelas[fil][col].estado = vacia;
		}
	}
}


void crearCultivo(Cultivo& semilla, char tipo) {

	if (tipo == NOMBRELISTA_A) {
		semilla.nombreLista = NOMBRELISTA_A;
		semilla.nombreCreciendo = NOMBRECRECIENDO_A;
		semilla.costoSemilla = COSTOSEMILLA_A;
		semilla.turnosHastaCosecha = TURNOSHASTACOSECHA_A;
		semilla.rentabilidad = RENTABILIDAD_A;
		semilla.tiempoDeRecuperacion = TIEMPORECUPERACION_A;
	}

	else if (tipo == NOMBRELISTA_B) {
		semilla.nombreLista = NOMBRELISTA_B;
		semilla.nombreCreciendo = NOMBRECRECIENDO_B;
		semilla.costoSemilla = COSTOSEMILLA_B;
		semilla.turnosHastaCosecha = TURNOSHASTACOSECHA_B;
		semilla.rentabilidad = RENTABILIDAD_B;
		semilla.tiempoDeRecuperacion = TIEMPORECUPERACION_B;
	}

	else if (tipo == NOMBRELISTA_C) {
		semilla.nombreLista = NOMBRELISTA_C;
		semilla.nombreCreciendo = NOMBRECRECIENDO_C;
		semilla.costoSemilla = COSTOSEMILLA_C;
		semilla.turnosHastaCosecha = TURNOSHASTACOSECHA_C;
		semilla.rentabilidad = RENTABILIDAD_C;
		semilla.tiempoDeRecuperacion = TIEMPORECUPERACION_C;
	}

}
