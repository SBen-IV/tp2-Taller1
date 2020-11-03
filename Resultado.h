#ifndef RESULTADO_H
#define RESULTADO_H

#include <map>
#include <string>
#include <iterator>
#include <mutex>

typedef std::map<std::string, std::string> HashOrdenado;

class Resultado {
private:
	HashOrdenado resultados;
	std::mutex& m;
public:
	Resultado(std::mutex& m);
	void agregar(const std::string& nombre_archivo, const int resultado);
	void imprimir();
	~Resultado();
};

#endif
