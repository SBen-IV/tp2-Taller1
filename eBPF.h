#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>
#include "Archivo.h"

class eBPF {
private:
	const std::vector<std::string> jmp; //FALTA LLENAR
	const size_t largo_jmp;
public:
	eBPF();
	void analizar(Archivo archivo);
	~eBPF();
private:
	bool esJmp(const std::string opcode);
};

#endif