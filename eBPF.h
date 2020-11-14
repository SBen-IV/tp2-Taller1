#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>
#include "Grafo.h"
#include "AnalizadorInstruccion.h"
#include "Repositorio.h"
#include "Resultado.h"

class eBPF {
private:
	Repositorio& nombres_archivos;
	Resultado& resultados;
public:
	eBPF(Repositorio& _nombres_archivos, Resultado& _resultados);
	void operator()();
	~eBPF();
};

#endif
