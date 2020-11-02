#include "Instruccion.h"

#define RET_OPCODE "ret"

typedef std::vector<std::string> VectorString;

const VectorString JUMP_OPCODE = {"jmp", "ja", "jeq",\
									"jneq", "jne", "jlt",\
									"jle", "jgt", "jge", "jset"};
const std::size_t LARGO_JMP = JUMP_OPCODE.size();

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

bool Instruccion::tieneEtiqueta(const std::string& etiqueta) {
	return (this->etiqueta == etiqueta);
}

std::string Instruccion::getLinea() const {
	return this->linea;
}

void Instruccion::saltoA(std::vector<Instruccion>& instrucciones,
								Grafo& grafo) {
	std::list<std::string>::iterator it_saltos = this->argumentos.begin();
	for(; it_saltos != this->argumentos.end(); ++it_saltos) {
		std::vector<Instruccion>::iterator it_instruc = instrucciones.begin();
		for(; it_instruc != instrucciones.end(); ++it_instruc) {
			if ((*it_instruc).tieneEtiqueta((*it_saltos))) {
				grafo.agregarArista(this->linea, (*it_instruc).getLinea());
			}
		}
	}
}

void Instruccion::conectar(const std::vector<Instruccion>& instrucciones,
					std::vector<Instruccion>& jmps, Grafo& grafo) {
	if (!instrucciones.empty()) {
		Instruccion ultima_instruccion = instrucciones.back();
		
		if ((!esJmp(ultima_instruccion.opcode) ||
			esJmp2Args(ultima_instruccion.argumentos)) &&
			!esRet(ultima_instruccion.opcode)) {
			grafo.agregarArista(ultima_instruccion.linea, this->linea);
		}
	}

	if (esJmp(this->opcode)) {
		jmps.push_back((*this));
	}
}

Instruccion::~Instruccion() {}
