#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "genePool.h"

using namespace std;

void outputVec(vector<int> outputText, int fitness);

genePool::genePool()	{}

int genePool::getPoolSize()	{
	return this->my_list.size();
}

void genePool::clear()	{
	this->my_list.clear();
}

void genePool::sortVector(vector<Gene>& sortThis)	{
	// Basic Insertion Sort (Needs to be improved to quicksort I'm just lazy atm)
	Gene temp;
	int location;
	for(int i = 0; i < sortThis.size()-1; i++)	{
		temp = sortThis[i];
		location = i;
		for(int j = i+1; j < sortThis.size(); j++)	{
			if(temp.getFitness() < sortThis[j].getFitness())	{
				temp = sortThis[j];
				location = j;
			}
		}
		sortThis[location] = sortThis[i];
		sortThis[i] = temp;
	}
}

int genePool::binaryFindPosConstruct(Gene geneNeedPos)	{
	return binaryFindPos(geneNeedPos.getFitness(), 0, this->my_list.size());
}

int genePool::binaryFindPos(int fitness, int start, int end)	{
	int midpoint = (start + end)/2;
	if(midpoint == start)	{
		if(fitness > this->my_list[start].getFitness())	{
			return start;
		}
		return start + 1;
	}
	if(fitness < this->my_list[midpoint].getFitness())	{
		return binaryFindPos(fitness, midpoint, end);
	}	else if(fitness > this->my_list[midpoint].getFitness())	{
		return binaryFindPos(fitness, start, midpoint);
	}	else	{
		return midpoint;
	}
}

void genePool::addGene(Gene newGene)	{
	if(getPoolSize() == 0)	{
		this->my_list.push_back(newGene);
		return;
	}
	int binaryAddPos = binaryFindPosConstruct(newGene);
	if(newGene.getFitness() == my_list[binaryAddPos].getFitness())	{
		return;
	}
	if(newGene.getFitness() == my_list[binaryAddPos-1].getFitness())	{
		return;
	}
	this->my_list.insert(my_list.begin()+binaryAddPos, newGene);
}

Gene genePool::getGeneAtIndex(int index)	{
	return this->my_list[index];
}

void genePool::addTenBestToNext(genePool& addHere)	{
	for(int i = 0; i < 10; i++)	{
		addHere.addGene(this->my_list[i]);
	}
}

vector<Gene> genePool::getFourBest(vector<Gene> tenRandom)	{
	vector<Gene> fourBest;
	sortVector(tenRandom);
	for(int i = 0; i < 4; i++)	{
		fourBest.push_back(tenRandom[i]);
	}
	return fourBest;
}

Gene genePool::randomGene(vector<Gene>& genesList)	{
	int thisRand = rand()%genesList.size();
	Gene returnGene = genesList[thisRand];
	genesList.erase(genesList.begin()+thisRand);
	return returnGene;
}

vector<Gene> genePool::generateRandomTenGenes()	{
	vector<Gene> temp = this->my_list, pool;
	int myRand, this_size = this->my_list.size();
	for(int i = 0; i < 10; i++)	{
		myRand = rand() % this_size;
		pool.push_back(temp[myRand]);
		temp.erase(temp.begin()+myRand);
		this_size--;
	}

	return pool;
}

void genePool::crossOverGenes(Gene& gene1, Gene& gene2)	{
	// I'm choosing to crossover at a random point each time.
	// I want it to be alteast 3 in every time though, can be changed.
	int crossPoint = ((rand()%(gene1.getGene().size()-3))+3), hold;
	for(int i = crossPoint; i < gene1.getGene().size(); i++)	{
		hold = gene1.getCity(i);
		gene1.assignCity(i, gene2.getCity(i));
		gene2.assignCity(i, hold);
	}
	fixGene(gene1);
	fixGene(gene2);
}

void genePool::fixGene(Gene& fixThisGene)	{
	vector<int> stillNotUsedList, fixGeneVec = fixThisGene.getGene();
	int vecSize = fixGeneVec.size(), notUsed, counter = 0, myRand;
	for(int i = 1; i <= vecSize; i++)	{
		stillNotUsedList.push_back(i);
	}
	for(int i = 0; i < vecSize; i++)	{
		notUsed = stillNotUsedList[fixThisGene.getCity(i)-1];
		if(notUsed == -1)	{
			fixThisGene.assignCity(i, -1);
		}	else	{
			stillNotUsedList[fixThisGene.getCity(i)-1] = -1;
		}
	}
	while(counter < stillNotUsedList.size())	{
		if(stillNotUsedList[counter] == -1)	{
			stillNotUsedList.erase(stillNotUsedList.begin()+counter);
		}	else	{
			counter++;
		}
	}
	for(int i = 0; i < fixGeneVec.size(); i++)	{
		if(fixThisGene.getCity(i) == -1)	{
			myRand = rand()%stillNotUsedList.size();
			fixThisGene.assignCity(i, stillNotUsedList[myRand]);
			stillNotUsedList.erase(stillNotUsedList.begin()+myRand);
		}
	}
}

void genePool::getCrossovered(Gene& cross1, Gene& cross2)	{
	vector<Gene> tempPool = generateRandomTenGenes();
	tempPool = getFourBest(tempPool);
	cross1 = randomGene(tempPool);
	cross2 = randomGene(tempPool);
	crossOverGenes(cross1, cross2);
}

void outputVec(vector<int> outputText, int fitness)	{
	for(int i = 0; i < outputText.size(); i++)	{
		cout << outputText[i] << " ";
	}
	cout << ": " << fitness << endl;
}