#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    first = 0;
    last = 0;
}

LinkedList::~LinkedList() {
    node* current = first;
    while (current) {
        node* temp = current->next;
        delete current;
        current = temp;
    }

    first = 0;
}

bool LinkedList::enqueue(int k) {
	node* current = first;
	while (current) {
		if (current->key == k) {
			return false;
		}

		current = current->next;
	}

	node* Node = new node;
    Node->key = k;

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

bool LinkedList::dequeue(int k){
    if (!first) {
        return false;
    }

    node* current = first;
    while (current) {
        if (current->key == k) {
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                last = current->prev;
            }

            if (current->prev) {
                current->prev->next = current->next;
            } else {
                first = current->next;
            }

            delete current;
            return true;
        }

        current = current->next;
    }

    return false;
}

int LinkedList::search(int k) {
    if (!first) {
        return -1;
    }

    node* current = first;
    int i = 0;
    while (current) {
        if (current->key == k) {
            return i;
        }

        i ++;
        current = current->next;
    }

    return -1;
}