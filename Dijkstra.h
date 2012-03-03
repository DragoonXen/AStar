#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "BaseAStar.h"

namespace AStar{
class Dijkstra : public BaseAStar {

public:
	Dijkstra(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom);

protected:
	virtual double heuristicCostEstimate(City *from);
};

}


#endif