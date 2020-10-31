#include "Grafo.h"

#define NO_EXISTE 0
#define VACIO ""

#define OK 0
#define BUCLE 1
#define NODOS_SIN_VISITAR 2

Grafo::Grafo() {}

void Grafo::agregarNodo(const std::string& nodo) {
	if (this->grafo.count(nodo) == NO_EXISTE) {
		Lista lista_de_aristas = {};
		this->grafo[nodo] = std::move(lista_de_aristas);
		if (this->primer_nodo == VACIO) this->primer_nodo = nodo;
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


static bool esNodoAnterior(const std::string& nodo,
						const std::vector<std::string>& anteriores) {
	bool resultado = false;

	for (size_t i = 0; i < anteriores.size() && !resultado; ++i) {
		if (nodo == anteriores[i]) resultado = true;
	}

	return resultado;
}

static int dfs(Hash& grafo, const std::string& nodo,
				std::unordered_map<std::string, bool>& visitados,
				std::vector<std::string>& anteriores) {
	if (esNodoAnterior(nodo, anteriores)) return BUCLE;

	visitados[nodo] = true;
	anteriores.push_back(nodo);

	Lista aristas = grafo[nodo];

	Lista::iterator it_aristas = aristas.begin();

	for(; it_aristas != aristas.end(); ++it_aristas) {
		if (visitados.count((*it_aristas)) == NO_EXISTE) {
			return dfs(grafo, (*it_aristas), visitados, anteriores);
		}
	}

	anteriores.pop_back();

	return OK;
}

int Grafo::aplicarDFS() {
	std::vector<std::string> anteriores;
	std::unordered_map<std::string, bool> visitados;

	int resultado = dfs(this->grafo, this->primer_nodo, visitados, anteriores);

	if (this->grafo.size() != visitados.size()) resultado = NODOS_SIN_VISITAR;

	return resultado;
}

Grafo::~Grafo() {}
