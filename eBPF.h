#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>

#include "Grafo.h"
#include "AnalizadorInstruccion.h"
#include "RepositorioProtected.h"
#include "ResultadoProtected.h"

class eBPF {
private:
	RepositorioProtected& nombres_archivos;
	ResultadoProtected& resultados;
public:
	eBPF(RepositorioProtected& _nombres_archivos,
		ResultadoProtected& _resultados);
	void operator()();
	~eBPF();
};

#endif
