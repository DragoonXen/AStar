#ifndef BASE_A_STAR_H_
#define BASE_A_STAR_H_
#include "City.h"

#include <vector>

namespace AStar{
using std::vector;
using std::pair;

class BaseAStar{
private:
	void print_result();
protected:
	vector<City*> cities;
	City *start_city;
	City *finish_city;
	virtual double distance(City *from, City *to);
	virtual double heuristicCostEstimate(City *from) = 0;

public:
	BaseAStar();
	size_t citiesCount();
	void calculate();
	
};
}

#endif