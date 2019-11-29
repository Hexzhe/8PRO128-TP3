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

	tabFig[0] = new Triangle(69, 420, 69);
	tabFig[1] = new TriangleEq(69);
	tabFig[2] = new Tetraedre(420);

	tabFig[3] = new Ellipse();
	tabFig[4] = new Cercle(69);
	tabFig[5] = new Sphere(420);

	tabFig[6] = new Rectangle();
	tabFig[7] = new Carre();
	tabFig[8] = new Cube();

	for (size_t i = 0; i < 9; i++)
	{
		std::cout << *tabFig[i] << std::endl;
	}

	std::cout << std::endl;

	//Partie 3
	std::cout << "===== Partie 3 =====" << std::endl;
	

	return 0;
}