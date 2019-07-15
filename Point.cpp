#include "Point.h"

Point::Point() : ID(-1)
{
}

Point::~Point()
{
	if(values.size() > 0)
		values.clear();
}

void Point::setID(int ID)
{
	this->ID = ID;
}

int Point::getID()
{
	return ID;
}

void Point::addValue(double value)
{
	values.push_back(value);
}

double Point::getValue(int index)
{
	if (index >= 0 && index < values.size())
		return values[index];
	else
		return -1.0; // error indicator
}

int Point::getValuesSize()
{
	return values.size();
}

void Point::changeValue(int index, double newValue)
{
	if (index >= 0 && index < values.size())
		values[index] = newValue;
}

DoubleVector* Point::getValues()
{
	return &values;
}

Point Point::operator+(const Point &p)
{
	if (values.size() == p.values.size())
	{
		for (int i = 0 ; i < values.size() ; i++)
			values[i] += p.values[i];
	}
	return *this;
}

Point Point::operator/(int m)
{
	for (int i = 0 ; i < values.size() ; i++)
		values[i] /= m;
	return *this;
}

Point Point::operator=(const Point &p)
{
	int i;
	if (values.size() == 0)
	{
		for (i = 0 ; i < p.values.size() ; i++)
			values.push_back(p.values[i]);
	}
	else
	{
		for (i = 0 ; i < p.values.size() ; i++)
			values[i] = p.values[i];
	}
	return *this;
}

bool Point::operator==(const Point &p)
{
	int s1 = values.size();
	int s2 = p.values.size();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
		if(values[i] != p.values[i]) return false;
	return true;
}

bool Point::operator<(const Point &p)
{
	if (values.size() == p.values.size())
	{
		for (int i = 0 ; i < values.size() ; i++)
			if (values[i] >= p.values[i]) return false;
		return true;
	}
	else
		return false;
}

void Point::printValuesToConsole()
{
	for (int i = 0 ; i < values.size() ; i++)
		std::cout << " " << values[i];
}

void Point::writeValuesToFile(std::ostream &out)
{
	for (int i = 0 ; i < values.size() ; i++)
		out << " " << values[i];
}