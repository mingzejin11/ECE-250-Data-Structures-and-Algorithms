// Author: Mingze Jin (Sept 2019)
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Polynomial.h" // Class to index polynomials
// #include "Polynomial.cpp"

int main() {
	double arr[1] = {0};
	Polynomial p1(0, arr);
	Polynomial p2(0, arr);
	Polynomial expected(0, arr);

	string input;
	int size = 0;
	int p1_size = 0;
	int p2_size = 0;
	int expected_size = 0;
	double x = 0;
	double expected_x = 0;
	string command = "";
	string data = "";
	string coefficient = "";

	while (getline(cin, input)) {
		command = input.substr(0, input.find_first_of(" ", 0));
		data = input.substr(input.find_first_of(" ", 0) + 1, input.length() - input.find_first_of(" ", 0));

		if (command == "init") {
			size = stoi(input.substr(input.find_first_of(" ", 0), input.length() - input.find_first_of(" ", 0)));
			cout << "success" << endl;
		} else if (command == "coeff_p1") {
			p1_size = size;
			p1.uninit();
			p1.init(size, data);
			cout << "success" << endl;
		} else if (command == "get") {
			p1.get(p1_size, data, p1.head);
		} else if (command == "eval") {
			x = stod(input.substr(input.find_first_of(" ", 0), input.length() - input.find_first_of(" ", 0)));
			expected_x = stod(data.substr(data.find_first_of(" ", 0), data.length() - data.find_first_of(" ", 0)));
			p1.eval(x, expected_x, p1.head);
		} else if (command == "coeff_p2") {
			p2_size = size;
			p2.uninit();
			p2.init(size, data);
			cout << "success" << endl;
		} else if (command == "add") {
			expected.uninit();
			if (p1_size > p2_size) {
				expected.init(p1_size, data);
			} else {
				expected.init(p2_size, data);
			}
			p1.add(p1.head, p2.head, expected.head);
		} else if (command == "mult") {
			expected.uninit();
			expected.init((p1_size + p2_size - 1), data);
			p1.mult(p1.head, p1_size, p2.head, p2_size, expected.head);
		} else {
			cerr << "Error: invalid command" << endl;
		}
	}

	return 0;
}
