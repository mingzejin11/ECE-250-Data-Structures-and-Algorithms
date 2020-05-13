// Author: Mingze Jin (Oct 2019)
// Chaining

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "unorderedht.h"

ChainHash::ChainHash() {
}

int ChainHash::hash(int input) {
	return input % size;
}

void ChainHash::n(int m) {
	size = m;
	
	// Clear existing hash table
	for (int i = 0; i < hashTable.size(); i ++) {
		hashTable[i]->~LinkedList();
	}
	hashTable.clear();

	// Create a new hash table of specified size "m"
	for (int i = 0; i < size; i ++) {
		hashTable.push_back(new LinkedList);
	}
 	cout << "success" << endl;
}

void ChainHash::i(int k) {
	if (hashTable[hash(k)]->enqueue(k)) {
		cout << "success" << endl;
	} else {
		cout << "failure" << endl;
	}
}

void ChainHash::s(int k) {
	if (hashTable[hash(k)]->search(k) != -1) {
		cout << "found in " << hash(k) << endl;
	} else {
		cout << "not found" << endl;
	}
}

void ChainHash::d(int k) {
	if (hashTable[hash(k)]->dequeue(k)) {
		cout << "success" << endl;
	} else {
		cout << "failure" << endl;
	}	
}