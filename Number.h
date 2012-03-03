#ifndef NUMBER_H_
#define NUMBER_H_

#include "Dijkstra.h"

namespace AStar{
class Number : public Dijkstra {

protected:
	double distance(City *from, City *to);
};

}


#endif