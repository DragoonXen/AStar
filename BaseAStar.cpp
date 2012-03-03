#include "BaseAStar.h"
#include "QueueNode.h"
#include <algorithm>
#include <math.h>
#include <queue>

namespace AStar{
	BaseAStar::BaseAStar(vector<City*> cities, size_t start_city_nom, size_t finish_city_nom){
		cities_.assign(cities.begin(), cities.end());
		start_city = cities_[start_city_nom];
		finish_city = cities_[finish_city_nom];
	}

	size_t BaseAStar::citiesCount(){
		return cities_.size();
	}

	double BaseAStar::distance(City *from, City *to){
		return from->distance(to);
	}

	vector<City*> BaseAStar::calculate(){
		std::priority_queue<QueueNode, vector<QueueNode>, std::greater<QueueNode> > open_set;
		//create start node
		QueueNode node;
		node.traveledDistance = 0;
		node.city = start_city;
		node.estimate_distance = heuristicCostEstimate(start_city);
		open_set.push(node);
		start_city->distance_evaluation(0.0);

		while (open_set.size()){
			node = open_set.top();
			if (node.city == finish_city){
				return generate_path();
			}
			open_set.pop();

			//skip, if we already used better way
			if (node.traveledDistance > node.city->distance_evaluation()) continue;

			node.city->closed(true);

			for(size_t i = 0; i != node.city->roads.size(); i++){
				City *aim_city = node.city->roads[i];
				if (aim_city->closed()) continue;

				double tentative_distance = node.traveledDistance + distance(node.city, aim_city);

				if (aim_city->distance_evaluation() == -1 || aim_city->distance_evaluation() > tentative_distance){
					QueueNode tmp;
					tmp.city = aim_city;
					aim_city->distance_evaluation(tmp.traveledDistance = tentative_distance);
					aim_city->came_from(node.city);
					tmp.estimate_distance = tentative_distance + heuristicCostEstimate(aim_city);

					open_set.push(tmp);
				}
			}
		}
		vector<City*> empty_path;
		return empty_path;
	}

	vector<City*> BaseAStar::generate_path(){
		vector<City*> cities_path;
		for(City *i = finish_city; i != NULL; i = i->came_from()){
			cities_path.push_back(i);
		}
		return cities_path;
	}
}