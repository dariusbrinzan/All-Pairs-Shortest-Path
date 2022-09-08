
#include <vector>
#include <iostream>
#include <climits>
#include "algo.h"

void Floyd_Warshall(std::vector<std::vector<int> >& cost) {
	int n = cost.size();
	for(int k = 0;k< n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(cost[i][j] > cost[i][k]+cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
}

void Bellman_Ford(std::vector<std::pair<int, edge> >& edges, std::vector<int>& cost, int src) {
	cost[src] = 0;
	for (unsigned int i = 1; i <= cost.size()-1; ++i) 
    { 
        for (unsigned int j = 0; j < edges.size(); j++) 
        { 
            int u = edges[j].first; 
            int v = edges[j].second.first; 
            int weight = edges[j].second.second; 
            if (cost[u] != INF && cost[u] + weight < cost[v]) 
                cost[v] = cost[u] + weight; 
        } 
    } 
}

int minDistance(int dist[], bool sptSet[], int n) 
{ 
    int min = INT_MAX, min_index = -1; 
   
    for (int v = 0; v < n; v++) {
	    if (sptSet[v] == false && dist[v] <= min) {
	        min = dist[v];
	        min_index = v;
	    }
     }
   
   return min_index; 
} 

void Dijkstra(std::vector<std::vector<int > >& cost, int src) {
	int dist[cost.size()];
   
    bool sptSet[cost.size()];

    for (unsigned int i = 0; i < cost.size(); i++) {
    	dist[i] = INF;
        sptSet[i] = false;
    }

    dist[src] = 0; 
   
    for (unsigned int count = 0; count < cost.size()-1; count++) 
    {
       int u = minDistance(dist, sptSet, cost.size());
       sptSet[u] = true;

       for (unsigned int v = 0; v < cost.size(); v++) {
	      if (!sptSet[v] && cost[u][v] != INF && dist[u] != INF  
	                                       && dist[u]+cost[u][v] < dist[v]) {
	            dist[v] = dist[u] + cost[u][v]; 
	    	 }
	     }
 	}

     for (unsigned int i  = 0; i < cost.size(); ++i) {
     	cost[src][i] = dist[i];
     }
}

void Johnson(const std::vector<std::vector<edge> >& graph, std::vector<std::vector<int> >& cost) {
	std::vector<std::pair<int, edge> > edges;
	for (unsigned int i = 0; i < graph.size(); ++i) {
		for (unsigned int j = 0; j < graph[i].size(); ++j) {
			edges.push_back(std::make_pair(i, graph[i][j]));
		}
	}

	for (unsigned int i = 0; i < graph.size(); ++i) {
		edges.push_back(std::make_pair(graph.size(), std::make_pair(i, 0)));
	}


	std::vector<int> cost_from_src;
	for (unsigned int j = 0; j <= graph.size(); ++j) {
		cost_from_src.push_back(INF);
	}

	Bellman_Ford(edges, cost_from_src, graph.size());

	for (unsigned int i = 0; i < cost.size(); ++i) {
		for (unsigned int j = 0; j < cost[i].size(); ++j) {
			cost[i][j] = cost[i][j] + cost_from_src[i] - cost_from_src[j];
		}
	}

	for (unsigned int i = 0; i < graph.size(); ++i) {
		Dijkstra(cost, i);
	}


}

std::vector<std::vector<int> > shortest_path_all(const std::vector<std::vector<edge> >& graph, char algh) {
	if (algh == 'F') {
		std::vector<std::vector<int> > cost;

		for (unsigned int i = 0; i < graph.size(); ++i) {
			std::vector<int> help;
			for (unsigned int k = 0; k < graph.size(); ++k) {
				help.push_back(INF);
			}

			help[i] = 0;

			for (unsigned int j = 0; j < graph[i].size(); ++j) {
				help[graph[i][j].first] = graph[i][j].second;
			}
			cost.push_back(help);
		}

		Floyd_Warshall(cost);
		return cost;
	} else {
		if (algh == 'B') {
			std::vector<std::pair<int, edge> > edges;
			for (unsigned int i = 0; i < graph.size(); ++i) {
				for (unsigned int j = 0; j < graph[i].size(); ++j) {
					edges.push_back(std::make_pair(i, graph[i][j]));
				}
			}

			std::vector<std::vector<int> > cost;
			for (unsigned int i = 0; i < graph.size(); ++i) {
				std::vector<int> cost_from_src;
				for (unsigned int j = 0; j < graph.size(); ++j) {
					cost_from_src.push_back(INF);
				}

				Bellman_Ford(edges, cost_from_src, i);
				cost.push_back(cost_from_src);
			}

			return cost;
		} else {
			if (algh == 'J') {
				std::vector<std::vector<int> > cost;

				for (unsigned int i = 0; i < graph.size(); ++i) {
					std::vector<int> help;
					for (unsigned int k = 0; k < graph.size(); ++k) {
						help.push_back(INF);
					}

					help[i] = 0;

					for (unsigned int j = 0; j < graph[i].size(); ++j) {
						help[graph[i][j].first] = graph[i][j].second;
					}
					cost.push_back(help);
				}

				Johnson(graph, cost);

				return cost;
			} else {
				return std::vector<std::vector<int> >();
			}
		}
	}
}
