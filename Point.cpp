#include "Point.h"

Point::Point() : ID(-1)
{
}

Point::~Point()
{
	if (v.size() > 0)
	{
		v.clear();
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
	v.push_back(value);
}

size_t Point::size()
{
	return v.size();
}

void Point::changeValue(int index, double val)
{
	if (index >= 0 && index < v.size())
	{
		v[index] = val;
	}
}

DoubleVector* Point::values()
{
	return &v;
}

Point Point::operator+(const Point &p)
{
	if (v.size() == p.v.size())
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			v[i] += p.v[i];
		}
	}
	return *this;
}

Point Point::operator=(const Point &p)
{
	size_t i;
	if (v.size() == 0)
	{
		for (i = 0; i < p.v.size(); ++i)
		{
			v.push_back(p.v[i]);
		}
	}
	else
	{
		for (i = 0; i < p.v.size(); ++i)
		{
			v[i] = p.v[i];
		}
	}
	return *this;
}

bool Point::operator==(const Point &p)
{
	size_t s1 = v.size();
	size_t s2 = p.v.size();
	size_t s = s1 < s2 ? s1 : s2;
	for (size_t i = 0; i < s; ++i)
	{
		if (v[i] != p.v[i])
		{
			return false;
		}
	}
	return true;
}

bool Point::operator<(const Point &p)
{
	if (v.size() == p.v.size())
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] >= p.v[i])
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
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] /= m;
	}
	return *this;
}

double Point::operator()(size_t index)
{
	if (index >= 0 && index < v.size())
	{
		return v[index];
	}
	else
	{
		return -1.0; // error indicator
	}
}

void Point::printValuesToConsole()
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << " " << v[i];
	}
}

void Point::writeValuesToFile(std::ostream &out)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		out << " " << v[i];
	}
}