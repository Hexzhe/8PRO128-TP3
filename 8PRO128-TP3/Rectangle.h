#pragma once
#include "Figure.h"

class Rectangle :
	public Figure
{
public:
	Rectangle();
	~Rectangle() {};

	double largeur;
	double longueur;

	double aire() const;
	double perimetre() const;
	double diagonale() const;

	void afficher() const;
	static std::string getEntete();

	friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
};
