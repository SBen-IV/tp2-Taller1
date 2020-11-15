#include <iterator>
#include <fstream>
#include "eBPF.h"
#include "Grafo.h"
#include "AnalizadorInstruccion.h"
#include "Repositorio.h"
#include "Resultado.h"

#define VACIO ""

eBPF::eBPF(RepositorioProtected& _nombres_archivos,
			ResultadoProtected& _resultados) :
			nombres_archivos(_nombres_archivos), resultados(_resultados) {}

static int analizar(const std::string& nombre_archivo) {
	std::fstream archivo(nombre_archivo, std::fstream::in);
	std::string linea;
	std::vector<Instruccion> instrucciones;
	std::vector<std::size_t> jmps; 
	Grafo grafo;

	while (!archivo.eof()) {
		std::getline(archivo, linea);

		if (linea != VACIO) {
			grafo.agregarNodo(linea);

			AnalizadorInstruccion analizador;

			Instruccion instruccion = analizador.identificar(linea);

			instruccion.conectar(instrucciones, jmps, grafo);

			instrucciones.push_back(instruccion);
		}
	}

	for (std::size_t i = 0; i < jmps.size(); ++i) {
		std::size_t pos_jmp = jmps[i];
		instrucciones[pos_jmp].saltoA(instrucciones, pos_jmp, grafo);
	}

	return grafo.aplicarDFS();
}

void eBPF::operator()() {
	std::string nombre_archivo_actual;

	while (!this->nombres_archivos.estaVacio()) {
		nombre_archivo_actual = this->nombres_archivos.obtenerSiNoEstaVacio();

		if (nombre_archivo_actual == VACIO) break;

		int resultado = analizar(nombre_archivo_actual);

		this->resultados.agregar(nombre_archivo_actual, resultado);
	}
}

eBPF::~eBPF() {}
