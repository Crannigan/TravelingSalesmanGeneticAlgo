#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>

#include "graph.h"
#include "create_city_map.h"
#include "calculateFitness.h"
#include "genePool.h"

using namespace std;

void outputVec(vector<int> outputText, map<string, Graph> distanceMap, map<int, string> cityIndex);

int main(int argc, char** argv)	{
	if(argc < 5 || argc > 5)	{
		cout << "You do not have the correct input parameters" << endl;
	}

	map<int, string> cityIndex;
	map<string, Graph> distanceMap;
	Graph hold;
	int gensCount, geneCount;
	vector<int> base_path, temp_path;
	string starting_city;
	genePool main_pool, next_pool;
	Gene tempGene;
	
	// Create Base Map with Distances Between Cities and Initialize Inputs
	cityIndex = listCityNames(argv[1]);
	distanceMap = create_city_map(argv[1], argv[2]);
	geneCount = stoi(argv[3]);
	gensCount = stoi(argv[4]);
	starting_city = cityIndex[0];

	// Create Base Path of 1-N, exclude 0 because this is the starting and ending city
	for(int i = 1; i < cityIndex.size(); i++)	{
		base_path.push_back(i);
	}

	// Create Initial Gene Pool
	for(int i = 0; i < geneCount; i++)	{
		temp_path = base_path;
		random_shuffle(temp_path.begin(), temp_path.end());
		tempGene = Gene(temp_path);
		tempGene.setFitness(calculateFitness(distanceMap, temp_path, cityIndex));
		main_pool.addGene(tempGene);
	}

	for(int i = 0; i < 10; i++)	{
		outputVec(main_pool.getGeneAtIndex(i).getGene(), distanceMap, cityIndex);
	}

	cout << "\n" << main_pool.getPoolSize() << endl;

	return 0;
}

void outputVec(vector<int> outputText, map<string, Graph> distanceMap, map<int, string> cityIndex)	{
	for(int i = 0; i < outputText.size(); i++)	{
		cout << outputText[i] << " ";
	}
	cout << " : " << calculateFitness(distanceMap, outputText, cityIndex) << endl;
}