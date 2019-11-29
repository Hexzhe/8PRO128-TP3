#include <iostream>
#include "Tetraedre.h"
#include "Sphere.h"
#include "Cube.h"

int main()
{
	//Partie 1
	std::cout << "===== Partie 1 =====" << std::endl;
	//TODO
	std::cout << std::endl;

	//Partie 2
	std::cout << "===== Partie 2 =====" << std::endl;
	Figure* tabFig[9]; //Le docx mentionne 12 mais il n'y a que 9 figures?

	tabFig[0] = new Triangle(136.1354638546468, 140.61381464664846, 143.25072149870474);
	tabFig[1] = new TriangleEq(31.143995444364091487234122468365);
	tabFig[2] = new Tetraedre(31.143995444364091487234122468365);

	tabFig[3] = new Ellipse();
	tabFig[4] = new Cercle(10.981691073340778);
	tabFig[5] = new Sphere(4.64572566);

	tabFig[6] = new Rectangle(11, 6.27272727273);
	tabFig[7] = new Carre(20.5107288998);
	tabFig[8] = new Cube(7.48887238722);

	for (size_t i = 0; i < 9; i++)
		std::cout << *tabFig[i] << std::endl;

	std::cout << std::endl;

	//Partie 3
	std::cout << "===== Partie 3 =====" << std::endl;
	

	return 0;
}