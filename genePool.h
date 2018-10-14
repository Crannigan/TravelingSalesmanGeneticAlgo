using namespace std;

#include "gene.h"

class genePool	{
private:
	vector<Gene> my_list;

	int binaryFindPosConstruct(Gene geneNeedPos);

	int binaryFindPos(int fitness, int start, int end);
public:
	genePool();

	int getPoolSize();

	void addGene(Gene newGene);

	Gene getGeneAtIndex(int index);
};