// Author: Mingze Jin (November 2019)
// Quadtree header file
#include <iostream>
#include <string>
using namespace std;

struct city {
	// city information
    string name;
    float longitude;
    float latitude;
	int data [3];

	// direction pointers
    city* NW;
    city* NE;
    city* SW;
    city* SE;
};

class Quadtree {
public:
	int numberOfCities;

	// constructor
	Quadtree();

	// class functions
	city* i(city* current, city* newCity);
	city* s(city* current, float longitude, float latitude);
	int q_max(city* current, city* root, float longitude, float latitude, string d, int attr, int output);
	int q_min(city* current, city* root, float longitude, float latitude, string d, int attr, int output);
	int q_total(city* current, city* root, float longitude, float latitude, string d, int attr, int output);

	void print(city* current);
	void clear(city* current);
	int size();
};