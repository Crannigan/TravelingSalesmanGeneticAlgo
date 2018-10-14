#include <iostream>
#include <vector>
#include <list>

#include "gene.h"

using namespace std;

Gene::Gene()	{}

Gene::Gene(vector<int> new_seq)	{
	this->sequence = new_seq;
}

void Gene::addSequence(vector<int> new_seq)	{
	this->sequence = new_seq;
}

void Gene::setFitness(int fit)	{
	this->fitness = fit;
}

int Gene::getFitness()	{
	return this->fitness;
}

vector<int> Gene::getGene()	{
	return this->sequence;
}