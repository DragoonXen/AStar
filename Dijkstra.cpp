#include "Dijkstra.h"

namespace AStar{

Dijkstra::Dijkstra(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom): BaseAStar(cities, start_city_nom, finish_city_nom){
}

double Dijkstra::heuristicCostEstimate(City *from){
	return 0.0;
}

}