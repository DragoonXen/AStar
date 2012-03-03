#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "BaseAStar.h"

namespace AStar{
class Dijkstra : public BaseAStar {

protected:
	double heuristicCostEstimate(City *from);
};

}


#endif