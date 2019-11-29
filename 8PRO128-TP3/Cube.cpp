#include "Cube.h"

Cube::Cube() : Carre()
{
}

double Cube::aire() const
{
	return 6 * Carre::aire();
}

double Cube::face() const
{
	return Carre::aire();
}

double Cube::volume() const
{
	return pow(Carre::largeur, 3);
}

void Cube::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultCube.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Cube::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Cube::getEntete()
{
	return "cote      aire      face      vol";
}

std::istream& operator>>(std::istream& is, Cube& cube)
{
	is >> cube.largeur >> cube.longueur;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Cube& cube)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << cube.Carre::largeur << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cube.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cube.face() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cube.volume();

	return os;
}
