#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>
#include "Archivo.h"

class eBPF {
public:
	eBPF();
	int analizar(const std::string& nombre_archivo);
	~eBPF();
};

#endif
