#include "algo.h"

std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph) {
    int i, j, k;
    int n = graph.size();
    std::vector<std::vector<int> > result(n, std::vector<int>(n, INT_MAX));

    for (i = 0; i < n; i++) {
        for (j = 0; j < graph[i].size(); j++) {
            result[i][graph[i][j].first] = graph[i][j].second;
        }
        result[i][i] = 0;
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (result[i][k] == INT_MAX || result[k][j] == INT_MAX) {
                        continue;
                }
                long long current_dist = result[i][j];
                long long possible_dist = 1LL * result[i][k] + 1LL * result[k][j];
                if (current_dist > possible_dist) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    return result;
}
