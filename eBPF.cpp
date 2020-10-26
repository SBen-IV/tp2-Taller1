#include "eBPF.h"
#include "Grafo.h"

#define VACIO ""

#define JMP 1
#define RET 2

typedef std::vector<std::string> VectorString;

static void separar(const std::string linea,
					VectorString& instruccion_separada) {
	std::size_t pos_inicio = 0, pos_fin = linea.find(':');

	if (pos_fin != std::string::npos) {
		instruccion_separada.push_back(linea.substr(pos_inicio, pos_fin-1));
	} else {
		instruccion_separada.push_back(VACIO);
		pos_fin = 0;
	}

	std::size_t largo_linea = linea.length();

	while (pos_fin < largo_linea) {
		pos_inicio = linea.find_first_not_of(' ', pos_fin);
		pos_fin = linea.find(' ', pos_inicio);
		if (pos_fin == std::string::npos) {
			instruccion_separada.push_back(linea.substr(pos_inicio));
			pos_fin = largo_linea;
		} else { 
			instruccion_separada.push_back(linea.substr(pos_inicio, pos_fin));
		}
	}
}

static bool esJmp(const std::string opcode) {
	bool es_jmp = false;
	std::size_t i = 0;

	while (i < this->largo_jmp && !es_jmp) {
		if (this->jmp[i] == opcode) es_jmp = true;
	}

	return es_jmp;
}

static bool esRet(const std::string opcode) {
	return (opcode == "ret");
}

static int identificar(const std::string linea) {

	VectorString instruccion_separada;

	separar(linea, instruccion_separada);

	int tipo_instruccion = 0;

	if (instruccion_separada[0] != VACIO) {
		//TODO: Guardar etiqueta?
	}

	if (eBPF::esJmp(instruccion_separada[1])) {
		tipo_instruccion = JMP;
	} else if (esRet(instruccion_separada[1])) {
		tipo_instruccion = RET;
	}

	return tipo_instruccion;
}

eBPF::eBPF() : jmp({"jmp", "je", "jne"}), largo_jmp(3){
}

void eBPF::analizar(Archivo archivo) {

	std::string linea;
	Grafo grafo;

	while(!archivo.esEOF()) {
		archivo.leer(linea);
		grafo.agregarNodo(linea);

		int identificador = identificar(linea);

		if (identificar != RET) {
			//TODO: Enlazar con la linea anterior
			//grafo.agregarAristaDeA(nodo_anterior, linea)
		}


	}

	//DFS
}