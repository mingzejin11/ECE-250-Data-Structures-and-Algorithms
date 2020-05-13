// Author: Mingze Jin (November 2019)
// Graph header file
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "linkedlist.h"
using namespace std;

struct city {
	string name;
	int degree;
	int numUnvisited;
	bool visited;
	double tentativeD;
	Path *path = new Path;
	int length;
	LinkedList *nodes = new LinkedList;
};

class Graph {
public:
	// Stores the cities in an array 
	city* cities = new city[0];
	int numberOfEdges;
	int numberOfCities;
	int lengthOfPath;

	// Constructor
	Graph();

	// Class functions specified by the project guidelines
	void i(string cityInsert);
	void setd(string city1, string city2, double d);
	int s(string citySearch);
	int degree(string cityDegree);
	int graph_nodes();
	int graph_edges();
	void d(string city1, string city2);
	string* shortest_d(string city1, string city2, bool print);
	void print_path(string* p);
	void clear();
};

#endif