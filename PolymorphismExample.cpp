// PolymorphismExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Animal.h"

#include <list>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// list to hold all Animal and derived from Animal objects
	list<Animal*> animal_list;

	// create the objects
	Animal* p_animal = new Animal();							   // (only Animal class members are accessible)
	fourLeggedAnimal* p_dog = new fourLeggedAnimal("Karamel"); // you can say Animal* p_dog = new ...,
	twoLeggedAnimal* p_bird = new twoLeggedAnimal("Sarisin");  // but can't reach the extra members of fourLeggedAnimal class
	noLeggedAnimal* p_snake = new noLeggedAnimal("no legs needed");

	//p_animal = p_dog; // this is OK
	//p_dog = p_animal // NOT OK!

	// enter them into the list
	animal_list.push_back(p_dog);
	animal_list.push_back(p_bird);
	animal_list.push_back(p_animal);
	animal_list.push_back(p_snake);
	
	// use the virtual function in the base class (reverse_iterator used)
	list<Animal*>::reverse_iterator a_ri;
	for (a_ri = animal_list.rbegin(); a_ri != animal_list.rend(); a_ri++){
		(*a_ri)->print();
	}

	// print extra member value
	//cout << p_dog->getSpeed() << endl;

	// clean up
	list<Animal*>::iterator a_i;
	for (a_i = animal_list.begin(); a_i != animal_list.end(); a_i++){
		delete *a_i;
	}

	//  keep the console open
	cin.get();
	return 0;
}

