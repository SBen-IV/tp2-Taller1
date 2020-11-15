#include "Instruccion.h"

#define RET_OPCODE "ret"

typedef std::vector<std::string> VectorString;

static const VectorString JUMP_OPCODE = {"jmp", "ja", "jeq",\
										"jneq", "jne", "jlt",\
										"jle", "jgt", "jge", "jset"};
static const std::size_t LARGO_JMP = JUMP_OPCODE.size();

static bool esJmp(const std::string& opcode) {
	bool es_jmp = false;
	std::size_t i = 0;

	while (i < LARGO_JMP && !es_jmp) {
		if (JUMP_OPCODE[i] == opcode) es_jmp = true;
		i++;
	}

	return es_jmp;
}

static bool esRet(const std::string& opcode) {
	return (opcode == RET_OPCODE);
}

static bool esJmp2Args(const std::list<std::string>& argumentos) {
	return (argumentos.size() == 2);
}

Instruccion::Instruccion(const std::string& _linea,
						const std::string& _etiqueta,
						const std::string& _opcode, 
						const std::list<std::string>& _argumentos) :
						linea(_linea), opcode(_opcode), etiqueta(_etiqueta),
						argumentos(_argumentos) {}

bool Instruccion::tieneEtiqueta(const std::string& etiqueta) const {
	return (this->etiqueta == etiqueta);
}

void Instruccion::saltoA(const std::vector<Instruccion>& instrucciones,
						const std::size_t pos_actual, Grafo& grafo) {
	std::list<std::string>::iterator it_saltos = this->argumentos.begin();

	for (; it_saltos != this->argumentos.end(); ++it_saltos) {
		for (size_t i = 0; i < instrucciones.size(); ++i) {
			if (instrucciones[i].tieneEtiqueta((*it_saltos))) {
				grafo.agregarArista(pos_actual, i);
			}
		}
	}
}

void Instruccion::conectar(const std::vector<Instruccion>& instrucciones,
					std::vector<std::size_t>& jmps, Grafo& grafo) {
	std::size_t pos_actual = instrucciones.size();
	if (!instrucciones.empty()) {
		Instruccion ultima_instruccion = instrucciones.back();
		
		if ((!esJmp(ultima_instruccion.opcode) ||
			esJmp2Args(ultima_instruccion.argumentos)) &&
			!esRet(ultima_instruccion.opcode)) {
			grafo.agregarArista(pos_actual - 1, pos_actual);
		}
	}

	if (esJmp(this->opcode)) {
		jmps.push_back(pos_actual);
	}
}

Instruccion::~Instruccion() {}
