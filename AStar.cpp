#include "AStar.h"

namespace AStar{
AStar::AStar(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom): BaseAStar(cities, start_city_nom, finish_city_nom){
	distance_array_ = new double[citiesCount()];
	for(size_t i = 0; i != citiesCount(); i++){
		distance_array_[i] = -1.0;
	}
}

AStar::~AStar(){
	delete[] distance_array_;
}

double AStar::heuristicCostEstimate(City *from){
	if (distance_array_[from->number()] == -1.0){
		distance_array_[from->number()] = distance(from, finish_city);
	}
	return distance_array_[from->number()];
}

}
