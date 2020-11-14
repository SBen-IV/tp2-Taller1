#include "AnalizadorInstruccion.h"
#include "Instruccion.h"
#include <list>

#define RET_OPCODE "ret"
#define VACIO ""

std::size_t obtenerEtiqueta(const std::string& linea, std::string& etiqueta) {
	std::size_t pos_fin = linea.find(':');

	if (pos_fin == std::string::npos) {
		etiqueta = VACIO;
		pos_fin = linea.find_first_not_of(' ');
	} else {
		etiqueta = linea.substr(0, pos_fin);
		pos_fin = linea.find_first_not_of(' ', pos_fin + 1);
	}

	return pos_fin;
}

std::size_t obtenerOpcode(const std::string& linea, std::string& opcode) {
	std::size_t pos_fin = linea.find(' ');

	if (pos_fin == std::string::npos) {
		opcode = linea;
		pos_fin = linea.length() - 1;
	} else {
		opcode = linea.substr(0, pos_fin);
		pos_fin = linea.find_first_not_of(' ', pos_fin);
	}

	return pos_fin;
}

void obtenerSaltos(const std::string& linea,
					std::list<std::string>& argumentos) {
	std::size_t pos_inicio = 0, pos_fin = linea.find(',');

	do {
		argumentos.push_back(linea.substr(pos_inicio, pos_fin-pos_inicio));
		pos_inicio = linea.find_first_not_of(", ", pos_fin);
		pos_fin = linea.find(',', pos_inicio);
	} while (pos_inicio != std::string::npos);
}

Instruccion AnalizadorInstruccion::identificar(const std::string& linea) {
	std::string etiqueta, opcode;
	std::list<std::string> argumentos;
	std::size_t pos_inicio = 0;

	pos_inicio += obtenerEtiqueta(linea, etiqueta);
	pos_inicio += obtenerOpcode(&linea[pos_inicio], opcode);
	obtenerSaltos(&linea[pos_inicio], argumentos);

	Instruccion instruccion(linea, etiqueta, opcode, argumentos);

	return instruccion;
}

AnalizadorInstruccion::AnalizadorInstruccion() {}

AnalizadorInstruccion::~AnalizadorInstruccion() {}
