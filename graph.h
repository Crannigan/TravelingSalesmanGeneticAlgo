using namespace std;

class Graph	{
private:
	map<string, int> city_distances;
	string curr_name;
public:
	Graph();

	Graph(string city_name);

	string getCity();

	void addDistance(string city_name, int distance);

	int getDistance(string city_name);
};