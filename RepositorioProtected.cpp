#include "RepositorioProtected.h"

RepositorioProtected::RepositorioProtected(Repositorio& _nombres_archivos) : 
										nombres_archivos(_nombres_archivos) {}

std::string RepositorioProtected::obtenerSiNoEstaVacio() {
	std::unique_lock<std::mutex> lock(this->m);
	std::string nombre_archivo;

	if(!this->nombres_archivos.estaVacio()) {
		nombre_archivo = this->nombres_archivos.obtener();
	}

	return nombre_archivo;
}

bool RepositorioProtected::estaVacio() {
	std::unique_lock<std::mutex> lock(this->m);

	return this->nombres_archivos.estaVacio();
}

RepositorioProtected::~RepositorioProtected() {}
