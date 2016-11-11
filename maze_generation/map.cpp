#include "map.h"
#include "pos.h"

bool map::get(int x, int y)const
{
	if (!isValid(x, y))
		throw "Invalid Coordinate!";
	return table[x][y];
}

bool map::get(pos p) const { return get(p.x, p.y); }

void map::set(int x, int y, bool f)
{
	if (!isValid(x, y))
		throw "Invalid Coordinate!";
	table[x][y] = f;
}

void map::set(pos p, bool f) { set(p.x, p.y, f); }

std::ostream & operator<<(std::ostream & out, const map & m)
{
	vector<vector<bool>> table = m.table;
	for each (const vector<bool> & t in table)
	{
		for each (bool i in t)
		{
			if (!i)
				out << '#';
			else
				out << '.';
		}
		out << std::endl;
	}
	return out;
}
