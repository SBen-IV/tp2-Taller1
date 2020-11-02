#include "Resultado.h"
#include <iostream>

#define OK 0
#define BUCLE 1
#define NODOS_SIN_VISITAR 2

Resultado::Resultado() {}

void Resultado::agregar(const std::string& nombre_archivo,
						const int resultado) {
	switch (resultado) {
		case OK:
			this->resultados[nombre_archivo] = " GOOD";
			break;
		case BUCLE:
			this->resultados[nombre_archivo] = " FAIL: cycle detected";
			break;
		case NODOS_SIN_VISITAR:
			this->resultados[nombre_archivo] = " FAIL: unused instructions";
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
