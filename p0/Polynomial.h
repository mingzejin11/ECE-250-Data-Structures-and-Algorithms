// Author: Mingze Jin (Sept 2019)
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <math.h>
using namespace std;

// Polynomial for single variable X
class Polynomial {
	// Class variables
private:
	struct node {
		int power;
		double coefficient;
		node *next;
		node(int pow, double coeff) {
			power = pow;
			coefficient = coeff;
		}
	};

public:
	node *head = NULL;
	node *tail = NULL;

	// Constructor
	Polynomial (const int& size_p, const double coeff_p[]) {
	}

	// Class functions
	void init(const int& size_p, string data);
	void uninit();
	void get(int size, string data, node *rootPtr);
	void eval(int x, int expected_value, node *rootPtr);
	void add(node *p1_head, node *p2_head, node *expected_poly);
	void mult(node *p1_head, int size_p1, node *p2_head, int size_p2, node *expected_poly);

	// Function for testing polynomials
	void displayLinkedList(node *head);
};

#endif