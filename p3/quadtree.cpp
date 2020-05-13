// Author: Mingze Jin (November 2019)
// Quadtree file

#include <iostream>
#include <sstream>
#include <string>
#include "quadtree.h"
using namespace std;

Quadtree::Quadtree() {
	numberOfCities = 0;
}

city* Quadtree::i(city* current, city* newCity) {
	if (current == nullptr) {
		numberOfCities ++;
		cout << "success" << endl;
		return newCity;
	}

	// check if city already exists in location
	if (current->longitude == newCity->longitude && current->latitude == newCity->latitude) {
		cout << "failure" << endl;
		return current;
	}

	if (newCity->longitude >= current->longitude && newCity->latitude > current->latitude) {
		current->NE = i(current->NE, newCity);
	} else if (newCity->longitude < current->longitude && newCity->latitude >= current->latitude) {
		current->NW = i(current->NW, newCity);
	} else if (newCity->longitude <= current->longitude && newCity->latitude < current->latitude) {
		current->SW = i(current->SW, newCity);
	} else if (newCity->longitude > current->longitude && newCity->latitude <= current->latitude) {
		current->SE = i(current->SE, newCity);
	}

	return current;
}

city* Quadtree::s(city *current, float longitude, float latitude) {
	// base case where city is found
	if (current == nullptr || (current->longitude == longitude && current->latitude == latitude)) {
		return current;
	}

	if (longitude >= current->longitude && latitude > current->latitude) {
		return s(current->NE, longitude, latitude);
	} else if (longitude < current->longitude && latitude >= current->latitude) {
		return s(current->NW, longitude, latitude);
	} else if (longitude <= current->longitude && latitude < current->latitude) {
		return s(current->SW, longitude, latitude);
	} else if (longitude > current->longitude && latitude <= current->latitude) {
		return s(current->SE, longitude, latitude);
	}

	return current;
}

int Quadtree::q_max(city* current, city* root, float longitude, float latitude, string d, int attr, int output) {
	// error case for when there isn't a tree
	if (root == nullptr || (current == nullptr && output != -1)) {
		return output;
	}
	
	if (output == -1) {
		current = s(root, longitude, latitude);
		// Check if city exists
		if (current == nullptr) {
			return output;
		}

		if (d == "NE") {
			if (current->NE == nullptr) {
				return output;
			} else {
				// recursively search for the max
				current = current->NE;
				output = current->data[attr];
			}
		} else if (d == "NW") {
			if (current->NW == nullptr) {
				return output;
			} else {
				current = current->NW;
				output = current->data[attr];
			}
		} else if (d == "SW") {
			if (current->SW == nullptr) {
				return output;
			} else {
				current = current->SW;
				output = current->data[attr];
			}
		} else if (d == "SE") {
			if (current->SE == nullptr) {
				return output;
			} else {
				current = current->SE;
				output = current->data[attr];
			}
		}

		// recursively search all branches in direction d
		int NE = q_max(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_max(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_max(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_max(current->SW, root, longitude, latitude, d, attr, output);

		if (output < NE) {
			output = NE;
		}
		
		if (output < NW) {
			output = NW;
		}

		if (output < SE) {
			output = SE;
		}

		if (output < SW) {
			output = SW;
		}

		return output;
	} else {
		if (output < current->data[attr]) {
			output = current->data[attr];
		}

		int NE = q_max(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_max(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_max(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_max(current->SW, root, longitude, latitude, d, attr, output); 
		
		if (output < NE) {
			output = NE;
		}
		
		if (output < NW) {
			output = NW;
		}

		if (output < SE) {
			output = SE;
		}

		if (output < SW) {
			output = SW;
		}

		return output;		
	}
}

int Quadtree::q_min(city* current, city* root, float longitude, float latitude, string d, int attr, int output) {
	// error case for when there isn't a tree
	if (root == nullptr || (current == nullptr && output != -1)) {
		return output;
	}
	
	if (output == -1) {
		current = s(root, longitude, latitude);
		// Check if city exists
		if (current == nullptr) {
			return output;
		}

		if (d == "NE") {
			if (current->NE == nullptr) {
				return output;
			} else {
				// recursively search for the max
				current = current->NE;
				output = current->data[attr];
			}
		} else if (d == "NW") {
			if (current->NW == nullptr) {
				return output;
			} else {
				current = current->NW;
				output = current->data[attr];
			}
		} else if (d == "SW") {
			if (current->SW == nullptr) {
				return output;
			} else {
				current = current->SW;
				output = current->data[attr];
			}
		} else if (d == "SE") {
			if (current->SE == nullptr) {
				return output;
			} else {
				current = current->SE;
				output = current->data[attr];
			}
		}

		// recursively search all branches in direction d
		int NE = q_min(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_min(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_min(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_min(current->SW, root, longitude, latitude, d, attr, output);

		if (output > NE) {
			output = NE;
		}
		
		if (output > NW) {
			output = NW;
		}

		if (output > SE) {
			output = SE;
		}

		if (output > SW) {
			output = SW;
		}

		return output;
	} else {
		if (output > current->data[attr]) {
			output = current->data[attr];
		}

		int NE = q_min(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_min(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_min(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_min(current->SW, root, longitude, latitude, d, attr, output); 
		
		if (output > NE) {
			output = NE;
		}
		
		if (output > NW) {
			output = NW;
		}

		if (output > SE) {
			output = SE;
		}

		if (output > SW) {
			output = SW;
		}

		return output;		
	}	
}

int Quadtree::q_total(city* current, city* root, float longitude, float latitude, string d, int attr, int output) {
	// error case for when there isn't a tree
	if (root == nullptr) {
		return output;
	} else if (current == nullptr && output != -1) {
		return 0;
	}
	
	if (output == -1) {
		current = s(root, longitude, latitude);
		// Check if city exists
		if (current == nullptr) {
			return output;
		}

		if (d == "NE") {
			if (current->NE == nullptr) {
				return output;
			} else {
				// recursively search for the max
				current = current->NE;
				output = current->data[attr];
			}
		} else if (d == "NW") {
			if (current->NW == nullptr) {
				return output;
			} else {
				current = current->NW;
				output = current->data[attr];
			}
		} else if (d == "SW") {
			if (current->SW == nullptr) {
				return output;
			} else {
				current = current->SW;
				output = current->data[attr];
			}
		} else if (d == "SE") {
			if (current->SE == nullptr) {
				return output;
			} else {
				current = current->SE;
				output = current->data[attr];
			}
		}

		// recursively search all branches in direction d
		int NE = q_total(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_total(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_total(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_total(current->SW, root, longitude, latitude, d, attr, output);

		return output + NE + NW + SE + SW;
	} else {
		int NE = q_total(current->NE, root, longitude, latitude, d, attr, output);
		int NW = q_total(current->NW, root, longitude, latitude, d, attr, output);
		int SE = q_total(current->SE, root, longitude, latitude, d, attr, output);
		int SW = q_total(current->SW, root, longitude, latitude, d, attr, output); 

		return current->data[attr] + NE + NW + SE + SW;		
	}	
}

void Quadtree::print(city* current) {
	// return when there are no cities left to print
	if (current == nullptr) {
		return;
	}

	// print names of cities
	print(current->NE);
	print(current->NW);

	cout << current->name << " ";

	print(current->SW);
	print(current->SE);
}

void Quadtree::clear(city* current) {
	// return when there are no more leaves to delete
	if (current == nullptr) {
		return;
	}

	clear(current->NE);
	clear(current->NW);
	clear(current->SE);
	clear(current->SW);	
	
	delete current;
	// decrement the number of cities
	numberOfCities = 0;
}

int Quadtree::size() {
	// return the number of cities
	return numberOfCities;
}