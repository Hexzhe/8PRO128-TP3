#pragma once
#include "Triangle.h"

class TriangleEq :
	public Triangle
{
public:
	TriangleEq();
	~TriangleEq() {};

	double aire() const;
	double perimetre() const;
	double hauteur() const;

	void afficher() const;
	static std::string getEntete();

	friend std::istream& operator>>(std::istream& is, TriangleEq& triangleEq);
	friend std::ostream& operator<<(std::ostream& os, const TriangleEq& triangleEq);
};
