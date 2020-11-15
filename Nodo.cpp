#include "Nodo.h"

#include <utility>

#define VACIO ""

Nodo::Nodo(const std::string& _clave, const std::list<std::size_t>& _valor) :
			clave(_clave), valor(_valor) {}


Nodo& Nodo::operator=(Nodo&& otro) {
	if (this == &otro) return *this;

	this->clave = std::move(otro.clave);
	this->valor = std::move(otro.valor);

	otro.clave = VACIO;
	otro.valor.clear();

	return *this;
}

Nodo::Nodo(Nodo&& otro) {
	if (this == &otro) return;

	this->clave = std::move(otro.clave);
	this->valor = std::move(otro.valor);

	otro.clave = VACIO;
	otro.valor.clear();
}

void Nodo::agregarValor(const std::size_t _valor) {
	this->valor.push_back(_valor);
}

Lista Nodo::obtenerValor() const {
	return this->valor;
}

Nodo::~Nodo() {}
