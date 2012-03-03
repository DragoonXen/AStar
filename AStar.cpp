#include "AStar.h";

namespace AStar{

AStar::AStar(){
	distance_array_ = new double[citiesCount()];
	for(size_t i = 0; i != citiesCount(); i++){
		distance_array_[i] = -1.0;
	}
}

AStar::~AStar(){
	delete[] distance_array_;
}

double AStar::heuristicCostEstimate(size_t from){
	if (distance_array_[from] == -1.0){
		distance_array_[from] = distance(from, finish_city);
	}
	return distance_array_[from];
}

}
