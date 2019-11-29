#include "Triangle.h"

Triangle::Triangle() : Figure()
{
	cote1 = 0.0;
	cote2 = 0.0;
	cote3 = 0.0;
}

double Triangle::aire() const
{
	double p = perimetre();
	return sqrt(p * (p - cote1) * (p - cote2) * (p - cote3));
}

double Triangle::perimetre() const
{
	return cote1 + cote2 + cote3;
}

double Triangle::hauteur(int cote) const
{
	if (cote <= 0 || cote > 3)
	{
		std::cout << "ERROR: Triangle::hauteur(int) param must be between 1-3" << std::endl;
		exit(1);
	}

	switch (cote)
	{
	case 1:
		return 2 * aire() / cote1;
	case 2:
		return 2 * aire() / cote2;
	case 3:
		return 2 * aire() / cote3;
	}
}

void Triangle::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultTriangle.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Triangle::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Triangle::getEntete()
{
	return "cote1     cote2     cote3     aire      perim     haut (b=cote1)";
}

std::istream& operator>>(std::istream& is, Triangle& triangle)
{
	is >> triangle.cote1 >> triangle.cote2 >> triangle.cote3;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.cote1 << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.cote2 << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.cote3 << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.perimetre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << triangle.hauteur(1);

	return os;
}
