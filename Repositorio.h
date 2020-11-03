#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include <queue>
#include <string>
#include <mutex>

class Repositorio {
private:
	std::queue<std::string> nombres;
	std::mutex& m;
public:
	Repositorio();
	Repositorio(std::mutex& _m);
	Repositorio(Repositorio&& otro) = delete;
	void agregar(const std::string& nombre);
	bool estaVacio() const;
	std::string obtener();
	~Repositorio();
};

#endif
