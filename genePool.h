using namespace std;

#include "gene.h"

class genePool	{
private:
	vector<Gene> my_list;

	void sortVector(vector<Gene>& sortThis);

	int binaryFindPosConstruct(Gene geneNeedPos);

	int binaryFindPos(int fitness, int start, int end);

	vector<Gene> generateRandomTenGenes();

	vector<Gene> getFourBest(vector<Gene> tenRandom);

	Gene randomGene(vector<Gene>& genesList);

	void crossOverGenes(Gene& gene1, Gene& gene2);

	void fixGene(Gene& fixThisGene);
public:
	genePool();

	int getPoolSize();

	void addGene(Gene newGene);

	Gene getGeneAtIndex(int index);

	void addTenBestToNext(genePool& addHere);

	void getCrossovered(Gene& cross1, Gene& cross2);

	void clear();
};