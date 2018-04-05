#include <string>

#ifndef SRC_TIPOS_H_
#define SRC_TIPOS_H_


//define el estado actual de la parcela
enum EstadoParcela {
	vacia,
	creciendo,
	listaParaCosechar,
	recuperando,
};


//almacena todas las caracteristicas de un tipo de cultivo.
struct Cultivo {
	std::string nombreCreciendo;
	std::string nombreLista;
	int costoSemilla;
	unsigned int turnosHastaCosecha;
	unsigned int rentabilidad;
	unsigned int tiempoDeRecuperacion;
};


//representa una parcela; con su estado, cultivo plantado (si lo esta),
//turnosRestantes hasta cosechar o recuperarse y si fue regada o no.
struct Parcela {
	EstadoParcela estado;
	Cultivo cultivo;
	int turnosRestantes;
	bool regadaEsteTurno;
};


#endif /* SRC_TIPOS_H_ */
