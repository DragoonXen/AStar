#ifndef A_STAR_H_
#define A_STAR_H_

#include "BaseAStar.h"

namespace AStar{
class AStar : public BaseAStar {

public:
	AStar(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom);
	virtual ~AStar();

private:
	double* distance_array_;
	virtual double heuristicCostEstimate(City *from);
};
}

#endif
