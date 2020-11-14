#include "Grafo.h"

#include <utility>
#include <unordered_map>

#define NO_EXISTE 0
#define VACIO ""

#define OK 0
#define BUCLE 1
#define NODOS_SIN_VISITAR 2

Grafo::Grafo() {}

void Grafo::agregarNodo(const std::string& _nodo) {
	Lista lista_de_aristas = {};
	Nodo nodo(_nodo, lista_de_aristas);
	this->grafo.push_back(std::move(nodo));
}

void Grafo::agregarArista(const std::size_t nodo_1,
							const std::size_t nodo_2) {
	if (this->grafo.size() < nodo_1 || this->grafo.size() < nodo_2) return;

	this->grafo[nodo_1].agregarValor(nodo_2);
}

static bool esNodoAnterior(const std::size_t& nodo,
						const std::vector<std::size_t>& anteriores) {
	bool resultado = false;

	for (size_t i = 0; i < anteriores.size() && !resultado; ++i) {
		if (nodo == anteriores[i]) resultado = true;
	}

	return resultado;
}

static void dfs(Nodos& grafo, const std::size_t nodo,
				std::unordered_map<std::size_t, bool>& visitados,
				std::vector<std::size_t>& anteriores,
				bool* tiene_ciclo) {
	if (esNodoAnterior(nodo, anteriores)) {
		*tiene_ciclo = true;
		return;
	}

	visitados[nodo] = true;
	anteriores.push_back(nodo);

	Lista aristas = grafo[nodo].obtenerValor();

	Lista::iterator it_aristas = aristas.begin();

	for(; it_aristas != aristas.end(); ++it_aristas) {
		dfs(grafo, (*it_aristas), visitados, anteriores, tiene_ciclo);
	}

	anteriores.pop_back(); 
}

int Grafo::aplicarDFS() {
	std::vector<std::size_t> anteriores;
	std::unordered_map<std::size_t, bool> visitados;
	bool tiene_ciclo = false;
	
	dfs(this->grafo, 0, visitados, anteriores, &tiene_ciclo);

	int resultado = OK;

	if (this->grafo.size() != visitados.size()) resultado = NODOS_SIN_VISITAR;
	if (tiene_ciclo) resultado = BUCLE;

	return resultado;
}

Grafo::~Grafo() {}
