#pragma once
#include <vector>
#include <iostream>
using std::vector;

struct pos;

class map
{
public:
	map(int _x_size, int _y_size) :x_size(_x_size), y_size(_y_size)
	{
		table.resize(x_size);
		for (int i = 0; i < x_size; i++)
		{
			table[i].resize(y_size);
			for (int j = 0; j < y_size; j++)
				table[i][j] = false;
		}
	}

	bool get(int x, int y)const;
	bool get(pos p)const;
	void set(int x, int y, bool f);
	void set(pos p, bool f);
	int map_x_size()const { return x_size; }
	int map_y_size()const { return y_size; }

	friend std::ostream & operator<<(std::ostream& out, const map & m);

private:
	vector<vector<bool>> table;
	int x_size;
	int y_size;
};