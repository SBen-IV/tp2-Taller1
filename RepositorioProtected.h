#ifndef REPOSITORIOPROTECTED_H
#define REPOSITORIOPROTECTED_H

#include <mutex>
#include <string>

#include "Repositorio.h"

class RepositorioProtected {
private:
	std::mutex m;
	Repositorio& nombres_archivos;
public:
	explicit RepositorioProtected(Repositorio& _nombres_archivos);
	std::string obtenerSiNoEstaVacio();
	~RepositorioProtected();
};

#endif
