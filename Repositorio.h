#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include <queue>
#include <string>

class Repositorio {
private:
	std::queue<std::string> nombres;
public:
	Repositorio();
	Repositorio(Repositorio&& otro);
	void agregar(const std::string& nombre);
	bool estaVacio() const;
	std::string obtener();
	~Repositorio();
	
};

#endif
