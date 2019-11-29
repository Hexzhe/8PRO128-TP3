#include "Sphere.h"

Sphere::Sphere() : Cercle()
{
}

double Sphere::diametre() const
{
	return 2 * Cercle::rayon;
}

double Sphere::aire() const
{
	return 4 * Cercle::aire();
}

double Sphere::volume() const
{
	return 4 * M_PI * pow(Cercle::rayon, 3) / 3;
}

void Sphere::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultSphere.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Sphere::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Sphere::getEntete()
{
	return "rayon     diam      aire      vol";
}

std::istream& operator>>(std::istream& is, Sphere& sphere)
{
	is >> sphere.rayon;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Sphere& sphere)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << sphere.Cercle::rayon << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << sphere.diametre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << sphere.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << sphere.volume();

	return os;
}
