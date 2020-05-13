// Author: Mingze Jin (Oct 2019)
// Linear probing
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#include "openht.h"

ProbeHash::ProbeHash() { // Constructor
}

int ProbeHash::hash(int input) {
	return input % size;
}

void ProbeHash::n(int m) { // Defines size of the hash table
	size = m;
	hashTable.clear();

	// Fill entire table with -1 to represent empty slots
	for (int i = 0; i < m; i ++) {
		hashTable.push_back(-1);
	}
	
	cout << "success" << endl;
}

void ProbeHash::i(int k, int count) { // Inserts the key
	if (count == 0) { // Check if key already is in table
		bool exists = false;
		for (int i = 0; i < size; i ++) {
			if (hashTable[i] == k) {
				exists = true;
			}
		}

		if (exists) {
			cout << "failure" << endl;
		} else {
			i(k, count + 1);
		}
	} else if (hashTable[hash(k)] == -1) { // Check if current slot is empty
		hashTable[hash(k)] = k - count + 1;
		numberOfElements ++;
		cout << "success" << endl;
	} else if (numberOfElements == size || hashTable[hash(k)] == k - count + 1) { // Check if table is full
		cout << "failure" << endl;
	} else { // If the current slot isn't empty, probe for an empty slot using recursion
		i(k + 1, count + 1);
	}
}

void ProbeHash::s(int k, int count) { // Searches for the key
	if (hashTable[hash(k)] == k - count + 1) { // Checks if key is in index specified by hash function
		cout << "found in " << hash(k) << endl;
	} else if (count == size) { // Checks if the whole table has been searched
		cout << "not found" << endl;
	} else { // Otherwise continue searching recursively
		s(k + 1, count + 1);
	}
}

void ProbeHash::d(int k, int count) { // Deletes the key
	if (hashTable[hash(k)] != -1 && hashTable[hash(k)] == k - count + 1) {
		hashTable[hash(k)] = -1;
		numberOfElements --;
		// 		for (int i = 0; i < size; i ++) {
		// 	cout << hashTable[i] << endl;
		// }
		cout << "success" << endl;

	} else if (count == size) {
		cout << "failure" << endl;
	} else  {
		d(k + 1, count + 1);
 	}
}