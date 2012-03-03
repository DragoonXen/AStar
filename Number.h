#ifndef NUMBER_H_
#define NUMBER_H_

#include "Dijkstra.h"

namespace AStar{
class Number : public Dijkstra {

public:
	Number(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom);
protected:
	virtual double distance(City *from, City *to);
};

}


#endif