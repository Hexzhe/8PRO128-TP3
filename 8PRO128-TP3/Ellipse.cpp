#include "Ellipse.h"

Ellipse::Ellipse() :  Figure()
{
}

void Ellipse::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultEllipse.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Ellipse::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Ellipse::getEntete()
{
	return "No header";
}

std::istream& operator>>(std::istream& is, Ellipse& ellipse)
{
	return is;
}

std::ostream& operator<<(std::ostream& os, const Ellipse& ellipse)
{
	os << "?";
	return os;
}
