#ifndef QUEUE_NODE_H_
#define QUEUE_NODE_H_

namespace AStar{
struct QueueNode{
	double traveledDistance;
	double funcG; //funcG = traveledDistance + heuristicDistance;
	size_t cityNumber;

	bool operator > (const QueueNode &other) const;

};
}
#endif
