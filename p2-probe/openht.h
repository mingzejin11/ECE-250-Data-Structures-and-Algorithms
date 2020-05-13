// Author: Mingze Jin (Oct 2019)
// Linear probing
#ifndef PROBE_H
#define PROBE_H

#include <vector>
using namespace std;

class ProbeHash {
private:
	vector <int> hashTable;
	int size;
	int numberOfElements = 0;

public:
	// Constructor
	ProbeHash();

	// Hash function 
	int hash(int input);

	// Functions named after project specifications
	void n(int m);
	void i(int k, int count);
	void s(int k, int count);
	void d(int k, int count);
};

#endif