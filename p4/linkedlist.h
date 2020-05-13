// Author: Mingze Jin (November 2019)
// Linkedlist header file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct node {
    node* next;
    node* prev;
    double d;
	int index;
	string name;
};

class LinkedList {
private:
    node* first;
    node* last;

public:
	// Constructor
    LinkedList();

    bool enqueue(string name, double d, int index);
    double search(string name);
	int returnIndex(int degree);
	double returnDistance(int degree);
};

class Path {
public:
	string path[100];

	// Constructor
    Path();

    void enqueue(string name, int index);
	string search(int index);
	void reset();
};

#endif