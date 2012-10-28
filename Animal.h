

#pragma once

#include "stdafx.h"

using namespace std;

class Animal{
private:
	char* name;
public:
	char* getName() { return name; }
	void setName(char nameIn[]) { name = nameIn; }

	Animal(char nameIn[]) : name(nameIn) {};
	Animal(){ setName("no name"); }

	virtual void print() { cout << "I'm just an animal (base class)" << endl; };
};


class fourLeggedAnimal:public Animal{
private:
	double ground_speed;
public:
	void print(){ cout << "I'm a four legged animal. My name is:  " << getName() << endl; }
	void setSpeed(double speedIn) { ground_speed = speedIn; }
	double getSpeed() { return ground_speed; }
	fourLeggedAnimal(char nameIn[], double speedIn = 10.0):Animal(nameIn), ground_speed(speedIn) {} // constructor
};

class twoLeggedAnimal:public Animal{
private:
	double air_speed;
public:
	void print(){ cout << "I'm a two legged animal. My name is:  " << getName() << endl; }

	twoLeggedAnimal(char nameIn[], double air_speedIn = 3.3):Animal(nameIn), air_speed(air_speedIn) {} //constructor
};

class noLeggedAnimal:public Animal{
private:
	double ground_speed;
public:
	void print(){ cout << "I'm a two legged animal. My name is:  " << getName() << endl; }

	noLeggedAnimal(char nameIn[], double ground_speedIn = 3.3):Animal(nameIn), ground_speed(ground_speedIn) {} //constructor
};