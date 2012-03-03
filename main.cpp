#include <iostream>
#include <string.h>
#include "AStar.h"
#include "Dijkstra.h"

int main(int argc, char *argv[]){
	using AStar::BaseAStar;
	using AStar::Dijkstra;
	using AStar::AStar;
	

	BaseAStar* clazz;
	if (strcmp(argv[argc - 1], "AStar") == 0){
		clazz = new AStar();
	}
	if (strcmp(argv[argc - 1], "Dijkstra") == 0){
		clazz = new Dijkstra();
	}
	clazz->calculate();
	delete (clazz);

	return 0;
}