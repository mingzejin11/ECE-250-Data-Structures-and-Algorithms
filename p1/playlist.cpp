// Author: Mingze Jin (Sept 2019)
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "playlist.h"

void Playlist::i(string song, string artist) {
	// Search for a song in the playlist with a matching name
	if (std::find(songs.begin(), songs.end(), song) != songs.end()) {
		cout << "can not insert " << song << ";" << artist << endl;
	} else {
		songs.push_back(song);
		artists.push_back(artist);
		length ++;

		cout << "success" << endl;
	}
}

void Playlist::p(int n) {
	// Check if a song exists at position n
	if (songs.empty() || n > songs.size() || n < 1) {
		cout << "could not play " << n << endl;
	} else {
		cout << "played " << n << " " << songs.at(n - 1) << ";" << artists.at(n - 1) << endl;
	}
}

void Playlist::e(int n) {
	if (songs.empty() || n > songs.size() || n < 1) {
		cout << "could not erase " << n << endl;
	} else {
		songs.erase(songs.begin() + n - 1);
		artists.erase(artists.begin() + n - 1);
		length --;

		cout << "success" << endl;
	}
}

int Playlist::getSize() {
	if (length > 0 && length < 10) {
		return 1;
	} else if (length > 9) {
		return 2;
	} else if (length > 99) {
		return 3;
	} else {
		return 0;
	}
}