#include "Grafo.h"

#define NO_EXISTE 0

Grafo::Grafo() {}

void Grafo::agregarNodo(const std::string& nodo) {
	if (this->grafo.count(nodo) == NO_EXISTE) {
		Lista lista_de_aristas = {};
		this->grafo[nodo] = std::move(lista_de_aristas);
	}
}

void Grafo::agregarArista(const std::string& nodo_1,
							const std::string& nodo_2) {
	if (this->grafo.count(nodo_1) == NO_EXISTE ||
		this->grafo.count(nodo_2) == NO_EXISTE) return;

	Lista lista_de_aristas = this->grafo[nodo_1];
	lista_de_aristas.push_back(nodo_2);
	this->grafo[nodo_1] = lista_de_aristas;
}

Grafo::~Grafo() {}
