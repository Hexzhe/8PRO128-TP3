// Fig. 10.1: fig10_01.cpp
// Driver for Employee hierarchy

#include <iostream>
#include <iomanip>
#include "employ2.h"
#include "boss1.h"
#include "commis1.h"
#include "piece1.h"
#include "hourly1.h"
#include <ctime>

using std::cout;
using std::endl;
using std::ios;
using std::setiosflags;
using std::setprecision;

void virtualViaPointer(const Employee *);
void virtualViaReference(const Employee &);

int main2()
{
	// set output formatting
	cout << setiosflags(ios::fixed | ios::showpoint)
		<< setprecision(2);
	Boss b("John", "Smith", 800.00);
	b.print();
	cout << " earned $" << b.earnings(); // static binding
	virtualViaPointer(&b); // uses dynamic bi
	virtualViaReference(b);  // uses dynamic binding

	CommissionWorker c("Sue", "Jones", 200.0, 3.0, 150);
	c.print();
	cout << " earned $" << c.earnings(); // static binding
	virtualViaPointer(&c); // uses dynamic binding
	virtualViaReference(c); // uses dynamic binding

	PieceWorker p("Bob", "Lewis", 2.5, 200);
	p.print();
	cout << " earned $" << p.earnings(); // static binding
	virtualViaPointer(&p);  // uses dynamic binding
	virtualViaReference(p); // uses dynamic binding

	HourlyWorker h("Karen", "Price", 13.75, 40);
	h.print();
	cout << " earned $" << h.earnings(); // static binding
	virtualViaPointer(&h); // uses dynamic binding
	virtualViaReference(h); // uses dynamic binding

	cout << endl;
	return 0;
}

// Make virtual function calls off a base-class pointer
// using dynamic binding.
void virtualViaPointer(const Employee *baseClassPtr)
{
	baseClassPtr->print();
	cout << " earned $" << baseClassPtr->earnings();
}

// Make virtual function calls off a base-class reference
// using dynamic binding.
void virtualViaReference(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << " earned $" << baseClassRef.earnings();
} 