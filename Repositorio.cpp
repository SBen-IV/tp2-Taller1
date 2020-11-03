#include "Repositorio.h"

Repositorio::Repositorio(std::mutex& _m) : m(_m) {}

void Repositorio::agregar(const std::string& nombre) {
	this->nombres.push(nombre);
}

bool Repositorio::estaVacio() const {
	return this->nombres.empty();
}

std::string Repositorio::obtener() {
	this->m.lock();
	std::string aux = this->nombres.front();
	this->nombres.pop();
	this->m.unlock();

	return aux;
}

Repositorio::~Repositorio() {}
