#include "ResultadoProtected.h"

#include <string>

ResultadoProtected::ResultadoProtected(Resultado& _resultados) : 
										resultados(_resultados) {}

void ResultadoProtected::agregar(const std::string& nombre_archivo,
									const int resultado) {
	std::lock_guard<std::mutex> lock(this->m);
	this->resultados.agregar(nombre_archivo, resultado);
}

ResultadoProtected::~ResultadoProtected() {}
