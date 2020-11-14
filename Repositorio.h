#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include <queue>
#include <string>

class Repositorio {
private:
	std::queue<std::string> nombres;
public:
	Repositorio(char const *nombre_archivos[],
				int cant_nombre_archivos);
	Repositorio(const Repositorio& otro) = delete;
	Repositorio& operator=(const Repositorio& otro) = delete;
	Repositorio(Repositorio&& otro) = delete;
	Repositorio& operator=(Repositorio&& otro) = delete;
	bool estaVacio() const;
	std::string obtener();
	~Repositorio();
};

#endif
