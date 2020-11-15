#ifndef NODO_H
#define NODO_H

#include <string>
#include <list>

typedef std::list<std::size_t> Lista;

class Nodo {
private:
	std::string clave;
	std::list<std::size_t> valor;
public:
	Nodo(const std::string& _clave, const std::list<std::size_t>& _valor);
	Nodo& operator=(const Nodo& otro) = delete;
	Nodo(const Nodo& otro) = delete;
	Nodo& operator=(Nodo&& otro);
	Nodo(Nodo&& otro);
	void agregarValor(const std::size_t valor);
	Lista obtenerValor() const;
	~Nodo();
};

#endif
