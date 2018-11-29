#pragma once
#include <iostream>
#include <vector>
#include "enums.h"

using namespace std;

class gate;
class wire {
public:
	wire(wireValue state, int wireNumber) :state(state = unknown), wireNumber(wireNumber) {};
	void setGate(gate* gate1);
	void setState(wireValue stat);

	wireValue getState();
protected:
	int wireNumber;
	wireValue state = unknown;
	vector<gate*> gates;
};