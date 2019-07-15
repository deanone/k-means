#include "Point.h"

Point::Point() : ID(-1)
{
}

Point::~Point()
{
	if (values.size() > 0)
	{
		values.clear();
	}
}

void Point::setID(int _ID)
{
	ID = _ID;
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
	{
		return values[index];
	}
	else
	{
		return -1.0; // error indicator
	}
}

int Point::getValuesSize()
{
	return values.size();
}

void Point::changeValue(int index, double newValue)
{
	if (index >= 0 && index < values.size())
	{
		values[index] = newValue;
	}
}

DoubleVector* Point::getValues()
{
	return &values;
}

Point Point::operator+(const Point &p)
{
	if (values.size() == p.values.size())
	{
		for (size_t i = 0; i < values.size(); ++i)
		{
			values[i] += p.values[i];
		}
	}
	return *this;
}

Point Point::operator=(const Point &p)
{
	size_t i;
	if (values.size() == 0)
	{
		for (i = 0; i < p.values.size(); ++i)
		{
			values.push_back(p.values[i]);
		}
	}
	else
	{
		for (i = 0; i < p.values.size(); ++i)
		{
			values[i] = p.values[i];
		}
	}
	return *this;
}

bool Point::operator==(const Point &p)
{
	size_t s1 = values.size();
	size_t s2 = p.values.size();
	size_t s = s1 < s2 ? s1 : s2;
	for (size_t i = 0; i < s; ++i)
	{
		if (values[i] != p.values[i])
		{
			return false;
		}
	}
	return true;
}

bool Point::operator<(const Point &p)
{
	if (values.size() == p.values.size())
	{
		for (size_t i = 0; i < values.size(); ++i)
		{
			if (values[i] >= p.values[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

Point Point::operator/(int m)
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		values[i] /= m;
	}
	return *this;
}

void Point::printValuesToConsole()
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		std::cout << " " << values[i];
	}
}

void Point::writeValuesToFile(std::ostream &out)
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		out << " " << values[i];
	}
}