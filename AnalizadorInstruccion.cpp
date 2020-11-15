#include "AnalizadorInstruccion.h"
#include "Instruccion.h"

#include <list>
#include <sstream>

#define RET_OPCODE "ret"
#define VACIO ""
#define MAX_ARGS 3

static void obtenerEtiqueta(std::istringstream& linea,
							const std::string& _linea,
							std::string& etiqueta) {
	if (_linea.find(':') != std::string::npos) {
		std::getline(linea, etiqueta, ':');
	}
}

static void obtenerArgumentos(std::istringstream& linea, 
								std::list<std::string>& argumentos) {
	std::string aux;
	for (std::size_t i = 0; i < MAX_ARGS && !linea.eof(); ++i) {
		linea >> aux;
		if (aux != VACIO) {
			if (aux.back() == ',') {
				aux.pop_back();
			}

			argumentos.push_back(aux);
		}
	}
}

Instruccion AnalizadorInstruccion::identificar(const std::string& _linea) {
	std::istringstream linea(_linea);
	std::string etiqueta, opcode;
	std::list<std::string> argumentos;

	obtenerEtiqueta(linea, _linea, etiqueta);
	linea >> opcode;
	obtenerArgumentos(linea, argumentos);

	Instruccion instruccion(etiqueta, opcode, argumentos);

	return instruccion;
}

AnalizadorInstruccion::AnalizadorInstruccion() {}

AnalizadorInstruccion::~AnalizadorInstruccion() {}
