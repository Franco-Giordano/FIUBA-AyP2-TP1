#include "tipos.h"
#include "constantes.h"


#ifndef SRC_INICIALIZACIONJUEGO_H_
#define SRC_INICIALIZACIONJUEGO_H_



//dada una matriz de structs Parcela, establece el estado de cada una como 'vacia'
void vaciarTerreno(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]);


//dada una variable tipo &Cultivo y un char, configura la variable con las constantes
//correspondientes al cultivo NOMBRELISTA_X. Constantes previamente definidas en 'constantes.h'
void crearCultivo(Cultivo& semilla, char tipo);


#endif /* SRC_INICIALIZACIONJUEGO_H_ */
