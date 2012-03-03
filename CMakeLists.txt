cmake_minimum_required (VERSION 2.6) 
project (HMEinit) 
add_definitions(-O5 -static)
add_executable(AStar main.cpp AStar.cpp BaseAStar.cpp City.cpp Dijkstra.cpp Number.cpp QueueNode.cpp)
