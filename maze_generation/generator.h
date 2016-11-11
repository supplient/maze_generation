#pragma once
#include "map.h"

class generator
{
public:
	static map randomKruskalGenerate(int x_size, int y_size);
	static map randomPrimGenerate(int x_size, int y_size);//without loops
private:
	static bool isNotLinked(const map & m, const pos & sp, const pos & gp);
	static void updateLink(const pos & rp, const pos & tp);
	static pos findRoot(const pos & p);
	static bool hasNeighbour(map & m, const pos & p);
	static pos chooseNeighbour(const pos & p, int d);
};

void initPreTable(const map & m);
