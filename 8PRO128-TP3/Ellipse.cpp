#include "Ellipse.h"

Ellipse::Ellipse() :  Figure()
{
}

void Ellipse::afficher(std::ostream& os) const
{
	os << "Ellipse:" << std::endl;
	os << this->getEntete() << std::endl;
	os << "?" << std::flush;
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
	ellipse.afficher(os);
	return os;
}
