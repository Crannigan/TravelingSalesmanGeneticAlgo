map<int, string> listCityNames(string filename)	{
	map<int, string> city_index;
	string get_var;
	int counter = 0;
	ifstream myfile;
	myfile.open(filename);
	while(myfile >> get_var)	{
		city_index[counter] = get_var;
		counter++;
	}

	myfile.close();
	return city_index;
}

map<string, Graph> create_base_map(string filename)	{
	map<string, Graph> distance_map;
	ifstream myfile;
	myfile.open(filename);
	string get_var;
	while(myfile >> get_var)	{
		distance_map[get_var] = Graph(get_var);
	}
	myfile.close();


	return distance_map;
}

map<string, Graph> create_city_map(string filename1, string filename2)	{
	map<string, Graph> distance_map = create_base_map(filename1);
	ifstream myfile;
	myfile.open(filename2);
	string start_city, end_city;
	int dist;
	Graph hold;
	while(myfile >> start_city)	{
		hold = distance_map[start_city];
		myfile >> end_city;
		myfile >> dist;
		hold.addDistance(end_city, dist);
		distance_map[start_city] = hold;
	}
	
	return distance_map;
}