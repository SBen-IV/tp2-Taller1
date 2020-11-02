#include "Resultado.h"
#include <iostream>

#define OK 0
#define BUCLE 1
#define NODOS_SIN_VISITAR 2

const std::string MENSAJE_GOOD = " GOOD";
const std::string MENSAJE_CYCLE = " FAIL: cycle detected";
const std::string MENSAJE_UNUSED = " FAIL: unused instructions detected";

Resultado::Resultado() {}

void Resultado::agregar(const std::string& nombre_archivo,
						const int resultado) {
	switch (resultado) {
		case OK:
			this->resultados[nombre_archivo] = MENSAJE_GOOD;
			break;
		case BUCLE:
			this->resultados[nombre_archivo] = MENSAJE_CYCLE;
			break;
		case NODOS_SIN_VISITAR:
			this->resultados[nombre_archivo] = MENSAJE_UNUSED;
		break;
	}
}

void Resultado::imprimir() {
	HashOrdenado::iterator it_resultados = this->resultados.begin();

	for(; it_resultados != this->resultados.end(); ++it_resultados) {
		std::cout << it_resultados->first << it_resultados->second
		<< std::endl;
	}
}

Resultado::~Resultado() {}
