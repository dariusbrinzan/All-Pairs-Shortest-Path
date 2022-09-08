#include <iostream>
#include "algo.h"


int main(int argc, char const *argv[])
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<edge> > graph;

	for (int i = 0 ;i < n; ++i) {
		graph.push_back(std::vector<edge>());
	}

	for (int i = 0; i < m; ++i) {
		int x, y, z;
		std::cin >> x >> y >> z;

		edge e = std::make_pair(y - 1, z);
		graph[x - 1].push_back(e);
	}

	std::vector<std::vector<int> > cost;
	if (argc != 0) {
		cost = shortest_path_all(graph, argv[1][0]);
	}

	for (unsigned int i = 0; i < cost.size(); ++i) {
		for (unsigned int j = 0; j < cost[i].size(); ++j) {
			if (cost[i][j] == INF) {
				std::cout << "inf ";
			} else {
				std::cout << cost[i][j] << ' ';
			}
		}

		std::cout << '\n';
	}

	return 0;
}

/*
pentru rularea unui test se vor da urmatoarele comenzi

make
make build_best
./algo_test F/J/B <input_file_test > out_file_test

cu ce algoritmi au fost create testele de output
0 -> B
1 -> F
2 -> J
BIS
*/