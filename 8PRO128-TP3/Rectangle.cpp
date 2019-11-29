#include "Rectangle.h"

Rectangle::Rectangle() : Figure()
{
	largeur = 0.0;
	longueur = 0.0;
}

double Rectangle::aire() const
{
	return longueur * largeur;
}

double Rectangle::perimetre() const
{
	return (largeur + longueur) * 2;
}

double Rectangle::diagonale() const
{
	return sqrt(pow(largeur, 2) + pow(longueur, 2));
}

void Rectangle::afficher() const
{
	std::cout << *this << std::endl;

	std::string path = "ResourceFiles/Output/resultRectangle.txt";
	bool exist = false;

	std::ifstream ifs(path);
	if (ifs)
		exist = true;
	ifs.close();

	std::ofstream ofs(path, std::ios::out | std::ios::app);
	if (!exist)
		ofs << Rectangle::getEntete() << std::endl;

	ofs << *this << std::endl;

	ofs.close();
}

std::string Rectangle::getEntete()
{
	return "larg      long      aire      perim     diago";
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle)
{
	is >> rectangle.largeur >> rectangle.longueur;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
	os << std::setw(9) << std::setprecision(2) << std::fixed << rectangle.largeur << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << rectangle.longueur << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << rectangle.aire() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << rectangle.perimetre() << " ";
	os << std::setw(9) << std::setprecision(2) << std::fixed << rectangle.diagonale();

	return os;
}
