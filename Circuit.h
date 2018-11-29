#pragma once
#include <iostream>
#include <map>
#include "wire.h"

using namespace std;

class circuit {
public:
	void insertWire(char c, wire* w1);
private:
	map<char, wire*> wireMap;
	int pqTB;
};
class event {
public:
	event(wire w1, int time, wireValue val) : w1(w1), time(time), val(val) {};
private:
	wire w1;
	int time;
	wireValue val;
};
