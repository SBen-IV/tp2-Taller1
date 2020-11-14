#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <list>
#include <vector>

#include "Nodo.h"

typedef std::vector<Nodo> Nodos;

class Grafo {
private:
	Nodos grafo;
public:
	Grafo();
	Grafo& operator=(const Grafo& otro) = delete;
	Grafo(const Grafo& otro) = delete;
	void agregarNodo(const std::string& _nodo);
	void agregarArista(const std::size_t nodo_1, const std::size_t nodo_2);
	int aplicarDFS();
	~Grafo();
};

#endif
