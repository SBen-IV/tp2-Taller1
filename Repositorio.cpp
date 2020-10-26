#include "Repositorio.h"

Repositorio::Repositorio() {}

void Repositorio::agregar(const std::string nombre) {

	this->nombres.push(nombre);
}

Repositorio::Repositorio(Repositorio&& otro) {
	this->nombres = otro.nombres;
}

bool Repositorio::estaVacio() const {
	return this->nombres.empty();
}

std::string Repositorio::obtener() {
	std::string aux = this->nombres.back();
	this->nombres.pop();

	return aux;
}

Repositorio::~Repositorio() {}