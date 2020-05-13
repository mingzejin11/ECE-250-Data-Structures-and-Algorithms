// Author: Mingze Jin (November 2019)
// Linkedlist file
#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    first = 0;
    last = 0;
}

bool LinkedList::enqueue(string name, double d, int index) {
	node* current = first;
	// Case where distance has already been set and is now being updated
	while (current) {
		if (current->name == name) {
			current->d = d;
			return false;
		}

		current = current->next;
	}

	// Case where distance is not yet set
	node* Node = new node;
    Node->name = name;
	Node->d = d;
	Node->index = index;

    if (!first) {
        first = Node;
        last = Node;
        Node->prev = 0;
        Node->next = 0;
    } else {
        last->next = Node;
        Node->prev = last;
        last = Node;
    }

	return true;
}

double LinkedList::search(string name) {
	// Error case when the linked list is empty
    if (!first) {
        return -1;
    }

    node* current = first;
    while (current) {
        if (current->name == name) {
            return current->d;
        }

        current = current->next;
    }

    return -1;
}

int LinkedList::returnIndex(int degree) {
	node* current = first;
	int i = 0;
    while (current) {
        if (i == degree) {
            return current->index;
        }

		current = current->next;
		i ++;
    }
	
	return -1;
}

double LinkedList::returnDistance(int degree) {
	node* current = first;
	int i = 0;
    while (current) {
        if (i == degree) {
            return current->d;
        }

		current = current->next;
		i ++;
    }
	
	return -1;
}

Path::Path() {
	for (int i = 0; i < 100; i ++) {
		path[i] = "";
	}
}

void Path::enqueue(string name, int index) {
	path[index] = name;
}

string Path::search(int index) {
	return path[index];
}

void Path::reset() {
	for (int i = 0; i < 100; i ++) {
		path[i] = "";
	}
}