#pragma once
#include "Rectangle.h"

class Carre :
	public Rectangle
{
public:
	Carre();
	~Carre() {};

	double aire() const;
	double perimetre() const;
	double diagonale() const;

	void afficher() const;
	static std::string getEntete();

	friend std::istream& operator>>(std::istream& is, Carre& carre);
	friend std::ostream& operator<<(std::ostream& os, const Carre& carre);
};
