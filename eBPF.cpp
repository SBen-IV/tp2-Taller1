#include "eBPF.h"
#include "Grafo.h"
#include "AnalizadorInstruccion.h"
#include <iterator>

#define VACIO ""

eBPF::eBPF() {}

int eBPF::analizar(const std::string& nombre_archivo) {
	Archivo archivo(nombre_archivo, std::fstream::in);
	std::string linea;
	std::vector<Instruccion> instrucciones, jmps;
	Grafo grafo;

	while (!archivo.esEOF()) {
		archivo.leer(linea);

		if (linea != VACIO) {
			grafo.agregarNodo(linea);

			AnalizadorInstruccion analizador;

			Instruccion instruccion = analizador.identificar(linea);

			instruccion.conectar(instrucciones, jmps, grafo);

			instrucciones.push_back(instruccion);
		}
	}

	std::vector<Instruccion>::iterator it_jmps = jmps.begin();

	for(; it_jmps != jmps.end(); ++it_jmps) {		
		(*it_jmps).saltoA(instrucciones, grafo);
	}

	return grafo.aplicarDFS();
}

eBPF::~eBPF() {}
