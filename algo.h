#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include <climits>

#define INF 100000

typedef std::pair<int, int> edge;

 
std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph, char algh);

#endif