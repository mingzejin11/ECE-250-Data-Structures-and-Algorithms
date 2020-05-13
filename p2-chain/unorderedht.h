// Author: Mingze Jin (Oct 2019)
// Chaining
// #ifndef CHAIN_H
// #define CHAIN_H

#include <vector>
#include "linkedlist.h"
using namespace std;

class ChainHash {
private:
	int size;
	vector <LinkedList*> hashTable;

public:
	ChainHash();

	int hash(int input);
	void n(int m);
	void i(int k);
	void s(int k);
	void d(int k);

};

// #endif