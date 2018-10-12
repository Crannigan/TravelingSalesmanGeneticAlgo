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
#include "calculateFitness.h"

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

	return 0;
}