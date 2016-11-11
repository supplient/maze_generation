#include "pos.h"
#include "map.h"
#define NORMAL_SIZE 20

map pos::pos_map(NORMAL_SIZE, NORMAL_SIZE);

bool isValid(int x, int y)
{
	return isValid(pos(x, y));
}

bool isValid(const pos & p)
{
	if (p.x < 0 || p.x >= pos::pos_map.map_x_size() || p.y < 0 || p.y >= pos::pos_map.map_y_size())
		return false;
	return true;
}

pos::pos(int _x, int _y, const map & m)
{
	if (&pos_map != &m)
		pos_map = m;
	if (_x < 0)
		x = 0;
	else if (_x >= m.map_x_size())
		x = m.map_x_size()-1;
	else
		x = _x;

	if (_y < 0)
		y = 0;
	else if (_y >= m.map_y_size())
		y = m.map_y_size()-1;
	else
		y = _y;
}
