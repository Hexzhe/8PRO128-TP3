#include "TriangleEq.h"

TriangleEq::TriangleEq() : Triangle()
{
}

double TriangleEq::aire() const
{
	return Triangle::aire();
}

double TriangleEq::perimetre() const
{
	return Triangle::perimetre();
}

double TriangleEq::hauteur() const
{
	return Triangle::cote1 * sqrt(3) / 2;
}

void TriangleEq::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultTriangleEq.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << TriangleEq::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string TriangleEq::getEntete()
{
	return "cote      aire      perim     haut ";
}

std::istream& operator>>(std::istream& is, TriangleEq& triangleEq)
{
	is >> triangleEq.cote1;
	triangleEq.cote3 = triangleEq.cote2 = triangleEq.cote1;

	return is;
}

std::ostream& operator<<(std::ostream& os, const TriangleEq& triangleEq)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangleEq.Triangle::cote1 << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangleEq.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangleEq.perimetre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangleEq.hauteur();

	return os;
}
