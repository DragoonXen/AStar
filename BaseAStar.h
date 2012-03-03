#ifndef BASE_A_STAR_H_
#define BASE_A_STAR_H_
#include "City.h"

#include <cstdlib>
#include <vector>

namespace AStar{
using std::vector;
using std::pair;

class BaseAStar{
private:
	vector<City*> generate_path();
protected:
	vector<City*> cities_;
	City *start_city;
	City *finish_city;
	virtual double distance(City *from, City *to);
	virtual double heuristicCostEstimate(City *from) = 0;

public:
	BaseAStar(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom);
	size_t citiesCount();
	vector<City*> calculate();
	vector<City*> cities();
	
};
}

#endif