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
		cin >> n >> m >> start_city >> finish_city;
		//convert to zero based indexes
		--start_city; --finish_city;

		evaluation.assign(n, -1.0);
		came_from.assign(n, -1);

		positions.resize(n);
		roads.resize(n);

		//read cities coordinates
		for(size_t i = 0; i != n; ++i){
			cin >> positions[i].first >> positions[i].second;
		}

		//read roads
		for(size_t i = 0; i != m; ++i){
			size_t q, w;
			cin >> q >> w;
			roads[--q].push_back(--w);
			roads[w].push_back(q);
		}

#ifdef _FREOPEN_READ
		fclose(stdin);
#endif
	}

	size_t BaseAStar::citiesCount(){
		return positions.size();
	}

	double BaseAStar::distance(size_t from, size_t to){
		return sqrt((double)((positions[from].first - positions[to].first) * (positions[from].first - positions[to].first) + 
			(positions[from].second - positions[to].second) * (positions[from].second - positions[to].second)));
	}

	void BaseAStar::calculate(){
		bool* closed_set = new bool[citiesCount()];
		std::fill(closed_set, closed_set + citiesCount(), false);
		priority_queue<QueueNode, vector<QueueNode>, std::greater<QueueNode> > open_set;
		//create start node
		QueueNode node;
		node.traveledDistance = 0;
		node.cityNumber = start_city;
		node.funcG = heuristicCostEstimate(start_city);
		open_set.push(node);
		evaluation[start_city] = 0;

		while (open_set.size()){
			node = open_set.top();
			if (node.cityNumber == finish_city){
				print_result();
				delete[] closed_set;
				return;
			}
			open_set.pop();

			//skip, if we already used better way
			if (node.traveledDistance > evaluation[node.cityNumber]) continue;

			closed_set[node.cityNumber] = true;

			for(size_t i = 0; i != roads[node.cityNumber].size(); i++){
				size_t aim_city = roads[node.cityNumber][i];
				if (closed_set[aim_city]) continue;
				double tentative_distance = node.traveledDistance + distance(node.cityNumber, aim_city);

				if (evaluation[aim_city] == -1 || evaluation[aim_city] > tentative_distance){
					QueueNode tmp;
					tmp.cityNumber = aim_city;
					evaluation[aim_city] = tmp.traveledDistance = tentative_distance;
					came_from[aim_city] = node.cityNumber;
					tmp.funcG = tentative_distance + heuristicCostEstimate(aim_city);

					open_set.push(tmp);
				}
			}
		}
		delete[] closed_set;
	}

	void BaseAStar::print_result(){
		cout << evaluation[finish_city] << endl;
		vector<size_t> cities_path;

		for(size_t i = finish_city; i != -1; i=came_from[i]){
			cities_path.push_back(i + 1);
		}

		cout << cities_path.size() << endl;

		for(vector<size_t>::reverse_iterator it = cities_path.rbegin(); it != cities_path.rend(); ++it){
			cout << *it << ' ';
		}

		cout << endl;
	}
}