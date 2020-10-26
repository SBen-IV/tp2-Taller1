#include <iostream>
#include <string>
#include "Repositorio.h"
#include "Archivo.h"
#include "eBPF.h"

#define POS_INICIAL 2

static void desarrollar_ebpf(Repositorio nombres_archivos) {

	while (nombres_archivos.estaVacio()) {
		Archivo archivo(nombres_archivos.obtener(), std::fstream::in);

		eBPF handler;

		handler.analizar(std::move(archivo));
	}
}


int main(int argc, char const *argv[]) {

	if (argc < 3) {
		std::cout << "./tp <num hilos> <archivo> [<archivo>...]" << std::endl;
		return 0;
	}

	Repositorio nombres_archivos;

	for (int i = POS_INICIAL; i < argc; i++) {
		nombres_archivos.agregar(argv[i]);
	}
	
	desarrollar_ebpf(std::move(nombres_archivos));

	return 0;
}