#include <iterator>
#include "eBPF.h"
#include "Grafo.h"
#include "AnalizadorInstruccion.h"
#include "Repositorio.h"
#include "Resultado.h"

#define VACIO ""

eBPF::eBPF(Repositorio& _nombres_archivos, Resultado& _resultados) :
			nombres_archivos(_nombres_archivos), resultados(_resultados) {}

static int analizar(const std::string& nombre_archivo) {
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

void eBPF::operator()() {
	while (!this->nombres_archivos.estaVacio()) {
		std::string nombre_archivo_actual = this->nombres_archivos.obtener();

		int resultado = analizar(nombre_archivo_actual);

		resultados.agregar(nombre_archivo_actual, resultado);
	}
}

eBPF::~eBPF() {}
