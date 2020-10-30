#include "Archivo.h"

Archivo::Archivo(const std::string nombre, std::ios_base::openmode modo) : 
					nombre_archivo(nombre) {
	this->archivo.open(this->nombre_archivo, modo);
}

Archivo::Archivo(Archivo&& otro) {
	this->archivo = std::move(otro.archivo);
	this->nombre_archivo = otro.nombre_archivo;
}

void Archivo::leer(std::string& linea) {
	std::getline(this->archivo, linea);
}

bool Archivo::esEOF() {
	return this->archivo.eof();
}

Archivo::~Archivo() {
	if (this->archivo.is_open()) this->archivo.close();
}
