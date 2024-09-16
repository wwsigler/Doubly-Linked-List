/*
William Walker Sigler
3/20/23
CSC 1310 001
Program 2:
This program is a doubly-linked list that will read a list of counties
in the US from a csv file and add each to a linked list, then the linked
list will use merge sort to sort the counties by population.
*/

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include "County.h"
#include <list>
#include "List.h"

using namespace std;

int main()
{
	ifstream file;
	stringstream temp;
	string line, county, state;
	int index, pop;
	//file.open("counties_list.csv", ios::in);
	file.open("counties_ten.csv", ios::in);

	List<County*> counties; //new list of county pointers

	County* newCounty;

	if(file.good())
	{
	while(getline(file, line, ','))
	{
		temp.clear();
		temp.str(line);
		temp >> index;

		getline(file, line, ',');
		county = line;

		getline(file, line, ',');
		state = line;

		getline(file, line, '\n');
		temp.clear();
		temp.str(line);
		temp >> pop;

		newCounty = new County(index, county, state, pop);
		counties.append(newCounty);
	}
	}

	counties.mergesort();

	counties.print();

	file.close();

	return 0;
}
