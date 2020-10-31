#include <iostream>
#include <string>
#include "Repositorio.h"
#include "eBPF.h"

#define POS_INICIAL 2

static void desarrollar_ebpf(Repositorio& nombres_archivos) {

	while (!nombres_archivos.estaVacio()) {
		std::string nombre_archivo_actual = nombres_archivos.obtener();

		eBPF filtro;

		int resultado = filtro.analizar(nombre_archivo_actual);

		std::cout << resultado << " " + nombre_archivo_actual << std::endl;
	// TODO:
	//	objeto_compartido_2.agregar(nombre_archivo_actual, tipo);
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
	
	desarrollar_ebpf(nombres_archivos);

	return 0;
}
