#ifndef ANALIZADORINSTRUCCION_H
#define ANALIZADORINSTRUCCION_H

#include <string>
#include <vector>
#include "Instruccion.h"

class AnalizadorInstruccion {
public:
	AnalizadorInstruccion();
	Instruccion identificar(const std::string& linea);
	~AnalizadorInstruccion();
};

#endif
