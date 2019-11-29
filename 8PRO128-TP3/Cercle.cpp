#include "Cercle.h"

Cercle::Cercle() : Ellipse()
{
	rayon = 0.0;
}

double Cercle::aire() const
{
	return M_PI * pow(rayon, 2);
}

double Cercle::perimetre() const
{
	return 2 * M_PI * rayon;
}

double Cercle::diametre() const
{
	return 2 * rayon;
}

void Cercle::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultCercle.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Cercle::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Cercle::getEntete()
{
	return "rayon     aire      perim     diam";
}

std::istream& operator>>(std::istream& is, Cercle& cercle)
{
	is >> cercle.rayon;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Cercle& cercle)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << cercle.rayon << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cercle.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cercle.perimetre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << cercle.diametre();

	return os;
}
