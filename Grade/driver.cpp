/************************
David Scheele
CPSC 1020 1, F16
Programming Assignment 2
dscheel
To compile: g++ driver.cpp
************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "grade.h"

using namespace std;

//Needs to read in file
//Start by just simply reading in values

int main(int argc, char *argv[1])
{
	int i, j;
	int n, a, t;
	double g, w;
	double total;
	double percent;
	double percent_total;
	string name;
	ifstream input;
	input.open(argv[1]);
	grade grade;
	input >> n;
	//Nested for loop to read in each category
	for(i = 0; i < n; i++)
	{
		double s = 0;
		input >> name;
		input >> a;
		//Reads in each individual grade and adds it in
		for(j = 0; j < a; j++)
		{
			input >> g;
			s += g;
		}
		grade.setGradeSum(s);
		input >> t;
		grade.setTotal(t);
		input >> w;
		grade.setWorth(w);
		percent =((w/t)/100);
		percent_total += a*percent;
		total += grade.printGrade(percent);
	}
	cout << "Current Average: ";
	cout << fixed << showpoint << setprecision(2) 
		<< grade.printFinal(total, percent_total) << endl;
}
