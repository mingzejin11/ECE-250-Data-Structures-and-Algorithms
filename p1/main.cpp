// Author: Mingze Jin (Sept 2019)
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "playlist.h"
// #include "playlist.cpp"

int main() {
	Playlist user(0);

	string input;
	string command = "";
	string song = "";
	string artist = "";
	int index = 0;

	while (getline(cin, input)) {
		command = input.substr(0, input.find_first_of(" ", 0));

		if (command == "i") { // Insert
			song = input.substr(input.find_first_of(" ", 0) + 1, input.find_first_of(";", 0) - 2);
			artist = input.substr(input.find_first_of(";", 0) + 1, input.length() - input.find_first_of(";", 0));

			user.i(song, artist);
		} else if (command == "p") { // Play
			input = input.substr(input.find_first_of(" ", 0) + 1, user.getSize());
			index = stoi(input);

			user.p(index); 
		} else if (command == "e") { // Erase
			input = input.substr(input.find_first_of(" ", 0) + 1, user.getSize());
			index = stoi(input);

			user.e(index);
		} else { // Error case when command is invalid
			cout << "Error: invalid command" << endl;
		}
	}

	return 0;
}