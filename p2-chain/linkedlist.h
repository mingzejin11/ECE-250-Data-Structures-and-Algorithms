#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    node* next;
    node* prev;
    int key;
};

class LinkedList {
private:
    node* first;
    node* last;

public:
	// constructor
    LinkedList();

	// destructor
    ~LinkedList();

    bool enqueue(int k);
    bool dequeue(int k);
    int search(int k);
};

#endif