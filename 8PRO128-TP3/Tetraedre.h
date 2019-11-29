#pragma once
#include "TriangleEq.h"

class Tetraedre :
	public TriangleEq
{
public:
	Tetraedre();
	~Tetraedre() {};

	double aire() const;
	double face() const;
	double volume() const;
	double hauteur() const;

	void afficher() const;
	static std::string getEntete();

	friend std::istream& operator>>(std::istream& is, Tetraedre& tetraedre);
	friend std::ostream& operator<<(std::ostream& os, const Tetraedre& tetraedre);
};
