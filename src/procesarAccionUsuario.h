#include "tipos.h"
#include "constantes.h"



#ifndef SRC_LOGICA_H_
#define SRC_LOGICA_H_






//dada una Parcela& y demas variables, procesa la eleccion y siembra del usuario en dicho espacio, ajustando
//las propiedades de Parcela.
void procesarSiembra(Parcela& parcelaElegida, int &creditos, Cultivo cultivos[], int cantidadSemillas);


//dada una Parcela& y demas variables, procesa la cosecha en dicho espacio.
void procesarCosecha(Parcela& parcelaElegida, int &creditos);


////dada una Parcela& y demas variables, procesa el riego en dicho espacio.
void procesarRiego(Parcela& parcelaElegida, int& tanqueDeAgua);








#endif /* SRC_LOGICA_H_ */
