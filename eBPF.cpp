#include "eBPF.h"
#include "Grafo.h"
#include "AnalizadorInstruccion.h"

#define VACIO ""

eBPF::eBPF() {}

int eBPF::analizar(const std::string& nombre_archivo) {
	Archivo archivo(nombre_archivo_actual, std::fstream::in);
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

	return 0; //grafo.aplicarDFS();
}

eBPF::~eBPF() {}
