// Author: Mingze Jin (November 2019)
// Graph file
#include <iostream>
#include <array>
#include "undirectedGraph.h"
using namespace std;

Graph::Graph() {
	// Set the initial values for the number of edges and nodes
	numberOfEdges = 0;
	numberOfCities = 0;
	lengthOfPath = 0;
}

void Graph::i(string cityInsert) {
	// Error case for when the city doesn't exist
	if (s(cityInsert) != -1) {
		cout << "failure" << endl;
	} else {
		// Create a temporary array
		city* temp = new city[numberOfCities + 1];
		
		// Copy over all the information into the temporary array
		for (int i = 0; i < numberOfCities; i ++) {
			temp[i] = cities[i];
		}
		
		// Create a new city and assign its attributes
		city* newCity = new city;
		newCity->name = cityInsert;
		newCity->degree = 0;
		newCity->numUnvisited = 0;
		newCity->visited = false;
		newCity->tentativeD = 999999999;
		newCity->length = 0;

		// Push the new city into the array
		temp[numberOfCities] = *newCity;
		numberOfCities ++;
		cities = temp;

		// Delete the temporary array
		delete[] temp;
		cout << "success" << endl;
	}
}

void Graph::setd(string city1, string city2, double d) {
	int city1index = s(city1);
	int city2index = s(city2);

	// Check if the cities exist
	if (city1index != -1 && city2index != -1) {
		numberOfEdges ++;
		// Update the adjacency list of city 1
		bool city1insert = cities[city1index].nodes->enqueue(city2, d, city2index);
		// Check if the distance being set is fresh, or if it's overriding a previous command
		if (city1insert) {
			cities[city1index].degree ++;
			cities[city1index].numUnvisited ++;
		}

		// Update city 2 by repeating the same process for city 1
		bool city2insert = cities[city2index].nodes->enqueue(city1, d, city1index);
		if (city2insert) {
			cities[city2index].degree ++;
			cities[city2index].numUnvisited ++;
		}
		
		cout << "success" << endl;
	} else {
		cout << "failure" << endl;
	}
}

int Graph::s(string citySearch) {
	// Loop through the city array, searching for the specified city
	for (int i = 0; i < numberOfCities; i ++) {
		if (cities[i].name == citySearch) {
			// If found, return the index
			return i;
		}
 	}
	
	// Otherwise return an error signal
	return -1;
} 

int Graph::degree(string cityDegree) {
	// Loop through the city array, searching for the specified city
	for (int i = 0; i < numberOfCities; i ++) {
		if (cities[i].name == cityDegree) {
			return cities[i].degree;
		}
 	}

	// If not found then return error signal
	return -1;
}

int Graph::graph_nodes() {
	return numberOfCities;
}

int Graph::graph_edges() {
	return numberOfEdges;
}

void Graph::d(string city1, string city2) {
	int city1index = s(city1);
	double result = cities[city1index].nodes->search(city2);

	if (result != -1) {
		cout << "direct distance " << city1 << " to " << city2 << " " << result << endl;
	} else {
		cout << "failure" << endl;
	}
}

string* Graph::shortest_d(string city1, string city2, bool print) {
	int city1index = s(city1);
	int city2index = s(city2);
	static string shortest_path[100];

	// Error case when cities aren't found
	if ((city1index == -1 || city2index == -1) && print) {
		cout << "failure" << endl;
		return shortest_path;
	} else if (city1index == -1 || city2index == -1) {
		return shortest_path;
	}

	// Case when destination is source 
	if (city1index == city2index) {
		shortest_path[0] = city1;
		shortest_path[1] = city2;
		shortest_path[99] = "yay";
		lengthOfPath = 1;

		if (print) {
			cout << "shortest distance " << city1 << " to " << city2 << " " << 0 << endl;
		}

		return shortest_path;
	}

	// Source is always already visited
	int currIndex = city1index;
	int minIndex;
	cities[city1index].tentativeD = 0;
	cities[city1index].path->enqueue(city1, 0);

	// Dijkstra's algorithm
	int tempIndex;
	double tempDistance;
	int tempLength;
	int loops = cities[currIndex].degree;

	if (loops == 0) {
		if (print) {
			cout << "failure" << endl;
		}

		return shortest_path;
	}

	for (int i = 0; i < loops; i ++) {
		// Make sure visited nodes aren't being checked again
		while (cities[cities[currIndex].nodes->returnIndex(i)].visited) {
			i ++;
		}

		// Set 3 variables for readability
		tempIndex = cities[currIndex].nodes->returnIndex(i);
		tempDistance = cities[currIndex].nodes->returnDistance(i); 
		tempLength = cities[currIndex].length;

		// Decrement the number of unvisited cities
		if (cities[currIndex].numUnvisited != 0) {
			cities[currIndex].numUnvisited --;
			cities[tempIndex].numUnvisited --;
		}

		// Check if the tentative distance needs to be updated
		if (cities[tempIndex].tentativeD > tempDistance + cities[currIndex].tentativeD && !cities[tempIndex].visited) {
			cities[tempIndex].tentativeD = cities[currIndex].tentativeD + tempDistance;
			
			// Record the shortest path to this city
			for (int j = 0; j <= tempLength; j ++) {
				cities[tempIndex].path->enqueue(cities[currIndex].path->search(j), j);
			}

			cities[tempIndex].length = tempLength + 1;
			cities[tempIndex].path->enqueue(cities[tempIndex].name, cities[tempIndex].length);
		}

		if (cities[tempIndex].numUnvisited == 0) {
			cities[tempIndex].visited = true;
		}

		// If done checking all neighbours, update current index
		if (i >= cities[currIndex].degree - 1 || cities[currIndex].numUnvisited == 0) {
			cities[currIndex].visited = true;
			int unreachable = 0;
			

			// Search for next shortest path
			for (int j = 0; j < numberOfCities; j ++) {
				if (!cities[j].visited && cities[j].tentativeD < cities[tempIndex].tentativeD) {
					tempIndex = j;
				}
			}

			// Update current index to the new minimum
			currIndex = tempIndex;
			i = -1;
		 	loops = cities[currIndex].degree;
		}

		// Check if destination is found
		if (cities[city2index].visited) {
			i = cities[currIndex].degree;
			shortest_path[99] = "yay";
			continue; 
		}
	}

	lengthOfPath = cities[city2index].length;

	// Copy final path into output array
	if (shortest_path[99] == "yay") {
		for (int i = 0; i <= lengthOfPath; i ++) {
			shortest_path[i] = cities[city2index].path->search(i);
		}
	}
	
	// Check if the function should print the success message
	if (print && shortest_path[99] == "yay") {
		cout << "shortest distance " << city1 << " to " << city2 << " " << cities[city2index].tentativeD << endl;
	}

	// Reset the visited and tentative distance values
	for (int i = 0; i < numberOfCities; i ++) {
		cities[i].visited = false;
		cities[i].tentativeD = 999999999;
		cities[i].numUnvisited = cities[i].degree;

		for (int j = 0; j < 100; j ++) {
			cities[i].path->reset();
		}
	}

	return shortest_path;
}

void Graph::print_path(string* p) {
	if (*(p + 99) == "yay") {
		for (int i = 0; i <= lengthOfPath; i ++) {
			cout << *(p + i) << " ";
		}

		cout << endl;
	} else {
		cout << "failure" << endl;
	}
}

void Graph::clear() {
	// Reset variables that store number of edges and nodes
	numberOfEdges = 0;
	numberOfCities = 0;
	lengthOfPath = 0;

	// Create a new empty array and delete the current one containing the cities
	city* temp = new city[0];
	delete[] cities;
	cities = temp;
	delete[] temp;

	cout << "success" << endl;
}