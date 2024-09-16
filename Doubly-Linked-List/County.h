#ifndef COUNTY_H
#define COUNTY_H

#include<iostream>

using namespace std;

class County
{
	private:
		int index;
		string name;
		string state;
		int population;
	public:
		County(int, string, string, int);
		int getIndex();
		void setIndex(int);
		int getPopulation();

		bool operator <(const County& c);
		bool operator >(const County& c);

		friend ostream& operator <<(ostream& os, const County& c)
		{
			os << c.name << ", " << c.state << ": " << c.population;
			return os;
		}
};

#endif