#include <string>
#include "tipos.h"
#include "constantes.h"


#ifndef SRC_LOGICAPORTURNO_H_
#define SRC_LOGICAPORTURNO_H_




//dado un eje ("columna" o "fila"), obtiene del usuario un numero en el rango de [0, XXX_TERRENO) y lo devuelve.
//XXX sera FIL o COL segun eje.
int obtenerCoordenada(std::string eje);


/*recibe una &parcela, &creditos disponibles, un array de los tipos de cultivos disponibles,
 *la longitud del mismo, la cantidad almacenada de agua, columna y fila de la parcela elegida.
 *obtiene, procesa y comunica al usuario el resultado de su accion en dicha parcela*/
bool menuUsuario(Parcela& parcelaElegida, int &creditos, Cultivo cultivos[], int cantidadSemillas, int tanqueDeAgua, int col, int fil);


//dada una matriz de Parcelas, chequea condiciones entre turnos y pudre/seca las correspondientes.
void pudrirYsecarParcelas(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]);


//dada una matriz de Parcelas, evoluciona los turnos restantes de cada cultivo,
//define si esta listo, y reestablece su condicion de riego a falsa.
void actualizarEstadoParcelas(Parcela matrizParcelas[FIL_TERRENO][COL_TERRENO]);







#endif /* SRC_LOGICAPORTURNO_H_ */
