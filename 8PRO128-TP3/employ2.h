// Abstract base class Employee
#include <ctime>
#ifndef EMPLOY2_H
#define EMPLOY2_H

class Employee {
public:
	Employee(const char *, const char *);
	~Employee(); // destructor reclaims memory

	const char *getFirstName() const;
	const char *getLastName() const;

	// Pure virtual function makes Employee abstract base class
	virtual double earnings() const = 0; // pure virtual
	virtual void print() const; // virtual

private:
	Date birthDate; //TODO
	char *firstName;
	char *lastName;
};
#endif 