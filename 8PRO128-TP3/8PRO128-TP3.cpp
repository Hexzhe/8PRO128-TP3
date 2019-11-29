/******************************************************************
* Titre:       Travail pratique #3 (https://github.com/Hexzhe/8PRO128-TP3)
* Auteur(e)s:  Dominique Boivin (BOID31609701)
*              Jason Gilbert (GILJ05069703)
* Date:        2019-11-28
* Description: Petit programme d'affichage en trois parties selon le
			   document TP3_2.docx.
			   Partie 1: Transformation des classes Point et Segment
			   du premier travail en Template.
			   Partie 2: Implémentation d'une fonction d'affichage
			   virtuelle dans tous les classes dérivés de Figure.
			   Partie 3: Modification de la classe Employe pour y
			   ajouter un attribut birthDate de type Date.
*******************************************************************/

#include <iostream>
#include "Tetraedre.h"
#include "Sphere.h"
#include "Cube.h"
#include "Segment.h"
#include "piece1.h"
#include "hourly1.h"
#include "commis1.h"
#include "boss1.h"

int main()
{
	//Partie 1
	std::cout << "===== Partie 1 =====" << std::endl;
	
	Point<double>* point = new Point<double>(4.89, 7.89);
	std::cout << "Voici un Point<double>: " << point->Info() << std::endl;
	std::cout << "Deplacement relatif de (1.11, 1.11): " << point->MoveRelative(1.11, 1.11).Info() << std::endl;
	std::cout << std::endl;

	Segment<char>* segment = new Segment<char>('"', 7, 'g', 7);
	std::cout << "Voici un Segment<char>: " << segment->Info() << std::endl;
	std::cout << "Deplacement relatif de (p, p): " << segment->MoveRelative('p', 'p').Info() << std::endl;

	std::cout << std::endl;

	//Partie 2
	std::cout << "===== Partie 2 =====" << std::endl;
	Figure* tabFig[9]; //Le docx mentionne 12 mais il n'y a que 9 figures?

	tabFig[0] = new Triangle(136.1354638546468, 140.61381464664846, 143.25072149870474);
	tabFig[1] = new TriangleEq(23);
	tabFig[2] = new Tetraedre(31.143995444364091487234122468365);

	tabFig[3] = new Ellipse();
	tabFig[4] = new Cercle(10.981691073340778);
	tabFig[5] = new Sphere(4.64572566);

	tabFig[6] = new Rectangle(11, 6.27272727273);
	tabFig[7] = new Carre(20.5107288998);
	tabFig[8] = new Cube(7.48887238722);

	for (size_t i = 0; i < 9; i++)
	{
		std::cout << *tabFig[i] << std::endl;
		std::cout << std::endl;
	}

	//Partie 3
	std::cout << "===== Partie 3 =====" << std::endl;
	std::cout << "Creation de 4 employees: \n  un PieceWorker (2000-03-03), \n  un HourlyWorker (2000-06-06), \n  un CommissionWorker (2000-09-09) et \n  un Boss (2000-12-12)" << std::endl;

	Employee* tabEmp[4];

	tabEmp[0] = new PieceWorker("PieceWorker", "Name", Date(3, 3, 2000), 10, 5);
	tabEmp[1] = new HourlyWorker("HourlyWorker", "Name", Date(6, 6, 2000), 10, 5);
	tabEmp[2] = new CommissionWorker("CommissionWrkr", "Name", Date(9, 9, 2000), 10, 5, 25);
	tabEmp[3] = new Boss("Boss", "Name", Date(12, 12, 2000), 10);

	std::cout << std::endl;
	std::cout << "Simulation d'une année de paie (paie chaque premier du mois):" << std::endl;

	Date date(1, 1, 2019);
	for (size_t i = 0; i < 12; i++)
	{
		std::cout << date << std::endl;

		for (size_t j = 0; j < 4; j++)
		{
			tabEmp[j]->print();
			std::cout << "                Pay: $" << tabEmp[j]->earnings() << std::endl;
			std::cout << std::endl;
		}

		date.setDate(i + 1, 1, 2019);
		
	}
	
	delete point, segment, tabFig;
	return 0;
}