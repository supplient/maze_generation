#include "generator.h"
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		for (int n = 0; n < 5; n++)
		{
			map m = generator::randomKruskalGenerate(10, 10);
			
			//通路率计算
			int oneCount = 0;
			for (int i = 0; i < m.map_x_size(); i++)
				for (int j = 0; j < m.map_y_size(); j++)
					if (m.get(i, j))
						oneCount++;
			cout << n + 1 << ":" << double(oneCount) / double(m.map_x_size()*m.map_y_size()) << endl;

			//打印地图
			//cout << m << endl;
		}
		int i = 0;
		cin >> i;
		if (i == 0)
			break;
		cout << endl;
	}
	return 0;
}