#pragma once

class map;

struct pos
{
	int x;
	int y;
	static map pos_map;
	pos(int _x = 0, int _y = 0, const map & m = pos_map);

	bool operator==(const pos & opr)
	{
		if (x == opr.x && y == opr.y)
			return true;
		return false;
	}

	bool operator!=(const pos & opr)
	{
		return !(*this == opr);
	}
};

bool isValid(int x, int y);
bool isValid(const pos & p);
