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

void outputVec(Gene thisGene, map<int, string> cityIndex);

int main(int argc, char** argv)	{
	if(argc < 5 || argc > 5)	{
		cout << "You do not have the correct input parameters" << endl;
	}

	srand (time(NULL));

	map<int, string> cityIndex;
	map<string, Graph> distanceMap;
	Graph hold;
	int gensCount, geneCount;
	vector<int> base_path, temp_path;
	string starting_city;
	genePool main_pool;
	Gene tempGene, cross1, cross2;
	
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

	// Calculate each generation after the first up to gensCount
	for(int i = 0; i < gensCount; i++)	{
		genePool next_pool;
		main_pool.addTenBestToNext(next_pool);
	
		while(next_pool.getPoolSize() < geneCount)	{
			main_pool.getCrossovered(cross1, cross2);
			cross1.setFitness(calculateFitness(distanceMap, cross1.getGene(), cityIndex));
			cross2.setFitness(calculateFitness(distanceMap, cross2.getGene(), cityIndex));
			next_pool.addGene(cross1);
			next_pool.addGene(cross2);
		}
		main_pool.clear();
		main_pool = next_pool;
		if(i%5 == 0)	{
			cout << "Completed " << i << " out of " << gensCount << " generations." << endl;
		}
	}

	outputVec(main_pool.getGeneAtIndex(0), cityIndex);

	return 0;
}

void outputVec(Gene thisGene, map<int, string> cityIndex)	{
	vector<int> outputText = thisGene.getGene();
	int fitness = thisGene.getFitness();
	for(int i = 0; i < outputText.size(); i++)	{
		cout << outputText[i] << " ";
	}
	cout << ": " << fitness*-1 << endl;
}