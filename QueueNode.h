#ifndef QUEUE_NODE_H_
#define QUEUE_NODE_H_
#include "City.h"

namespace AStar{
struct QueueNode{
	double traveledDistance;
	double funcG; //funcG = traveledDistance + heuristicDistance;
	City* city;

	bool operator > (const QueueNode &other) const;

};
}
#endif
