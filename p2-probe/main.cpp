// Author: Mingze Jin (Oct 2019)
#include <iostream>
#include "openht.h"
using namespace std;

int main() {
	// These two variables will represent the inputs of the program
	string command;
	int input;

	ProbeHash p2;

	while (cin >> command) {
		cin >> input;

		if (command == "n") { // Define the size of the hash table
			p2.n(input);
		} else if (command == "i") { // Delete
			p2.i(input, 0);
		} else if (command == "s") { // Search
			p2.s(input, 1);
		} else if (command == "d") { // Delete
			p2.d(input, 1);
		} else { // Error case when command is invalid
			cout << "Error: invalid command" << endl;
		}
	}

	return 0;
}