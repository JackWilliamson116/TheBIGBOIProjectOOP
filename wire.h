#pragma once
#include <iostream>
#include <vector>
#include "enums.h"

using namespace std;

class gate;
class wire {
public:
	wire(int wireNumber, wireValue state = unknown) : wireNumber(wireNumber), state(state) {};
	void setGate(gate* gate1);
	void setState(wireValue stat);
	int getWireNumber() { return wireNumber; };
	wireValue getState();
protected:
	int wireNumber;
	wireValue state = unknown;
	vector<gate*> gates;
};