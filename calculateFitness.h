using namespace std;

int calculateFitness(map<string, Graph> city_dist_map, vector<int> path, 
					map<int, string> index_to_city)	{

	int total = 0;
	Graph hold;
	string city_one, city_two;
	for(int i = 0; i < path.size() - 1; i++)	{
		city_one = index_to_city[path[i]];
		city_two = index_to_city[path[i+1]];
		hold = city_dist_map[city_one];
		total += hold.getDistance(city_two);
	}

	hold = city_dist_map[index_to_city[0]];
	total += hold.getDistance(index_to_city[path[0]]);
	total += hold.getDistance(index_to_city[path[path.size()-1]]);

	return total*-1;
}