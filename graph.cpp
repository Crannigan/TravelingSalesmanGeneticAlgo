#include <iostream>
#include <map>
#include <string>

#include "graph.h"

using namespace std;

Graph::Graph()	{}

Graph::Graph(string city_name)	{
	this->curr_name = city_name;
}

string Graph::getCity()	{
	return this->curr_name;
}

void Graph::addDistance(string city_name, int distance)	{
	city_distances[city_name] = distance;
}

int Graph::getDistance(string city_name)	{
	return city_distances[city_name];
}