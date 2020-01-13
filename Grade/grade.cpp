/************************
David Scheele
CPSC 1020 1, F16
Programming Assignment 2
dscheel
************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "grade.h"

/*Worth of individual grades
	MyProgrammingLab- 10% total
	Assignments- 20% total
	Labs- 1% each, .01
	Quizzes- 3% each, .03
	Midterm- 15% each, .15
	Final- 15%, .15*/
/*Arithmetic
	MyProgrammingLab
	-(totalGradeVal)*(total%/#ofgrades)
	Assignments
	-(totalAssVal)*(total%/#ofgrades)
	Labs
	-(totalLabVal)*(total%/#ofgrades)
	Quizzes
	-(totalQuizVal)*(total%/#ofgrades)
	Midterm
	-(totalMidVal)*(total%/#ofgrades)
	Final
	-(totalFinVal)*(total%/#ofgrades)*/
	//currentGradeTot = avail*(total/100);
	//currentGrade = addedVal*currentGradeTot;

using namespace std;

grade::grade(int n, int a, double s, int t, double w)
{
	numCat = n;
	avail = a;
	gradeSum = s;
	total = t;
	worth = w;
}

grade::grade()
{
	numCat = 0;
	avail = 0;
	gradeSum = 0;
	total = 0;
	worth = 0;
}

int grade::getNumCat()
{
	return numCat;
}

int grade::getAvail()
{
	return avail;
}

double grade::getGradeSum()
{
	return gradeSum;
}

int grade::getTotal()
{
	return total;
}

double grade::getWorth()
{
	return worth;
}

void grade::setNumCat(int n)
{	
	numCat = n;
}

void grade::setAvail(int a)
{
	avail = a;
}

void grade::setGradeSum(double s)
{
	gradeSum = s;
}

void grade::setTotal(int t)
{
	total = t;
}

void grade::setWorth(double w)
{
	worth = w;
}

double grade::printGrade(double per)
{
	//Need to pass gradesum to main. Multiply it by % to get the value
	//of the individual category
	gradeSum *= per;
	cout << "total is " << gradeSum << endl;
	return gradeSum;
}

double grade::printFinal(double v, double p)
{
	//final grade is total pts/total%
	double final;
	final = v/p;
	return final;
}
