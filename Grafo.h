#ifndef GRAFO_H
#define GRAFO_H

#include <unordered_map>
#include <string>
#include <list>

typedef std::list<std::string> Lista;
typedef std::unordered_map<std::string, Lista> Hash;

class Grafo {
private:
	Hash grafo;
public:
	Grafo();
	Grafo(const Grafo& grafo) = delete;
	void agregarNodo(std::string nodo);
	void agregarAristaDeA(std::string nodo_1, std::string nodo_2);
	~Grafo();
	
};

#endif
