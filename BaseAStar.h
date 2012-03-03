#ifndef BASE_A_STAR_H_
#define BASE_A_STAR_H_

#include <vector>
namespace AStar{
using std::vector;
using std::pair;

class BaseAStar{
private:
	void print_result();
protected:
	vector<vector<size_t> > roads;
	vector<pair<size_t, size_t> > positions; //cities coordinates
	size_t start_city, finish_city;
	vector<size_t> came_from;
	
	vector<double> evaluation; //evaluation of minimum distance, traveled to this city from start

	double distance(size_t from, size_t to);
	virtual double heuristicCostEstimate(size_t from) = 0;

public:
	BaseAStar();
	size_t citiesCount();
	void calculate();
	
};
}

#endif