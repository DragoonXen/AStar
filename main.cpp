#include <iostream>
#include <string.h>
#include <vector>
#include "AStar.h"
#include "Number.h"
#include "City.h"
#include <cstdlib>

//#define _FREOPEN_READ
#ifdef _FREOPEN_READ
#include <stdio.h>
#endif

int main(int argc, char *argv[]){
	using AStar::BaseAStar;
	using AStar::Dijkstra;
	using AStar::Number;
	using AStar::City;
	using AStar::AStar;

	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;
	
	vector<City*> cities;
#ifdef _FREOPEN_READ
		freopen("input.txt","r",stdin);
#endif
		size_t n, m;
		size_t start_city_nom, finish_city_nom;
		cin >> n >> m >> start_city_nom >> finish_city_nom;
		//convert to zero based indexes
		--start_city_nom; --finish_city_nom;

		cities.reserve(n);

		//read cities_ coordinates
		for(size_t i = 0; i != n; ++i){
			cities.push_back(new City(i));
		}

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

	BaseAStar* obj = NULL;
	if (strcmp(argv[argc - 1], "AStar") == 0){
		obj = new AStar(cities, start_city_nom, finish_city_nom);
	}
	if (strcmp(argv[argc - 1], "Dijkstra") == 0){
		obj = new Dijkstra(cities, start_city_nom, finish_city_nom);
	}
	if (strcmp(argv[argc - 1], "Number") == 0){
		obj = new Number(cities, start_city_nom, finish_city_nom);
	}

	vector<City*> path;

	if (obj != NULL){
		path = obj->calculate();
		delete (obj);

		if (path.size()){
			cout.setf(std::ios_base::fixed);
			cout.precision(6);
			cout << path.front()->distance_evaluation() << endl;

			cout << path.size() - 1 << endl;

			for(vector<City*>::reverse_iterator i = path.rbegin(); i != path.rend(); ++i){
				cout << (*i)->number() + 1 <<' ';
			}
			cout << endl;
		}
	} else {
		std::cout << "algorithm with name " << argv[argc - 1] << " not found." << std::endl;
	}

	return 0;
}