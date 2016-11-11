#include "generator.h"
#include "pos.h"
#include <random>
#include <chrono>
#define PER_LINK_EDGE 2
vector<vector<pos>> preTable;
int branchNum = 0;

map generator::randomKruskalGenerate(int x_size, int y_size)
{
	map m(x_size, y_size);
	initPreTable(m);
	//墙率太低……重新设计一下随机方法……
	std::mt19937_64 gen(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> xDis(0, x_size - 1);//[min, max]
	std::uniform_int_distribution<int> yDis(0, y_size - 1);
	std::uniform_int_distribution<int> dirDis(0, 3);//up 0;right 1;down 2;left 3
	
	pos startPoint(xDis(gen), yDis(gen), m);
	pos goalPoint(xDis(gen), yDis(gen));
	while (goalPoint == startPoint)
		goalPoint = pos(xDis(gen), yDis(gen));

	m.set(startPoint, true);
	m.set(goalPoint, true);

	while (isNotLinked(m, startPoint, goalPoint))
	{
		for (int countVar = 0; countVar < PER_LINK_EDGE; countVar++)
		{
			pos rp(xDis(gen), yDis(gen));
			while (!hasNeighbour(m, rp))
				rp = pos(xDis(gen), yDis(gen));
			m.set(rp, true);
			pos tp = chooseNeighbour(rp, dirDis(gen));
			while (m.get(tp))
			{
				int dir = dirDis(gen);
				hasNeighbour(m, rp);
				tp = chooseNeighbour(rp, dirDis(gen));
			}
			m.set(tp, true);
			updateLink(rp, tp);
		}
	}

	return m;
}

map generator::randomPrimGenerate(int x_size, int y_size)
{
	map m(x_size, y_size);



	return m;
}



void initPreTable(const map & m)
{
	preTable.resize(m.map_x_size());
	for (int i = 0; i<m.map_x_size(); i++)
	{
		preTable[i].resize(m.map_y_size());
		for (int j = 0; j < m.map_y_size(); j++)
			preTable[i][j] = pos(i, j);
	}
	branchNum = m.map_x_size()*m.map_y_size();
}

bool generator::isNotLinked(const map & m, const pos & sp, const pos & gp)
{
	if (findRoot(sp) != findRoot(gp))
		return true;
	return false;
}

void generator::updateLink(const pos & rp, const pos & tp)
{
	pos rRp = findRoot(rp);
	pos rTp = findRoot(tp);
	if (rRp != rTp)
	{
		preTable[rRp.x][rRp.y] = rTp;
		branchNum--;
	}
		
}

pos generator::findRoot(const pos & p)
{
	pos r = p;
	while (r != preTable[r.x][r.y])
		r = preTable[r.x][r.y];
	return r;
}

bool generator::hasNeighbour(map & m, const pos & p)
{
	m.set(p, true);
	pos up(p.x, p.y - 1);
	pos right(p.x + 1, p.y);
	pos down(p.x, p.y + 1);
	pos left(p.x - 1, p.y);
	if (!m.get(up) || !m.get(right) || !m.get(down) || !m.get(left))
	{
		m.set(p,false);
		return true;
	}
	m.set(p, false);
	return false;
}

pos generator::chooseNeighbour(const pos & p, int d)
{
	switch (d)
	{
	case 0:return pos(p.x, p.y - 1);
	case 1:return pos(p.x + 1, p.y);
	case 2:return pos(p.x, p.y + 1);
	case 3:return pos(p.x - 1, p.y);
	default:
		throw "Error!disGeneration runs Error!";
	}
}
