#include "QueueNode.h"

namespace AStar{
	bool QueueNode::operator > (const QueueNode &other) const{
		return estimate_distance > other.estimate_distance;
	}
}
