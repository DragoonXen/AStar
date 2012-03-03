#include "QueueNode.h";

namespace AStar{
	bool QueueNode::operator > (const QueueNode &other) const{
		return funcG > other.funcG;
	}
}