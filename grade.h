/************************
David Scheele
CPSC 1020 1, F16
Programming Assignment 2
dscheel
************************/

//Class Declaration

using namespace std;

class grade
{
	private:
		//Total number of categories in input.txt
		int numCat;
		//Number of grades in category available
		int avail;
		//Grades in category
		double gradeSum;
		//Total number of grades there will be
		int total;
		//Weight of category
		double worth;

	public:
		//Default Constructor
		grade();
		//Regular Constructor
		grade(int, int, double, int, double);
		//Getters
		int getNumCat(); 
		int getAvail();
		double getGradeSum();
		int getTotal();
		double getWorth();
		//Setters
		void setNumCat(int);
		void setAvail(int);
		void setGradeSum(double);
		void setTotal(int);
		void setWorth(double);
		//functions containing formulas (one calcs % values, other total)
		double printGrade(double);
		double printFinal(double, double);
};
