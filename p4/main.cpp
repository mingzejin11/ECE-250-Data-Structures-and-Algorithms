// Author: Mingze Jin (November 2019)
// Graph testing file
#include <iostream>
#include "undirectedGraph.h"

int main() {
	string input;
	string command;
	Graph graph;

	string city;
	string city1;
	string city2;
	double d;
	int result;

	while (cin >> command) {
		// Commands with no parameters
		if (command == "graph_nodes") {
			cout << "number of nodes " << graph.graph_nodes() << endl;
		} else if (command == "graph_edges") {
			cout << "number of edges " << graph.graph_edges() << endl;
		} else if (command == "clear") {
			graph.clear();
		} else if (command == "i" || command == "s" || command == "degree") {
			// Commands with 1 parameter
			cin >> city;

			if (command == "i") {
				graph.i(city);
			} else if (command == "s") {
				if (graph.s(city) != -1) {
					cout << "found " << city << endl;
				} else {
					cout << "not found" << endl;
				}
			} else if (command == "degree") {
				result = graph.degree(city);
				if (result < 0) {
					cout << "failure" << endl;
				} else {
					cout << "degree of " << city << " " << graph.degree(city) << endl;
				}
			}
		} else if (command == "d" || command == "shortest_d" || command == "print_path") {
			// Commands with 2 parameters
			cin >> input;
			city1 = input.substr(0, input.find_first_of(";", 0));
			city2 = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));

			if (command == "d") {
				graph.d(city1, city2);
			} else if (command == "shortest_d") {
				graph.shortest_d(city1, city2, true);
			} else if (command == "print_path") {
				string* p = graph.shortest_d(city1, city2, false);
				graph.print_path(p);
			}
		} else if (command == "setd") {
			// Commands with 3 parameters
			cin >> input;
			city1 = input.substr(0, input.find_first_of(";", 0));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			city2 = input.substr(0, input.find_first_of(";", 0));
			d = stod(input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0)));

			graph.setd(city1, city2, d);
		} else {
			cout << "error: invalid command" << endl;
		}
	}

	return 0;
}