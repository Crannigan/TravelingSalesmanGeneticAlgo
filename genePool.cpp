#include <iostream>
#include <vector>

#include "genePool.h"

using namespace std;

genePool::genePool()	{}

int genePool::getPoolSize()	{
	return this->my_list.size();
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
	this->my_list.insert(my_list.begin()+binaryAddPos, newGene);
}

Gene genePool::getGeneAtIndex(int index)	{
	return this->my_list[index];
}