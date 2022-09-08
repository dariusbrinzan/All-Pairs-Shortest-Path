#include "algo.h"

std::vector<int> d;
 struct cmp {
     bool operator()(const edge &x, const edge &y) const {
         return d[x.first] > d[y.first];
     }
 };

std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph) {
    int n;

	n = graph.size();

    std::priority_queue <edge, std::vector<edge>, cmp > pq;
    std::vector<std::vector<int> > result(n, std::vector<int>(n, INT_MAX));

	for (int i = 0; i < n; i++)
		d.push_back(INT_MAX);
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[j] = INT_MAX;
		}

        d[i] = 0;
        pq.push({i, 0});

        while(!pq.empty()){
            int node = pq.top().first;
            int dist = pq.top().second;
            pq.pop();

            if(d[node] < dist)
                continue;

            for(unsigned int j = 0; j < graph[node].size(); j++) {
                int son = graph[node][j].first;
                int weight = graph[node][j].second;
                if(d[son] > d[node] + weight) {
                    d[son] = d[node] + weight;
                    pq.push({son, d[son]});
                }
            }
        }
        for(int j = 0; j < n; j++) {
            result[i][j] = d[j];
        }
    }
    return result;
}
