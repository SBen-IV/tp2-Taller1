#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>

class Archivo {
private:
	std::fstream archivo;
	std::string nombre_archivo;
public:
	Archivo(const std::string nombre, std::ios_base::openmode modo);
	Archivo(Archivo&& otro);
	void leer(std::string& linea);
	bool esEOF();
	~Archivo();
};

#endif