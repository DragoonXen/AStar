#ifndef CITY_H_
#define CITY_H_
#include <vector>

namespace AStar{
	using std::vector;
class City{
private:
	int coord_x;
	int coord_y;
	City* came_from_;
	double distance_evaluation_;
	size_t number_;
	bool closed_;//no need to calculate smth to & from this city
	
public:
	vector<City*> roads;
	City(size_t number);
	double distance(City *other);
	void addRoad(City *other);

	double distance_evaluation();
	void distance_evaluation(double value);
	bool closed();
	void closed(bool value);
	City* came_from();
	void came_from(City *value);
	size_t number();
};

}
#endif