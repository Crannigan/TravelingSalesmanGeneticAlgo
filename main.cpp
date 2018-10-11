#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "create_city_map.h"

using namespace std;

int main(int argc, char** argv)	{
	if(argc < 5 || argc > 5)	{
		cout << "You do not have the correct input parameters" << endl;
	}

	map<int, string> city_index;
	map<string, Graph> distance_map;
	Graph hold;
	
	city_index = listCityNames(argv[1]);
	distance_map = create_city_map(argv[1], argv[2]);

	for(int i = 0; i < city_index.size(); i++)	{
		for(int j = 0; j < city_index.size(); j++)	{
			if(i == j)	{
				continue;
			}
			hold = distance_map[city_index[i]];
			cout << city_index[i] << " " << city_index[j] << " " << hold.getDistance(city_index[j]) << endl;
		}
	}

	return 0;
}