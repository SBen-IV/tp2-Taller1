#include "Repositorio.h"

Repositorio::Repositorio(char const *nombre_archivos[],
						int cant_nombre_archivos) {
	for (int i = 0; i < cant_nombre_archivos; ++i) {
		this->nombres.push(nombre_archivos[i]);
	}
}

bool Repositorio::estaVacio() const {
	return this->nombres.empty();
}

std::string Repositorio::obtener() {
	std::string aux = this->nombres.front();
	this->nombres.pop();

	return aux;
}

Repositorio::~Repositorio() {}
