#ifndef RESULTADOPROTECTED_H
#define RESULTADOPROTECTED_H

#include <mutex>
#include <string>

#include "Resultado.h"

class ResultadoProtected {
private:
	std::mutex m;
	Resultado& resultados;
public:
	explicit ResultadoProtected(Resultado& _resultados);
	void agregar(const std::string& nombre_archivo,	const int resultado);
	~ResultadoProtected();
};

#endif
