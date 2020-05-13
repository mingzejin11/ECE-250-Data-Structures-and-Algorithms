// Author: Mingze Jin (Sept 2019)
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class Playlist {
private:
	// 2 vectors, one to store artist names and the other for song titles
	vector<string> songs;
	vector<string> artists;
	int length;

public:
	// Constructor
	Playlist (int size) {
		this->length = size;
	}

	// Class functions
	// Adds songs to playlist
	void i(string song, string artist);

	// Plays the song at index
	void p(int n);

	// Erases song at index
	void e(int n); 

	// Gets size of playlist
	int getSize();
};

#endif