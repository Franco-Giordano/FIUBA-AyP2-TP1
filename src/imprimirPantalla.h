#include "tipos.h"
#include "constantes.h"

#ifndef SRC_INTERACCIONUSUARIO_H_
#define SRC_INTERACCIONUSUARIO_H_





//recibe una matriz de parcelas, imprime el estado del terreno con sus coordenadas.
//'#' parcela vacia. 'R' parcela recuperandose. 'x' parcela aun creciendo, cultivo de tipo X.
//'X' parcela ya lista para cosechar, cultivo de tipo X.
void imprimirTerreno(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]);


//imprime al usuario estas varibales junto a un mensaje de ayuda en los primeros turnos
void mensajeInicioTurno(int creditos, int dado, int tanqueDeAgua, int turno);


//al finalizar el juego, imprime un mensaje final con la cantidad de creditos
void mensajeFinDeJuego(int creditosFinales);




#endif /* SRC_INTERACCIONUSUARIO_H_ */
