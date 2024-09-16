#include "County.h"

using namespace std;

County::County(int i, string n, string s, int p)
{
	index = i;
	name = n;
	state = s;
	population = p;
}

int County::getIndex()
{
	return index;
}

void County::setIndex(int i)
{
	index = i;
}

int County::getPopulation()
{
	return population;
}

bool County::operator <(const County& c)
{
	if(population < c.population)
		return true;
	else
		return false;
}

bool County::operator >(const County& c)
{
	if(population > c.population)
		return true;
	else
		return false;
}
