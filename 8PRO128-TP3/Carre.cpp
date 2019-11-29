#include "Carre.h"

Carre::Carre() : Rectangle()
{
}

double Carre::aire() const
{
	auto x = pow(Rectangle::largeur, 2);
	return x;
}

double Carre::perimetre() const
{
	return 4 * Rectangle::largeur;
}

double Carre::diagonale() const
{
	return sqrt(aire() * 2);
}

void Carre::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultCarre.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Carre::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Carre::getEntete()
{
	return "cote      aire      perim     diago";
}

std::istream& operator>>(std::istream& is, Carre& carre)
{
	is >> carre.largeur;
	carre.longueur = carre.largeur;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Carre& carre)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << carre.Rectangle::largeur << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << carre.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << carre.perimetre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << carre.diagonale();

	return os;
}
