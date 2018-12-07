#pragma once
#include <iostream>
#include <vector>
#include "enums.h"
#include <map>

using namespace std;

class gate;
class wire {
public:
	wire(int wireNumber, wireValue state = unknown) : wireNumber(wireNumber), state(state) {};
	void setGate(gate* gate1);
	vector<gate*> getGates();
	void setState(wireValue stat);
	int getWireNumber() { return wireNumber; };
	wireValue getState();
	void addToHistory(int i, wireValue val);
	void print(int fTime);
protected:
	int wireNumber;
	wireValue state = unknown;
	vector<gate*> gates;
	string wireName;
	map<int, wireValue> history;
};