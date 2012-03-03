#include "City.h"

#include <math.h>
#include <iostream>

namespace AStar{

using std::cin;

City::City(size_t number){
	this->number_ = number;
	cin >> coord_x >> coord_y;
	distance_evaluation_ = -1.0;
	came_from_ = NULL;
	closed_ = false;
}

double City::distance(City *other){
	return sqrt(double((coord_x - other->coord_x)*(coord_x - other->coord_x)
		+ (coord_y - other->coord_y)*(coord_y - other->coord_y)));
}
void City::addRoad(City *other){
	roads.push_back(other);
}

double City::distance_evaluation(){
	return distance_evaluation_;
}

void City::distance_evaluation(double value){
	this->distance_evaluation_ = value;
}

bool City::closed(){
	return closed_;
}

void City::closed(bool value){
	this->closed_ = value;
}

City* City::came_from(){
	return came_from_;
}

void City::came_from(City *value){
	came_from_ = value;
}

size_t City::number(){
	return number_;
}

}
