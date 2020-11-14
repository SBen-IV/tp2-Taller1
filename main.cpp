#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Repositorio.h"
#include "eBPF.h"
#include "Resultado.h"

#define POS_INICIAL 2

int main(int argc, char const *argv[]) {
	if (argc < 3) {
		std::cout << "./tp <num hilos> <archivo> [<archivo>...]" << std::endl;
		return 0;
	}

	int cant_hilos = std::stoi(argv[1]);

	Repositorio nombres_archivos(&argv[2], argc-2);

	std::vector<std::thread> threads;
	Resultado resultados;

	for (int i = 0; i < cant_hilos; ++i) {
		threads.push_back(std::thread {eBPF(nombres_archivos, resultados)});
	}

	for (int i = 0; i < cant_hilos; ++i) {
		threads[i].join();
	}

	resultados.imprimir();

	return 0;
}
