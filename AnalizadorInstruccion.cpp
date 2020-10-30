#include "AnalizadorInstruccion.h"

#define RET_OPCODE "ret"
#define VACIO ""

#define OTRO 0
#define JMP 1
#define RET 2

typedef std::vector<std::string> VectorString;

const VectorString JUMP_OPCODE = {"jmp", "ja", "jeq",\
									"jneq", "jne", "jlt",\
									"jle", "jgt", "jge", "jset"};
const std::size_t LARGO_JMP = JUMP_OPCODE.size();

static void separar(const std::string& linea,
					VectorString& instruccion_separada) {
	std::size_t pos_inicio = linea.find_first_not_of(' '),
				pos_fin = linea.find(' ', pos_inicio);

	instrucciones.push_back(linea.substr(pos_inicio, pos_fin-pos_inicio));

	while (pos_fin != std::string::npos) {
		pos_inicio = linea.find_first_not_of(' ', pos_fin);
		pos_fin = linea.find(' ', pos_inicio);
		instrucciones.push_back(linea.substr(pos_inicio, pos_fin-pos_inicio));
	}
}

static void limpiar(VectorString& instruccion_separada) {

	for(; iterador != instrucciones.end(); ++iterador) {
		if ((*iterador)[(*iterador).length()-1] == ':') {
			aux.push_back((*iterador).substr(0, (*iterador).length()-1));

		} else if (((*iterador)[0] != '#') && ((*iterador)[0] != '[')) {
			if ((*iterador)[(*iterador).length()-1] == ',') {
				aux.push_back((*iterador).substr(0, (*iterador).length()-1));
			} else {
				aux.push_back((*iterador));
			}
		}
	}
}

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

Instruccion AnalizadorInstruccion::identificar(const std::string& linea) {

	VectorString instruccion_separada;

	separar(linea, instruccion_separada);

	limpiar(instruccion_separada);

	if (esJmp(instruccion_separada[1])) {
		Jmp instruccion(instruccion_separada[0], instruccion_separada[1]
						instruccion_separada[2]);
	} else if (esRet(instruccion_separada[1])) {
		Ret instruccion(instruccion_separada[0], instruccion_separada[1]
						instruccion_separada[2]);
	} else {
		Otro instruccion(instruccion_separada[0], instruccion_separada[1]
						instruccion_separada[2]);
	}

	return std::move(instruccion);
}

AnalizadorInstruccion::AnalizadorInstruccion() {}

AnalizadorInstruccion::~AnalizadorInstruccion() {}