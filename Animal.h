
#pragma once
/*****************************************************************************

Module Name:
	Animal.h

Description:
	Header file for the Animal class.

Author: 
	lepistes
	e-mail: ...

Derived Classes: fourLeggedAnimal
				 twoLeggedAnimal
				 noLeggedAnimal

Public Methods:
	getName(): get name
	setName(): set name
******************************************************************************/

#include "stdafx.h"

using namespace std;

// Animal base class
class Animal{
private:
	char* name;
public:
	char* getName() { return name; }					// Get name
	void setName(char nameIn[]) { name = nameIn; }  // Set name

	Animal(char nameIn[]) : name(nameIn) {};			// Constructor
	Animal(){ setName("no name"); }					// Default constructor

	virtual void print() { cout << "I'm just an animal (base class)" << endl; }; // Print relevant info
};


class fourLeggedAnimal:public Animal{
private:
	double ground_speed; // Speed
public:
	void print(){ cout << "I'm a four legged animal. My name is:  " << getName() << endl; } // Virtual print()
	void setSpeed(double speedIn) { ground_speed = speedIn; }	// Set speed
	double getSpeed() { return ground_speed; }					// Get speed
	fourLeggedAnimal(char nameIn[], double speedIn = 10.0):Animal(nameIn), ground_speed(speedIn) {} // constructor
};

class twoLeggedAnimal:public Animal{
private:
	double air_speed; // Speed
public:
	void print(){ cout << "I'm a two legged animal. My name is:  " << getName() << endl; } // Virtual print()

	twoLeggedAnimal(char nameIn[], double air_speedIn = 3.3):Animal(nameIn), air_speed(air_speedIn) {} //constructor
};

class noLeggedAnimal:public Animal{
private:
	double ground_speed; // Speed
public:
	void print(){ cout << "I have no legs. My name is:  " << getName() << endl; } // Virtual print()

	noLeggedAnimal(char nameIn[], double ground_speedIn = 3.3):Animal(nameIn), ground_speed(ground_speedIn) {} //constructor
};