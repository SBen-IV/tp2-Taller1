#include <iostream>
#include <string>
#include "Repositorio.h"
#include "eBPF.h"
#include "Resultado.h"

#define POS_INICIAL 2

static void desarrollar_ebpf(Repositorio& nombres_archivos,
							Resultado& resultados) {
	while (!nombres_archivos.estaVacio()) {
		std::string nombre_archivo_actual = nombres_archivos.obtener();

		eBPF filtro;

		int resultado = filtro.analizar(nombre_archivo_actual);

		resultados.agregar(nombre_archivo_actual, resultado);
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
	
	Resultado resultados;
	desarrollar_ebpf(nombres_archivos, resultados);

	resultados.imprimir();

	return 0;
}
