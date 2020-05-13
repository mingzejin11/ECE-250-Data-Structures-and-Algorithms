// Author: Mingze Jin (November 2019)
// Quadtree test file
#include "quadtree.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string input;
	string command;
	Quadtree quadtree;
	city *root = nullptr;

	while (cin >> command) {
		if (command == "print") {
			quadtree.print(root);
			cout << endl;
			continue;
		} else if (command == "clear") {
			quadtree.clear(root);			
			cout << "success" << endl;
			root = nullptr;
			continue;
		} else if (command == "size") {
			cout << "tree size: " << quadtree.size() << endl;
			continue;
		}

		if (command == "i") {
			cin >> input;
			// parse the command line
			string name = input.substr(0, input.find_first_of(";", 0));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			float longitude = stof (input.substr(0, input.find_first_of(";", 0)));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			float latitude = stof (input.substr(0, input.find_first_of(";", 0)));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			int p = stoi (input.substr(0, input.find_first_of(";", 0)));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			int r = stoi (input.substr(0, input.find_first_of(";", 0)));
			int s = stoi (input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0)));	

			// create a new leaf containing city info
			city* newCity = new city;
			newCity->name = name;	
			newCity->longitude = longitude;
			newCity->latitude = latitude;
			newCity->data[0] = p;
			newCity->data[1] = r;
			newCity->data[2] = s;
			newCity->NE = NULL;
			newCity->NW = nullptr;
			newCity->SE = nullptr;
			newCity->SW = nullptr;

			// insert leaf into tree
			if (quadtree.size() == 0) {
				root = quadtree.i(root, newCity);
			} else {
				quadtree.i(root, newCity);
			}
		} else if (command == "s") {
			cin >> input;
			// parse the command line
			float longitude = stof (input.substr(0, input.find_first_of(";", 0)));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			float latitude = stof (input);

			// store results in new city
			city* result = quadtree.s(root, longitude, latitude);
			if (result != nullptr) {
				cout << "found " << result->name << endl;
			} else {
				cout << "not found" << endl;
			}
		} else {
			cin >> input;
			city* reference = new city;

			// parse the command line
			float longitude = stof (input.substr(0, input.find_first_of(";", 0)));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			float latitude = stof (input);
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			string d = input.substr(0, input.find_first_of(";", 0));
			input = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));
			
			// store the index of the type of information being retrieved
			int attr;
			if (input == "p") {
				attr = 0;
			} else if (input == "r") {
				attr = 1;
			} else if (input == "s") {
				attr = 2;
			}

			// store the output
			int output = -1;

			if (command == "q_max") {
				// store the result
				int result = quadtree.q_max(reference, root, longitude, latitude, d, attr, output);
				
				if (result == -1) {
					cout << "failure" << endl;
				} else {
					cout << "max " << result << endl;
				}
			} else if (command == "q_min") {
				// store the result
				int result = quadtree.q_min(reference, root, longitude, latitude, d, attr, output);
				
				if (result == -1) {
					cout << "failure" << endl;
				} else {
					cout << "min " << result << endl;
				}			
			} else if (command == "q_total") {
				// store the result
				int result = quadtree.q_total(reference, root, longitude, latitude, d, attr, output);
				
				if (result == -1) {
					cout << "failure" << endl;
				} else {
					cout << "total " << result << endl;
				}
			}
		}
	}

	return 0;
}