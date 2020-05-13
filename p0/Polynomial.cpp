// Author: Mingze Jin (Sept 2019)
#include <iostream>
#include <sstream>
using namespace std;

#include "Polynomial.h"

void Polynomial::init(const int& size_p, string data) {
	double coeff [size_p];
	string coefficient = "";
	node *nodePtr = NULL;
	int i = 0;

	while (i < size_p - 1) {
		if (i == size_p - 1) {
			coefficient = data.substr(data.find_first_of(" ", 0), data.length() - data.find_first_of(" ", 0));
		} else {
			coefficient = data.substr(data.find_first_of(" ", 0), data.find_first_of(";", 0) - data.find_first_of(" ", 0));
		}

		coeff[i] = stod(coefficient);


			data = data.substr(data.find_first_of(";", 0) + 1, data.length() - data.find_first_of(";", 0));

		i ++;
	}

	coeff[size_p - 1] = stod(data.substr(data.find_first_of(" ", 0), data.length() - data.find_first_of(" ", 0)));

    node *Ptr = NULL;
    node *rootNodePtr = NULL;
    node *lastNodePtr = NULL;
    for(int i = 0 ; i < size_p; i++) {
        if(!Ptr) {
            Ptr = new node(i, coeff[i]);
            if(!rootNodePtr)
                rootNodePtr = Ptr;    
            if(lastNodePtr)    
                lastNodePtr->next = Ptr;
        }
        lastNodePtr = Ptr;
        Ptr = Ptr->next;

		cout << i << endl;
    }
}

void Polynomial::uninit() {
	node *current = head;

    while (current != NULL) {
        node *next = current->next;
        delete current;
        current = next;
	}
    head = 0;
}

void Polynomial::get(int size_p, string data, node *rootPtr) {
	int i;
	bool match = true;
	node *temp = rootPtr;
	double coeff[size_p];
	string coefficient = "";

	for (int i = 0; i < size_p; i ++) {
		if (i == size_p - 1) {
			coefficient = data.substr(data.find_first_of(" ", 0), data.length() - data.find_first_of(" ", 0));
		} else {
			coefficient = data.substr(data.find_first_of(" ", 0), data.find_first_of(";", 0) - data.find_first_of(" ", 0));
		}

		coefficient = data.substr(data.find_first_of(" ", 0), data.length() - data.find_first_of(" ", 0));

		coeff[i] = stod(coefficient);
		if (size_p > 1 && i != size_p - 1) {
			data = data.substr(data.find_first_of(";", 0) + 1, data.length() - data.find_first_of(";", 0));
		}
	}

	while(rootPtr != NULL) {
		if (rootPtr->coefficient != coeff[i]) {
			match = false;
		}

		rootPtr = rootPtr->next;
		i ++;
	}

	if (match == true) {
		cout << "success" << endl;
	} else {
		cout << "failure" << endl;
	}

	rootPtr = temp;
}

void Polynomial::eval(int x, int expected_value, node *rootPtr) {
	int i;
	int product;
	int sumOfProducts;
	node *temp = rootPtr;

	while (rootPtr != NULL) {
		product = rootPtr->coefficient * pow(x, rootPtr->power);
		sumOfProducts += product;
		rootPtr = rootPtr->next;
		i ++;
	}

	if (sumOfProducts != expected_value) {
		cout << "failure" << endl;
	} else {
		cout << "success" << endl;
	}

	rootPtr = temp;
}

void Polynomial::add(node *p1_head, node *p2_head, node *expected_poly) {
	int i;
	double sum = 0.0;
	bool match = true;
	node *temp1 = p1_head;
	node *temp2 = p2_head;
	node *tempExpected = expected_poly;

	while (p1_head != NULL || p2_head != NULL) {
		if (p1_head == NULL) {
			sum = p2_head->coefficient;
			p2_head = p2_head->next;
		}

		if (p2_head == NULL) {
			sum = p1_head->coefficient;
			p1_head = p1_head->next;
		}

		if (p1_head != NULL && p2_head != NULL) {
			sum = p1_head->coefficient + p2_head->coefficient;
			p1_head = p1_head->next;
			p2_head = p2_head->next;
		}

		if (sum != expected_poly->coefficient) {
			match = false;
		}

		expected_poly = expected_poly->next;
		i ++;
	}

	if (match == false) {
		cout << "failure" << endl;
	} else {
		cout << "success" << endl;
	}

	p1_head = temp1;
	p2_head = temp2;
	tempExpected = expected_poly;
}

void Polynomial::mult(node *p1_head, int size_p1, node *p2_head, int size_p2, node *expected_poly) {
	int i;
	int degree;
	double product[size_p1 + size_p2 - 1];
	bool match = true;
	node *temp1 = p1_head;
	node *temp2 = p2_head;
	node *tempExpected = expected_poly;

	for (int j = 0; j < size_p1 + size_p2 - 1; j ++) {
		product[j] = 0.0;
	}

	while (p1_head != NULL) {
		while (p2_head != NULL) {
			degree = p1_head->power + p2_head->power;
			product[degree] += p1_head->coefficient * p2_head->coefficient;
			p2_head = p2_head->next;
		}

		p2_head = temp2;
		p1_head = p1_head->next;
	}

	while (expected_poly != NULL) {
		if (expected_poly->coefficient != product[i]) {
			match = false;
		}

		expected_poly = expected_poly->next;
		i ++;
	}

	if (match == false) {
		cout << "failure" << endl;
	} else {
		cout << "success" << endl;
	}

	p1_head = temp1;
	p2_head = temp2;
	tempExpected = expected_poly;
}

void Polynomial::displayLinkedList(node *head) {
	while(head != NULL) {
		cout << head->coefficient << " ";
		head = head->next;
	}

	cout << endl;
}
