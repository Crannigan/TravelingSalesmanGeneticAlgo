using namespace std;

class Gene	{
private:
	vector<int> sequence;
	int fitness;
public:
	Gene();

	Gene(vector<int> new_seq);

	void addSequence(vector<int> new_seq);

	void setFitness(int fit);

	int getFitness();

	vector<int> getGene();

	void assignCity(int pos, int val);

	int getCity(int pos);
};