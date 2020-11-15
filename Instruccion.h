#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include <string>
#include <list>
#include <vector>

#include "Grafo.h"

class Instruccion {
private:
	const std::string opcode;
	const std::string etiqueta;
	std::list<std::string> argumentos;
public:
	Instruccion(const std::string& _etiqueta, const std::string& _opcode,
				const std::list<std::string>& _argumentos);
	void conectar(const std::vector<Instruccion>& instrucciones,
					std::vector<std::size_t>& jmps, Grafo& grafo);
	void saltoA(const std::vector<Instruccion>& instrucciones,
				const std::size_t pos_actual, Grafo& grafo);
	~Instruccion();
private:
	bool tieneEtiqueta(const std::string& etiqueta) const;
};

#endif
