#ifndef A_STAR_H_
#define A_STAR_H_

#include "BaseAStar.h"

namespace AStar{
class AStar : public BaseAStar {

public:
	AStar();
	virtual ~AStar();

private:
	double* distance_array_;
	double heuristicCostEstimate(City *from);
};
}

#endif
