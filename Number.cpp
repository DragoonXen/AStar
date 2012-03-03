#include "Number.h"

namespace AStar{

Number::Number(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom): Dijkstra(cities, start_city_nom, finish_city_nom){
}

double Number::distance(City *from, City *to){
	return 1.0;
}

}
