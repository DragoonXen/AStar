#include "BaseAStar.h"
#include "QueueNode.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <iostream>

#define _FREOPEN_READ
#ifdef _FREOPEN_READ
#include <stdio.h>
#endif

namespace AStar{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::priority_queue;

	BaseAStar::BaseAStar(){
#ifdef _FREOPEN_READ
		freopen("input.txt","r",stdin);
#endif
		size_t n, m;
		size_t start_city_nom, finish_city_nom;
		cin >> n >> m >> start_city_nom >> finish_city_nom;
		//convert to zero based indexes
		--start_city_nom; --finish_city_nom;

		cities.reserve(n);

		//read cities coordinates
		for(size_t i = 0; i != n; ++i){
			cities.push_back(new City(i));
		}
		start_city = cities[start_city_nom];
		finish_city = cities[finish_city_nom];

		//read roads
		for(size_t i = 0; i != m; ++i){
			size_t q, w;
			cin >> q >> w;
			cities[--q]->addRoad(cities[--w]);
			cities[w]->addRoad(cities[q]);
		}

#ifdef _FREOPEN_READ
		fclose(stdin);
#endif
	}

	size_t BaseAStar::citiesCount(){
		return cities.size();
	}

	double BaseAStar::distance(City *from, City *to){
		return from->distance(to);
	}

	void BaseAStar::calculate(){
		priority_queue<QueueNode, vector<QueueNode>, std::greater<QueueNode> > open_set;
		//create start node
		QueueNode node;
		node.traveledDistance = 0;
		node.city = start_city;
		node.funcG = heuristicCostEstimate(start_city);
		open_set.push(node);
		start_city->distance_evaluation(0.0);

		while (open_set.size()){
			node = open_set.top();
			if (node.city == finish_city){
				print_result();
				return;
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
					tmp.funcG = tentative_distance + heuristicCostEstimate(aim_city);

					open_set.push(tmp);
				}
			}
		}
	}

	void BaseAStar::print_result(){
		cout << finish_city->distance_evaluation() << endl;
		vector<size_t> cities_path;

		for(City *i = finish_city; i != NULL; i = i->came_from()){
			cities_path.push_back(i->number() + 1);
		}

		cout << cities_path.size() << endl;

		for(vector<size_t>::reverse_iterator it = cities_path.rbegin(); it != cities_path.rend(); ++it){
			cout << *it << ' ';
		}

		cout << endl;
	}
}