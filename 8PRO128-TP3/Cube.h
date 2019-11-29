#pragma once
#include "Carre.h"

class Cube :
	public Carre
{
public:
	Cube();
	~Cube() {};

	double aire() const;
	double face() const;
	double volume() const;

	void afficher() const;
	static std::string getEntete();

	friend std::istream& operator>>(std::istream& is, Cube& cube);
	friend std::ostream& operator<<(std::ostream& os, const Cube& cube);
};
