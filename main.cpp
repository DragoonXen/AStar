#include <iostream>
#include "AStar.h"

int main(int argc, char *argv[]){
	using AStar::BaseAStar;
	using AStar::AStar;

	BaseAStar* clazz = new AStar();
	clazz->calculate();
	delete (clazz);

	return 0;
}