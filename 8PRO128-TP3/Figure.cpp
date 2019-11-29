#include "Figure.h"

void Figure::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultFigure.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Figure::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Figure::getEntete()
{
	return "No header";
}

std::istream& operator>>(std::istream& is, Figure& figure)
{
	return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure)
{
	os << "?";

	return os;
}
