#include "algo.h"
#include <climits>
#include <string>

std::vector<std::vector<edge> > read_graph(int &n, int &m) {
	std::ifstream input_file;
	input_file.open("./test.in");
    input_file >> n >> m;
    std::vector<std::vector<edge> > graph(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        // in >> u >> v >> w;
		input_file >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }
	input_file.close();
    return graph;
}

int main() {
	std::ofstream output_files;
	output_files.open("./test.out");
	int n, m;
	std::vector<std::vector<edge> > graph;
	graph = read_graph(n, m);
	std::vector<std::vector<int> > result;
	int start_s = clock();
	result = shortest_path_all(graph);
	int stop_s = clock();
	std::cout << "Time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << '\n';
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
	        if(result[i][j] == INT_MAX)
				output_files << "inf ";
	        else
				output_files << result[i][j] << " ";
	    }
		output_files << '\n';
	}
	output_files.close();
	return 0;
}
